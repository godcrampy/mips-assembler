#include <iostream>
#include "file-io/file-io.hpp"
#include <vector>

int main(int argc, char const *argv[])
{
  FileIO file;
  auto instructions = file.get_instruction_vector(*(argv + 1));
  for (auto instruction : instructions)
    std::cout << instruction << std::endl;
  return 0;
}
