#include <iostream>

using namespace std;

int Ackerman(int m, int n)
{
    if(m==0)
      return n+1;
    else
    {
        if(n==0)
           return Ackerman(m-1, 1);
        else
           return Ackerman(m-1, Ackerman(m, n-1));
    }
}
int main()
{
    int m, n, num ;

    cout<<"Ingrese <m>: ";
    cin>> m ;
    cout<<"Ingrese <n>: ";
    cin>> n ;
    
    num = Ackerman(m,n);
    
    cout<<"\nEl numero es: "<< Ackerman(m,n);
    return 0;
}

/*Recuersividad anidada desde mi perspectiva: 
		Es cuando  se usan los parámetros que tiene la función dentro de la invocación de  esta misma 		
*/