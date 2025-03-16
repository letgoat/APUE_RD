# 第5章--标准IO库  
## 5.1 流和FILE对象  
所有的I/O函数都是围绕fd  
标准I/O库都是围绕流(stream)进行的  
ASCII字符集：一个字符用一个字节表示  
国家字符集：一个字符可以用多个字节表示   
标准I/O文件流可以用于单个字节或多个字节字符集  
流的定向决定了所读写的字符是单字节还是多字节  
流的定向初始未设置，根据第一个I/O函数，定向才被设置  
- freopen函数清楚一个流的定向  
- fwide函数设置一个流的定向  
#include <stdio.h>  
#include <wchar.h>  
int fwide(FILE *fd, int mode)  
//若流是宽定向的，返回正值；若流是字节定向的，返回负值；若流是未定向的，返回0  
## 5.2 标准输入、标准输出和标准错误  

## 5.3 缓冲  
标准I/O库三种类型的缓冲：  
1. 全缓冲：在填满标准I/O缓冲区后才进行实际I/O操作（磁盘上的文件）  
2. 行缓冲：在输入和输出中遇到换行符，标准I/O库才执行I/O操作；设计终端时（如标准输入和标准输出），通常使用行缓冲  
3. 不带缓冲：标准I/O库不对字符进行缓冲存储；例如标准I/O函数fputs,标准错误流stderr也是不带缓冲的，错误信息就可以尽快显示出来
下列两个函数可以更改缓冲类型：
#include <stdio.h>  
void setbuf(FILE *restrict stream, char *restrict buf);
int setbuf(FILE *restrict streram, char *restrict buf, int mode, size_t size);  
//若成功，返回0；若失败，返回非0  
使用setvbuf函数，可以精确的通过mode参数指明所需的缓冲类型  
_IOFBF: 全缓冲
_IOLBF: 行缓冲  
_IONBF: 不带缓冲  

## 5.4 打开流  
#include <stdio.h>  
FILE *fopen(const char *restrict pathname, const char *restrict type);  
FILE *freopen(const char *restrict pathname, const char *restrict type, FILE *restrict fp);  
FILE *fdopen(int fd, const char *type);  
3个函数的区别如下：  
1. fopen函数打开路劲名为pathname的文件
2. freopen函数在一个指定的流上打开一个指定的文件，如若该流已经打开，则先关闭流。若流已经定向，则使用freopen清除该定向。此函数一般用于将一个指定的文件打开为一个预定义的流：标准输入，标准输出，标准错误
3. fdopen函数取一个已有的文件描述符，并使一个标准的I/O流与之相结合。此函数常用于创建管道和网络通信函数返回的描述符。因为这类描述符不能用标准I/O函数fopen打开，所以我们必须先调用设备专用函数以获得一个文件描述符，然后用fdopen使一个标准I/O流与该描述符结合  

fclose函数关闭一个流，并释放与流相关的资源  
#inlcude <stdio.h>  
int fclose(FILE *fp)  
在该文件被关闭之前，冲洗缓冲区中的数据。缓冲区中的任何输入数据被丢弃。如果标准I/O库已经为该流自动分配了一个缓冲区，则释放次缓冲区  
当有一个进程正常终止时（直接调用exit函数，或从main函数返回），则所有带未写缓冲数据的标准I/O流都被冲洗，所有打开的标准I/O都被关闭  

## 5.5 读和写流
一旦打开流，则可在3种不同类型的非格式化I/O中进行选择，对其进行读，写操作  
- 字符I/O：一次读或写一个字符，如果流是带缓冲的，则标准I/O函数处理所有缓冲  
- 行I/O：如果想要一次读或写一行，则使用fgets和fputs函数，每行以一个换行符终止。当调用fgets时，应说明能处理的最大行数  
- 直接I/O：fread和fwrite函数支持这种类型的I/O  

## 5.6 每次一行I/O
include <stdio.h>  
char *fgets(char *restrict s, int n, FILE *restrict fp);  
char *gets(char *buf);  
//若成功，返回buf；若已经到达文件末尾或出错，返回NULL  
