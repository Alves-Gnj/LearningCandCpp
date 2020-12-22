#include <vector>
#include <iostream>
#include "tentativaErrada.hpp"

extern std::vector<char> chutesErrados;

void tentativaErrada() {
  std::cout << "Chutes errados: ";
  for (char letra : chutesErrados) {
    std::cout << letra << " ";
  }
  std::cout << std::endl;
}