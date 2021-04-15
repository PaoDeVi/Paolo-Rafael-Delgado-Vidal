//Imprimir un string al revés
#include<iostream>
#include<string>

using namespace std;

void invertir(string &mensaje){
	int aux = mensaje.length()-1;
	for(int i=0;i<aux;i++){
		swap(mensaje[i],mensaje[aux]);
		aux--;
	}
}


int main(){
	string mensaje;
	cout<<"Escriba un mensaje: ";
	getline(cin,mensaje);
	
	cout<<"El mensaje es: "<<mensaje<<endl;;
	invertir(mensaje);
	cout<<"El mensaje invertido es: "<<mensaje;
	
}
