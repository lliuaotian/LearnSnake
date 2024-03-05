#pragma once

class Game {
public:
  Game();
  Game(int mapwidth_, int mapheight_);
  ~Game();
  // run_game中要实现贪吃蛇游戏的整个逻辑
  int run_game();
  // 顾名思义
  int game_over();

private:
  // 地图的大小及一些基础信息还需要在main中写出来传递过来，方便扩展
  int mapwidth;
  int mapheight;

  
};

