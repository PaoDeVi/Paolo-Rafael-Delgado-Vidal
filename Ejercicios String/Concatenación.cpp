//Concatenación de nombres y apellidos
#include<iostream>
#include<string>

using namespace std;
int main(){
	string pr_nombre;
	string pr_apellido;
	
	cout<<"Escriba su primer nombre: ";cin>>pr_nombre;
	cout<<"Escriba su primer apellido: ";cin>>pr_apellido;
	
	string nombre_completo(pr_nombre + " " + pr_apellido);
	
	cout<<"Su nombre completo es: "<<nombre_completo;
		
	return 0;
}

