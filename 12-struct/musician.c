//
// Created by hfwei on 2022/12/8.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

// enumeration
typedef enum gender {
  MALE,
  FEMALE,
} Gender;

typedef struct score {
  int c_score;  // 4
  int java_score; // 4
  int python_score; // 4
} Score;

typedef struct musician {
  char *name; // 8
  Gender gender;  // 1

  char *album;  // 8
  Score score;
} Musician;

// void PrintMusician(const Musician m);
void PrintMusician(const Musician *m);
int CompareMusician(const void *m1, const void *m2);

int main() {
  printf("sizeof Musician = %zu\n", sizeof(Musician));

  Musician luo = {
      .name = "Luo Dayou",
      .gender = MALE,
      .album = "ZhiHuZheYe",
      .score = {
          .c_score = 0,
          .java_score = 10,
          .python_score = 20,
      }
  };

  Musician cui = {
      .name = "Cui Jian",
      .gender = MALE,
      .album = "XinChangZhengLuShangDeYaoGun",
      .score = {
          .c_score = 0,
          .java_score = 10,
          .python_score = 20,
      }
  };

  char album[] = "YiKeBuKenMeiSuDeXin";
  Musician zhang = {
      .name = "Zhang Chu",
      .gender = MALE,
      .album = album,
      .score = {
          .c_score = 0,
          .java_score = 10,
          .python_score = 20,
      }
  };

  Musician guo = zhang;
  guo.name = "guo";
  guo.album = "album";
  // strcpy(guo.album, "YiKeJiuMeiSuDeXin");
  PrintMusician(&guo);
  PrintMusician(&zhang);

  Musician musicians[] = {luo, cui, zhang};
  int len = sizeof musicians / sizeof *musicians;

  qsort(musicians, len, sizeof *musicians, CompareMusician);

  for (int i = 0; i < len; ++i) {
    PrintMusician(&musicians[i]);
  }

  return 0;
}

// void PrintMusician(const Musician m) {
//   printf("%s\t%c\t%s\t%d\t%d\t%d\n",
//          m.name,
//          m.gender,
//          m.album,
//          m.score.c_score,
//          m.score.java_score,
//          m.score.python_score);
// }

void PrintMusician(const Musician *m) {
  printf("%s\t%c\t%s\t%d\t%d\t%d\n",
         m->name,
         m->gender,
         m->album,
         m->score.c_score,
         m->score.java_score,
         m->score.python_score);
}

// m1, m2: Muisician *
int CompareMusician(const void *m1, const void *m2) {
  const Musician *left_m = m1;
  const Musician *right_m = m2;

  return strcmp(left_m->name, right_m->name);

  // const char *const *left_m = m1;
  // const char *const *right_m = m2;
  // return strcmp(*left_m, *right_m);
}