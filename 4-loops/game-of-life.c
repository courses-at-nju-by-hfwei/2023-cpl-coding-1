//
// Created by hfwei on 2023/10/19.
//

#include <stdio.h>
#include <unistd.h>

#define SIZE 6

const int board[SIZE][SIZE] = {
    { 0 },
    { 0, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 0 },
    { 0 }
};

//const int board[SIZE][SIZE] = {
//    [1][1] = 1, [1][2] = 1,
//    [2][1] = 1, [2][2] = 1,
//    [3][3] = 1, [3][4] = 1,
//    [4][3] = 1, [4][4] = 1
//};

int main() {
  // TODO: play game-of-life
  // extend the board
  int old_board[SIZE + 2][SIZE + 2] = { 0 };

  for (int row = 1; row <= SIZE; row++) {
    for (int col = 1; col <= SIZE; col++) {
      old_board[row][col] = board[row - 1][col - 1];
    }
  }

  // print the initial state
  for (int row = 1; row <= SIZE ; ++row) {
    for (int col = 1; col <= SIZE; ++col) {
      printf("%c ", old_board[row][col] ? '*' : ' ');
    }
    printf("\n");
  }
  system("clear");

  // board = apply rule > new_board
  int new_board[SIZE + 2][SIZE + 2] = { 0 };

  for (int i = 0; i < 10; i++) {
    for (int row = 1; row <= SIZE; ++row) {
      for (int col = 1; col <= SIZE; ++col) {
        // counting the number of live cells around old_board[row][col]
        int neighbors =
            old_board[row - 1][col - 1] +
                old_board[row - 1][col] +
                old_board[row - 1][col + 1] +
                old_board[row][col - 1] +
                old_board[row][col + 1] +
                old_board[row + 1][col - 1] +
                old_board[row + 1][col] +
                old_board[row + 1][col + 1];

        // apply the rules => new_board
        if (old_board[row][col]) {
          new_board[row][col] = (neighbors == 2 || neighbors == 3);
        } else {
          new_board[row][col] = (neighbors == 3);
        }
      }
    }

    // print new_board
    for (int row = 1; row <= SIZE; ++row) {
      for (int col = 1; col <= SIZE; ++col) {
        printf("%c ", new_board[row][col] ? '*' : ' ');
      }
      printf("\n");
    }
    // Linux: #include <unistd.h>
    sleep(1);
    // Windows: #include <windows.h> (Sleep(ms))

    // Linux: #include <stdlib.h>
    // Windows: #include <stdlib.h> (system("cls"))
    system("clear");

    // old_board <- new_board
    for (int row = 1; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        old_board[row][col] = new_board[row][col];
      }
    }
  }

  return 0;
}