// Arquivo: esfera.c
#include <stdio.h>
#include "esfera.h"
#include <math.h>

// Função para criar uma esfera com um dado raio
Esfera criarEsfera(double raio) {
    Esfera e;
    e.raio = raio;
    return e;
}

// Função para obter o raio da esfera
double obterRaio(Esfera e) {
    return e.raio;
}

// Função para calcular a área superficial da esfera
double calcularArea(Esfera e) {
    return 4 * 3.14 * pow(e.raio, 2);
}

// Função para calcular o volume da esfera
double calcularVolume(Esfera e) {
    return (4.0/3.0) * 3.14 * pow(e.raio, 3);
}
