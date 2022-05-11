#include <stdio.h>
#include <string.h>

int delannoy(int n, int m);

int main(void){

    int n, m;

    do{
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
        printf("Inserisci un numero secondo intero maggiore o uguale a zero: ");
        scanf("%d", &m);
    } while(n<0 || m<0);

    printf("\nQuesti sono i numeri di Delannoy fino a %d;%d:\n\n", n,m);
    
    //segno con un@ le righe importanti, il resto serve tutto per scrivere bene la tabella
    for(int i=0; i<=n; i++){ //@
        if(!i){
            for(int j=0; j<=m; j++){
                if(!j)
                    printf(" n\\m");
                printf("\t%d",j);
            }
            printf("\n\n");
        }
        for(int j=0; j<=m; j++){ //@
            if(!j)
                printf(" %d\t",i);
            printf("%d\t", delannoy(i,j)); //@
        }
        printf("\n"); //@
    }

    return 0;
}

int delannoy(int n, int m){
    if (!n || !m){
        return 1;
    }
    else
        return delannoy(m-1,n)+delannoy(m,n-1)+delannoy(m-1,n-1);
}
