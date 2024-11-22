#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

struct Livro {
    int id;
    char titulo[100];
    char autor[50];
    char genero[30];
    int ano_publicacao;
    int disponivel;
};

struct Livro livros[MAX];
int qtdLivros = 0;

void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void criarLivro() {
    if (qtdLivros >= MAX) {
        printf("Lim�te m�ximo de livros alcan�ado\n");
        return;
    }
    
    printf("Informe o ID do livro: ");
    scanf("%d", &livros[qtdLivros].id);
    getchar();

    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].id == livros[qtdLivros].id) {
            printf("Inv�lido: ID j� existe\n");
            return;
        }
    }

    printf("Informe o t�tulo do livro: ");
    fgets(livros[qtdLivros].titulo, sizeof(livros[qtdLivros].titulo), stdin);
    removerNovaLinha(livros[qtdLivros].titulo);

    printf("Informe o autor do livro: ");
    fgets(livros[qtdLivros].autor, sizeof(livros[qtdLivros].autor), stdin);
    removerNovaLinha(livros[qtdLivros].autor);

    printf("Informe o g�nero do livro: ");
    fgets(livros[qtdLivros].genero, sizeof(livros[qtdLivros].genero), stdin);
    removerNovaLinha(livros[qtdLivros].genero);

    printf("Informe o ano de publica��o do livro: ");
    scanf("%d", &livros[qtdLivros].ano_publicacao);

    do {
        printf("Informe se o livro est� dispon�vel (0 para indispon�vel e 1 para dispon�vel): ");
        scanf("%d", &livros[qtdLivros].disponivel);
    } while (livros[qtdLivros].disponivel != 0 && livros[qtdLivros].disponivel != 1);
    
    qtdLivros++;
    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros() {
    if (qtdLivros == 0) {
        printf("Nenhum livro est� cadastrado\n");
        return;
    }
    
    for (int i = 0; i < qtdLivros; i++) {
        printf("Livro %d\n", i + 1);
        printf("ID: %d\n", livros[i].id);
        printf("T�tulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("G�nero: %s\n", livros[i].genero);
        printf("Ano de publica��o: %d\n", livros[i].ano_publicacao);
        
        if (livros[i].disponivel == 1) {
            printf("Disponibilidade: Dispon�vel\n");
        } else {
            printf("Disponibilidade: Indispon�vel\n");
        }
        printf("------------------------------\n");
    }
}

void atualizarLivro() {
    int id, encontrado = 0;
    
    printf("Informe o ID do livro ser� atualizado: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].id == id) {
            encontrado = 1;

            printf("Informe o novo t�tulo do livro: ");
            fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
            removerNovaLinha(livros[i].titulo);

            printf("Informe o novo autor do livro: ");
            fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
            removerNovaLinha(livros[i].autor);

            printf("Informe o novo g�nero do livro: ");
            fgets(livros[i].genero, sizeof(livros[i].genero), stdin);
            removerNovaLinha(livros[i].genero);

            printf("Informe o novo ano de publica��o do livro: ");
            scanf("%d", &livros[i].ano_publicacao);

            do {
                printf("Informe se o livro est� dispon�vel (0 para indispon�vel e 1 para dispon�vel): ");
                scanf("%d", &livros[i].disponivel);
            } while (livros[i].disponivel != 0 && livros[i].disponivel != 1);

            printf("Livro atualizado com sucesso!\n");
            break;
        }
    }
    
    if (encontrado != 1) {
        printf("Livro n�o encontrado\n");
    }
}

void excluirLivro() { 
    int id;

    printf("Digite o ID do livro a ser exclu�do: ");
    scanf("%d", &id);
    
    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].id == id) {
            for (int j = i; j < qtdLivros - 1; j++) {
                livros[j] = livros[j + 1];
            }
            qtdLivros--;
            printf("Livro exclu�do com sucesso!\n");
            return;
        }
    }
    printf("Livro n�o encontrado\n");
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        printf("\nSistema de cadastro de livros\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Atualizar livro\n");
        printf("4. Excluir Livro\n");
        printf("5. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nCadastro do livro\n");
            criarLivro();
            break;
        case 2:
            printf("\nListagem dos livros\n");
            listarLivros();
            break;
        case 3:
            printf("\nAtualiza��o do livro\n");
            atualizarLivro();
            break;
        case 4:
            printf("\nRemo��o do livro\n");
            excluirLivro();
            break;
        case 5:
            printf("Finalizando o programa...\n");
            break;
        default:
            printf("\nN�mero inv�lido, digite somente 1 at� 5\n");
            break;
        }
    } while (opcao != 5);
}