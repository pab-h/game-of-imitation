/* 
* Segundo requirements.pdf, o máximo tamanho
* de uma string será 100
*/
#define MAX_STRING_LENGHT 100

#include <locale.h>
#include <stdio.h>
#include <string.h>

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

void teste() {
    char texto[] = "voce acertou";
    char textoCodificado[strlen(texto)];

    codificaTexto(texto, textoCodificado, 5);

    printf("Original: %s\n", texto);
    printf("Codificado: %s\n", textoCodificado);

    char textoDecodificado[strlen(texto)];

    decodificaTexto(textoCodificado, textoDecodificado, 5);

    printf("Decodificado: %s\n", textoDecodificado);
}

int main() {

    setlocale(LC_ALL, "");
    
    teste();

    return 0;
}