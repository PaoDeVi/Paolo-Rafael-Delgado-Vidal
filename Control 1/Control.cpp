//COntrol
#include<iostream>
#include<string>

using namespace std;
//Pregunta 1g
void imprimir_vector(string tokens[],int n){
	for(int k=0;k<n;k++){
		cout<<tokens[k]<<" ";
	}
	cout<<endl;
}

//Pregunta 1e
string guardar_en_string(string token[],int n,int clave){
	string frase;
	int aux = 0;
	for(int i=0;i<n;i++){
		frase = frase + token[i];
		frase.insert(frase.end(),'*');
	}
	return frase;
}


void dividir_en_bloques(string mensaje, int clave){
	int aux=0,aux2=0;
	//completa los carácteres faltantes con X Pregunta 1d
	while(mensaje.length()%clave != 0){
		mensaje.resize(mensaje.size()+1,'X');
	}
	//Imprime los bloques indivuales y lo divide en palabras de n caracteres
	for(int i=0;i<mensaje.length()/clave;i++){
		for(int j=0;j<clave;j++){
			cout<<mensaje[aux2];
			aux2++;
		}
		cout<<endl;
	}
	
	string tokens[mensaje.length()/clave];
	// Pregunta 1f
	for(int i=0;i<mensaje.length()/clave;i++){
		for(int j=0;j<clave;j++){
			tokens[i] = tokens[i] + (mensaje[aux]);
			aux++;
		}
	}
	//Imprime las partes pregunta 1g y 1e
	cout<<"El vector es: ";
	imprimir_vector(tokens,mensaje.length()/clave);
	cout << "String con *: "<<guardar_en_string(tokens,mensaje.length()/clave,clave);
}

int main(){
	string mensaje;
	int clave;
	
	cout<<"Ingrese una linea de texto: ";
	getline(cin,mensaje);
	
	cout<<"Ingrese una clave: ";cin>>clave;
	
	dividir_en_bloques(mensaje,clave);
}
