# strace
UNIX Syscall tracer

# Usage
```bash
$> make && ./strace -h
```

# Example
`$> ./strace ls`
```
rt_sigprocmask(2, 0x7ffd105d7f70, NULL, 8) = 0
execve("/home/simon/bin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/usr/local/bin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/home/simon/.cargo/bin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/home/simon/.local/bin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/usr/local/sbin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/usr/local/bin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/usr/sbin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = -1 ENOENT (No such file or directory)
execve("/usr/bin/ls", 0x7ffd105d8258, 0x7ffd105d8268) = 0
brk(NULL)                                = 0x55bf8b24d000
arch_prctl(12289, 0x7ffe9ba3d6f0)        = -1 EINVAL (Invalid argument)
access("/etc/ld.so.preload", 4)          = -1 ENOENT (No such file or directory)
openat(4294967196, "/etc/ld.so.cache", 524288, 0x0) = 3
fstat(3, 0x7ffe9ba3c850)                 = 0
mmap(NULL, 126154, 1, 2, 3, 0x0)         = 0x7f740370e000
close(3)                                 = 0
openat(4294967196, "/lib/x86_64-linux-gnu/libselinux", 524288, 0x0) = 3
read(3, "\177ELF\2\1\1", 832)            = 832
fstat(3, 0x7ffe9ba3c8a0)                 = 0
mmap(NULL, 8192, 3, 34, 4294967295, 0x0) = 0x7f740370c000
mmap(NULL, 174568, 1, 2050, 3, 0x0)      = 0x7f74036e1000
mmap(0x7f74036e7000, 102400, 5, 2066, 3, 0x6000) = 0x7f74036e7000
mmap(0x7f7403700000, 32768, 1, 2066, 3, 0x1f000) = 0x7f7403700000
mmap(0x7f7403708000, 8192, 3, 2066, 3, 0x26000) = 0x7f7403708000
mmap(0x7f740370a000, 6632, 3, 50, 4294967295, 0x0) = 0x7f740370a000
close(3)                                 = 0
openat(4294967196, "/lib/x86_64-linux-gnu/libc.so.6"..., 524288, 0x0) = 3
read(3, "\177ELF\2\1\1\3", 832)          = 832
pread64(3, "", 784, 0x40)                = 784
pread64(3, "`\37777777711\37777777643\37777777633\37777777776\177", 32, 0x350) = 32
(...)
```
