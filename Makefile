CC = g++
all: src/main.cpp src/file-io/file-io.cpp
	${CC} ./src/main.cpp ./src/file-io/file-io.cpp -o ./build/mips

clean:
	rm ./build/*