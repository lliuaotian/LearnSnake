#pragma once
#include <vector>


class Fruit{
  public:
    Fruit(int width, int height) : maxwidth(width), maxheight(height) {}
    void draw(std::vector<std::vector<int>> &mapArray);
    // move函数这里没有选择实现，但是以后可以升级为果实会变换位置，也很好玩
    std::vector<int> get_new_head();
    void move(){} ;
    void set_new_head(int x, int y){} ;
    int getmaxwidth() const { return maxwidth; };
    int getmaxheight() const { return maxheight; };
  private:
    int maxwidth;
    int maxheight;
    
    std::vector<int> randfruit();
    std::vector<int> fruit_xy;
};
