/* 
* Segundo requirements.pdf, o máximo tamanho
* de uma string será 100
*/
#define TAMANHO_MAXIMO_STRING 100

#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

    if (validaTexto(texto)) {
        printf("O texto \"%s\" é válido!\n", texto);
    } else {
        printf("O texto \"%s\" não é válido!\n", texto);

        return 1; 
    }

    char textoCodificado[TAMANHO_MAXIMO_STRING];

    codificaTexto(texto, textoCodificado, 5);

    printf("O texto original é \"%s\"\n", texto);
    printf("O texto codificado é \"%s\"\n", textoCodificado);

    return 0;
}

int main() {

    setlocale(LC_ALL, "");
    
    return teste();
}