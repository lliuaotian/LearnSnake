#include "../src/Board.h"
#include <iostream>

int main (int argc, char *argv[]) {
  Board board(10, 10);

  BoardCoordinate a;
  a.x = 3;
  a.y = 3;

  board.draw();

  board.setCell(a, 1);

  board.draw();

  a.x = 4;
  a.y = 5;
  board.setCell(a, 1);

  board.draw();


  std::cout << "获取的坐标位置的数据是:" << board.getCell(a) << std::endl;

  return 0;
}
