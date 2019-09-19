#ifndef _FILE_IO_HPP_
#define _FILE_IO_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class FileIO
{
public:
  std::vector<std::string> get_instruction_vector(const std::string &path = "main.mips");
  std::vector<std::string> get_register_vector(const std::string &path = "register.reg");
  std::vector<std::string> get_memory_vector(const std::string &path = "memory.ram");
};

#endif