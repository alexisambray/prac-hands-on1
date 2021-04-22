#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 7
#define SEGMENT_LENGTH 3
#define FIRST_DIGIT 4
#define FIRST_LETTER 0

typedef struct {
  bool monday, tuesday, wednesday, thursday, friday, saturday, sunday;
} AvailableDays;

typedef enum {
  DOCTOR = 'D',
  AMBULANCE = 'A',
  FIRETRUCK = 'F'
} EmergencyServices;

char* getPlateNumber(void) {
  char* plateNumber = (char*)malloc(MAX_LENGTH * sizeof(char));

  printf("Enter Plate no.: ");
  scanf("%s", plateNumber);
  return plateNumber;
}

bool isValidPlateNumber(char* plateNumber) {
  for (int i = 0; i < SEGMENT_LENGTH; i++) {
    if (!isalpha(
            plateNumber[i])) {  // If first three characters are not letters
      return false;
    }
  }
  for (int i = MAX_LENGTH - 1; i > SEGMENT_LENGTH; i--) {
    if (!isdigit(
            plateNumber[i])) {  // If first three characters are not numbers
      return false;
    }
  }
  return true;
}

AvailableDays determineAvailableDays(char* plateNumber) {
  AvailableDays availableDays = {.monday = true,
                                 .tuesday = true,
                                 .wednesday = true,
                                 .thursday = true,
                                 .friday = true,
                                 .saturday = true,
                                 .sunday = true};
  switch (plateNumber[FIRST_LETTER]) {
    case DOCTOR:
    case AMBULANCE:
    case FIRETRUCK:
      break;
    default:
      switch (plateNumber[FIRST_DIGIT]) {
        case '1':
        case '2':
          availableDays.monday = false;
          break;
        case '3':
        case '4':
          availableDays.tuesday = false;
          break;
        case '5':
        case '6':
          break;
          availableDays.wednesday = false;
        case '7':
        case '8':
          break;
          availableDays.thursday = false;
        case '9':
        case '0':
          break;
          availableDays.friday = false;
      }
  }
  return availableDays;
}

void displayAvailableDays(AvailableDays availableDays) {
  puts("Travel is on: ");
  if (availableDays.monday) {
    puts("MONDAY");
  }
  if (availableDays.tuesday) {
    puts("TUESDAY");
  }
  if (availableDays.wednesday) {
    puts("WEDNESDAY");
  }
  if (availableDays.thursday) {
    puts("THURSDAY");
  }
  if (availableDays.friday) {
    puts("FRIDAY");
  }
  if (availableDays.saturday) {
    puts("SATURDAY")
  }
  if (availableDays.sunday) {
    puts("SUNDAY");
  }
}

int main() {
  char* plateNumber = getPlateNumber();

  if (isValidPlateNumber(plateNumber)) {
    AvailableDays availableDays = determineAvailableDays(plateNumber);
    displayAvailableDays(availableDays);
  } else {
    puts("INVALID PLATE NO.");
  }

  free(plateNumber);
  return 0;
}
