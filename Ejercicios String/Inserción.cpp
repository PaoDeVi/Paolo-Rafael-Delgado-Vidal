//Insertar "******" en la mitad de un string
#include<iostream>
#include<string>

using namespace std;

int main(){
	string mensaje;
	cout<<"Escriba un mensaje: ";
	getline(cin,mensaje);
	
	cout<<"El mensaje es: "<<mensaje;
	
	mensaje.insert((mensaje.size()/2),"******");
	
	cout<<"El mensaje con * es: "<<mensaje;
}
