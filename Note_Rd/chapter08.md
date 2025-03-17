# 第8章--进程控制
## 8.1 进程标识  
- ID为0：调度进程（交换进程），是内核的一部分，不执行任何磁盘上的程序，因此被称为系统进程  
- ID为1：init进程，是系统启动时第一个被创建的用户进程，负责启动其他进程，并监控它们的运行状态  

除了进程ID，每个进程还有其他标识符。下列函数返回这些标识符：  
- pid_t getpid(void)  
- pid_t getppid(void)  
- uid_t getuid(void)  
- uid_t geteuid(void)  
- gid_t getgid(void)  
- gid_t getegid(void)  

## 8.2 函数fork  

## 8.3 函数vfork  

## 8.4 函数exit  

## 8.5 函数wait和waitpid  

## 8.6 函数waitid

## 8.7 函数wait3和wait4  

## 8.8 竞争条件  

## 8.9 函数exec  

## 8.10 更改用户ID和组ID  

## 8.11 解释器文件  

## 8.12 函数system  

## 8.13 进程会计  

## 8.14 用户标识  

## 8.15 进程调度  

## 8.16 进程时间  