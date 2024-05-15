#include "Snake.h"

Snake::Snake() {
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
}

int Snake::Move() {
  // 控制Snake移动
  // get current position
  if (directions.find('q') != directions.end()) {
    return 1; 
  }

  if (directions.find(direction) == directions.end()) {
    // 如果找到末尾也没找到元素 就退出，肯定是错误输入
    return -1;
  }
  // 
  auto it = directions.find(direction);
  auto current_head = snake.front();
  auto move_direction = it->second;
  std::pair<int, int> new_head = {current_head.first + move_direction.first, current_head.second + move_direction.second };


  snake.push_front(new_head);
  snake.pop_back();

  return 0;
}


