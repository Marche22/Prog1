#include <stdio.h>
#include <string.h>

int maschio(int);
int femmina(int);

int main(void){

    int num;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &num);
    } while(num<0);

    printf("\nI primi %d-esimi numeri delle sequenze maschio-femmina di Hofstadter sono:\n", num+1);
    printf("\n\tn\tF(n)\tM(n)\n");
    for(int i=0; i<=num; i++)
        printf("\t%d\t%d\t%d\n", i, femmina(i), maschio(i));

    return 0;
}

int femmina(int n){
    if(!n)
        return 1;
    else
        return n-maschio(femmina(n-1));
}

int maschio(int n){
    if(!n)
        return 0;
    else
        return n-femmina(maschio(n-1));
}
