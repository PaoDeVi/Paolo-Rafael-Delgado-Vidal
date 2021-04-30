#include<iostream>
#include<string>
#include "Funciones Algoritmo Afin.h"

using namespace std;

class afin{
	private:
		int a,b;
		string alfabeto="abcdefghijklmnopqrstuvwxyz";
	
	public:
		afin(){  //Constructor del emisor
			a = generador_de_claves(a,alfabeto.size());
			b = rand()%alfabeto.size();
		}
		afin(int x,int y){//Constructor del receptor
			a = inversa(x,alfabeto.size());
			b = y; 
		}
		
		int get_a(){return a;}
		int get_b(){return b;}
		
		void cifrar(string &mensaje){
			string cifrado;
			int aux;
			for(int i=0;i<mensaje.size();i++){
				aux = alfabeto.find(mensaje[i]);
				if(aux != alfabeto.npos){
					cifrado = cifrado + alfabeto[division(((aux*a)+b),alfabeto.size())];
				}
			}
			mensaje = cifrado;
		}
		
		void descifrar(string &mensaje){
			int aux;
			string cifrado;
			for(int i=0;i<mensaje.size();i++){
				aux = alfabeto.find(mensaje[i]);
				if(aux != alfabeto.npos){
					int resta = aux - b;
					if(resta<0){
						resta = division(resta,alfabeto.size());
					}
					cifrado = cifrado + alfabeto[division((a*resta),alfabeto.size())];
				}
			}
			mensaje = cifrado;
		}
};

int main(){
	string mensaje;
	cout<<"Ingrese un mensaje: ";
	getline(cin,mensaje);
	
	afin emisor;
	
	afin receptor(emisor.get_a(),emisor.get_b());
	
	emisor.cifrar(mensaje);
	cout<<"El mensaje cifrado es: "<<mensaje<<endl;
	receptor.descifrar(mensaje);
	cout<<"El mensaje descifrado es: "<<mensaje<<endl;
	
	
}



