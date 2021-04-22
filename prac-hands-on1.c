// Ask for plate number (Assume consist of 7 characters with 4th character being
// a '-') 3 letters - 3 real numbers else invalid input
// First digit:
// If 1 - 2: Vehicles may traverse roads on any day EXCEPT Mondays
// If 3 - 4: Vehicles may traverse roads on any day EXCEPT Tuesdays
// If 5 - 6: Vehicles may traverse roads on any day EXCEPT Wednesdays
// If 7 - 8: Vehicles may traverse roads on any day EXCEPT Thursdays
// If 9 - 0: Vehicles may traverse roads on any day EXCEPT Fridays
// First letter:
// If D (for doctors) and A (for ambulances) and F (for firetrucks) ALLOWED on
// ANY DAY
// ALL vehicles allowed on Saturdays and Sundays

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 7
#define SEGMENT_LENGTH 3

char* getPlateNumber(void) {
  char* plateNumber = (char*)malloc(MAX_LENGTH * sizeof(char));

  printf("Enter Plate no.: ");
  scanf("%s", plateNumber);

  return plateNumber;
}

bool isValidPlateNumber(char* plateNumber) {
  for (int i = 0; i < SEGMENT_LENGTH; i++) {
    if (plateNumber[i] < 'A' ||
        plateNumber[i] > 'Z') {  // If first three characters are not letters
      return false;
    }
  }
  for (int i = MAX_LENGTH - 1; i > SEGMENT_LENGTH; i--) {
    if (plateNumber[i] < '0' ||
        plateNumber[i] > '9') {  // If first three characters are not numbers
      return false;
    }
  }
  return true;
}

int main() {
  char* plateNumber = getPlateNumber();

  if (isValidPlateNumber(plateNumber)) {
    puts("VALID");
  } else {
    puts("INVALID!");
  }

  free(plateNumber);
  return 0;
}
