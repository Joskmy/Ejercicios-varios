#include <iostream>

using namespace std;


int factorial(int numero)
{
	int i, factorial = 1;
	
	for (i = 1;  i <= numero ; i++){
    	factorial = factorial * i;
	}

    return factorial;
}

int main(){
    int n;
    
    cout<< "Ingrese un numero: ";
    cin>>n;
    
	cout << "El factorial es: "<<factorial(n);
	return 0;
	
}