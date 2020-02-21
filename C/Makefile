/*
*Makefile编写的好可以在工程项目编译链接的过程中省去很多麻烦，平时在练习的过程中也是能方便高效的学习。
*/

一、Makefile相关知识点
1. 忽略出错的命令:
如果不希望某条命令因为出错了而导致整个make执行被终止，可以在命令前面加上“-”，表示不管该命令出不出错，后面的命令都将继续执行下去。如：
    mkdir lpyuan
如果不加“-”并且dir已经存在，则这条命令就会出错，并将导致整个make执行被终止。要想不被终止，则要改成：
    -mkdir dir

2. 显示命令：
一般默认make会把命令原样显示出来后再去执行命令，如果我们不需要原样显示命令，则可以在命令前面加一个“@”， 如
    @m -rf lpyuan
    则是不会输出命令
    
3. makefile $@, $^, $<, $?
$@  表示目标文件
$^  表示所有的依赖文件
$<  表示第一个依赖文件
$?  表示比目标还要新的依赖文件列表

如一个目录下有如下文件：
hello.c  hi.c  main.c  Makefile

按照 Makefile 规则规规矩矩的写：
main: main.o hello.o hi.o
        gcc -o main main.o hello.o hi.o

main.o: main.c
        cc -c main.c

hello.o: hello.c
        cc -c hello.c

hi.o: hi.c
        cc -c hi.c

clean:
        rm *.o
        rm main

改为用上述符号进行替代：

main: main.o hello.o hi.o
        gcc -o $@ $^
main.o: main.c
        cc -c $<
hello.o: hello.c
        cc -c $<
hi.o: hi.c
        cc -c $<
clean:
        rm *.o
        rm main
        
4.Makefile中的常用函数

4.1 功能说明
$(filter-out PATTERN…,TEXT) `
函数名称 ：反过滤函数—filter-out。
函数功能 ：和“filter”函数实现的功能相反。过滤掉字串“TEXT”中所有符合模式“PATTERN”的单词，保留所有不符合此模式的单词。可以有多个模式。存在多个模式时，模式表达式之间使用空格分割。
返回值 ：空格分割的“TEXT”字串中所有不符合模式“PATTERN”的字串。
函数说明： “filter-out”函数也可以用来去除一个变量中的某些字符串（实现和“filter”函数相反）。

4.2示例
objects=main1.o foo.o main2.o bar.o 
mains=main1.o main2.o
$(filter-out$(mains),$(objects))
实现了去除变量“objects”中“mains”定义的字串（文件名）功能。它的返回值为“foo.o bar.o”。

二、【Makefile通用模板】
TARGET=server
CC=g++
CFLAG=-c -g -static
#所有的.c文件
SRCS:=$(wildcard ../*.c)
FILTERS=../hello.c
#从SRCS中除了hello.c文件 filter函数可以选择满足条件的
SRCS:=$(filter-out $(FILTERS), $(SRCS))
OBJS:=$(patsubst %.c, %.o, $(SRCS))
CURRENT_PATH=$(PWD)
CPPFLAGS= -I../include -I../util
LIBS_PATH=-L../lib64
LIBS=-lmylib

#判断是哪个系统32bit编译还是在64bit编译。
ARCH:=$(shell uname -m)
ifeq ($(ARCH), x86_64)
VERSION:=X86_64
else
VERSION:=i686
endif

$(TARGET):$(OBJS)
        $(CC) $(DEBUG) $(SRCS) $(LIBS_PATH) $(LIBS) $(CPPFLAGS) -o $(TARGET)

$(OBJS):%.o:%.c
        $(CC) $(CFLAG) $< -o $@

.PHONY:clean
clean:
        rm -rf *~ *.bak $(TARGET)

【顶层Makefile编写】
all: all_client all_server
    rm -rf *~ *.bak
all_client:
    $(MAKE) -C client
all_server:
    $(MAKE) -C server

clean: clean_client clean_server
    rm -rf *~ *.bak
clean_client:
    $(MAKE) -C client clean
clean_server:
    $(MAKE) -C server clean

