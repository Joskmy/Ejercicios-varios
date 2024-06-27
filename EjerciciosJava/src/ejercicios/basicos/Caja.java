package ejercicios.basicos;

public class Caja {
	int ancho;
	int alto;
	int profundo;
	
	public Caja(){
	}
	
	public Caja(int ancho, int alto, int profundo){
		this.ancho = ancho;
		this.alto = alto;
		this.profundo = profundo;
	}
	
	public int calcularVolumenCaja() {
		return ancho * alto * profundo;
	}
	
	public static void main(String[] args) {
		Caja caja1 = new Caja(3,2,1);
		System.out.println(caja1.calcularVolumenCaja());
		
	}
}

