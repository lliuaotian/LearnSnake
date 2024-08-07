#include "Food.h"
#include <random>
#include "Board.h"
#include <iostream>

void FFood::AddFood(Board& board) {
  // 增加一个Food
  airList = board.getAirList();
  if (airList.size() == 0) {
    // 如果返回的大小是0就说明里边已经有食物了
    return;
  }

  airrandom = GetNumber();
    
  board.setCell(airList.at(airrandom), Food);
  
  //std::cout << "current_xy:" << airList.at(airrandom).first << "," << airList.at(airrandom).second << std::endl;
}

int FFood::GetNumber() {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> dis(1, airList.size()-1);

  return dis(gen);
}
