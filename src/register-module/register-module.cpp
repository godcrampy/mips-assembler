#include "register-module.hpp"

RegisterModule::RegisterModule(std::vector<std::vector<std::string>> register_table)
{
  for (auto line : register_table)
    this->set_register(line[0], line[1]);
}

long RegisterModule::get_register(std::string name)
{
  if (name[1] == 't')
    return this->$t[name[2] - '0'];
  if (name[1] == 's')
    return this->$s[name[2] - '0'];
  return 0; // accounting for $zero
}

void RegisterModule::set_register(std::string name, std::string value)
{
  if (name[1] == 't')
    this->$t[name[2] - '0'] = std::stoi(value);
  if (name[1] == 's')
    this->$s[name[2] - '0'] = std::stoi(value);
}
