#include <iostream>
#include <string>

using namespace std;

class rail_fence{
	private:
		int clave;
		
		
	public:
		
		rail_fence(int c){
			clave = c;
		}
		
		void cifrar(string &mensaje){
			int salto1 = clave*2 - 2;
			int salto2 = 0;
			int cambio = 1;
			
			string encrypted ;

			while(mensaje.size() % salto1 != 0){
				mensaje = mensaje + ' ';
			}
			
			
			for(int i = 0;i<clave;i++){
		
				if(salto2 == 0){
					for(int j = i;j < mensaje.size(); j = j + salto1){
						encrypted = encrypted + mensaje[j];
					}
				}
				
				else if(salto1 == 0){
					for(int k = i;k<mensaje.size();k = k+salto2){
						encrypted = encrypted + mensaje[k];
					}
				}
				
				else{
					int h = i;
					while(h < mensaje.size()){
						encrypted = encrypted + mensaje[h];
						if(cambio % 2 != 0){
							h = h + salto1;
						}
						else{
							h = h + salto2;
						}
						cambio++;	
						}
					}
				
					salto1 = salto1 - 2;
					salto2 = salto2 + 2;
				}
				
				mensaje = encrypted;	
		}
		
		void descifrar(string &mensaje){
			int aux = 0;
			int y[clave];
			int x[clave];	
			string railes[clave];
				
			for(int i=0;i<clave;i++){
				x[i]=0;
				y[i]=0;
			}
					
					
			while(aux!=mensaje.size()){	
				for(int i=0;i<clave;i++){
						aux++;
						x[i]++;
					}
						
				for(int i=clave-2;i>0;i--){
					aux++;
					x[i]++;
				}
					
			}
				
			aux=0;
				
			for(int i=0;i<clave;i++){
				for(int j=0;j<x[i];j++){
					railes[i][j] = mensaje[aux];
					aux++;	
				}
			}
				
			aux = 0;
				
			while(aux!=mensaje.size()){
				for(int i=0;i<clave;i++){
					mensaje[aux] = railes[i][y[i]];
					aux++;
					y[i]++;
				}
				
				for(int i=clave-2;i>0;i--){
					mensaje[aux] = railes[i][y[i]];
					aux++;
					y[i]++;
					}
				}
		}
		
		
};



int main(){
	int c;
 	string mensaje;
 		
 	cout<<"Escriba un mensaje: ";
	getline(cin,mensaje);
	cout<<"Ingrese la clave: "; cin>> c;
	
	rail_fence emisor(c);
	rail_fence receptor(c);
	
	cout<<"El mensaje es: "<<mensaje<<endl;
	emisor.cifrar(mensaje);
	cout<<"El mensaje cifrado es: "<<mensaje<<endl;
	receptor.descifrar(mensaje);
	cout<<"El mensaje descifrado es: "<<mensaje<<endl;
		
		
	return 0;
}
