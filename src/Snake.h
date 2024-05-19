/*
 * 这个文件利用Board类实现贪吃蛇和食物逻辑
 */

#pragma once
#include <deque>
#include <unordered_map>
#include <utility>
#include "./Board.h"
#include "Input.h"
#include "./Food.h"

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
  std::pair<int, int> getNewHead();
  Board_state checkCollision(std::pair<int, int>);

  // Board
  Board board;
  
  // getch
  Input input;

  // 食物生成
  FFood food;
  
  // 检查输入
  int checkInput();

  void GameOver();


public:
  Snake();
  // 该函数控制贪吃蛇移动，返回1就是退出 -1就是输入错误
  // 返回0就是正常移动
  int Move();
  /*
   * 把贪吃蛇队列输出到屏幕中
   */
  void DrawBoard();
  void getDirection();
  ~Snake();
};

// NOTE:碰撞测试
