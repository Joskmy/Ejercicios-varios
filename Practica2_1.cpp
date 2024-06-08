#include <iostream>
#include <conio.h>
#include <string>
#include <ctime> // Agregar esta librería para el uso de time()

using namespace std;

struct Estudiantes {
    int cod;
    string nom, apell;
    string dir, tel;
    string ciudad;
    Estudiantes* siguiente;
}* primero_estudiante = nullptr, * ultimo_estudiante = nullptr;

struct Libros {
    int cod_lib;
    int num_ejem;
    string nom_lib;
    string autor_lib;
    string editorial_lib;
    string ciudad_pub_lib;
    bool disponibilidad;
    Libros* siguiente_2;
}* primero_libro = nullptr, * ultimo_libro = nullptr;

struct NodoPrestamo { // Agregar la estructura NodoPrestamo para la lista de préstamos
    int codigo_libro;
    int codigo_estudiante;
    time_t fecha_prestamo;
    NodoPrestamo* siguiente;
}* primero_prestamo = nullptr, * ultimo_prestamo = nullptr;

// Agregar las funciones buscarLibro() y buscarEstudiante() para buscar un libro o estudiante por su código
Libros* buscarLibro(int codigo) {
    Libros* actual = primero_libro;
    while (actual != nullptr) {
        if (actual->cod_lib == codigo) {
            return actual;
        }
        actual = actual->siguiente_2;
    }
    return nullptr;
}

Estudiantes* buscarEstudiante(int codigo) {
    Estudiantes* actual = primero_estudiante;
    while (actual != nullptr) {
        if (actual->cod == codigo) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void insertarEstudiante();
void mostrarEstudiante();
void insertarLibros();
void mostrarLibro();
void prestar_libro();

int n1 = 0; // Inicializar en 0

int main() {
    int opcion;
    do {
        cout << "\n************************************************\n1. ADICIONAR ESTUDIANTE\n";
        cout << "2. ADICIONAR LIBRO\n3. LISTAR ESTUDIANTES\n4. LISTAR LIBROS\n5. HACER PRESTAMO\n";
        cout << "6. LISTADO LIBROS PRESTADOS\n7. SALIR\n************************************************\n";

        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Ingresar estudiantes" << endl;
            cout << "************************************************" << endl;
            insertarEstudiante();
            break;
        case 2:
            cout << "Ingresar libro" << endl;
            cout << "************************************************" << endl;
            insertarLibros();
            break;
        case 3:
            cout << "Estudiantes" << endl;
            cout << "************************************************" << endl;
            mostrarEstudiante();
            cout << "Presiona cualquier tecla para continuar\n";
            getch();
            break;
        case 4:
            cout << "Libros" << endl;
            cout << "************************************************" << endl;
            mostrarLibro();
            cout << "Presiona cualquier tecla para continuar\n";
            getch();
            break;
        case 5:
            cout << "Prestar libro" << endl;
            cout << "************************************************" << endl;
            prestar_libro();
            break;
        }
    } while (opcion != 7);
    return 0;
}

void prestar_libro() {
    int codigo_libro;
    int codigo_estudiante;

    cout
