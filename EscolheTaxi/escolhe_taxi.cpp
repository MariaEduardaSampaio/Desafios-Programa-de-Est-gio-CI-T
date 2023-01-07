#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

std::string prd(const double x, const int decDigits) {
    std::stringstream ss;
    ss << std::fixed;
    ss.precision(decDigits);
    ss << x;
    return ss.str();
}

float CalculaPreco(float taxa, float val_km, float distancia){
    return ((val_km*distancia) + taxa);
}

std::string escolhe_taxi(std::string tf1,std::string vqr1,std::string tf2,std::string vqr2) {
    float Taxa_E1 = stof(tf1);
    float Taxa_E2 = stof(tf2);
    float ValKm_E1 = stof(vqr1);
    float ValKm_E2 = stof(vqr2);
    float Preco_E1_Antes = 0.0, Preco_E2_Antes = 0.0, distancia = 0.0;
    std::string EmpresaAntes, EmpresaDepois;

    distancia = (Taxa_E1 - Taxa_E2) / (ValKm_E2 - ValKm_E1);
    Preco_E1_Antes = CalculaPreco(Taxa_E1, ValKm_E1, distancia - 1);
    Preco_E2_Antes = CalculaPreco(Taxa_E2, ValKm_E2, distancia - 1);

    if ((ValKm_E1 == ValKm_E2) && (Taxa_E1 == Taxa_E2))
        return "Tanto faz";
    else if ((ValKm_E1 > ValKm_E2) && (Taxa_E1 > Taxa_E2))
        return "Empresa 2";
    else if ((ValKm_E2 > ValKm_E1) && (Taxa_E2 > Taxa_E1))
        return "Empresa 1";
    else {
        if (Preco_E1_Antes < Preco_E2_Antes)
            EmpresaAntes = {"Empresa 1"};
        else if (Preco_E2_Antes < Preco_E1_Antes)
            EmpresaAntes = {"Empresa 2"};
        
        if (EmpresaAntes == "Empresa 1")
            EmpresaDepois = {"Empresa 2"};
        else if (EmpresaAntes == "Empresa 2")
            EmpresaDepois = {"Empresa 1"};
 
        int d = distancia;
        if (distancia / d == 1)
            return EmpresaAntes + " quando a distância < " + prd(distancia, 1) + ", Tanto faz quando a distância = " + prd(distancia, 1) + ", " + EmpresaDepois + " quando a distância > " + prd(distancia, 1);
        else
            return EmpresaAntes + " quando a distância < " + prd(distancia, 2) + ", Tanto faz quando a distância = " + prd(distancia, 2) + ", " + EmpresaDepois + " quando a distância > " + prd(distancia, 2);

    }
}

int main(){
    std::cout << escolhe_taxi("2.5", "1.0", "5.0", "0.75");
    return 0;
}