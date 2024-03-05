#include <iostream>
#include "randomxy.h"

int main (int argc, char *argv[]) {
  Random rand;
  std::cout << rand.get_x(0, 10) << "," << rand.get_y(0, 10) << std::endl;

  return 0;
}
