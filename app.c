/* 
* Segundo requirements.pdf, o máximo tamanho
* de uma string será 100
*/
#define MAX_STRING_LENGHT 100

#include <stdio.h>

void print_menu() {
    printf("---\n");
    printf("Um menu bem foda aqui!\n");
    printf("---\n");
}

int main() {

    print_menu();

    printf("O tamanho máximo da string será %d\n", MAX_STRING_LENGHT);

    return 0;
}