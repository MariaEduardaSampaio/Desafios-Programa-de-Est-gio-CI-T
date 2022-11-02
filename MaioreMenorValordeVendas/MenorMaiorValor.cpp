#include <vector>
#include <iostream>
#include <string>
std::vector<int> retorna_menor_e_maior_valor_de_vendas(std::vector<std::vector<int>> tickets) {
  int menor_valor;
  int maior_valor;
  
 for (int i = 0; i < tickets.size(); i++)
 {
   if (i == 0){
     maior_valor = tickets[0][0];
     menor_valor = tickets[0][0];
   }
   
   for (int j = 0; j < tickets[i].size(); j++){
     if ((tickets[i][j] > maior_valor) && tickets[i][j] <= 500)
       maior_valor = tickets[i][j];
    else if ((tickets[i][j] < menor_valor) && tickets[i][j] >= 20)
       menor_valor = tickets[i][j];
    else
       continue;
   }
 }
  
  std::vector<int> vect_vendas {menor_valor, maior_valor};
  return vect_vendas;
}