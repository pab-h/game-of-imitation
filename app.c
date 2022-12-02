#define TAMANHO_MAXIMO_STRING 100
#define TAMANHO_MAXIMO_DESLOCAMENTO 26
#define ARQUIVO_RESULTADOS "./resultados.txt"
#define QUANTIDADE_ESCOLHAS 3

#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validaDeslocamento(int deslocamento) {
    return deslocamento >= 1 && deslocamento <= TAMANHO_MAXIMO_DESLOCAMENTO;
}

int validaTexto(char *texto) {

    while (*texto != '\0') {

        if (!isalpha(*texto) && !isspace(*texto)) {
            return 0;
        }

        texto++;

    }

    return 1;
}

int validaEscolha(char escolha, char *escolhasValidas) {
    int i = 0;

    while (i < QUANTIDADE_ESCOLHAS) {
        if (escolha == *escolhasValidas) {
            return 1;
        }

        escolhasValidas++;
        i++;

    }

    return 0;
}

void salvaResultado(char *texto, char *textoCodificado, const int deslocamento) {
    FILE *arquivo;

    arquivo = fopen(ARQUIVO_RESULTADOS, "a");
    
    if (arquivo == NULL) {
        arquivo = fopen(ARQUIVO_RESULTADOS, "w");

    }

    fputs("Texto original: ", arquivo);
    fputs(texto, arquivo);
    fputs("\n", arquivo);

    fputs("Texto codificado: ", arquivo);
    fputs(textoCodificado, arquivo);
    fputs("\n", arquivo);

    fputs("Chave: ", arquivo);
    char chave[2]; 
    snprintf(chave, 3, "%d", deslocamento);
    fputs(chave, arquivo);
    fputs("\n", arquivo);

    fputs("+++++++++++++++++++++\n", arquivo);

    fclose(arquivo);

}

void caixaBaixaTexto(char *texto) {

    while (*texto != '\0') {
        *texto = tolower(*texto);

        texto++;

    }

}

void codificaTexto(char *texto, char *textoCodificado, const int deslocamento) {

    while (*texto != '\0') {
        *textoCodificado = *texto + deslocamento;

        texto++;
        textoCodificado++;

    }

    *textoCodificado = '\0';

}

void decodificaTexto(char *textoCodificado, char *texto, const int deslocamento) {

    while (*textoCodificado != '\0') {
        *texto = *textoCodificado - deslocamento;

        texto++;
        textoCodificado++;

    }

    *texto = '\0';

}

void mostraMenu() {
    printf("======MENU======\n");

    printf("A. Codificar string com deslocamento;\n");
    printf("B. Decodificar string com deslocamento;\n");
    printf("C. Sair;\n");

    printf("================\n\n");

}

void mostraAjuda() {
    printf("======AJUDA======\n");
    printf("Lembre-se: O deslocamento deve estar entre 1 e 26;\n");
    printf("Lembre-se: Os textos pedidos devem ter no máximo 100 caracteres;\n");
    printf("Lembre-se: O texto a ser codificado deve ter somente letras e espaço;\n");
    printf("Lembre-se: O texto a ser codificado será convertido para caixa baixa;\n");
    printf("=================\n\n");

}

void loop() {
    char escolha;
    char escolhasValidas[QUANTIDADE_ESCOLHAS] = { 'a', 'b', 'c' };
    char texto[TAMANHO_MAXIMO_STRING + 1];
    char textoCodificado[TAMANHO_MAXIMO_STRING + 1];
    int deslocamento;

    while (1) {
        mostraMenu();

        printf("Digite a sua escolha: \n>>>");
        scanf(" %c", &escolha);
        fgetc(stdin);
        escolha = tolower(escolha);

        if (!validaEscolha(escolha, escolhasValidas)) {
            printf("[Erro] A escolha \"%c\" não é válida!\n", escolha);

            continue;
        }

        if (escolha == 'c') {
            break;
        }

        if (escolha == 'a') {
            printf("Digite um texto para codificar:\n>>>");
            fgets(texto, TAMANHO_MAXIMO_STRING, stdin);
            texto[strlen(texto) - 1] = 0;

            if (!validaTexto(texto)) {
                printf("[Erro] O texto \"%s\" não é válido!\n", texto);
                mostraAjuda();

                continue;
            }

            caixaBaixaTexto(texto);

            printf("Digite o deslocamento:\n>>>");
            scanf("%d", &deslocamento);
            fgetc(stdin);

            if (!validaDeslocamento(deslocamento)) {
                printf("[Erro] O deslocamento \"%d\" não é válido!\n", deslocamento);
                mostraAjuda();

                continue;
            }

            codificaTexto(texto, textoCodificado, deslocamento);

        }

        if (escolha == 'b') {
            printf("Digite o texto codificado:\n>>>");
            fgets(textoCodificado, TAMANHO_MAXIMO_STRING, stdin);
            textoCodificado[strlen(textoCodificado) - 1] = 0;

            printf("Digite o deslocamento:\n>>>");
            scanf("%d", &deslocamento);
            fgetc(stdin);

            if (!validaDeslocamento(deslocamento)) {
                printf("[Erro] O deslocamento \"%d\" não é válido!\n", deslocamento);
                mostraAjuda();

                continue;
            }
            
            decodificaTexto(textoCodificado, texto, deslocamento);

        }

        salvaResultado(texto, textoCodificado, deslocamento);

        printf("----Resultado----\n");
        printf("Texto original: %s\n", texto);
        printf("Texto codificado: %s\n", textoCodificado);
        printf("Deslocamento: %d\n", deslocamento);
        printf("Obs: Os resultados foram gravados em %s\n", ARQUIVO_RESULTADOS);
        printf("-----------------\n");

        memset(texto, 0, TAMANHO_MAXIMO_STRING);
        memset(textoCodificado, 0, TAMANHO_MAXIMO_STRING);

    }

}

int main() {
    setlocale(LC_ALL, "");
    
    loop();

    return 1;
}