//Ordenado por selección
#include<iostream>
#include<string>
using namespace std;

void selectionSort(string arr[], int n) 
{ 
    int min; 
    for (int i = 0; i < n-1; i++) 
    { 
 
        min = i; 
        for (int j = i+1; j < n; j++){
        	if (arr[j].compare(arr[min]) < 0){
        		min = j;
			}	 	
		}
        arr[min].swap(arr[i]); 
    } 
} 

void imprimir(string lista[],int n){
	for(int i=0;i<n;i++){
		cout<<lista[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Indique la cantidad de strings a ordenar: ";cin>>n;
	string lista[n];
	for(int i=0;i<n;i++){
		string aux;
		cout<<"Escriba una palabra: ";cin>>aux;
		lista[i] = aux;
	}
	cout<<"Lista sin ordenar: "<<endl;
	imprimir(lista,n);
	selectionSort(lista,n);
	cout<<"Lista ordenada lexicograficamente: "<<endl;
	imprimir(lista,n);
}
