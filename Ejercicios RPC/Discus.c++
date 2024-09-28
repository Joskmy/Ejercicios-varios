#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int puntuacion_maxima_discos(int n, int m, const vector<int>& cuadrados) {
    // Inicializamos la puntuación máxima como negativo infinito
    int max_score = numeric_limits<int>::min();
    
    // Mantenemos el mejor puntaje alcanzable desde cada posición
    vector<int> mejor_puntuacion(n, 0);

    auto actualizar_mejor_puntuacion = [&](int i) {
        int puntuacion_inicio = cuadrados[i];
        for (int j = 1; j <= m; ++j) {
            if (i + j < n) {
                int puntuacion = cuadrados[i + j] - puntuacion_inicio;
                mejor_puntuacion[i + j] = max(mejor_puntuacion[i + j], puntuacion);
            }
        }
        return max(mejor_puntuacion[i], max_score);
    };

    // Aplicamos la función a cada índice
    for (int i = 0; i < n; ++i) {
        max_score = max(max_score, actualizar_mejor_puntuacion(i));
    }

    return max_score;
}

int main() {
    // Lectura de entrada
    int n, m;
    cin >> n >> m;
    vector<int> cuadrados(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> cuadrados[i];
    }

    // Cálculo de la puntuación máxima
    int resultado = puntuacion_maxima_discos(n, m, cuadrados);

    // Salida del resultado
    cout << resultado << endl;

    return 0;
}
