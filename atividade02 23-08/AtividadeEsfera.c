// Arquivo: main.c
#include <stdio.h>
#include "esfera.h"

int main() {
    // Criando uma esfera com raio 5.0
    Esfera e = criarEsfera(5.0);

    // Obtendo e imprimindo o raio
    printf("Raio: %.2f\n", obterRaio(e));

    // Calculando e imprimindo a área superficial
    printf("Área superficial: %.2f\n", calcularArea(e));

    // Calculando e imprimindo o volume
    printf("Volume: %.2f\n", calcularVolume(e));

    return 0;
}
