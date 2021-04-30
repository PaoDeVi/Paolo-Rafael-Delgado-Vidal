#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int division(int a, int n ){
		
		int q = a / n;
		int r = a - (q*n);
		
		if(r < 0 && n > 0){
			q = q - 1;
			r = a - (q*n);
		}
		else if(r < 0 && n < 0){
			q = q + 1;
			r = a - (q*n);
		}
		else{
			r = a - (q*n);
		}
		return r;
}

int algoritmo_de_euclides(int a, int b){
	if(a==0){
		return b;
	}
	else if(b==0){
		return a;
	}
	
	if(a<b){
		algoritmo_de_euclides(a,division(b,a));
	}
	else{
		algoritmo_de_euclides(b,division(a,b));
	}
	
}

int euclides_extendido(int a, int b) {

	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;
	int r, s, t;

	while (r2 > 0) {
		int q = r1 / r2;

		r = r1 - (q * r2);
		r1 = r2;
		r2 = r;

		s = s1 - (q * s2);
		s1 = s2;
		s2 = s;

		t = t1 - (q * t2);
		t1 = t2;
		t2 = t;
	}

	return s1;
}

int inversa(int a, int b){
	int inv = euclides_extendido(a,b);
	if(inv<0){
		inv = division(inv,b);
	}
	return inv;
}

int generador_de_claves(int a,int c){
	while(algoritmo_de_euclides(a,c) != 1){
		a = rand()%c;
	}
	return a;
}

