#ifndef _RAM_MODULE_HPP_
#define _RAM_MODULE_HPP_
#include <vector>
#include <string>

class RamModule
{
private:
  std::vector<long> memory;

public:
  RamModule(std::vector<std::vector<std::string>>, long);
  long get_memory(long address);
  long get_memory(std::string);
  void set_memory(long address, long value);
  void set_memory(std::string, std::string);

  auto get_memory()
  {
    return this->memory;
  }
};

#endif