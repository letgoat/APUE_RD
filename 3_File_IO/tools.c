#include <sys/types.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include "tools.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

extern int unlink(const char* pathname);
extern char *strerror(int _errnum);
extern int My_open_with_mode(const char* pathname, int flags, mode_t mode);
int prepare_file(const char* pathname, const void* buffer, int len, mode_t mode){
    if(unlink(pathname) == -1) //删除文件，如果失败
        if(errno != ENOENT) return -1;
    int fd = open(pathname, O_CREAT|O_RDWR, mode); //打开文件（未存在则创建，可读写）
    if(fd == -1){  //如果打开文件失败
        printf("open file %s failed, beacase %s\n", pathname, strerror(errno));
        return -1;
    }
    if(len > 0 && buffer != NULL){ //如果有数据需要写入
        if(-1 == write(fd, buffer, len)){ //写入数据，如果失败
            printf("write file %s failed, beacase %s\n", pathname, strerror(errno));
            close(fd);
            return -1;
        }
    }
    close(fd);
    return 0;
}

void un_prepare_file(const char* pathname){
    unlink(pathname);
}

void print_char_buffer(const char* buffer, int len){
    printf("char buffer is:/n");
    for(int i = 0; i < len; i++){
        if(buffer[i] == '\n')
            break;
        printf("%c", buffer[i]);
    }
}

void fcntl_lock(int fd){
    struct flock data;
    data.l_type = F_WRLCK;
    data.l_whence = SEEK_SET;
    data.l_start = 0;
    data.l_len = 0; //整个文件
    int result = fcntl(fd, F_SETLKW, &data); //F_SETLKW为阻塞版本
    if(-1 == result){
        printf("fcntl_lock failed, beacase %s\n", strerror(errno));
    }
}

void fcntl_unlock(int fd){
    struct flock data;
    data.l_type = F_UNLCK;
    data.l_whence = SEEK_SET;
    data.l_start = 0;
    data.l_len = 0;
    int result = fcntl(fd, F_SETLKW, &data);
    if(-1 == result){
        printf("fcntl_unlock failed, beacase %s\n", strerror(errno));
    }
}

char* abs_path(const char* dir_name, const char* file_name){
    static char buffer[1024];
    if(dir_name == NULL)
    {
        printf("dir_name must not be NULL\n");
        return NULL;
    }
    if(file_name == NULL){
        printf("file_name must not be NULL\n");
        return NULL;
    }
    if(file_name[0] == '/'){
        printf("file_name must not start with /\n");
        return NULL;
    }
    if(dir_name[0] != '/'){
        printf("dir_name must start with /\n");
        return NULL;
    }
    strcpy(buffer, dir_name); //拷贝
    strcat(buffer, "/"); //拼接
    strcat(buffer, file_name); //拼接
    return buffer;
}
