#include <iostream>
#include "file-io/file-io.hpp"
#include "parser/parser.hpp"
#include "register-module/register-module.hpp"
#include "ram-module/ram-module.hpp"
#include "cpu-module/cpu.hpp"
#include <vector>

int main(int argc, char const *argv[])
{
  if (argc != 4)
  {
    std::cout << "Pass .mips .reg .ram file as arguments" << std::endl;
    return 1;
  }
  FileIO file(*(argv + 1), *(argv + 2), *(argv + 3));
  auto instructions = file.fetch_instruction_vector();
  auto registers = file.fetch_register_vector();
  auto memory = file.fetch_memory_vector();
  Parser parser(instructions, registers, memory);

  auto instruction_table = parser.get_instruction_table();
  auto register_table = parser.get_register_table();
  auto memory_table = parser.get_memory_table();

  RegisterModule reg(register_table);
  RamModule ram(memory_table, 1000);
  CPU cpu(ram, reg, instruction_table);
  cpu.execute();
  cpu.print_status();
  return 0;
}
