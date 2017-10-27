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
  cout << placeholder.size() << endl;
  for (size_t i = 0; i < placeholder.size(); i++) {
    placeholder[i].imprimir();
  }
  return 0;
}
