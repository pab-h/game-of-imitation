/* 
* Segundo requirements.pdf, o máximo tamanho
* de uma string será 100
*/
#define TAMANHO_MAXIMO_STRING 100
#define TAMANHO_MAXIMO_DESLOCAMENTO 26
#define ARQUIVO_RESULTADOS "./resultados.txt"

#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

int validaDeslocamento(int deslocamento) {
    return deslocamento >= 1 && deslocamento <= TAMANHO_MAXIMO_DESLOCAMENTO;
}

void caixaBaixaTexto(char *texto) {

    while (*texto != '\0') {
        *texto = tolower(*texto);

        texto++;
    }

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

void menu() {
    printf("======MENU======\n");

    printf("A. Codificar string com chave;\n");
    printf("B. Decodificar string com chave;\n");
    printf("C. Sair;\n");

    printf("================\n");

}

void loop() {
    char escolha;
    char texto[TAMANHO_MAXIMO_STRING];
    char textoCodificado[TAMANHO_MAXIMO_STRING];
    int deslocamento;

    do {

        menu();

        printf("Digite a sua escolha: \n>>>");
        scanf(" %c", &escolha);
        fflush(stdin);
        escolha = tolower(escolha);

        if (escolha == 'a') {
            printf("Digite um texto para codificar:\n>>>");
            scanf(" %s", texto);
            fflush(stdin);
        
            printf("Digite o deslocamento:\n>>>");
            scanf(" %d", &deslocamento);
            fflush(stdin);
        }
        
    } while (escolha != 'c');
}

int teste() {

    loop();

    return 0;
}

int main() {

    setlocale(LC_ALL, "");
    
    return teste();
}