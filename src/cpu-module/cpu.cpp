#include "cpu.hpp"
#include <string>
#include <iostream>

CPU::CPU(RamModule memory, RegisterModule registers, std::vector<std::vector<std::string>> instruction_table)
    : memory(memory), registers(registers), instructions(instruction_table)
{
  for (auto i = 0; i < this->instructions.size(); ++i)
  {
    if (instructions.at(i).size() == 5)
      this->label_map.insert({this->instructions.at(i).at(0), i});
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
    if (instruction.size() != 4 && instruction.size() != 2)
    {
      std::cout << "Error: Unknown instruction on line " << i + 1 << std::endl;
      break;
    }
    auto operation = instruction.at(0);
    auto a = instruction.at(1);
    std::string b, c;
    if (instruction.size() == 4)
    {
      b = instruction.at(2);
      c = instruction.at(3);
    }
    if (operation == "add")
    {
      auto value = this->registers.get_register(b) + this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "addi")
    {
      auto value = this->registers.get_register(b) + std::stol(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "sub")
    {
      auto value = this->registers.get_register(b) - this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "and")
    {
      auto value = this->registers.get_register(b) & this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "andi")
    {
      auto value = this->registers.get_register(b) & std::stol(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "or")
    {
      auto value = this->registers.get_register(b) | this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "ori")
    {
      auto value = this->registers.get_register(b) | std::stol(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "sll")
    {
      auto value = this->registers.get_register(b) << this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "srl")
    {
      auto value = this->registers.get_register(b) >> this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "nor")
    {
      auto value = !(this->registers.get_register(b) | this->registers.get_register(c));
      this->registers.set_register(a, value);
    }
    else if (operation == "sub")
    {
      auto value = this->registers.get_register(b) - this->registers.get_register(c);
      this->registers.set_register(a, value);
    }
    else if (operation == "lw")
    {
      auto value = this->memory.get_memory((std::stol(b)) + this->registers.get_register(c));
      this->registers.set_register(a, value);
    }
    else if (operation == "sw")
    {
      auto address = std::stol(b) + this->registers.get_register(c);
      std::cout << b << " " << c;
      this->memory.set_memory(4, std::stol(a));
    }
    else if (operation == "log")
    {
      // log <name> <i> <address> => name:
      std::cout << a << " " << this->registers.get_register(c) + std::stol(b) << std::endl;
    }
    else if (operation == "beq")
    {
      auto value1 = this->registers.get_register(a);
      auto value2 = this->registers.get_register(b);
      if (value1 == value2)
        i = this->label_map[c];
    }
    else if (operation == "bne")
    {
      auto value1 = this->registers.get_register(a);
      auto value2 = this->registers.get_register(b);
      if (value1 != value2)
        i = this->label_map[c];
    }
    else if (operation == "j")
    {
      i = this->label_map[b];
    }
    else
    {
      std::cout << "Error: Unknown instruction on line " << i + 1 << std::endl;
      break;
    }
  }
}

void CPU::print_memory()
{
  this->memory.print_memory();
}
