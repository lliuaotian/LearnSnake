#include "../src/Board.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Board board(10, 10);
  Board_state board_element;

  BoardCoordinate a;
  a.x = 3;
  a.y = 3;

  board.draw();

  board.setCell(a, Snake_head);

  board.draw();

  a.x = 4;
  a.y = 5;
  board.setCell(a, Snake_body);

  board.draw();

  a.x = 7;
  a.y = 7;
  board.setCell(a, Food);

  board.draw();

  a.x = 10;
  a.y = 10;
  board.setCell(a, Food);

  board.draw();

  std::cout << "获取的坐标位置的数据是:" << board.getCell(a) << std::endl;

  return 0;
}
