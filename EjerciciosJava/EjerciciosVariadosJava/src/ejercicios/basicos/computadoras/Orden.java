package ejercicios.basicos.computadoras;

public class Orden {
	private int idOrden;
	private Computadora computadoras[];
	private static int contadorOrdenes;
	private  int contadorComputadoras;
	private static final int MAX_COMPUTADORAS = 10;
	
	public Orden() {
		this.idOrden = ++Orden.contadorOrdenes;
		this.computadoras = new Computadora[Orden.MAX_COMPUTADORAS];
	}
	
	public void agregarComputadoras(Computadora computadora) {
		if(!(this.contadorComputadoras < Orden.MAX_COMPUTADORAS)) {
			System.out.println("Ha superado número máximo de computadoras");
			return;
		}
		
		this.computadoras[this.contadorComputadoras++] = computadora;

	}
	
	
	public void mostrarOrden() {
		System.out.println("Id orden: " + this.idOrden);
		System.out.println("Computadoras de la Orden: ");
		for (int i = 0; i < this.contadorComputadoras; i++) {
			System.out.println(this.computadoras[i]);
		}
	}
	
	
	
}
