CC=g++
STD=-std=c++11
WALL=-Wall -g
SrcFiles=$(wildcard *.cpp)
DestFiles=$(patsubst %.cpp,%,$(SrcFiles))#把%.cpp,替换成%,源文件



all:$(DestFiles)

$(DestFiles):%:%.cpp
	$(CC) $(STD) $(WALL) $< -o $@ -lm

clean:
	-rm $(DestFiles)

test:
	-@echo $(SrcFiles)
	-@echo $(DestFiles)
    
.PHONY:all clean test
