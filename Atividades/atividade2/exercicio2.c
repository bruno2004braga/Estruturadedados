#include <stdio.h>

int main(int argc, char* argv[]){

    int v[4] = {5, 4, 8, 6}, min, max;
    min = v[0];
    max = v[0];

    for(int i = 0; i < 4; i++){
        if(v[i] < min){
            min = v[1];
        }
        if (v[i] > max){
            max = v[i];
        }
    }

    printf("O maior elemento da array ehh: %d\n", max);
    printf("O menor elemento da array ehh: %d", min);

    return 0;
}