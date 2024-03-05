#include "Snake.h"
#include "randomxy.h"
#include <iostream>

Snake::Snake(int width_, int height_) : maxwidth(width_), maxheight(height_) {
  // 初始化的时候应该给蛇一个最基本的位置
  Random rand;
  int width = this->getmaxwidth();
  int height = this->getmaxheight();

  int x = rand.get_x(1, width - 2);
  int y = rand.get_y(1, height - 2);

  std::cout << "maxwidth:" << width << std::endl;
  std::cout << "maxheight:" << height << std::endl;

  snakeposition body;
  body.x = x;
  body.y = y;

  snakebody.push_back(body);
}

char Snake::get_input() {
  /*
     先写一个简单的
  */
  char input = 'w';

  std::cin >> input;

  return input;
}

void Snake::move() {
  // 贪吃蛇移动
  /*
     <- x = x - 1
     ^  y = y - 1
     -> x = x + 1
     ↓  y = y + 1
  */
  // get_input返回值目前是一个char类型
  new_head.x = snakebody[0].x;
  new_head.y = snakebody[0].y;

  std::cout << "此时new_head_x的内容是" << new_head.x << std::endl;
  std::cout << "此时new_head_y的内容是" << new_head.y << std::endl;


  char input = get_input();
  std::cout << "你输入的是：" << input << std::endl;

  switch (input) {
    case 'w':
      new_head.y = new_head.y - 1;
      break;
    case 's':
      new_head.y = new_head.y + 1;
      break;
    case 'a':
      new_head.x = new_head.x - 1;
      break;
    case 'd':
      new_head.x = new_head.x + 1;
      break;
  }

  if (collisionDetected() == -1) {
    return;
  }

}

int Snake::collisionDetected() {
  // 返回0说明没有碰撞
  // 返回-1说明碰到了蛇身
  // 检测碰撞
  for (auto body : snakebody) {
    // 遍历每一个身体
    if (body.x == new_head.x and body.y == new_head.y) {
      // 如果下一个位置的x坐标和y坐标等于身子的某个坐标，说明游戏结束
      // 这里应该把new_head放在 == 的前边能提升代码可读性，留给之后来个pr吧
      return -1;
    }
  }


  return 0;
}

void Snake::draw(std::vector<std::vector<int>> &mapArray) {
  for (auto body : snakebody) {
    mapArray[body.x][body.y] = 2;
  }
}

std::vector<int> Snake::get_new_head() {
  // 返回蛇头部的最新位置
  std::vector<int> body;
  body.push_back(this->new_head.x);
  body.push_back(this->new_head.y);
  return body;
}

bool Snake::is_head(int x, int y) {
  // 如果是头部就返回true 否则返回false
  if (snakebody[0].x == x and snakebody[0].y) {
    return true;
  }

  return false;
}

void Snake::set_new_head(int x, int y) {
  snakebody.insert(snakebody.begin(), {x, y});
}
