#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

std::vector<int> calcula_porcentagem_sorteio(std::vector<bool> assinante, std::vector<int> minutos_assistidos) {
    std::vector<int> horas_assistidas;
    std::map<std::vector<bool>, std::vector<int>> Map_AssinanteHora;
    std::vector<int> ChancesAssinante;

    for (int i = 0; i < minutos_assistidos.size(); i++) {
        float x = ceil((float)(minutos_assistidos[i] / (float)60));
        horas_assistidas.push_back(x);
    }

    //Map_AssinanteHora.insert(std::make_pair(assinante, horas_assistidas));
    int total = 0;
    for (int i = 0; i < assinante.size(); i++)
    {
        if (assinante[i])
            ChancesAssinante.push_back(horas_assistidas[i] * 2);
        else 
            ChancesAssinante.push_back(horas_assistidas[i] * 1);
        total += ChancesAssinante[i];
    }

    std::vector<int> resultado;

    for (int i = 0; i < assinante.size(); i++) {
        float porcentagem = 100 * ((float)ChancesAssinante[i] / (float)total);
        int x = round(porcentagem);
        resultado.push_back(x);
    }

    return resultado;
}

int main() {
    std::vector<int> resultado;
    resultado = calcula_porcentagem_sorteio(std::vector<bool>{true, false, true, true, false}, std::vector<int>{60, 120, 240, 45, 30});
    return 0;
}

// Equals(std::vector<int>{50,50}) 1 2 4 1 1 -> 2 2 8 2 1