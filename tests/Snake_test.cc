#include "../src/Snake.h"
#include <thread>
#include <chrono>

int main(void) {
  Snake snake;

  // 中断两秒
  while (snake._while()) {

    snake.DrawBoard();
    snake.Move();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    return 0;
}
