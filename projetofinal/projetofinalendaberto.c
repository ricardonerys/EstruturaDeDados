#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

typedef struct {
    int id;
    char nome[50];
    float preco;
    int estoque;
    int ocupado; // 0 = livre, 1 = ocupado
} Produto;

typedef struct {
    int id;
    int quantidade;
} ItemCarrinho;

Produto tabela_hash[TAMANHO_TABELA];
ItemCarrinho carrinho[TAMANHO_TABELA];
int tamanho_carrinho = 0;

// Função hash simples
int hash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Insere produto na tabela hash
void inserir_produto(int id, const char *nome, float preco, int estoque) {
    int indice = hash(id);
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int tentativa = (indice + i) % TAMANHO_TABELA;
        if (!tabela_hash[tentativa].ocupado) {
            tabela_hash[tentativa].id = id;
            strcpy(tabela_hash[tentativa].nome, nome);
            tabela_hash[tentativa].preco = preco;
            tabela_hash[tentativa].estoque = estoque;
            tabela_hash[tentativa].ocupado = 1;
            printf("Produto '%s' inserido com sucesso.\n", nome);
            return;
        }
    }
    printf("Erro: tabela hash cheia.\n");
}

// Busca produto
Produto* buscar_produto(int id) {
    int indice = hash(id);
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int tentativa = (indice + i) % TAMANHO_TABELA;
        if (tabela_hash[tentativa].ocupado && tabela_hash[tentativa].id == id) {
            return &tabela_hash[tentativa];
        }
        if (!tabela_hash[tentativa].ocupado) break;
    }
    return NULL;
}

// Adiciona produto ao carrinho
void adicionar_ao_carrinho(int id, int quantidade) {
    Produto *produto = buscar_produto(id);
    if (produto) {
        if (produto->estoque >= quantidade) {
            carrinho[tamanho_carrinho].id = id;
            carrinho[tamanho_carrinho].quantidade = quantidade;
            tamanho_carrinho++;
            produto->estoque -= quantidade;
            printf("Produto '%s' adicionado ao carrinho.\n", produto->nome);
        } else {
            printf("Estoque insuficiente para '%s'.\n", produto->nome);
        }
    } else {
        printf("Produto não encontrado.\n");
    }
}

// Exibe os itens do carrinho
void exibir_carrinho() {
    printf("\nCarrinho de Compras:\n");
    float total = 0;
    for (int i = 0; i < tamanho_carrinho; i++) {
        Produto *produto = buscar_produto(carrinho[i].id);
        if (produto) {
            printf("%s x%d - R$%.2f\n", produto->nome, carrinho[i].quantidade, produto->preco * carrinho[i].quantidade);
            total += produto->preco * carrinho[i].quantidade;
        }
    }
    printf("Total: R$%.2f\n\n", total);
}

int main() {
    // Inicializa a tabela hash
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_hash[i].ocupado = 0;
    }

    // Adiciona produtos
    inserir_produto(1, "Arroz", 5.50, 100);
    inserir_produto(2, "Feijao", 7.80, 50);
    inserir_produto(3, "Macarrao", 4.30, 30);

    // Adiciona ao carrinho
    adicionar_ao_carrinho(1, 2);
    adicionar_ao_carrinho(2, 1);
    adicionar_ao_carrinho(4, 1); // Produto inexistente

    // Exibe o carrinho
    exibir_carrinho();

    return 0;
}
