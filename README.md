# UNIX基础知识
## 1.2 体系结构 
操作系统是一种软件，我们通常称它为内核(kernel),内核接口被成为系统调用(system call)，应用程序可使用公共函数库和 __系统调用__ shell为运行其他应用程序提供了接口
## 1.3 登录
shell的历史
## 文件和目录
目录是包含目录项的文件。
## 1.4 输入和输出
 1. 文件描述符
 2. 标准输入、输出和标准错误
 3. 不带缓存I/O
## 1.5 标准I/O带缓冲

## 1.6 程序和进程
 1. 程序
 2. 进程和进程ID
    长整型可提高移植性
 3. 进程控制
    fork、exec、waitpid 
 4. 线程和线程ID
## 1.7 出错处理
 * errno
 * <errno.h> 分致命错误与非致命错误
 * errno　绝对不为０
## 1.8　用户标识
 1. 用户ＩＤ
 2. 组ID
 3. 附属组ID 
  /etc/group ，Unix允许一个用户至多１６个其它的组
## 1.9 信号
　进程可以 1) 忽略信号 2) 按系统默认方式处理　3)　产生一个信号时捕捉该信号
## 1.10 时间值
 １)日历时间 __time_t__　 2) 进程时间　__clock_t__
  一个进程维护了：
    * 时钟时间
    * 用户CPU时间
    * 系统CPU时间

 ``` shell
cd /usr/include
time grep _POSIX_SOURCE */*.h >　/dev/null
 ```
## 1.11 系统调用和库函数
 * 系统调用与库函数的区别