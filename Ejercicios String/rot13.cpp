//Cifrado rot13
#include<iostream>
#include<string>

using namespace std;

int division(int a, int n){
		
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

void rot13_cifrado(string alfabeto, string &mensaje, int clave){
	string cifrado;
	int aux, res;
	char aux2;
	
	for(int i=0;i<mensaje.size();i++){
		if(mensaje[i]== ' '){
			cifrado = cifrado + " ";	
		}
		else{
			aux = alfabeto.find(mensaje[i]);
			if(aux != alfabeto.npos){
				if((aux+clave)>=alfabeto.size()){
					res = division((aux+clave),alfabeto.size());
					cifrado = cifrado + alfabeto[res];
				}
				else{
					cifrado = cifrado + alfabeto[aux+clave];
				}
			}
			else{
				if(alfabeto.find(toupper(mensaje[i])) != alfabeto.npos){
					aux = alfabeto.find(toupper(mensaje[i]));
					if((aux+clave)>=alfabeto.size()){
						res = division((aux+clave),alfabeto.size());
						aux2 = tolower(alfabeto[res]);
						cifrado = cifrado + aux2;
					}
					else{
						aux2 = tolower(alfabeto[aux+clave]);
						cifrado = cifrado + aux2;
					}
				}
			}
		}
	}
	mensaje = cifrado;
}

void rot13_descifrado(string alfabeto, string &mensaje, int clave){
	string cifrado;
	int aux, res;
	char aux2;
	for(int i=0;i<mensaje.size();i++){
		if(mensaje[i]== ' '){
				cifrado = cifrado + " ";	
			}
			else{
				aux = alfabeto.find(mensaje[i]);
				if(aux != alfabeto.npos){
					if((aux-clave)<0){
						res = aux+alfabeto.size()-clave;
						cifrado = cifrado + alfabeto[res];
					}
					else{
						cifrado = cifrado + alfabeto[aux-clave];
					}
				}
				else{
					if(alfabeto.find(toupper(mensaje[i])) != alfabeto.npos){
						aux = alfabeto.find(toupper(mensaje[i]));
						if((aux-clave)<0){
							res = aux + alfabeto.size() - clave;
							aux2 = tolower(alfabeto[res]);
							cifrado = cifrado + aux2;
						}
						else{
							aux2 = tolower(alfabeto[aux-clave]);
							cifrado = cifrado + aux2;
						}
					}
				}
			}
		}
	mensaje = cifrado;
}

int main(){
	string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string mensaje;
	int clave; 
	
	cout<<"Ingrese un mensaje/palabra: ";
	getline(cin,mensaje);
	
	cout<<"Ingrese una clave: ";cin>>clave;
	
	rot13_cifrado(alfabeto,mensaje,clave);
	cout<<"El mensaje/palabra cifrado es: "<<mensaje<<endl;
	rot13_descifrado(alfabeto,mensaje,clave);
	cout<<"El mensaje/palabra descifrado es: "<<mensaje<<endl;
	
}
