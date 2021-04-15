//Reemplazar todos los signos de punteación por " " y usar strtok
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void reemplazar_sp(string &mensaje){
	string signos = ".,;:()!?";
	for(int i = 0;i<signos.size();i++){
		int posicion = mensaje.find(signos[i]);
		while (posicion != mensaje.npos){
 			mensaje.replace(posicion,1, " " );
  			posicion = mensaje.find(signos[i], posicion + 1 );
 		} 
	}
}


void tokens(string mensaje){
	char str[mensaje.size()];
	strcpy(str,mensaje.c_str());
	char *token = strtok(str, " ");
    while (token)
    {
        cout << token << endl;
        token = strtok(NULL," ");
    }
}

int main(){
	string mensaje;
	cout<<"Escriba un mensaje: ";
	getline(cin,mensaje);
	
	cout<<"El mensaje es: "<<mensaje<<endl;
	reemplazar_sp(mensaje);
	cout<<"El mensaje sin signos es: "<<mensaje<<endl;
	cout<<"Los tokens son: "<<endl;
	tokens(mensaje);
}
