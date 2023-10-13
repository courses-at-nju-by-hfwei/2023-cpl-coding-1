//
// Created by hfwei on 2023/9/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int high = 100;
  int secret = 0;
  int guess = 0;
  int chance = 7;

  /*
   * print the rule
   */
  printf("The computer will generate a random number.\n"
         "You have %d chances.\n", chance);

  /*
   * choose a random number between 1 and high
   */
  srand(time(NULL));
  secret = rand() % high + 1;
  printf("%d\n", secret);

  while (chance > 0) {
    /*
     * ask the player to enter his/her guess
     */
    printf("Please enter your guess.\n");

    /*
     * store the guess, compare it with secret, inform the player of the result
     */
    scanf("%d", &guess);

    if (guess == secret) {
      printf("You Win!\n");
      break;
    } else if (guess > secret) {
      printf("guess > secret\n");
    } else {
      printf("guess < secret\n");
    }

    chance = chance - 1;

    /*
     * loop: until the player wins or loses
     */
  }
  return 0;
}