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
