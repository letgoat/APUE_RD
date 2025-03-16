# 第4章--文件和目录
## 4.1 函数stat、fsta、fstatat、lstat
#include <sys/stat.h>  
int stat(const char *restrict path, struct stat *restrict buf);  
int fstat(int fd, struct stat *buf);  
int lstat(const char *restrict path, struct stat *restrict buf);  
int fstatat(int fd, const char *restrict path, pathname, struct stat *restrict buf, int flag);  
//所有四个函数，成功返回0，出错返回-1  

## 4.2 文件类型  
1. 普通文件  
2. 目录文件  
3. 块特殊文件  
4. 字符特殊文件  
5. FIFO（命名管道）  
6. 套接字  
7. 符号链接（软链接）  

## 4.3 设置用户ID和组ID  

## 4.4 文件访问权限  

## 4.5 新文件和目录的所有权  

## 4.6 函数access和faccessat  

## 4.7 函数umask  
#include<sys/stat.h>  
mode_t umask(mode_t cmask);//设置文件权限掩码，返回之前的掩码  

## 4.8 函数chmod、fchmod、fchmodat  
#include<sys/stat.h>  
int chmod(const char *pathname, mode_t mode);  
int fchmod(int fd, mode_t mode);  
int fchmodat(int fd, const char *pathname, mode_t mode, int flag);  
//成功返回0，出错返回-1  
chmod: 修改指定的文件  
fchmod: 修改打开的文件

## 4.9 黏着位  

## 4.10 函数chown, fchown, fchownat, lchown  
//下面的几个函数用于更改文件的ID和组ID  
#include<unistd.h>  

