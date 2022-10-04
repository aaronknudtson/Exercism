#include "robot_simulator.h"
#include <string.h>
#include <stdio.h>

robot_position_t directions[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
  return (robot_status_t){ direction, (robot_position_t){ x, y }};
}

void robot_move(robot_status_t *robot, const char *commands) {
  int length = strlen(commands);
  for (int i = 0; i < length; ++i) {
    char command = commands[i];
    if (command == 'R') {
      if (robot->direction + 1 == DIRECTION_MAX) {
        robot->direction = DIRECTION_NORTH;
      } else {
        robot->direction = robot->direction + 1;
      }
    } else if (command == 'L') {
      if (robot->direction == 0) {
        robot->direction = DIRECTION_WEST;
      } else {
        robot->direction = robot->direction - 1;
      }
    } else if (command == 'A') {
      robot->position.x += directions[robot->direction].x;
      robot->position.y += directions[robot->direction].y;
    }
  }
}
