#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "../ram-module/ram-module.hpp"
#include "../register-module/register-module.hpp"
#include <vector>
#include <map>

class CPU
{
private:
  RamModule memory;
  RegisterModule registers;
  std::vector<std::vector<std::string>> instructions;
  int program_counter;
  std::map<std::string, long> label_map;

public:
  CPU(RamModule, RegisterModule, std::vector<std::vector<std::string>>);
  void execute();
  void print_status();
};

#endif