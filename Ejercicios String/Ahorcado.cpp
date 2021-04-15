#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
void volver_a_jugar(bool &run,string &temporal,string palabras[5],string &repetido,int &avance, int &oportunidades,int &rdm){
	char resp;
	cout<<"Quiere jugar otra vez? s/n: "; cin>>resp;
		if(resp=='s'||resp=='S'){
			rdm = rand()%5; 
			oportunidades = 7; avance = 0;
			run = true;
			string aux(palabras[rdm].length(),'X');
			temporal = aux;
			repetido = "";
		}
		else{
			cout<<"\tJUEGO TERMINADO"<<endl;
			system("pause");
			run = false;
		}
}

void colgado(int intentos){
	switch (intentos){
	    case 7:
	        cout << "__________\n|         |\n|\n|\n|\n|\n|";
	        break;
	    case 6:
	        cout << "__________\n|         |\n|         0\n|\n|\n|\n|";
	        break;
	    case 5:
	        cout << "__________\n|         |\n|         0\n|         |\n|\n|\n|";
	        break;
	    case 4:
	        cout << "__________\n|         |\n|         0\n|        /|\n|\n|\n|";
	        break;
	    case 3:
	        cout << "__________\n|         |\n|         0\n|        /|\\\n|\n|\n|";
	        break;
	    case 2:
	        cout << "__________\n|         |\n|         0\n|        /|\\\n|        /\n|\n|";
	        break;
	    case 1:
	        cout << " _________\n|         |\n|         0\n|        /|\\\n|        / \\\n|\n|\n";
	        break;
		}
}

int main(){
string palabras[5]={"hola","alfabeto","algebra","computacion","ahorcado"};
string repetido;
int rdm=rand()%5, oportunidades = 7, avance = 0;
char letra,resp;
bool run = true;
string temporal(palabras[rdm].size(),'X');

while(run){
	cout<<"\t Juego del Ahorcado\t"<<endl;
	cout<<"Adivine la palabra: "<<temporal<<endl<<endl;
	cout<<"Oportunidades restantes: "<<oportunidades<<endl;
	cout<<"Ingrese una letra: ";cin>>letra;
	
	int posicion = palabras[rdm].find(letra);
	if(posicion!=palabras[rdm].npos && repetido.find(letra) == repetido.npos){
		while (posicion != palabras[rdm].npos){
 			temporal[posicion] = palabras[rdm][posicion];
  			posicion = palabras[rdm].find(letra, posicion + 1 );
  			avance = avance + 1;
 		} 
 		repetido = repetido+letra;
	}
	else if (repetido.find(letra) != repetido.npos){
		cout<<"\tLetra Repetida!\t"<<endl;
		system("pause");
	}
	else{
		system("cls");
		cout<<"\tFallaste!\t"<<endl;
		colgado(oportunidades);
		oportunidades--;
		system("pause");
	}
	
	if(avance >= palabras[rdm].length()){
		cout<<"La palabra completa era: "<<temporal<<endl;
		cout<<"Felicidades!!! Adivino mi palabra!"<<endl;
		volver_a_jugar(run,temporal,palabras,repetido,avance,oportunidades,rdm);

	}
	else if(oportunidades == 0){
		system("cls");
		cout<<"\t Has perdido :C\t"<<endl;
		volver_a_jugar(run,temporal,palabras,repetido,avance,oportunidades,rdm);
	}
		
	system("cls");
}
return 0;
}
