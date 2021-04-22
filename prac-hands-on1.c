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

#include <math.h>
#include <stdio.h>

int getDigit(int plateNo, int digitPlace) {
  int divisor;
  divisor = plateNo / pow(10, digitPlace);
  divisor = divisor % 10;
  return divisor;
}

int main() {
  int plateNo = 0, letterDigit1, letterDigit2, letterDigit3, numDigit4,
      numDigit5, numDigit6;
  int digitPlace;

  printf("Enter Plate no.: ");
  scanf("%d", &plateNo);

  printf("Enter digit place: ");
  scanf("%d", &digitPlace);

  letterDigit1 = getDigit(plateNo, 1);
  letterDigit2 = getDigit(plateNo, 2);
  letterDigit3 = getDigit(plateNo, 3);
  numDigit4 = getDigit(plateNo, 4);
  numDigit5 = getDigit(plateNo, 5);
  numDigit6 = getDigit(plateNo, 4);

  printf("%dth digit of %d is %d.\n", digitPlace, plateNo,
         getDigit(plateNo, digitPlace));

  printf("Plate no. is %d%d%d-%d%d%d", letterDigit1, letterDigit2, letterDigit3,
         numDigit4, numDigit5, numDigit6);
  printf("\nTravel is on: ");

  return 0;
}
