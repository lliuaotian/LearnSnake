#pragma once

// Map类
#include <vector>
#include "Snake.h"
#include "Fruit.h"

class Map {
public:
  Map(int width, int height);
  void draw();
  void update();
  void set_cell(int x, int y, int cell);
  int get_cell(int x, int y);
  int getwidth() const { return mapwidth; };
  int getheight() const { return mapheight; };
  // 检测是否碰到墙壁
  bool collisionDetected();
  /*  TODO：
        后期可能会加入在游戏途中设置地图大小，到时候会用到以下两个函数 
  */
  void setwidth(int width) { mapwidth = width; };
  void setheight(int height) { mapheight = height; };

private:
  int mapwidth;
  int mapheight;
  // 在构造函数里初始化了地图
  std::vector<std::vector<int>> mapArray;
  Snake snake;
  Fruit fruit;

};
