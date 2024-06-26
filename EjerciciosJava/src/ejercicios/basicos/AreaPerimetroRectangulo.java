package ejercicios.basicos;

import java.util.Scanner;

/*En el siguiente ejercicio se solicita calcular el área y el perímetro de un Rectángulo, para ello deberemos crear las siguientes variables:

alto (int)

ancho (int)
*/

public class AreaPerimetroRectangulo {
	public static void main(String[] args) {
		Scanner consola = new Scanner(System.in);

		System.out.println("Proporciona el alto: ");
		int alto = Integer.parseInt(consola.nextLine());

		System.out.println("Proporciona el ancho: ");
		int ancho = Integer.parseInt(consola.nextLine());

		System.out.println( "Area: " + alto*ancho);
		System.out.println( "Perimetro: " + (2*alto+2*ancho));
		
		consola.close();
	}
}
