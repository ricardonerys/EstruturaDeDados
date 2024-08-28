// Arquivo: esfera.h
typedef struct {
    double raio;
} Esfera;

// Funções para manipular a esfera
Esfera criarEsfera(double raio);
double obterRaio(Esfera e);
double calcularArea(Esfera e);
double calcularVolume(Esfera e);
