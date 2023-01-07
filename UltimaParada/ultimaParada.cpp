#include <vector>
#include <iostream>
#include <string>
int ultima_parada(int combustivel,int consumo,std::vector<int> postos_de_gasolina) {
  int qntd_km_rodados = combustivel * consumo;
  int posto_final = 0;
  
  std::vector<int>::iterator it;
  
  for (auto it: postos_de_gasolina){
    if (it <= qntd_km_rodados && it > posto_final)
      posto_final = it;
    else
      continue;
  }
  if (posto_final == 0)
    return -1;
  return posto_final;
}