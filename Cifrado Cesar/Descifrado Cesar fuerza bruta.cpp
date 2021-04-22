//Algoritmo de César - Descifrado en fuerza bruta
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
		
string descifrar(string mensaje, int clave, string alfabeto){
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
				}
			}
		}
	return cifrado;
	}

void ordenar_palabras(string arr[], int n)
{ 
    int mayor; 
    for (int i = 0; i < n-1; i++) 
    { 
        mayor = i; 
        for (int j = i+1; j < n; j++){
        	if (arr[j].size()>arr[mayor].size()){
        		mayor = j;
			}	 	
		}
        arr[mayor].swap(arr[i]); 
    } 
}
///Imprime los descifrados hasta un limite de n claves
void prueba_y_error(string cifrado,int limite,string alfabeto){
	string descifrado[limite];
	int resp;
	for(int clave=1;clave<limite;clave++){
		descifrado[clave]=descifrado[clave] + descifrar(cifrado,clave,alfabeto);
	}
	
	for(int i=1;i<limite;i++){
		cout<<"Con clave "<<i<<" es "<<descifrado[i]<<endl;
	}
	cout<<"Ingrese el número de clave del descifrado que considere correcto: ";cin>>resp;
	cout<<"El mensaje descifrado es: "<<descifrado[resp]<<" con la clave "<<resp<<endl;
}
//compara un diccionario de palabras con un descifrdo de clave n buscando semejanzas/coherencias
void semejanza_de_cadena(string cifrado,int limite,string alfabeto){
	int cantf, aux;
	string descifrado;
	cout<<"Ingrese la cantidad de posibles palabras a encontrar: ";cin>>cantf;
	string diccionario[cantf];
	
	for(int i=0;i<cantf;i++){
		cout<<"Ingrese una posible palabra a encontrar: ";cin>>diccionario[i];
	}
	
	ordenar_palabras(diccionario,cantf);

	for(int clave=1;clave<limite;clave++){
		descifrado = descifrar(cifrado,clave,alfabeto);
		for(int j=0;j<cantf;j++){
			aux = descifrado.rfind(diccionario[j]);
			if(aux!=descifrado.npos){
				cout<<"El mensaje descifrado es: "<<descifrado<<" con la clave "<<clave<<endl;
				return;
			}
		}
	}
	
	cout<<"No se encontro una semejanza con las palabras dadas, intente de nuevo"<<endl;
}

int main(){
	string alfabeto = "abcdefghijklmnopqrstuvwxyz";
	string cifrado = "lspe gsqs iwxer xshsw";
	prueba_y_error(cifrado,5,alfabeto);
	semejanza_de_cadena(cifrado,5,alfabeto);
	return 0;
}
		
	
