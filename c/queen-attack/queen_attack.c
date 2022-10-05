#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
   if (queen_1.row > 7 || queen_1.column > 7 || queen_2.row > 7 || queen_2.column > 7 || (queen_1.row == queen_2.row && queen_1.column == queen_2.column)) {
    return INVALID_POSITION;
  } else if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
    return CAN_ATTACK;
  } 
  int drow = queen_1.row - queen_2.row;
  int dcol = queen_1.column - queen_2.column;
  if (drow < 0) {
    drow = -drow;
  }
  if (dcol < 0) {
    dcol = -dcol;
  }
  if (drow == dcol) {
    return CAN_ATTACK;
  }
  return CAN_NOT_ATTACK;
}

