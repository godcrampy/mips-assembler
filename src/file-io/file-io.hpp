#ifndef _FILE_IO_HPP_
#define _FILE_IO_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class FileIO
{
private:
  std::string instruction_path;
  std::string register_path;
  std::string memory_path;

public:
  FileIO(std::string instruction_path = "main.mips", std::string register_path = "register.reg", std::string memory_path = "memory.ram");
  std::vector<std::string> fetch_instruction_vector();
  std::vector<std::string> fetch_register_vector();
  std::vector<std::string> fetch_memory_vector();
};

#endif