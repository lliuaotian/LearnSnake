#include "Map.h"
#include <iostream>

Map::Map(int width, int height) : 
                              mapwidth(width), 
                              mapheight(height), 
                              mapArray(width, std::vector<int>(height)),
                              // 设置好snake和fruit的边界，好让他们知道生成身体和果实应该去哪里生成
                              snake(width, height),
                              fruit(width, height){
  /*
     可能这里用一个enum更合适
     map中0代表空
          1代表墙壁
          2代表蛇身 蛇身是个数组 数组索引0就是蛇头
          3代表果实
  */
  for(int i = 0; i < mapArray.size(); ++i) {
    for (int j = 0; j < mapArray[i].size(); ++j) {
      if (i == 0 or i == (mapArray.size() - 1)){
        // i == 0的时候说明现在是遍历的数组第一行或最后一行就是墙壁
        mapArray[i][j] = 1;
        continue;
      }
      if (j == 0 or j == (mapArray[i].size() - 1)) {
        mapArray[i][j] = 1;
        continue;
      }
      // 以上条件都不满足就是空的
      mapArray[i][j] = 0;
    }
  }

}

void Map::draw() {
  for(int i = 0; i < mapArray.size(); ++i) {
    for (int j = 0; j < mapArray[i].size(); ++j) {
      if (mapArray[i][j] == 0) {
        std::cout << " ";
      } else if (mapArray[i][j] == 1) {
        // 找到蛇头，打印别的字符
        if (snake.is_head(i, j)) {
          std::cout << "!";
        } else {
          std::cout << "*";
        }
      } else if (mapArray[i][j] == 2) {
        std::cout << "$";
      }
    }
    std::cout << "\n";
  }
}

void Map::update() {
  while (true) {
    snake.draw(mapArray);
    fruit.draw(mapArray);
    draw();
    snake.move();
    // 到这里其实发现Snake和Fruit public继承的GameObject类不是很方便，之后在更改
    std::vector<int> new_head = snake.get_new_head();
    std::vector<int> fruit_xy = fruit.get_new_head();
    // 如果下一步的位置和果实的位置相同那么添加到头部
    if (new_head[0] == fruit_xy[0] and new_head[1] == fruit_xy[1]) {
      snake.set_new_head(new_head[0], new_head[1]);
    }

    // 判断是否碰到墙壁
    if (new_head[0] == 0) {
      new_head[0] = mapArray.size() - 1;
    }
    if (new_head[0] == mapArray.size() - 1) {
      new_head[0] = 1;
    }
    if (new_head[1] == 0) {
      new_head[1] = mapArray[0].size() - 1;
    }
    if (new_head[1] == mapArray[0].size() - 1) {
      new_head[1] = 0;
    }
    snake.set_new_head(new_head[0], new_head[1]);

  }
  

}

void Map::set_cell(int x, int y, int cell) {
  // 这是一个在snake和fruit类中使用的函数，意在让snake和Fruit可以在自身实例
  // 中正确的设置哪里是蛇身，哪里是食物
  for (int i = 0; i < mapArray.size(); ++i) {
    for (int j = 0; j < mapArray.size(); ++j) {
      // 循环开始时x y 都是0
      if (x == i and y == j) {
        mapArray[i][j] = cell;
        return;
      }
    }
  }
}

int Map::get_cell(int x, int y) {
  return mapArray[x][y];
}
