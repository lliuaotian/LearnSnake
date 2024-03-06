#pragma once

#include <unistd.h>
#include <termios.h>

// return 一个数字是getch读取的字符数量 
// 不过在这个程序中肯定是读取的1，但是留个接口呗
class Input {
  /*
    键盘输入类
    在构造函数中设置终端属性
    在析构函数中还原终端属性
  */
  public:
    Input();
    int liuaotian_getch(char *, int);
    ~Input();
  private:
    // _ttyStateOld 保存运行程序时的终端属性
    struct termios _ttyStateOld;
    // _ttyState 设置非规范模式和不回显
    struct termios _ttyState;
};
