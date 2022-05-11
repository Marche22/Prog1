#include <stdio.h>
#include <string.h>

int fatt(int);
int binom(int, int);
int bell(int);

int main(void){

    int num;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &num);
    } while(num<0);

    printf("Il %d-esimo numero di Bell e\': %d\n", num, bell(num));

    return 0;
}

int fatt(int n){
    if(!n)
        return 1;
    else
        return n*fatt(n-1);
}

int binom(int n, int k){
    return fatt(n)/(fatt(k)*fatt(n-k));
}

int bell(int n){
    int temp = 0;
    if(!n)
        return 1;
    else{
        for(int k=0; k<n; k++)
            temp+=(binom(n-1,k)*bell(k));
        return temp;
    }
}
