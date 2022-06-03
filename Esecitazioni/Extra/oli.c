#include <stdio.h>
#include <unistd.h>

int main(void){
    char* string = "OLI PIRLA";
    for(int k=0; k<100000; k++){
        for(int j=0; j<200; j++){
            for(int i=0; i<j; i++){
                printf(" ");
            }
            printf("%s\n", string);
            usleep(35000);
        }
    }
    return 0;
}
