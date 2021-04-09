#include <iostream>

using namespace std;
	
	int division(int a, int n){
		
		int q = a / n;
		int r = a - (q*n);
		
		if(r < 0 && n > 0){
			q = q - 1;
			r = a - (q*n);
		}
		else{
			q = q + 1;
			r = a - (q*n);
		}
		
		cout<<q<<endl;
		cout<<r<<endl;
	}
	
int main(){
	int a,n;
	cout<<"Ingrese el número a: ";cin>> a;
	cout<<"Ingrese el número n: ";cin>> n,
	
	division(a,n);
	return 0;
}
