#include "grade_school.h"
#include <string.h>
#include <stdio.h>


void init_roster(roster_t *roster) {
  roster->count = 0;
}

int student_exists(roster_t *roster, char * name) {
  int count = roster->count;
  for (int i = 0; i < count; i++) {
    if (strcmp(roster->students[i].name, name) == 0) {
      return 0;
    }
  }
  return 1;
}

int add_student(roster_t *roster, char * name, int grade) {
  int i = roster->count;
  if (i < MAX_STUDENTS && student_exists(roster, name) == 1) {
    roster->students[i].grade = grade;
    strcpy(roster->students[i].name, name);
    roster->count++;
    sort_by_grade(roster);
    sort_by_name(roster);
    return 1;
  } else {
    return 0;
  }
}

roster_t get_grade(roster_t *roster, int grade) {
  roster_t out;
  init_roster(&out);
  int count = roster->count;
  for (int i = 0; i < count; i++) {
    if (roster->students[i].grade == grade) {
      add_student(&out, roster->students[i].name, roster->students[i].grade);
    }
  }
  return out;
}


void sort_by_name(roster_t *roster) {
  int count = roster->count;
  for (int j = 0; j < count; j++) {
    int hi = roster->count - j;
    for (int i = 0; i < hi - 1; i++) {
      if (strcmp(roster->students[i].name,roster->students[i+1].name) > 0 && roster->students[i].grade == roster->students[i + 1].grade) {
        student_t tmp = roster->students[i];
        roster->students[i] = roster->students[i + 1];
        roster->students[i + 1] = tmp;
      }
    }
  }
}

void sort_by_grade(roster_t *roster) {
  int count = roster->count;
  for (int j = 0; j < count; j++) {
    int hi = roster->count - j;
    for (int i = 0; i < hi - 1; i++) {
      if (roster->students[i].grade > roster->students[i+1].grade) {
        student_t tmp = roster->students[i];
        roster->students[i] = roster->students[i + 1];
        roster->students[i + 1] = tmp;
      }
    }
  }
}
