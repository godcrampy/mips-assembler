# MIPS Assembler

Assembler to emulate and execute programs written in [MIPS](https://en.wikipedia.org/wiki/MIPS_architecture) assembly language. The assembler will emulate a 1KB RAM Space and 32 bit registers without actually using up system registers directly. This allows it to run on any processor maching with a C++14 compiler.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

C++14 compiler preferrably GCC.

### Installing

1. Clone this repo to local machine

`$ git clone https://github.com/godcrampy/mips-assembler.git`

2. cd into the cloned repo
   `$ cd mips-assembler`

3. Build the program using _make_:
   (Assumes G++ installed, edit the Makefile for other options)
   `$ make`

OR

3. Build using compiler
   `$g++ src/main.cpp src/file-io/file-io.cpp src/parser/parser.cpp src/register-module/register-module.cpp src/ram-module/ram-module.cpp src/cpu-module/cpu.cpp -o build/mips`

### Executing MIPS

The assembler program will be built in the build directory. To run MIPS code, you need 3 files:

- .mips: This is the file in which you'll write the mips program
- .ram: This is the file in which you'll give ram configuration
- .reg: This is the file in which you'll give register configuration

_Example MIPS Code_

test.mips

```
lw	$t0, 0($s1)
addi $t1, $zero, 6
while: log loop 0 $t0
addi $t0, $t0, 1
bne $t0, $t1, while
```

register.reg

```
$s1: 120
```

memory.ram

```
120: 1
```

Execution: `$ ./mips ./test.mips ./register.reg ./memory.ram`
Output:

```
loop 1
loop 2
loop 3
loop 4
loop 5
```

## Current Status
Currently the following instructions are supported:
- _add_
- _addi_
- _sub_
- _and_
- _andi_
- _or_
- _ori_
- _srl_
- _sll_
- _lw_
- _sw_
- _log_

> Note: _log_ is not a mips instruction. It has been provided to print register data to the teminal. It's syntax is: _log message add register_. This will print _message_ followed by the data in the register with _add_ value added to it.