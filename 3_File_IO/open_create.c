#include <fcntl.h>
#include "open_create.h"
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

int My_open(const char* path, int oflag){
    int result = open(path, oflag);
    if(result == -1){
        printf("open(%s, %d) failed, because %s\n", path, oflag, strerror(errno));
    }
    else{
        printf("open(%s, %d) success, return file descriptor %d\n", path, oflag, result);
    }
    return result;
}

int My_open_with_mode(const char* path, int oflag, mode_t mode){
    int result = open(path, oflag, mode);
    if(result == -1){
        printf("open(%s, %d, %d) failed, because %s\n", path, oflag, mode, strerror(errno));
    }
    else{
        printf("open(%s, %d, %d) success, return file descriptor %d\n", path, oflag, mode, result);
    }
    return result;
}

int My_create(const char* path, mode_t mode){
    int result = open(path, mode);
    if(result == -1)
        printf("open(%s, %d) failed, because %s\n", path, mode, strerror(errno));
    else
        printf("open(%s, %d) success, return file descriptor %d\n", path, mode, result);
    return result;
}

void test_open_create(){
    printf("----------test_open_creat start----------\n");
    assert(prepare_file("test1", "0123456789", 10, S_IRWXU) == 0);
    assert(prepare_file("test2", "0123456789", 10, S_IRWXU) == 0);
    assert(prepare_file("test3", "0123456789", 10, S_IRWXU) == 0);
    assert(prepare_file("test4", "0123456789", 10, S_IRWXU) == 0);
    assert(prepare_file("test5", "0123456789", 10, S_IRWXU) == 0);
    un_prepare_file("no_such_file1");
    un_prepare_file("no_such_file2");
    un_prepare_file("no_such_file3");
    un_prepare_file("no_such_file4");
    un_prepare_file("no_such_file5");

    My_open("test1", O_RDWR);
    My_open("no_such_file1", O_RDWR);
    My_open_with_mode("test2", O_RDWR, S_IRUSR|S_IWUSR);
    My_open_with_mode("no_such_file2", O_RDWR, S_IRUSR|S_IWUSR);
    My_open_with_mode("test3", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    My_open_with_mode("no_such_file3", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    My_open_with_mode("test4", O_RDWR|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
    My_open_with_mode("no_such_file4", O_RDWR|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
    My_create("test5", S_IRUSR|S_IWUSR);
    My_create("no_such_file5", S_IRUSR|S_IWUSR);

    un_prepare_file("test1");
    un_prepare_file("test2");
    un_prepare_file("test3");
    un_prepare_file("test4");
    un_prepare_file("test5");
    un_prepare_file("no_such_file1");
    un_prepare_file("no_such_file2");
    un_prepare_file("no_such_file3");
    un_prepare_file("no_such_file4");
    un_prepare_file("no_such_file5");
    printf("----------test_open_create end----------\n");
}

