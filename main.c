#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
    // Array para armazenar frequência [0] e primeira posição [1]
    // para cada caractere (a-z)
    int hash[26][2] = {0};  // Inicializa com zeros

    // Primeiro loop: preenche o hash com frequências e posições
    for(int i = 0; i < strlen(s); i++) {
        int idx = s[i] - 'a';  // Converte char para índice (0-25)

        if(hash[idx][0] == 0) {  // Se é primeira ocorrência
            hash[idx][1] = i;     // Guarda posição
        }
        hash[idx][0]++;          // Incrementa frequência
    }

    // Encontra o primeiro caractere que aparece apenas uma vez
    int firstPos = -1;
    for(int i = 0; i < strlen(s); i++) {
        int idx = s[i] - 'a';
        if(hash[idx][0] == 1) {  // Se frequência é 1
            return hash[idx][1];  // Retorna primeira posição
        }
    }

    return -1;  // Nenhum caractere único encontrado
}

int main() {
    char s[] = "leetcode";
    int result = firstUniqChar(s);
    printf("Primeira posicao unica: %d\n", result);
    return 0;
}