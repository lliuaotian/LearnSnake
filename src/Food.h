#pragma once

// 接收一个Board类型，检查所有是Air的元素建立一个数组然后随机出一个元素设置为Food
#include "./Board.h"

class FFood {
public:
  void AddFood(Board& board);
  int GetNumber();
  

private:
  int airrandom;
  std::vector<std::pair<int, int>> airList;
  
};

