#include <iostream>
#include <string>

std::string menor_string_maior(std::string name) {
    std::string resultado;
    char MaiorValor = 0, AntigoMaiorValor = 0;

	if (name == ""){
        return "sem resposta";
    }

    for (int i = 0; i < name.size(); i++){
        if (name[i] > MaiorValor){
            AntigoMaiorValor = MaiorValor;
            MaiorValor = name[i];
        }
    }

    for (int i = 0; i < name.size(); i++){
        if ((name[i] != AntigoMaiorValor) && name[i] != MaiorValor){
            resultado += name[i];
        }
        else if (name[i] == AntigoMaiorValor){
            resultado += MaiorValor;
        }
        else if (name[i] == MaiorValor){
            resultado += AntigoMaiorValor;
        }
    }

    return resultado;
}

int main(){
    std::cout << menor_string_maior("abcde");
    return 0;
}