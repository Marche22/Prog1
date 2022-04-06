#include <stdio.h>

int main(void){
	
	int rain=-1, sund=-1, e_day=-1;
	char a1,a2,a3;
	
	printf("\nRispondere alle domande SOLO con 'S' per sì o 'N' per no: ");
	
	printf("\nLe previsioni del tempo non sono buone e/o stamattina piove? (S/N) ");
	a1 = getchar();
	getchar();
	printf("\nE\' domenica? (S/N) ");
	a2 = getchar();
	getchar();
	printf("\nE\' un giorno pari? (S/N) ");
	a3 = getchar();
	getchar();
		
	if(a1=='S')
		rain = 1;
	if(a1=='N')
		rain = 0;
	if(a2=='S')
		sund = 1;
	if(a2=='N')
		sund = 0;
	if(a3=='S')
		e_day = 1;
	if(a3=='N')
		e_day = 0;
	
	if(rain<0 || sund<0 || e_day<0){
		printf("\nUna delle risposte inserite non e\' valida\n");
		return -1;
	}
	
	if(rain){
		if(sund)
			printf("\nIl signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un ombrello.\n");
		else
			printf("\nIl signor Pignolino oggi non e' uscito.\n");
	}
	else{
		if(sund)
			printf("\nIl signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un parasole.\n");
		else{
			if(e_day)
				printf("\nIl signor Pignolino oggi e' uscito per recarsi ai giardini pubblici. Ha portato con se' un libro.\n");
			else
				printf("\nIl signor Pignolino oggi e' uscito per recarsi al Caffe'. Ha portato con se' il suo diario.\n");
		}
	}
	
	return 0;
}
