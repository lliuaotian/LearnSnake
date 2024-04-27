#pragma once

#include <map>
#include <vector>

// 共用的Board坐标系
struct BoardCoordinate {
  int x, y;
};

/*
  Board创建一个棋盘
  提供获取棋盘某个坐标的值
  提供设置棋盘某个坐标的值
  注意，该Board类的棋盘接收的坐标均是实际坐标，譬如食物在(1,
  1)那就是在第一排第一个，而不是第二排第二个，默认接收的参数下标不是从0开始

  */
/*
   0是空气
   1是墙壁
   2是蛇头
   3是蛇
   4是食物
   */
enum Board_state { Air, Wall, Snake_head, Snake_body, Food };

class Board {
private:
  Board_state board_state;
  int _width, _height;
  std::vector<std::vector<Board_state>> _boardMap;
  std::map<Board_state, const char *> board_state_to_char = {
      {Air, "  "},        {Wall, "##"}, {Snake_head, "(("},
      {Snake_body, "**"}, {Food, "@@"},
  };

public:
  // 根据传递进来的值设置地图的宽和高
  Board(int, int);
  // 获取某个坐标的值
  int getCell(BoardCoordinate);
  int setCell(BoardCoordinate, Board_state cell);
  void draw();
};
