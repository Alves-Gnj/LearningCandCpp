#include "leArquivo.hpp"

#include <fstream>
#include <iostream>

std::vector<std::string> leArquivo() {
  std::ifstream arquivo;
  arquivo.open("palavras.txt");

  if (arquivo.is_open()) {
    int quantidadePalavras;
    arquivo >> quantidadePalavras;

    std::vector<std::string> palavrasArquivo;

    for (int i = 0; i < quantidadePalavras; i++) {
      std::string palavraLida;
      arquivo >> palavraLida;
      palavrasArquivo.push_back(palavraLida);
    }
    arquivo.close();
    return palavrasArquivo;
  } else {
    std::cout << "Banco de palavras não foi localizado." << std::endl;
    exit(0);
  }
}
