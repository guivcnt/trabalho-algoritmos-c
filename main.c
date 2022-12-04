#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PALAVRA_SIZE 20


typedef struct Frequencia {
    char palavra[MAX_PALAVRA_SIZE];
    int frequencia;
};

typedef struct Palavra {
    char palavra[MAX_PALAVRA_SIZE];
    int index;
};

int find(char * palavra, struct Palavra palavraLookup[], int len){
    for (int i = 0; i < len; ++i) {
        if(!strcmp(palavra, palavraLookup[i].palavra)){
            return palavraLookup[i].index;
        }
    }
    return -1;
}


int main() {
    char nomeArquivo[100];
    printf( "Digite o nome do arquivo o qual deseja ler\n");
    scanf("%s", nomeArquivo);

    FILE * arquivoPtr = fopen(nomeArquivo,"r");
    if(arquivoPtr == NULL){
        printf("Nao foi possivel ler o arquivo, verifique o nome e tente novamente");
        return -1;
    }

    struct Palavra palavraLookup[20] = {NULL, 0};
    struct Frequencia frequenciaPalavra[200] = {NULL, 0};

    int sizearray;
    int i = 0;
    char palavra[MAX_PALAVRA_SIZE] = {0};
    while (fscanf(arquivoPtr, "%s", palavra) == 1) {
        int frequenciaPalavraIndex = find(palavra, palavraLookup, sizeof palavraLookup / sizeof palavraLookup[0]);
        if(frequenciaPalavraIndex == -1){
            frequenciaPalavra[i].frequencia = 1;
            strcpy(frequenciaPalavra[i].palavra,palavra);
            strcpy( palavraLookup[i].palavra,palavra);
            palavraLookup[i].index = i;
            i++;
            sizearray++;
            continue;
        }
        frequenciaPalavra[frequenciaPalavraIndex].frequencia += 1;
    }



    char palavraencontrada[10];
    char caracterBusca;
    int g;
    int v;
    struct Frequencia temp;

        int opcaoMenu;
        printf("1 - Consultar a quantidade de ocorrencias de uma determinada palavra no arquivo\n");
        printf("2 - Listar todas as palavras que constam no arquivo, bem como a quantidade de vezes que elas ocorrem, em ordem crescente de ocorrencia\n");
        printf("3 - Listar todas as palavras que constam no arquivo, bem como a quantidade de vezes que elas ocorrem, em ordem decrescente de ocorrencia\n");
        printf("4 - Listar todas as palavras que constam no arquivo, bem como a quantidade de vezes que elas ocorrem, em ordem alfabetica\n");
        printf("5 - Listar todas as palavras que constam no arquivo, e que iniciam por um caractere informado pelo usuario, bem como a quantidade de vezes que essas palavras ocorrem, em ordem crescente de ocorrencia\n");
        printf("6 - Encerrar o programa\n");

    while(true) {
        printf("\nSelecione a opcao desejada\n");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                printf("Digite a palavra a ser buscada \n");
                scanf("%s", palavraencontrada);
                for (int j = 0; j < sizearray; j++) {
                    if(isalpha(frequenciaPalavra[j].palavra[0]))
                    if (!strcmp(frequenciaPalavra[j].palavra, palavraencontrada)) {
                        printf("%d:%s\n", frequenciaPalavra[j].frequencia, frequenciaPalavra[j].palavra);
                        continue;
                    }
                }

                break;
            case 2:
                for (g = 0; g < sizearray - 1; g++) {
                    for (v = 0; v < (sizearray - 1 - g); v++) {
                        if (frequenciaPalavra[v].frequencia > frequenciaPalavra[v + 1].frequencia) {
                            temp = frequenciaPalavra[v];
                            frequenciaPalavra[v] = frequenciaPalavra[v + 1];
                            frequenciaPalavra[v + 1] = temp;
                        }
                    }
                }
                for (int j = 0; j < sizearray; j++) {
                    if(isalpha(frequenciaPalavra[j].palavra[0]))
                    printf("%d:%s\n", frequenciaPalavra[j].frequencia, frequenciaPalavra[j].palavra);
                }

                break;
            case 3:
                for (g = 0; g < sizearray - 1; g++) {
                    for (v = 0; v < (sizearray - 1 - g); v++) {
                        if (frequenciaPalavra[v].frequencia < frequenciaPalavra[v + 1].frequencia) {
                            temp = frequenciaPalavra[v];
                            frequenciaPalavra[v] = frequenciaPalavra[v + 1];
                            frequenciaPalavra[v + 1] = temp;
                        }
                    }
                }
                for (int j = 0; j < sizearray; j++) {
                    if(isalpha(frequenciaPalavra[j].palavra[0]))
                    printf("%d:%s\n", frequenciaPalavra[j].frequencia, frequenciaPalavra[j].palavra);
                }
                break;
            case 4:
                for (int w = 0; w < 13; w++) {
                    for (int i = 0; i <= 9; ++i) {
                        for (int k = 0; frequenciaPalavra[i].palavra[k] != '\0'; ++k) {
                            if ((frequenciaPalavra[i].palavra[k] > frequenciaPalavra[i + 1].palavra[k])) {
                                temp = frequenciaPalavra[i];
                                frequenciaPalavra[i] = frequenciaPalavra[i + 1];
                                frequenciaPalavra[i + 1] = temp;
                                break;
                            } else if ((frequenciaPalavra[i].palavra[k] < frequenciaPalavra[i + 1].palavra[k])) {
                                break;
                            }
                        }
                    }
                }
                for (int j = 0; j < sizearray; j++) {
                    if(isalpha(frequenciaPalavra[j].palavra[0]))
                    printf("%d:%s\n", frequenciaPalavra[j].frequencia, frequenciaPalavra[j].palavra);
                }
                break;
            case 5:
                printf("Digite o caracter a ser procurado \n");
                scanf(" %c", &caracterBusca);

                for (g = 0; g < sizearray - 1; g++) {
                    for (v = 0; v < (sizearray - 1 - g); v++) {
                        if (frequenciaPalavra[v].frequencia > frequenciaPalavra[v + 1].frequencia) {
                            temp = frequenciaPalavra[v];
                            frequenciaPalavra[v] = frequenciaPalavra[v + 1];
                            frequenciaPalavra[v + 1] = temp;
                        }
                    }
                }

                for (int j = 0; j < sizearray; ++j) {
                    if(isalpha(frequenciaPalavra[j].palavra[0]))
                    if (caracterBusca == frequenciaPalavra[j].palavra[0]) {
                        printf("%d:%s\n", frequenciaPalavra[j].frequencia, frequenciaPalavra[j]);

                    }
                }
                break;
            case 6:
                printf("Finalizando o programa.");
                return 1;
        }
    }
    }

