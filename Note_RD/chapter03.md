文件描述符：
- 0：标准输入，默认从键盘输入 STDIN_FILENO
- 1：标准输出，默认显示到屏幕 STDOUT_FILENO
- 2：标准错误，默认显示到屏幕 STDERR_FILENO

函数 open 和 openat:
#include <fcntl.h>
int open(const char *path, int flags, mode_t mode)
int openat(int fd, const char *path,int flags, mode_t mode)
flags:
- O_RDONLY：只读打开
- O_WRONLY：只写打开
- O_RDWR：读写打开
- O_EXEC: 只执行打开
- O_SEARCH: 只搜索打开（应用于目录）

函数 create
#include <fcntl.h>
int create(const char *path, mode_t mode); //若成功则返回只写打开的文件描述符；若出错，返回-1

函数 close
#include <unistd.h>
int close (int fd); //成功返回0，出错返回-1

函数 lseek
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence); //若成功，返回新的文件偏移量；若出错，返回为-1

函数 read
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count); //成功返回实际读取的字节数，若出错，返回-1

函数 write
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t nbytes); //若成功返回已写的字节数；若出错，返回-1

