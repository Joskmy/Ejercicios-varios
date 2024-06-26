package ejercicios.basicos;

import java.util.Scanner;

public class TiendaLibros {
	public static void main(String[] args) {
		Scanner consola = new Scanner(System.in);
		System.out.println("Proporciona el nombre: ");
		String nombre = consola.nextLine();
		System.out.println("Proporciona el id: ");
		int id = Integer.parseInt(consola.nextLine());
		System.out.println("Proporciona el precio: ");
		double precio = Double.parseDouble(consola.nextLine());
		System.out.println("Proporciona el envioGratuito: ");
		Boolean envioGratuito = Boolean.valueOf(consola.nextLine());

		System.out.println(nombre + "#" + id);
		System.out.println("Precio: $" + precio);
		System.out.println("Envio Gratuito: " + envioGratuito);

		consola.close();

	}

}
