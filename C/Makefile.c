/*
*Makefile编写的好可以在工程项目编译链接的过程中省去很多麻烦，平时在练习的过程中也是能方便高效的学习。
*/

1.忽略出错的命令:
如果不希望某条命令因为出错了而导致整个make执行被终止，可以在命令前面加上“-”，表示不管该命令出不出错，后面的命令都将继续执行下去。如：
        mkdir lpyuan
如果不加“-”并且dir已经存在，则这条命令就会出错，并将导致整个make执行被终止。要想不被终止，则要改成：
-mkdir dir


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
