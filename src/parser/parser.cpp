#include "parser.hpp"
#include <string>
#include <sstream>

Parser::Parser(std::vector<std::string> instruction_vector, std::vector<std::string> register_vector, std::vector<std::string> memory_vector)
    : instruction_vector{instruction_vector}, register_vector{register_vector}, memory_vector{memory_vector}
{
}

std::vector<std::vector<std::string>> Parser::vector_to_table(std::vector<std::string> vector)
{
  // works
  std::vector<std::vector<std::string>> table;
  for (auto element : vector)
  {
    std::vector<std::string> row;
    std::stringstream stream(element);
    std::string word;
    while (stream >> word)
      row.push_back(word);
    table.push_back(row);
  }
  return table;
}

std::vector<std::vector<std::string>> Parser::get_instruction_table()
{
  return this->vector_to_table(this->instruction_vector);
}

std::vector<std::vector<std::string>> Parser::get_register_table()
{
  return this->vector_to_table(this->register_vector);
}

std::vector<std::vector<std::string>> Parser::get_memory_table()
{
  return this->vector_to_table(this->memory_vector);
}