#include <stdio.h>

int main(int argc, char* argv[]){

    int v[8] = {5, 7, 9, 6, 7, 11, 6, 5}, a, b = 0;

    printf("Digite o número inteiro que deseja procurar: ");
    scanf("%d", &a);

    for(int i = 0; i < 8; i++){
        if(v[i] == a){
            b++;
        }
}

    printf("O número %d aparece: %d vezes no array",a , b);

    return 0;
}