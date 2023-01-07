#include <iostream>
#include <string>

int calcula_total_leds(int altura,int largura) {
    if (altura  != 0 && largura != 0)
        return (altura + 1) * (largura + 1);
    else
        return 0;
}