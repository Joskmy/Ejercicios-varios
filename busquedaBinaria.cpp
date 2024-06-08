#include <iostream>
#include <stdio.h> 
#include <math.h>


using namespace std;

int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha){
    if (izquierda > derecha) return -1;

    int indiceDeLaMitad = floor((izquierda + derecha) / 2);

    int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
    if (busqueda == valorQueEstaEnElMedio){
        return indiceDeLaMitad;
    }
    
    if (busqueda < valorQueEstaEnElMedio){
        // Entonces está hacia la izquierda
        derecha = indiceDeLaMitad - 1;
    }else{
        // Está hacia la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}

int main(){
    int numeros[] = {1, 2, 4, 8, 15, 16, 20, 50};
    int busqueda;
    int longitudDelArreglo = sizeof(numeros) / sizeof(numeros[0]);
    int resultadoBusquedaRecursiva;
    
    cout<<"Ingrese el numero a buscar: ";
    cin>>busqueda;
	resultadoBusquedaRecursiva = busquedaBinariaRecursiva(numeros, busqueda, 0, longitudDelArreglo - 1);
	if (resultadoBusquedaRecursiva == -1){
		printf("No se encontro en el vector");
	}
	else{
    printf("Al buscar %d recursivamente, se encuentra en la posicion %d del vector", busqueda, resultadoBusquedaRecursiva);
	}
    return 0;
}