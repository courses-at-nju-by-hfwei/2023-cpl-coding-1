/**
 * file: radius.c
 *
 * Created by hengxin on 11/24/23.
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main() {
  /********** On radius **********/
  // type: int; value: 100; address: &radius
  int radius = 100;

  printf("radius = %d\n", radius);
  // &: address-of operator
  printf("&radius = %p\n", &radius);

  radius = 200;
  double circumference = 2 * PI * radius;
  // printf("circumference = %f\n", circumference);
  /********** On radius **********/

  /********** On ptr_radius1 **********/
  // type: int * (pointer to int); value: &radius;
  int *ptr_radius1 = &radius;
  printf("ptr_radius1 = %p\n", ptr_radius1);
  printf("&ptr_radius1 = %p\n", &ptr_radius1);

  // as a lvalue and a rvalue
  int radius_1 = 1000;
  int *ptr_radius_1 = &radius_1;
  ptr_radius1 = ptr_radius_1;
  /********** On ptr_radius1 **********/

  /********** On *ptr_radius1 **********/
  // *: indirection (dereference) operator
  // *ptr_radius1 behaves like radius_1
  *ptr_radius1 = 2000;
  printf("radius_1 = %d\n", radius_1);
  printf("radius_1 = %d\n", *ptr_radius_1);
  circumference = 2 * PI * (*ptr_radius1);
  /********** On *ptr_radius1 **********/

  // int v = 100;
  // int *pv = &v;
  // pv = &pv;
  /********** On ptr_radius1 as lvalue and rvalue **********/
  /********** On ptr_radius1 as lvalue and rvalue **********/

  /********** On array names **********/
  int arr[] = {1, 2, 3};
  // arr++;
  // arr = arr + 1;
  /********** On array names **********/

  /********** On malloc/free **********/
  /********** On malloc/free **********/

  /********** On const **********/
  /********** On const **********/

  return 0;
}