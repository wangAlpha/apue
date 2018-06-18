# 文件I/O
## 文件描述符
0=>STD_FILENO
1=>STDOUT_FILENO
2=>STDERR_FILENO
## 函数 open and opentat
 * 相对路径和绝对路径
 * 文件名和路径截断
## creat() 
 ```c++ 
 int creat(const char *path, mode_t mode);
 =>
 open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
 ```
## 文件共享

　* 进程、内核和文件系统各自有不同的描述文件的方法，如下图



![](/home/me/Documents/Git/apue/picture/Selection_001.png)

* 假设两个独立的进程各自打开了同一文件，关系如下

  ![1529276453995](/home/me/Documents/Git/apue/picture/Selection_002.png)

  * 可能有多个文件描述符都指向同一文件表项，dup函数也会有这一点

## 原子操作

* open的O_APPEND是原子操作，这样write之前就可以不用调用lseek

* __Single UNIX Specification__ 有I/O原子扩张。如pread和pwrite

* open() + O_CREAT O_EXCL 组成了一个原子操作

## dup and dup2

![1529277109400](/home/me/Documents/Git/apue/picture/Selection_003.png)

dup 和 dup2 返回的**fd** 共享同一个文件表项

* dup2 和 fcntl有很大区别， 
  * dup2是原子操作，fcntl可能有有很多其他操作
  * dup2 和 fcntl有一些不同的errno

## sync、fsync and fdatasync

* 用于缓存同步，sync用于往所有修改过的块缓存区写队列，
* fsync用于指定某一个文件起作用，且写完后返回
* fdatasync　类似fsync　只影响文件的部分数据，但同时还包括文件属性

## fcntl

* 可以改变已经打开文件的属性

  ![1529279285791](/home/me/Documents/Git/apue/picture/Selection_004.png)

* 对于修改文件描述符或者文件状态时必须谨慎
* __O_SYNC__　会显著提高write的时间

## ioctl

* Single UNIX Specification 的一个扩展，__ioctl - control device__ 

* I/O操作杂物箱

* 终端使用较多

## /dev/fd/

* 等效为复制描述符_n_ (不是等同)