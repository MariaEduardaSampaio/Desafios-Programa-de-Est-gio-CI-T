#include <vector>
#include <string>
#include <iostream>
#include <map>

std::vector<std::string> calcula_top_ocorrencias_de_queries(std::string texto,std::vector<std::string> queries,int k) {
  std::map<std::string, int> myMap;
  size_t j = 0, i = 0;
  int contador_string_atual = 0;

  for (auto string_atual: queries)
  { 
    j = 0;
    contador_string_atual = 0;
    i = 0;
    while (i < texto.size())
    {
      if (string_atual[j] == texto[i])
      {
        if (j + 1 == string_atual.size()){ //verifica se chegou ao final do querie
          contador_string_atual++;
          j = 0; //reinicia o iterador do vet de char querie
        }
        else
          j++;
      }

      else if (string_atual[j] != texto[i]) // se for diferente não foi encontrado o querie
        j = 0; 

      i++;
    }
    myMap[string_atual] = contador_string_atual; // associa à chave a qnt de vezes q x querie repetiu com o valor querie
  }
  
  std::vector<std::string> Resultado;

  auto iter = myMap.end();
  iter--;

    while (iter != myMap.begin())
    {
        if (k != 0) {
            Resultado.push_back(iter->first);
            k--;
        }
        else if (k == 0)
            break;
      iter--;
    }
 
  return Resultado;
}
// a 7   el 1   em 2  i 11

int main(){
  std::vector<std::string> resultado;
  resultado = calcula_top_ocorrencias_de_queries("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua",std::vector<std::string>{"a","em","i","el"},3);
  for (auto i: resultado)
    std::cout << i << " ";
  return 0;
}