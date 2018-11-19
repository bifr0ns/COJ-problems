#include <stdio.h>

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

double valor(char s[], int letras){
	double mult = 0, v=0, mult2 = 0, v2 = 0, numero=0;
	if(letras == 3){
		mult2 = 1000;
		mult = 10000;
		v = ((double) s[0]-65) * 676;
		v = v + (((double) s[1]-65) * 26);
		v = v + ((double) s[2]-64);
		v = v * mult;
	}
	else if(letras == 5){
		mult = 100;
		mult2 = 10;
		double otromulti = 194481;
		for(int i=0; i<letras; i++){
			numero =(double) s[i]-64;
			if(s[i]=='B')
				numero = numero-1;
			else if(s[i]>=68 && s[i]<=72)
				numero = numero-2;
			else if(s[i]>=74 && s[i]<=76)
				numero = numero-3;
			else if(s[i]>=78 && s[i]<=79)
				numero = numero-4;
			else if(s[i]>=81 && s[i]<=90)
				numero = numero-5;

			if(i < 4){
				numero--;
				v = v + (numero * otromulti);
				otromulti = otromulti / 21;
			}
			else{
				v = v + numero;
			}
		}

		v = v * mult;
		v = v + 175770000 - 100;
	}

	for(int i=letras; i<7; i++){
		v2 = v2 + ((double) (s[i]-48))*mult2;
		mult2 = mult2 / 10;
	}
	v = v + v2;
	return v;
}

int main(){
	char sm[10];
	char si[10];
	int c=0;
	double valorsm, valorsi;
	scanf("%s %s %d", sm, si, &c);
	while(c!=0){
		int letrassi=0, letrassm=0;
		for(int i=0; i<7; i++){
			if(si[i]>=65 && si[i]<=90)
				letrassi++;
			if(sm[i]>=65 && sm[i]<=90)
				letrassm++;
		}
		if(itslegal(si, letrassi)==1){
			valorsm = valor(sm, letrassm);
			valorsi = valor(si, letrassi);
		//	printf("%s %.0lf %s %.0lf\n", sm, valorsm, si, valorsi);
			double diferencia = (valorsi - valorsm);
			//printf("%lf\n", diferencia);
			if(diferencia==0 || diferencia<0){
				printf("N\n");
				scanf("%s %s %d", sm, si, &c);
				continue;
			}
			else if(diferencia>0 && diferencia<=c){
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
		else{
			printf("N\n");
			scanf("%s %s %d", sm, si, &c);
			continue;
		}
		
	}
	return 0;
}