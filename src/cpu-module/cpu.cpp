#include "cpu.hpp"
#include <string>
#include <iostream>

CPU::CPU(RamModule memory, RegisterModule registers, std::vector<std::vector<std::string>> instruction_table)
    : memory(memory), registers(registers), instructions(instruction_table)
{
  for (auto i = 0; i < this->instructions.size(); ++i)
  {
    if (instructions.at(i).size() == 5)
      this->label_map.insert({i, this->instructions.at(i).at(0)});
  }
}

void CPU::execute()
{
  for (auto i = 0; i < this->instructions.size(); ++i)
  {
    std::vector<std::string> instruction = this->instructions.at(i);
    if (instruction.size() == 5)
    {
      instruction.erase(instruction.begin());
    }
    if (instruction.size() != 4)
    {
      std::cout << "Error: Unknown instruction on line " << i + 1 << std::endl;
      break;
    }
    auto operation = instruction.at(0);
    auto a = instruction.at(1);
    auto b = instruction.at(2);
    auto c = instruction.at(3);
    if (operation == "add")
    {
      auto value = this->registers.get_register(b) + this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "sub")
    {
      auto value = this->registers.get_register(b) - this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "log")
    {
      // log <name> <i> <address> => name:
      std::cout << a << " " << this->registers.get_register(c) + std::stol(b) << std::endl;
    }
    else
    {
      std::cout << "Error: Unknown instruction on line " << i + 1 << std::endl;
      break;
    }
  }
}
