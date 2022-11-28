/* 
* Segundo requirements.pdf, o máximo tamanho
* de uma string será 100
*/
#define TAMANHO_MAXIMO_STRING 100

#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

int teste() {
    char texto[TAMANHO_MAXIMO_STRING];

    printf("Digite um string para testar!\n>>>");
    fgets(texto, TAMANHO_MAXIMO_STRING, stdin);
    texto[strcspn(texto, "\n")] = 0;

    printf("Texto original: %s\n", texto);
    caixaBaixaTexto(texto);
    printf("Texto em caixa baixa: %s\n", texto);


    return 0;
}

int main() {

    setlocale(LC_ALL, "");
    
    return teste();
}