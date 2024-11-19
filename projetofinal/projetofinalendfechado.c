#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

typedef struct Produto {
    int id;
    char nome[50];
    float preco;
    int estoque;
    struct Produto *proximo;
} Produto;

typedef struct {
    int id;
    int quantidade;
} ItemCarrinho;

Produto *tabela_hash[TAMANHO_TABELA];
ItemCarrinho carrinho[TAMANHO_TABELA];
int tamanho_carrinho = 0;

// Função hash simples
int hash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Insere produto na tabela hash
void inserir_produto(int id, const char *nome, float preco, int estoque) {
    int indice = hash(id);
    Produto *novo_produto = (Produto *)malloc(sizeof(Produto));
    novo_produto->id = id;
    strcpy(novo_produto->nome, nome);
    novo_produto->preco = preco;
    novo_produto->estoque = estoque;
    novo_produto->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo_produto;
    printf("Produto '%s' inserido com sucesso.\n", nome);
}

// Busca produto
Produto* buscar_produto(int id) {
    int indice = hash(id);
    Produto *atual = tabela_hash[indice];
    while (atual) {
        if (atual->id == id) return atual;
        atual = atual->proximo;
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

// Libera a memória usada pela tabela hash
void liberar_tabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Produto *atual = tabela_hash[i];
        while (atual) {
            Produto *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    // Inicializa a tabela hash
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_hash[i] = NULL;
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

    // Libera a memória
    liberar_tabela();

    return 0;
}
