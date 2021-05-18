#ifndef SOMEINLINE_H
#define SOMEINLINE_H
Type Example(void);
//........其他函数的声明
#include"SomeInlie.cpp" //源文件后缀名随编译器而定
#endif
//SomeInline.cpp中
#include"SomeInline.h"
inline Type Example(void)
{
//..........
}
//...............其他函数的定义