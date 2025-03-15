#ifndef TOOLS_H
#define TOOLS_H
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>

/*!
 * \brief prepare_file: 为测试准备条件:新建一个文件（若存在则先删除），然后再向文件中写入指定内容
 * \param pathname: 新建文件的路径名（若存在则先删除）
 * \param buffer: 待写入文件的内容缓冲区
 * \param len: 待写入文件的内容的长度
 * \param mode: 新建文件的权限
*/
int prepare_file(const char* pathname, const void* buffer, int len, mode_t mode);

/*!
 * \brief un_prepare_file: 删除测试创建的一些文件
 * \param pathname: 待删除的文件的路径名
*/
void un_prepare_file(const char* pathname);

/**!
 * \brief print_char_buffer: 打印字符数组
 * \param buffer: 待打印的字符数组
 * \param len: 待打印的字符数组长度
 */
void print_char_buffer(const char* buffer, int len);

/**!
 * \brief fcntl_lock: 使用fcntl记录锁枷锁
 * \param fd: 加锁文件的操作符
 */
void fcntl_lock(int fd);

/** 
 * \brief fcntl_unlock: 解除fcntl记录锁
 * \param fd: 解锁文件的操作符
 */
void fcntl_unlock(int fd);

/** 
 * \brief abs_path: 根据目录和文件名获取绝对路径
 * \param dir_name: 目录的绝对路径
 * \param file_name: 文件名
 * \retrun : 返回拼接后的绝对路径
 */
char* abs_path(const char* dir_name, const char* file_name);

#endif
