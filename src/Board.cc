#include "Board.h"
#include <vector>
#include <iostream>

/*
   0是空气
   1是墙壁
   2是蛇
   3是食物
   */

Board::Board(int width, int height) :
  _width(width),
  _height(height),
  _boardMap(width, std::vector<int>(height)) {
  // 将棋盘初始化一下，四周都是墙壁，中间是空
  for (int i = 0; i < _boardMap.size(); ++i) {
    for (int j = 0; j < _boardMap[i].size(); ++j) {
      if (i == 0 or i == 9) {
        _boardMap[i][j] = 1;
        continue;
      }
      if (j == 0 or j == 9) {
        _boardMap[i][j] = 1;
        continue;
      }
    }
  }
}

int Board::setCell(BoardCoordinate coordinate, int cell) {
  // 留个接口，万一以后这个函数很麻烦 return的int类型可以判断状态
  _boardMap[coordinate.x - 1][coordinate.y - 1] = cell;
  return 0;
}

int Board::getCell(BoardCoordinate coordinate) {
  return _boardMap[coordinate.x - 1][coordinate.y - 1];
}

void Board::draw() {
  for (int i = 0; i < _boardMap.size(); ++i) {
    for (int j = 0; j < _boardMap[i].size(); ++j) {
      if (_boardMap[i][j] == 0) {
        std::cout << "  ";
      }
      if (_boardMap[i][j] == 1) {
        std::cout << "##";
      }
    }
    std::cout << std::endl;
  }

}
