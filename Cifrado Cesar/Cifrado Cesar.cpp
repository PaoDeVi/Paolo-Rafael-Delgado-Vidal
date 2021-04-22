//Algoritmo de César
#include<iostream>
#include<string>

using namespace std;

class algoritmo_de_cesar{
	private:
		
		int clave;
		string alfabeto = "abcdefghijklmnopqrstuvwxyz";
		
	public:
		algoritmo_de_cesar(int clave){
			this-> clave = clave;
		}
		//Funcion Módulo Auxiliar
		
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
		
		//Función de cifrado
		void cifrar(string &mensaje){
			string cifrado;
			int aux;
			char aux2;
			
			for(int i=0;i<mensaje.size();i++){
				if(mensaje[i]== ' '){
					cifrado = cifrado + " ";	
				}
				else{
					aux = alfabeto.find(mensaje[i]);
					if(aux != alfabeto.npos){
						if((aux+clave)>=alfabeto.size()){
							cifrado = cifrado + alfabeto[division((aux+clave),alfabeto.size())];//Pos de la letra + Clave mod del tamaño del alfabeto
						}
						else{
							cifrado = cifrado + alfabeto[aux+clave];
						}
					}/*    ///Auxiliar para convertir, hallar y cifrar mayúsculas///
					else{
						if(alfabeto.find(tolower(mensaje[i])) != alfabeto.npos){
							aux = alfabeto.find(tolower(mensaje[i]));
							if((aux+clave)>=alfabeto.size()){
								res = division((aux+clave),alfabeto.size());  
								aux2 = toupper(alfabeto[res]);
								cifrado = cifrado + aux2;
							}
							else{
								aux2 = toupper(alfabeto[aux+clave]);
								cifrado = cifrado + aux2;
							}
						}
					}*/
				}
			}
			mensaje = cifrado;
		}
		
		void descifrar(string &mensaje){
			string cifrado;
			int aux;
			char aux2;
			
			for(int i=0;i<mensaje.size();i++){
				if(mensaje[i]== ' '){
						cifrado = cifrado + " ";	
					}
					else{
						aux = alfabeto.find(mensaje[i]);
						if(aux != alfabeto.npos){
							if((aux-clave)<0){ 
								cifrado = cifrado + alfabeto[division((aux-clave),alfabeto.size())]; //Pos de la letra - Clave mod del tamaño del alfabeto
							}
							else{
								cifrado = cifrado + alfabeto[aux-clave];
							}
						}/*    ///Auxiliar para convertir, hallar y cifrar mayúsculas///
						else{
							if(alfabeto.find(tolower(mensaje[i])) != alfabeto.npos){
								aux = alfabeto.find(toupper(mensaje[i]));
								if((aux-clave)<0){
									res = division((aux-clave),alfabeto.size()); //Pos de la letra + Clave mod del tamaño del alfabeto
									aux2 = toupper(alfabeto[res]);
									cifrado = cifrado + aux2;
								}
								else{
									aux2 = toupper(alfabeto[aux-clave]);
									cifrado = cifrado + aux2;
								}
							}
						}*/
					}
				}
			mensaje = cifrado;
		}
		
		
};	

int main(){
	int clave;
	string mensaje;
	
	cout<<"Ingrese un mensaje: ";
	getline(cin,mensaje);
	cout<<"Ingrese una clave: ";cin>>clave;
	
	algoritmo_de_cesar emisor(clave);
	algoritmo_de_cesar receptor(clave);
	
	emisor.cifrar(mensaje);
	cout<<"El mensaje cifrado es: "<<mensaje<<endl;
	receptor.descifrar(mensaje);
	cout<<"El mensaje descifrado es: "<<mensaje<<endl;
	
}
	
	

