CC = g++
all: src/main.cpp src/test.cpp
	${CC} ./src/main.cpp ./src/test.cpp -o ./build/main

clean:
	rm ./build/*