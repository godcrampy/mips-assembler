#ifndef _REGISTER_MODULE_HPP_
#define _REGISTER_MODULE_HPP_
#include <vector>
#include <string>

class RegisterModule
{
private:
  long $zero = 0;
  std::vector<long> $s = {0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<long> $t = {0, 0, 0, 0, 0, 0, 0, 0};

public:
  RegisterModule(std::vector<std::vector<std::string>>);
  auto get_save()
  {
    return this->$s;
  }
  void set_register(std::string name, std::string value);
  void set_register(std::string name, long value);
  long get_register(std::string);
};

#endif