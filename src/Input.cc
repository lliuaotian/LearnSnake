#include "Input.h"
#include <sys/select.h>
#include <unistd.h>
#include <termios.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

Input::Input() {
  // 构造函数设置终端属性为非规范模式(ICANON)和不回显(ECHO)
  // 获取两份终端属性，old的不动留着析构函数还原，另一个更改并设置属性
  tcgetattr(STDIN_FILENO, &_ttyStateOld);
  tcgetattr(STDIN_FILENO, &_ttyState);
  _ttyState.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &_ttyState);
}

Input::~Input() {
  // 还原终端属性
  tcsetattr(STDIN_FILENO, TCSANOW, &_ttyStateOld);
}

int Input::liuaotian_getch(char * string, int stringSize) {
  // 输入的字符串长度
  int stringLength = 0;
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);

  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  int isReady = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

  if (isReady == -1) {
    std::cout << "ERROR: Input.cc Input select no ready" << std::endl;
    return -1;
  } else if (isReady == 0) {
    // 直接返回0 告诉调用该功能的宿主，没有输入任何内容
    return 0;
  } else {
    if (FD_ISSET(STDIN_FILENO, &fds)) {
      stringLength = read(STDIN_FILENO, string, stringSize - 1);
      if (stringLength < 0) {
        std::cout << "ERROR: Input.cc Input string read failed" << std::endl;
        return -1;
      } else if (stringLength == 0) {
        std::cout << "WARNING: Input.cc Input string length is 0" << std::endl; 
        return 0;
      } else {
        return stringLength;
      }
    }
  }
  
  return stringLength;
}
