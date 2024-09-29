all: main

INCLUDE=-I./UE4-Math
CXX = g++
override CXXFLAGS += -g -Wall -Werror -Wno-unused-label -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable $(INCLUDE)

INC = $(./UE4-Math/)
INC_PARAMS=$(foreach d, $(INC), -I$d)
SRC_DIR = ./UE4-Math

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0  $(SRCS) -o "$@"

clean:
	rm -f main main-debug>