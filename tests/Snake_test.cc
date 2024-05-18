#include "../src/Snake.h"
#include <thread>
#include <chrono>

int main(void) {
  Snake snake;

  // 中断两秒
  while (true) {

    snake.DrawBoard();
    snake.Move();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
    return 0;
}