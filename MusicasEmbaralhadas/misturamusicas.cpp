#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

std::vector<int> shuffle_musicas(std::vector<int> musicas_tocadas) {
	std::vector<int> DecrescenteMusicas = musicas_tocadas;
    std::vector<int> CrescenteMusicas = musicas_tocadas;
    std::vector<int> musicaEmbaralhada;

    std::sort(CrescenteMusicas.begin(),CrescenteMusicas.end());
    std::sort(DecrescenteMusicas.begin(),DecrescenteMusicas.end());
    std::reverse(DecrescenteMusicas.begin(), DecrescenteMusicas.end());
    
    int x = 0, y = 0;
    for(size_t i = 0; i < musicas_tocadas.size(); i++){
        if (i % 2 == 0) {
            musicaEmbaralhada.push_back(DecrescenteMusicas[x]);
            x++;
        }
        else{
            musicaEmbaralhada.push_back(CrescenteMusicas[y]);
            y++;
        }
    }

    return musicaEmbaralhada;
}

int main()
{
    std::vector<int> resultado = shuffle_musicas({1,2,3,4,5,6});
    for (auto i: resultado){
        std::cout << i;
    }
    return 0;
}