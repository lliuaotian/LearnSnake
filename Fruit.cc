#include "Fruit.h"
#include "randomxy.h"
#include <vector>
#include <iostream>


std::vector<int> Fruit::get_new_head() {
  if (this->fruit_xy.size() == 0) {
    std::cout << "Error: fruit class fruit_xy is empty" << std::endl;
    return std::vector<int> (2, 0);
  }

  return fruit_xy;
}

void Fruit::draw(std::vector<std::vector<int>> &mapArray) {
  while(true) {
    std::vector<int> fruit = randfruit();
    // 如果这个位置是空的就写入果实
    if (mapArray[fruit[0]][fruit[1]] == 0) {
      mapArray[fruit[0]][fruit[1]] = 3;
      break;
    }
  }
}

std::vector<int> Fruit::randfruit() {
  Random rand;
  int width = this->getmaxwidth();
  int height = this->getmaxheight();

  int x = rand.get_x(0, width - 1);
  int y = rand.get_y(0, height - 1);

  std::vector<int> fruit;
  fruit.push_back(x);
  fruit.push_back(y);

  return fruit;
}
