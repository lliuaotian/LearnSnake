#include "Snake.h"
#include "Board.h"
#include "Input.h"
// DEBUG:
#include <iostream>

// NOTE: 过滤掉无效输入，譬如在方向a的情况下肯定不能b

Snake::Snake() : board(gamewidth, gameheight) {
  // 初始化的时候规定好头部的位置
  std::pair<int, int> snake_head;
  snake_head.first = gamewidth / 2;
  snake_head.second = gameheight / 2;
  
  snake.push_back(snake_head);

  directions['w'] = { 0, -1 };
  directions['a'] = { -1, 0 };
  directions['s'] = { 0, 1 };
  directions['d'] = { 1, 0 };
  directions['q'] = { 0, 0 };

  board.setCell(snake.front(), Snake_head);
}

// 从键盘获取输入只返回第一个字符
void Snake::getDirection() {

  char buf[1024] = { 0 };

  int getStringLength = input.liuaotian_getch(buf, 1024);
  
  if(getStringLength <= 0) {
    // 用户没有输入 还用之前的那个数字
    return;
  }
  // DEBUG:
  std::cout << "Hello :" << buf[0] << std::endl;
  direction = buf[0];
}

Snake::~Snake() {
  return;
}

// new head或者也可以说是下一步的位置
std::pair<int, int> Snake::getNewHead() {
  auto it = directions.find(direction);
  auto current_head = snake.front();
  auto move_direction = it->second;
  std::pair<int, int> new_head = {current_head.first + move_direction.first, current_head.second + move_direction.second };
  // DEBUG:
  std::cout << "current_xy: " << current_head.first << "  " << current_head.second << std::endl;
  std::cout << "new_head_xy: " << new_head.first << "  " << new_head.second << std::endl;

  return new_head;
}

Board_state Snake::checkCollision(std::pair<int, int> new_head) {
  // 如果下一步是墙壁
  if(board.getCell(new_head) == Wall) {
    switch (direction) {
      case 'a':
        new_head.first = gamewidth;
        break;
      case 'd':
        new_head.first = 0;
        break;
      case 'w':
        new_head.second = gameheight;
        break;
      case 's':
        new_head.second = 0;
        break;
    }

    board.setCell(new_head, Snake_head);
    board.setCell(snake.front(), Snake_body);
    snake.push_front(new_head);
    board.setCell(snake.back(), Air);
    snake.pop_back();
    return Wall;
  }

  // 如果下一步是食物
  if(board.getCell(new_head) == Food) {
    board.setCell(new_head, Snake_head);
    board.setCell(snake.front(), Snake_body);
    snake.push_front(new_head);
    return Food;
  }

  // 如果是碰到自己
  if(board.getCell(new_head) == Snake_body) {
    // GameOver
  }

  // 如果不是食物 不是墙壁 那就是空气了
  snake.push_front(new_head);
  board.setCell(new_head, Snake_head);
  board.setCell(snake.back(), Air);
  snake.pop_back(); 

  return Air;
}

int Snake::Move() {
  // 控制Snake移动
  // get current position
  getDirection();

  if (direction == 'q') {
    return 1; 
  }

  if (directions.find(direction) == directions.end()) {
    // 如果找到末尾也没找到元素 就退出，肯定是错误输入
    return -1;
  }
  // 
  
  std::pair<int, int> new_head = getNewHead();
  Board_state check = checkCollision(new_head);

  return 0;
}

void Snake::DrawBoard(){
  board.draw();
}
