/*
 * 这个文件利用Board类实现贪吃蛇和食物逻辑
 */

#pragma once
#include <deque>
#include <unordered_map>
#include <utility>

// 此处固定一个游戏的范围，随后可以通过其他方式获取这个范围，动态调整

class Snake {
private:
  // 存放蛇的数组的元素类型

  // game width & height
  int gamewidth  = 10;
  int gameheight = 10;
  // deafult snake direction is left
  char direction = 'a';
  // 方向映射到字典
  std::unordered_map<char, std::pair<int, int>> directions;

  // snake
  std::deque<std::pair<int, int>> snake;

public:
  Snake();
  int Move();
  ~Snake();
};

// NOTE::下一步实现一个Draw 让Snake可以输出到棋盘中
