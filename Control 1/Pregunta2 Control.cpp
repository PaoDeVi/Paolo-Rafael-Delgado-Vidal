#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;


int main(){
	string numero;
	int num;
	cout<<"Ingrese un numero: ";cin>>numero;
	cout<<"El número en texto es: "<<numero<<endl;
	
	num = atoi(numero.c_str());
	cout<<"El numero convertido a entero es: "<<num<<endl;
	cout<<"Por lo tanto, "<<num<<" sumado a 100 da "<<num+100<<endl;

	string nuevo_numero = to_string(num);
	cout<<"El numero convertido a string es: "<<nuevo_numero<<endl;
	cout<<"Por lo tanto, "<<nuevo_numero<<" puede concatenarse "<<nuevo_numero +" ahora es una cadena"<<endl;
	
}
