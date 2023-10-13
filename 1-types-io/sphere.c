//
// Created by hfwei on 2023/9/22.
//

#include <stdio.h>
int main(void) {
  const double PI = 3.14159;
  int radius = 100;

  // surfaceArea
  double surface_area = 4 * PI * radius * radius;
  double volume = 4.0 / 3 * PI * radius * radius * radius;

  // %15.4f: 15 (minimum) filed width; .4: precision
  // -: flag (left alignment)
  printf("%-15.4f : surface_area\n%-15.4f : volume\n",
         surface_area, volume);

  return 0;
}