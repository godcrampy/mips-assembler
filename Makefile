CC = g++
all: src/main.cpp src/file-io/file-io.cpp
	${CC} src/main.cpp src/file-io/file-io.cpp src/parser/parser.cpp src/register-module/register-module.cpp src/ram-module/ram-module.cpp src/cpu-module/cpu.cpp -o build/mips

# for testing purposes only:
move:
	mv build/mips .

clean:
	rm ./build/*