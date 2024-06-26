package ejercicios.basicos;

import java.util.Scanner;

/*
 * El objetivo del ejercicio es crear un sistema de calificaciones, como sigue:

El usuario proporcionará un valor entre 0 y 10.

Si está entre 9 y 10: imprimir una A

Si está entre 8 y menor a 9: imprimir una B

Si está entre 7 y menor a 8: imprimir una C

Si está entre 6 y menor a 7: imprimir una D

Si está entre 0 y menor a 6: imprimir una F

cualquier otro valor debe imprimir: Valor desconocido
 */

public class NotaEstudiante {
	public static void main(String[] args) {
		Scanner consola = new Scanner(System.in);
        System.out.println("Proporciona un valor entre 0 y 10: ");
        float valor = Float.parseFloat(consola.nextLine());

        float[] limites = {0, 6, 7, 8, 9, 10};
        String[] calificaciones = {"F", "D", "C", "B", "A"};

        String resultado = "Valor desconocido";
        
        for (int i = 0; i < limites.length - 1; i++) {
            if (valor >= limites[i] && valor < limites[i + 1]) {
                resultado = calificaciones[i];
            }
        }

        System.out.println(resultado);
        consola.close();
	}
		
}
