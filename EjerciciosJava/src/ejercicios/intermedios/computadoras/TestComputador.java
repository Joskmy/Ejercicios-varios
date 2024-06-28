package ejercicios.intermedios.computadoras;

public class TestComputador {
	public static void main(String[] args) {
		Computadora computadora1 = new Computadora("Computadora HP", new Monitor("HP", 13), 
									new Teclado("bluetooth", "hp"), new Raton("bluetooth", "HP"));
		
		
		
		Orden orden1 = new Orden();
		orden1.agregarComputadoras(computadora1);
		
		orden1.mostrarOrden();
	}
}
