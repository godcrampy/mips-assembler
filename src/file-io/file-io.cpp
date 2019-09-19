#include "file-io.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

std::vector<std::string> FileIO::get_instruction_vector(const std::string &path)
{
  std::ifstream file(path);
  if (!file)
    std::cout << "Error loading: " << path << std::endl;
  std::vector<std::string> instructions;
  std::string line_data;
  while (std::getline(file, line_data))
  {
    if (line_data.size() > 0)
    {
      // remove comments, tabs and commas
      line_data = line_data.substr(0, line_data.find("#"));
      std::replace(line_data.begin(), line_data.end(), '\t', ' ');
      line_data.erase(std::remove(line_data.begin(), line_data.end(), ','), line_data.end());
      instructions.push_back(line_data);
    }
  }
  return instructions;
}

std::vector<std::string> FileIO::get_register_vector(const std::string &path)
{
  std::ifstream file(path);
  if (!file)
    std::cout << "Error loading: " << path << std::endl;
  std::vector<std::string> registers;
  std::string line_data;
  while (std::getline(file, line_data))
  {
    if (line_data.size() > 0)
    {
      // remove comments, tabs and commas
      std::replace(line_data.begin(), line_data.end(), '\t', ' ');
      registers.push_back(line_data);
    }
  }
  return registers;
}

std::vector<std::string> FileIO::get_memory_vector(const std::string &path)
{
  return this->get_register_vector(path);
}
