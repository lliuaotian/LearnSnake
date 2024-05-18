#include "../src/Food.h"

int main(void) {
  Board board(10, 10);

  FFood food;

  board.draw();
  food.AddFood(board);
  board.draw();
  

  return 0;
}
