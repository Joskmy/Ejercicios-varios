#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
	
using namespace std;
	
struct Estudiantes {
		int cod;
		string nom,  apell;
		string dir, tel;
		string ciudad;
		Estudiantes *siguiente;
	}*primero_estudiante, *ultimo_estudiante;
	
struct Libros {
		int cod_lib;
		int num_ejem;
		string nom_lib;
		string autor_lib;
		string editorial_lib;
		string ciudad_pub_lib;
		bool disponible = true;
		Libros *siguiente_2;
	}*primero_libro, *ultimo_libro;
	
void insertarEstudiante();
void mostrarEstudiante();
void insertarLibros();
void mostrarLibro();
void prestarLibro();
	
	
int n1, n2;
	
int main(){
		int opcion;
		do{
			cout<<"\n************************************************\n1. ADICIONAR ESTUDIANTE\n";
			cout<< "2. ADICIONAR LIBRO\n3. LISTAR ESTUDIANTES\n4. LISTAR LIBROS\n5. HACER PRESTAMO\n";
			cout<< "6. LISTADO LIBROS PRESTADOS\n7. SALIR\n************************************************\n";
			
			cin>>opcion;
			switch (opcion){
				case 1:
					cout<<"Ingresar estudiantes"<<endl;
					cout<<"************************************************"<<endl;
					insertarEstudiante();
					break;
				case 2:
					cout<<"Ingresar libro"<<endl;
					cout<<"************************************************"<<endl;
					insertarLibros();
					break;
				case 3:
					cout<<"Estudiantes"<<endl;
					cout<<"************************************************"<<endl;
					mostrarEstudiante();
					cout<<"Presiona cualquier tecla para continuar\n";
					getch();
					break;
				case 4:
					cout<<"Libros"<<endl;
					cout<<"************************************************"<<endl;
					mostrarLibro();
					cout<<"Presiona cualquier tecla para continuar\n";
					getch();
					break;
				case 5:
	    			cout << "Prestar libro" << endl;
				    cout << "************************************************" << endl;
				    prestarLibro();
					break;	
			}
		}while(opcion!=7);
		return 0;
	}
	
void insertarEstudiante(){
		string nomb,apell,ciu,dir,tel;
		Estudiantes * nuevo = new Estudiantes();
		n1 ++;
		nuevo->cod=n1;
		getline(cin, nomb);
		cout<<"Ingresa nombre: ";
		getline(cin, nomb);
		nuevo->nom=nomb;
		cout<<"Ingresa apellido: ";
		getline(cin, apell);
		nuevo->apell=apell;
		cout<<"Ingresa ciudad: ";
		getline(cin, ciu);
		nuevo->ciudad=ciu;
		cout<<"Ingresa direccion: ";
		getline(cin, dir);
		nuevo->dir=dir;
		cout<<"Ingresa telefono: ";
		getline(cin, tel);
		nuevo->tel=tel;
		if (primero_estudiante==NULL){
			primero_estudiante = nuevo;
			primero_estudiante->siguiente=primero_estudiante;
			ultimo_estudiante=primero_estudiante;
		}else{
			ultimo_estudiante->siguiente=nuevo;
			nuevo->siguiente=primero_estudiante;
			ultimo_estudiante=nuevo;
		}
		cout<<"Estudiante agregado"<<endl;
	}
void mostrarEstudiante(){
		Estudiantes *actual = new Estudiantes();
		actual = primero_estudiante;
		if (primero_estudiante!=NULL){
			do{
				cout<<"Estudiante #"<<actual->cod<<endl;
				cout<<"Nombre: "<<actual->nom<<endl;
				cout<<"Apellido: "<<actual->apell<<endl;
				cout<<"Ciudad: "<<actual->ciudad<<endl;
				cout<<"Direccion: "<<actual->dir<<endl;
				cout<<"Telefono: "<<actual->tel<<endl;
				cout<<"************************************************"<<endl;
				actual=actual->siguiente;
			}while(actual!=primero_estudiante);
		}
		else{
			cout<<"La lista esta vacia"<<endl;
		}
	}
	
void insertarLibros(){
		int numEjem; 
		string nomLib, autorLib, editorialLib, ciudadPub;
		Libros * nuevo = new Libros();
		n2 ++;
		nuevo->cod_lib=n2;
		cout<<"Ingresa numero de ejemplares: ";
		cin>>nuevo->num_ejem;
		getline(cin, nomLib);
		cout<<"Ingresa nombre del libro: ";
		getline(cin, nomLib);
		nuevo->nom_lib=nomLib;
		cout<<"Ingresa autor del libro: ";
		getline(cin, autorLib);
		nuevo->autor_lib = autorLib;
		cout<<"Ingresa editorial del libro: ";
		getline(cin, editorialLib);
		nuevo->editorial_lib=editorialLib;
		cout<<"Ingresa ciudad de publicacion del libro: ";
		getline(cin, ciudadPub);
		nuevo->ciudad_pub_lib=ciudadPub;
		if (primero_libro==NULL){
			primero_libro = nuevo;
			primero_libro->siguiente_2=primero_libro;
			ultimo_libro=primero_libro;
		}else{
			ultimo_libro->siguiente_2=nuevo;
			nuevo->siguiente_2=primero_libro;
			ultimo_libro=nuevo;
		}
		cout<<"Libro agregado"<<endl;
	}
	
void mostrarLibro(){
		Libros *actual2 = new Libros();
		actual2 = primero_libro;
		if (primero_libro!=NULL){
			do{
				cout<<"libro #"<<actual2->cod_lib<<endl;
				cout<<"numero de ejemplares: "<<actual2->num_ejem<<endl;
				cout<<"Ingresa nombre del libro:  "<<actual2->nom_lib<<endl;
				cout<<"AIngresa autor del libro: "<<actual2->autor_lib<<endl;
				cout<<"Ingresa editorial del libro: "<<actual2->editorial_lib<<endl;
				cout<<"Ingresa ciudad de publicacion del libro:  "<<actual2->ciudad_pub_lib<<endl;
				cout<<"************************************************"<<endl;
				actual2=actual2->siguiente_2;
			}while(actual2!=primero_libro);
		}
		else{
			cout<<"La lista esta vacia"<<endl;
		}
	}
	
void prestarLibro() {
	string nomLibro;
	Libros* temp = primero_libro;
	
	cout<<"Ingrese el nombre del libro que desea prestar: ";
	cin>>nomLibro;
    while (temp != NULL) { 
        if (temp->nom_lib == nomLibro) { 
            if (temp->disponible) { 
                temp->num_ejem--; 
                cout << "El libro \"" << temp->nom_lib << "\" ha sido prestado." << endl;
                if(temp->num_ejem == 0){
                	temp->disponible = false; 
				}
                return;
            } else {
                cout << "El libro \"" << temp->nom_lib << "\" no esta disponible para prestamo." << endl;
                return;
            }
        }
        temp = temp->siguiente_2;
    }
    cout << "El libro con el nombre " << nomLibro << " no existe." << endl;
}
