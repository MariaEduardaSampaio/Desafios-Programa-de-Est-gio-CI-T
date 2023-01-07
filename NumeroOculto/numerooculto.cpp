#include <iostream>
#include <string>
#include <vector>

bool checa_numero_escondido(int numero,int numero_oculto) {
    std::string Str_numero = std::to_string(numero);
    std::string Str_numeroOculto = std::to_string(numero_oculto);
    int PosicaoStrNum = 0, PosicaoStrNumOculto = 0;
    bool isOculto = false;
    std::string::iterator StrIterator;

    for (auto Str_numAtual : Str_numero) { 
        if (Str_numAtual == Str_numeroOculto[PosicaoStrNumOculto])
            PosicaoStrNumOculto++;
        else  
            continue;
    }

    if (PosicaoStrNumOculto == Str_numeroOculto.size())
        isOculto = true;
    else
        isOculto = false;

    return isOculto;
}