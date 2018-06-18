# UNIX标准及实现
## 2.3 IEEE POSIX
 * 可移植操作系统接口
 * Single UNIX Specification 前者超集
## 2.3 UNIX系统实现
``` c++
#include <unistd.h>
long sysconf(int name);
long patchconf(const char *pathname, int name);
long fpathconf(int fd, int name);
```
## 2.8 UNIX的基本数据类型是通用的