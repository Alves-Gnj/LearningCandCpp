#include "naoAcertou.hpp"

#include <map>
#include <string>

extern std::string palavraSecreta;
extern std::map<char, bool> chutou;

bool naoAcertou() {
  for (char letra : palavraSecreta) {
    if (!chutou[letra]) {
      return true;
    }
  }
  return false;
}
