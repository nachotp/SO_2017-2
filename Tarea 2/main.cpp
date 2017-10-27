#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Imports/funciones.h"

using namespace std;

int main(int argc, char const *argv[]) {
  vector<carta> placeholder;
  stack<carta> mazo;

  generarCartasNumericas(&placeholder);
  generarCartasExtra(&placeholder);
  random_shuffle(placeholder.begin(),placeholder.end());

  for (size_t i = 0; i < placeholder.size(); i++) {
    mazo.push(placeholder[i]);
  }

  placeholder.clear();

  while (!mazo.empty()) {
    mazo.top().imprimir();
    cout << endl;
    mazo.pop();
  }
  return 0;
}
