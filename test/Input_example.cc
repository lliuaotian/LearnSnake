#include "../Input.h"
#include <iostream>
#include <unistd.h>

int main (int argc, char *argv[]) {
  Input getch;
  const int maxBufLen = 1024;
  char buf[maxBufLen] = { 0 };
  int getStringLength = 0;

  while (true) {
    getStringLength = getch.liuaotian_getch(buf, maxBufLen);
    if (buf[0] == 'q') {
      break;
    }
    if (getStringLength <= 0) {
      continue;
    }
    std::cout << "你输入的字符长度是:" << getStringLength << "\t内容是:" << buf[0] << std::endl;
  }


  
  return 0;
}
