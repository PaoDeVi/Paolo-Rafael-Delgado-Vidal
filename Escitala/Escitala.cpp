#include<iostream>
#include<string>


using namespace std;

 class escitala{
 	private:
 		int clave[2]={0,0};
 		
 	public:
 		escitala(int x,int y){
 			clave[0] = x;
 			clave[1] = y;
		 }
		 
		void cifrar(string &mensaje){
			string encryptado;
			mensaje.resize((clave[0]*clave[1]),'_'); //Completa los espacios vacíos añadiendo _
	
			for(int i=0;i<clave[1];i++){
				int aux = i;
				for(int j=0;j<clave[0];j++){
					encryptado = encryptado + mensaje[aux];
					aux = aux + clave[1];
				}
			}
			
			mensaje = encryptado;
		}
		
		void descifrar(string &mensaje){
			string desencryptado;
			
			for(int i=0;i<clave[0];i++){
				int aux = i;
				for(int j=0;j<clave[1];j++){
					desencryptado = desencryptado + mensaje[aux];
					aux = aux + clave[0];
				}
			}
			
			mensaje = desencryptado;
		}
		
 };
 
 int main(){
 		int cx,cy;
 		string mensaje;
 		
 		cout<<"Escriba un mensaje: ";
		getline(cin,mensaje);
		
		cout<<"Ingrese una clave: ";cin>>cx>>cy;
		escitala emisor(cx,cy);
		escitala receptor(cx,cy);
		
 		
 		cout<<"El mensaje es: "<<mensaje<<endl;
 		
 		emisor.cifrar(mensaje);
 		cout<<"El mensaje cifrado es: "<<mensaje<<endl;
 		
 		receptor.descifrar(mensaje);
 		cout<<"El mensaje descifrado es: "<<mensaje<<endl;
 		
 	
 	
 	return 0;
 }
