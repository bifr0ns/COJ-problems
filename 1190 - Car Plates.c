#include <stdio.h>

int digitosm=1;
int digitosi=1;

int itslegal(char si[], int letras){
	if(letras==4)
		return 0;
	else if(letras>3){
		for(int i=0; i<5; i++)
			if(si[i]=='A' || si[i]=='C' || si[i]=='M' || si[i]=='I' || si[i]=='P')
				return 0;
	}
	return 1;
}

int sumar(char x, int digitos, int cual){
	if(x>=48 && x<=57){
		if(cual)
			digitosm = digitosm*10;
		else
			digitosi = digitosi*10;
		return ((int)(x-48))*digitos;
	}
	else{
		int numero=0;
		if(x=='B')
			x = x-1;
		else if(x>=68 && x<=72)
			x = x-2;
		else if(x>=74 && x<=76)
			x = x-3;
		else if(x=='O')
			x = x-4;
		else if(x>=81 && x<=90)
			x = x-5;
		numero = (int)(x-48);
		if(numero>=10){	
			if(cual)
				digitosm = digitosm*100;
			else
				digitosi = digitosi*100;
			int ayuda=0;
			ayuda = numero%10;
			ayuda = ayuda*digitos;
			digitos = digitos*10;
			numero = (numero/10)*digitos;
			numero = numero + ayuda;
			return numero;
		}
		else{
			if(cual)
				digitosm = digitosm*10;
			else
				digitosi = digitosi*10;
			return numero*digitos;
		}
	}
}

int same(char sm[], char si[], int letras, int c){
	int totalsm=0, totalsi=0;
	for(int i=0; i<letras; i++){
		if(si[i] < sm[i])
			return 0;
	}
	for(int i=6; i>=0; i--){
		totalsm = totalsm + sumar(sm[i], digitosm, 1);
		totalsi = totalsi + sumar(si[i], digitosi, 0);
	}
	if((totalsi - totalsm)<=c && (totalsi - totalsm)>0){
		return 1;
	}
	else{
		return 0;
	}


}

int fromoldtonew(){

}

int main(){
	char sm[7];
	char si[7];
	int c=0;
	scanf("%s %s %d", sm, si, &c);
	while(sm!='*' && si!='*' && c!=0){
		digitosm=1; digitosi=1;
		int letrassi=0, letrassm=0;
		for(int i=0; i<7; i++){
			if(si[i]>=65 && si[i]<=90)
				letrassi++;
			if(sm[i]>=65 && sm[i]<=90)
				letrassm++;
		}
		if(itslegal(si, letrassi)){
			if(letrassi==letrassm){
				if(same(sm, si, letrassm, c)){
					printf("Y\n");
					scanf("%s %s %d", sm, si, &c);
					continue;
				}
				else{
					printf("N\n");
					scanf("%s %s %d", sm, si, &c);
					continue;
				}
			}
			else if(letrassi>letrassm){
				fromoldtonew();
			}
		}
		else{
			printf("N\n");
			scanf("%s %s %d", sm, si, &c);
			continue;
		}
		
	}
	return 0;
}