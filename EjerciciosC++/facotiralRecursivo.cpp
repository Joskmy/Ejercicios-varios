#include <iostream>

using namespace std;


int factorial(int numero)
{
	if(numero > 1){
		return numero * factorial(numero - 1);
	}
	return 1;
}

int main(){
    int n;
    
    cout<< "Ingrese un numero: ";
    cin>>n;
    
	cout << "El factorial es: "<<factorial(n);
	return 0;
	
}