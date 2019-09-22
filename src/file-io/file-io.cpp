#include "file-io.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

FileIO::FileIO(std::string instruction_path, std::string register_path, std::string memory_path)
    : instruction_path(instruction_path), register_path(register_path), memory_path(memory_path)
{
}

std::vector<std::string> FileIO::fetch_instruction_vector()
{
  std::ifstream file(this->instruction_path);
  if (!file)
    std::cout << "Error loading: " << this->instruction_path << std::endl;
  std::vector<std::string> instructions;
  std::string line_data;
  while (std::getline(file, line_data))
  {
    if (line_data.size() > 0)
    {
      // remove comments, tabs and commas
      line_data = line_data.substr(0, line_data.find("#"));                                   // remove stuff after #
      std::replace(line_data.begin(), line_data.end(), '\t', ' ');                            // replace tabs with spaces
      std::replace(line_data.begin(), line_data.end(), '(', ' ');                             // repace ( with space
      line_data.erase(std::remove(line_data.begin(), line_data.end(), ','), line_data.end()); // remove ,
      line_data.erase(std::remove(line_data.begin(), line_data.end(), ')'), line_data.end()); // remove )
      instructions.push_back(line_data);
    }
  }
  return instructions;
}

std::vector<std::string> FileIO::fetch_register_vector()
{
  std::ifstream file(this->register_path);
  if (!file)
    std::cout << "Error loading: " << this->register_path << std::endl;
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

std::vector<std::string> FileIO::fetch_memory_vector()
{
  std::ifstream file(this->memory_path);
  if (!file)
    std::cout << "Error loading: " << this->memory_path << std::endl;
  std::vector<std::string> memory;
  std::string line_data;
  while (std::getline(file, line_data))
  {
    if (line_data.size() > 0)
    {
      // remove comments, tabs and commas
      std::replace(line_data.begin(), line_data.end(), '\t', ' ');
      memory.push_back(line_data);
    }
  }
  return memory;
}
