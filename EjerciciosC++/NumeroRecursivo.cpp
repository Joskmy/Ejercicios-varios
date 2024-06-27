#include <iostream>
#include <string>

using namespace std;

void numeroReves (int n){
	int numero;
	if(numero > 1){
		return numero = to_string(n%10) + to_string(numeroReves(n/10));
	};
}

int main(){
    int n;
    
    cout<< "Ingrese un numero: ";
    cin>>n;
    
	cout << "cambiando el numero  obtenemos "<<numeroReves(n);
	return 0;
	
}