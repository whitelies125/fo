# 添加 Makefile 搜索文件时的搜索目录，冒号分隔，搜索时的搜索目录顺序从前往后
VPATH = include : src
# 指定 .h 文件仅在 include 目录下搜索
vpath %.h include
# 指定 .cpp 文件在 src 目录下搜索
vpath %.cpp src

objects = main.o register.o implement.o

go.exe: $(objects)
	g++ -std=c++20 -o build/go $(objects)
main.o: main.cpp register.h
	g++ -std=c++20 -c src/main.cpp -I include
register.o: register.cpp register.h
	g++ -std=c++20 -c src/register.cpp -I include
implement.o: implement.cpp implement.h
	g++ -std=c++20 -c src/implement.cpp -I include

.PHONY: clean cleanObj cleanExe
clean: cleanObj cleanExe
cleanObj:
	-del *.o
cleanExe:
	-del build\\*.exe