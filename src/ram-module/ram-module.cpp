#include "ram-module.hpp"
#include <iostream>

RamModule::RamModule(std::vector<std::vector<std::string>> memory_table, long bytes) : memory(bytes / 4, 0)
{
  for (auto line : memory_table)
    this->memory[std::stoi(line[0]) / 4] = std::stoi(line[1]);
}

long RamModule::get_memory(long address)
{
  return this->memory[address / 4];
}

long RamModule::get_memory(std::string address)
{
  return this->get_memory(std::stol(address));
}

void RamModule::set_memory(long address, long value)
{
  this->memory[address / 4] = value;
}

void RamModule::set_memory(std::string address, std::string value)
{
  this->set_memory(std::stol(address), std::stol(value));
}

void RamModule::print_memory()
{
  std::cout << "Memory Status" << std::endl;
  for (auto i = 0; i < this->memory.size(); ++i)
    if (this->memory[i])
      std::cout << i * 4 << " : " << this->memory[i] << std::endl;
}
