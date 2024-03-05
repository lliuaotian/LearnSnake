#pragma once
#include <vector>

class Map;
// Snake和Fruit的公有类
class GameObject {
  public:
    // 设置好边界
    GameObject(int width, int height) : maxwidth(width), maxheight(height) {}
    // 绘制自身
    virtual void draw(std::vector<std::vector<int>> &mapArray);
     
    virtual std::vector<int> get_new_head();
    virtual void set_new_head(int x, int y);
    // 移动，蛇的移动是下个位置变成头部，果实的移动是变换一个新的位置
    virtual void move();
    // 检测碰撞，蛇的碰撞是检测身体和墙壁，果实的碰撞说明蛇吃到果实了
    virtual int collisionDetected();
    virtual bool is_head(int, int);
    int getmaxwidth() const { return maxwidth; };
    int getmaxheight() const { return maxheight; };
  private:
    int maxwidth;
    int maxheight;
};
