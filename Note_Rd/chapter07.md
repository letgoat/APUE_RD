# 第7章--进程环境
## 7.1 main函数  
c程序总是从main函数开始执行，main函数的原型是：  
int main(int argc, char *argv[]);  
其中, argc是命令行参数的个数，argv是一个指针数组，是指向各个参数的指针所组成的数组。  
- 调用main函数前，先调用一个特殊的启动例程，可执行文件将此启动例程作为程序的起始地址。启动例程从内核取得命令行参数和环境变量，按照以上方式为调用main函数做准备  

## 7.2 进程终止  
8种方式使进程终止，其中5种为正常终止：  
- 从main返回  
- 调用exit函数  
- 调用_exit或_Exit函数  
- 最后一个线程从启动例程返回  
- 从最后一个线程调用pthread_exit函数  

异常终止有3种：  
- 调用abort  
- 接到一个信号  
- 最后一个线程对取消请求做出响应  

退出函数：  
- exit函数：先执行一些清理处理，再进入内核  
- _exit和_Exit函数：直接进入内核  
#include <stdlib.h>  
void exit(int status);  
void _Exit(int status);  
#include <unistd.h>  
void _exit(int status);  

## 7.3 命令行参数  
当执行一个程序时，调用exec的进程可以将命令行参数传递给新程序  

## 7.4 环境表  

## 7.5 C程序的存储空间布局
C程序由以下几部分组成：  
- 正文段  
- 初始化数据段  
- 未初始化数据段  
- 栈  
- 堆  

## 7.6 共享库  

## 7.7 存储空间分配  
3个用于存储空间动态分配的函数：  
- malloc函数：分配指定字节数的存储区，此存储区的初始值不确定  
- calloc函数：为指定数量指定长度的对象分配存储空间，该空间的每一位都初始化为0  
- realloc函数：增加或者减少以前分配区的长度，当增加长度时，可能需将以前分配区的内容移动到另一个足够大的区域，以便在尾端提供增加的存储区，而新增区域内的初始值则不确定。  

#include <stdlib.h>  
void *malloc(size_t size);  
void *calloc(size_t nobj, size_t size);  
void *realloc(void *ptr, size_t size);  
//3个函数若成功返回非空指针，如果出错，返回NULL  
