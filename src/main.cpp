#include <iostream>
#include "file-io/file-io.hpp"
#include "parser/parser.hpp"
#include <vector>

int main(int argc, char const *argv[])
{
  FileIO file(*(argv + 1));
  auto instructions = file.fetch_instruction_vector();
  Parser parser(instructions);

  auto instruction_table = parser.get_instruction_table();
  for (auto instruction : instruction_table)
  {
    for (auto key : instruction)
    {
      std::cout << key << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
