// Tamanho máximo da string definido pelo enunciado
#define TAMANHO_MAXIMO_STRING 100

// Tamanho máximo do deslocamento definido pelo enunciado
#define TAMANHO_MAXIMO_DESLOCAMENTO 26

// Caminho para o arquivo de resultados
#define ARQUIVO_RESULTADOS "./resultados.txt"

// Quantidade de escolhas no menu
#define QUANTIDADE_ESCOLHAS 3

// Bibliotecas necessárias
#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Verifica se desclocamento está ente 1 e 26
int validaDeslocamento(int deslocamento) {
    return deslocamento >= 1 && deslocamento <= TAMANHO_MAXIMO_DESLOCAMENTO;
}

// Verifica, de acordo com o pedido, se texto passado pelo usuário 
int validaTexto(char *texto) {

    while (*texto != '\0') {

        if (!isalpha(*texto) && !isspace(*texto)) {
            return 0;
        }

        texto++;

    }

    return 1;
}

// Verifica se a escolha está entre as escolhas válidas
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

// Salva os resultados após um processo
// Salva no formato:
// Texto original: <string>
// Texto codificado: <string>
// Chave: <int>
// +++++++++++++++++++++
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

// Torna o texto passado todo em caixa baixa
void caixaBaixaTexto(char *texto) {

    while (*texto != '\0') {
        *texto = tolower(*texto);

        texto++;

    }

}

// Codifica o texto passado deslocando, no sentido positivo, pela tabela ascii, cada caractere do texto   
void codificaTexto(char *texto, char *textoCodificado, const int deslocamento) {

    while (*texto != '\0') {
        *textoCodificado = *texto + deslocamento;

        texto++;
        textoCodificado++;

    }

    *textoCodificado = '\0';

}

// Decodifica o texto passado deslocando, no sentido negativo, pela tabela ascii, cada caractere do texto
void decodificaTexto(char *textoCodificado, char *texto, const int deslocamento) {

    while (*textoCodificado != '\0') {
        *texto = *textoCodificado - deslocamento;

        texto++;
        textoCodificado++;

    }

    *texto = '\0';

}

// Mostra o menu formatado
void mostraMenu() {
    printf("======MENU======\n");

    printf("A. Codificar string com deslocamento;\n");
    printf("B. Decodificar string com deslocamento;\n");
    printf("C. Sair;\n");

    printf("================\n\n");

}

// Mostra um menu formatado de ajuda
void mostraAjuda() {
    printf("======AJUDA======\n");
    printf("Lembre-se: O deslocamento deve estar entre 1 e 26;\n");
    printf("Lembre-se: Os textos pedidos devem ter no máximo 100 caracteres;\n");
    printf("Lembre-se: O texto a ser codificado deve ter somente letras e espaço;\n");
    printf("Lembre-se: O texto a ser codificado será convertido para caixa baixa;\n");
    printf("=================\n\n");

}

// Loop do sistema 
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
        fgetc(stdin); // Resolve o bug da leitura fantasma
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
            texto[strlen(texto) - 1] = 0; // Retira-se o \n 

            if (!validaTexto(texto)) {
                printf("[Erro] O texto \"%s\" não é válido!\n", texto);
                mostraAjuda();

                continue;
            }

            caixaBaixaTexto(texto);

            printf("Digite o deslocamento:\n>>>");
            scanf("%d", &deslocamento);
            fgetc(stdin); // Resolve o bug da leitura fantasma

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
            textoCodificado[strlen(textoCodificado) - 1] = 0; // Retira-se o \n 

            printf("Digite o deslocamento:\n>>>");
            scanf("%d", &deslocamento);
            fgetc(stdin); // Resolve o bug da leitura fantasma

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

        // Limpa os textos para evitar erros
        memset(texto, 0, TAMANHO_MAXIMO_STRING);
        memset(textoCodificado, 0, TAMANHO_MAXIMO_STRING);

    }

}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    loop();

    return 1;
}