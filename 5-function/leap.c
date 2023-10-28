//
// Created by hfwei on 2023/10/6.
//

#include <stdio.h>
#include <stdbool.h>

bool IsLeapYear(int year);

int main(void) {
  // year: local variable
  // block variable
  int year = 0;
  scanf("%d", &year);

  // year: actual argument
  if (IsLeapYear(year)) {
    printf("%d is a leap year\n", year);
  } else {
    printf("%d is a common year\n", year);
  }

  return 0;
}

// year: local variable (formal parameter)
// scope: block scope
bool IsLeapYear(int year) {
  bool leap = (year % 4 == 0 && year % 100 != 0) ||
      (year % 400 == 0);
  return leap;
}