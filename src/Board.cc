#include "Board.h"
#include <iostream>
#include <vector>

// width+2 height+2 是因为棋盘的第一行、列 最后一行、列是墙壁
Board::Board(int width, int height)
    : _width(width), _height(height),
      _boardMap(width + 2, std::vector<Board_state>(height + 2)) {
  // 将棋盘初始化一下，四周都是墙壁，中间是空
  // 刚开始两个if判断，or后都是固定值9，但是这样如果传递到该类的width和height不是10就是错误，更改了这个出现错误的可能
  for (int i = 0; i < _boardMap.size(); ++i) {
    for (int j = 0; j < _boardMap[i].size(); ++j) {
      if (i == 0 or i == _boardMap.size() - 1) {
        _boardMap[i][j] = Air;
        continue;
      }
      if (j == 0 or j == _boardMap[i].size() - 1) {
        _boardMap[i][j] = Wall;
        continue;
      }
    }
  }
}

int Board::setCell(BoardCoordinate coordinate, Board_state cell) {
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
      if (_boardMap[i][j] == Air) {
        std::cout << "  ";
      }
      if (_boardMap[i][j] == Wall) {
        std::cout << "##";
      }
    }
    std::cout << std::endl;
  }
}
