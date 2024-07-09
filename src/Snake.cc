#include "Snake.h"
#include "Board.h"
#include "Input.h"
// DEBUG:
#include <cstdlib>
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
  food.AddFood(board);

  _gameover = true;
  fraction = 0;
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
  // std::cout << "Input :" << buf[0] << std::endl;
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
  // std::cout << "current_xy: " << current_head.first << "  " << current_head.second << std::endl;
  // std::cout << "new_head_xy: " << new_head.first << "  " << new_head.second << std::endl;

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
        new_head.first = 1;
        break;
      case 'w':
        new_head.second = gameheight;
        break;
      case 's':
        new_head.second = 1;
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
    GameOver();
  }

  // 如果不是食物 不是墙壁 那就是空气了
  board.setCell(new_head, Snake_head);
  // 这里少一个更改上一个头部的状态
  board.setCell(snake.front(), Snake_body);
  snake.push_front(new_head);
  board.setCell(snake.back(), Air);
  snake.pop_back(); 

  return Air;
}

int Snake::checkInput() {
  char direction_old = direction;
  getDirection();
  
  if (direction == 'q') {
    GameOver();
    return 1; 
  }
  std::unordered_map<char, char> disallowedDirections = {
    { 'a', 'd' },
    { 'd', 'a' },
    { 'w', 's' },
    { 's', 'w' }
  };

  auto it = disallowedDirections.find(direction);
  if (it != disallowedDirections.end() and it->second == direction_old) {
    // 过滤无效的内容
    direction = direction_old;
    return 0;
  }


  if (directions.find(direction) == directions.end()) {
    // 如果找到末尾也没找到元素 就退出，肯定是错误输入
    return -1;
  }

  return 0;
}

void Snake::GameOver() {
  // 游戏结束在这里显示
  // 
  system("clear");
  std::cout << R"( $$$$$$\                                           $$$$$$\                                 )" << std::endl;
  std::cout << R"($$  __$$\                                         $$  __$$\                                )" << std::endl;
  std::cout << R"($$ /  \__| $$$$$$\  $$$$$$\$$$$\   $$$$$$\        $$ /  $$ |$$\    $$\  $$$$$$\   $$$$$$\  )" << std::endl;
  std::cout << R"($$ |$$$$\  \____$$\ $$  _$$  _$$\ $$  __$$\       $$ |  $$ |\$$\  $$  |$$  __$$\ $$  __$$\ )" << std::endl;
  std::cout << R"($$ |\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |      $$ |  $$ | \$$\$$  / $$$$$$$$ |$$ |  \__|)" << std::endl;
  std::cout << R"($$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|      $$ |  $$ |  \$$$  /  $$   ____|$$ |      )" << std::endl;
  std::cout << R"(\$$$$$$  |\$$$$$$$ |$$ | $$ | $$ |\$$$$$$$\        $$$$$$  |   \$  /   \$$$$$$$\ $$ |      )" << std::endl;
  std::cout << R"( \______/  \_______|\__| \__| \__| \_______|       \______/     \_/     \_______|\__|      )" << std::endl;
  std::cout << "                             最高分数的分数是：" << fraction << std::endl;
  std::cout << "                            你此次的游戏时间是:" << 10 << std::endl;

  // 游戏结束
  _gameover = false;
}

int Snake::Move() {
  // 控制Snake移动
  // get current position
  
  // Input && check input
  int a = checkInput();
  if (a != 0) {
    return -1;
  }
  
  std::pair<int, int> new_head = getNewHead();
  Board_state check = checkCollision(new_head);

  if (check == Food) {
    fraction += 20;
    food.AddFood(board);
  }

  return 0;
}

void Snake::DrawBoard(){
  board.draw();
  std::cout << "你当前的分数是：" << fraction << std::endl;
}

bool Snake::_while(){
  if (_gameover) {
    return true;
  }

  return false;
}
