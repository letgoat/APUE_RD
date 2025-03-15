# 第三章--文件输入输出
## 文件描述符：
- 0：标准输入，默认从键盘输入 STDIN_FILENO
- 1：标准输出，默认显示到屏幕 STDOUT_FILENO
- 2：标准错误，默认显示到屏幕 STDERR_FILENO

_函数 open 和 openat_  
#include <fcntl.h>  
int open(const char *path, int flags, mode_t mode)
int openat(int fd, const char *path,int flags, mode_t mode)
flags:
- O_RDONLY：只读打开
- O_WRONLY：只写打开
- O_RDWR：读写打开
- O_EXEC: 只执行打开
- O_SEARCH: 只搜索打开（应用于目录
- O_APPEND: 每次写都追加到文件的末尾
- O_CREAT: 若文件不存在，则创建文件
- O_EXCL: 如果同时指定O_CREAT,而文件已经存在，则出错。用此可以测试一个文件是否存在，如果不存在则创建文件

mode_t:
S_IRUSR: 所有者读权限
S_IWUSR: 所有者写权限
S_IXUSR: 所有者执行权限
S_IRGRP: 同组读权限
S_IWGRP: 同组写权限
S_IXGRP: 同组执行权限
S_IROTH: 其他读权限
S_IWOTH: 其他写权限
S_IXOTH: 其他执行权限


函数 create  
#include <fcntl.h>  
int create(const char *path, mode_t mode); //若成功则返回只写打开的文件描述符；若出错，返回-1

函数 close  
#include <unistd.h>  
int close (int fd); //成功返回0，出错返回-1

函数 lseek  
#include <unistd.h>  
off_t lseek(int fd, off_t offset, int whence); //若成功，返回新的文件偏移量；若出错，返回为-1
whence:
- SEEK_SET: 从文件开始
- SEEK_CUR: 从当前位置
- SEEK_END: 从文件末尾

函数 read  
#include <unistd.h>  
ssize_t read(int fd, void *buf, size_t count); //成功返回实际读取的字节数，若出错，返回-1


函数 write  
#include <unistd.h>  
ssize_t write(int fd, const void *buf, size_t nbytes); //若成功返回已写的字节数；若出错，返回-1


函数 dup 和 dup2  
#include <unistd.h>  
int dup(int fd); //复制一个文件描述符，成功返回复制后的文件描述符，出错返回-1
int dup2(int fd, int fd2); //复制一个文件描述符，并将复制后的文件描述符赋给fd2，成功返回0，出错返回-1


函数 sync、fsync 和 fdatasync  
#include <unistd.h>  
void sync(void);
int fsync(int fd);
int fdatasync(int fd);
sync: 只是将修改过的块缓冲区排入写队列，并不等待实际写磁盘操作
fsync: 只对fd指向的文件起作用，并且等待写磁盘操作完成才返回
fdatasync: 类似fsync, 但是只对文件的数据部分起作用，不包含文件属性部分


_函数 fcntl_  
#include <fcntl.h>  
int fcntl(int fd, int cmd, ... /* arg */ ); //若成功依赖于cmd, 失败则返回-1
fcntl函数的5个功能：
- cmd = F_DUPFD或F_DUPFD_CLOEXEC: 复制一个文件描述符，并返回复制后的文件描述符
- cmd = F_GETFD或F_SETFD: 获取或设置文件描述符的标志
- cmd = F_GETFL或F_SETFL: 获取或设置文件描述符的状态标志
- cmd = F_GETLK或F_SETLK或F_SETLKW: 获取或设置文件锁
- cmd = F_GETOWN或F_SETOWN: 获取或设置进程接收SIGIO信号的权利


函数 ioctl  
#include <unistd.h>  
#include <sys/ioctl.h>  
int ioctl(int fd, int request, ... /* arg */ ); //若出错返回-1，若成功返回其他值

