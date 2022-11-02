#include <vector>
#include <string>
#include <iostream>
#include <map>

std::vector<std::string> calcula_top_ocorrencias_de_queries(std::string texto,std::vector<std::string> queries,int k) {
  std::map<int, std::string> myMap;
  int j = 0, i = 0;
  int contador_string_atual = 0;

  for (auto string_atual: queries)
  { 
    j = 0;
    contador_string_atual = 0;
    i = 0;
    while (i != texto.size())
    {
      if (string_atual[j] == texto[i])
      {
        if (j + 1 == string_atual.size()){
          contador_string_atual++;
          j = 0;
        }
        else
          j++;
      }

      else if (string_atual[j] != texto[i])
        j = 0; 

      i++;
    }
    myMap[contador_string_atual] = string_atual;
  }
  
  std::vector<std::string> Resultado;

  auto iter = myMap.end();
  iter--;
  while (iter != myMap.begin())
  {
      if (k != 0) {
          Resultado.push_back(iter->second);
          k--;
      }
      iter--;
  }
  return Resultado;
}
// a 7   el 1   em 2  i 11