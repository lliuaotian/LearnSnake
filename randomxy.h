#pragma once

// 在这个头文件中生成x，y坐标，因为现在随机生成的功能还很弱，先暂时都写到头文件中
#include <random>

class Random {
  public:
    Random() {} ;
    int get_x( int begin, int end ) { return random_number(begin, end); };
    int get_y( int begin, int end ) { return random_number(begin, end); };
    ~Random() {} ;
  private:
    int random_number( int begin, int end ) {
      std::random_device rd;
      std::mt19937 gen(rd());

      std::uniform_int_distribution<> dis(begin, end);

      return dis(gen);
    }

};
