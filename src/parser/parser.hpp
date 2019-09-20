#ifndef _PARSER_HPP_
#define _PARSER_HPP_
#include <vector>
#include <string>

class Parser
{
private:
  std::vector<std::string> instruction_vector;
  std::vector<std::string> memory_vector;
  std::vector<std::string> register_vector;
  std::vector<std::vector<std::string>> vector_to_table(std::vector<std::string>);

public:
  Parser(std::vector<std::string> instruction_vector = {}, std::vector<std::string> register_vector = {}, std::vector<std::string> memory_vector = {});
  std::vector<std::vector<std::string>> get_instruction_table();
  std::vector<std::vector<std::string>> get_register_table();
  std::vector<std::vector<std::string>> get_memory_table();
  bool is_memory_valid();
};

#endif