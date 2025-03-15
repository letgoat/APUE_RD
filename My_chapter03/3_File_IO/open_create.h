#ifndef OPEN_CREATE
#define OPEN_CREATE

#include <fcntl.h>
#include "tools.h"
/*!
*\brief My_open: 包装了open函数
*\param path: 传递给open函数的path参数
*\param oflag: 传递给open函数的oflag参数
*\return: 返回open函数的返回值 
*/ 
int My_open(const char* path, int oflag);

/*!
*\brief My_open_with_mode: 包装了open函数，并设置了mode参数
*\param path: 传递给open函数的path参数
*\param oflag: 传递给open函数的oflag参数
*\param mode: 传递给open函数的mode参数
*\return: 返回open函数的返回值 
*/
int My_open_with_mode(const char* path, int oflag, mode_t mode);

/*!
*\brief My_create: 包装了creat函数
*\param path: 传递给creat函数的path参数
*\param mode: 传递给creat函数的mode参数
*\return: 返回creat函数的返回值 
*/
int My_create(const char* path, mode_t mode);

/*!
*\brief test_open_create: 测试open和create函数
*/
void test_open_create();
#endif