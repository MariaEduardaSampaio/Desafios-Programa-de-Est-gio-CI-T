#include <vector>
#include <string>
#include <math.h>
#include <iostream>

int calcula_numero_da_senha(std::vector<std::string> senha) {
  int cont_true = 0, cont_false = 0, resultado = 0, cont_string = 0;
  std::vector<int> senha_final_codificada;

  for (int j = 0; j < senha.size(); j++)
  {
    for(int i = 0; i < senha.size(); i++){
      if (senha[i].at(j) == '1')
        cont_true++;
      else if (senha[i].at(j) == '0')
        cont_false++;
    }
    
    if (cont_true >= cont_false)
      senha_final_codificada.push_back(1);
    else
      senha_final_codificada.push_back(0);

    cont_false = cont_true = 0;
  }
    
  int expoente = 9;
  int i = 0;
  while (i != senha_final_codificada.size()){
    resultado += pow(2, expoente) * senha_final_codificada[i];
    expoente--;
    i++;
  }
  return resultado;
}