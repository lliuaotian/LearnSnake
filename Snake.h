#pragma once
#include <vector>

struct snakeposition {
  int x;
  int y;
};

class Snake{
  public:
    Snake(int , int);
    void move();
    void draw(std::vector<std::vector<int>> &);
    void set_new_head(int x, int y) ;
    int collisionDetected();
    std::vector<int> get_new_head();
    bool is_head(int x, int y);
    int getmaxwidth() const { return maxwidth; };
    int getmaxheight() const { return maxheight; };

  private:
    int maxwidth;
    int maxheight;
    char get_input();
    std::vector<snakeposition> snakebody;
    snakeposition new_head;


};
