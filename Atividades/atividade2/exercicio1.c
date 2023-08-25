#include <stdio.h>

int main(int argc, char* argv[]){

    int v[4] = {8, 9, 5, 4}, a = 0, b = 0;

    for(int i = 0; i < 4; i++){
        b = v[i] + a;
        a = b;
    }

    printf("A soma dos elementos da array ehh %d", b);

    return 0;
}