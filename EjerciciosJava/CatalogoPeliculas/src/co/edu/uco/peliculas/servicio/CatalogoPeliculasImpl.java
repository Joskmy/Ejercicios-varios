package co.edu.uco.peliculas.servicio;

import co.edu.uco.peliculas.datos.AccesoDatosImpl;
import co.edu.uco.peliculas.datos.IAccesoDatos;
import co.edu.uco.peliculas.domain.Pelicula;
import co.uco.edu.peliculas.excepciones.AccesoDatosEx;

public class CatalogoPeliculasImpl implements ICatalogoPeliculas {

	private final IAccesoDatos datos;

	public CatalogoPeliculasImpl() {
		this.datos = new AccesoDatosImpl();
	}

	@Override
	public void agregarPelicula(String nombrePelicula) {
		Pelicula pelicula = new Pelicula(nombrePelicula);
		boolean anexar = false;
		try {
			anexar = datos.revisarExistenciaRecurso(NOMBRE_RECURSO);
			datos.escribirInformacion(pelicula, NOMBRE_RECURSO, anexar);
		} catch (AccesoDatosEx ex) {
			System.out.println("Error de acceso a datos en el mètodo agegarPeliculas");
			ex.printStackTrace(System.out);
		}
	}

	@Override
	public void listarPeliculas() {
		try {
			var peliculas = this.datos.listarPelicula(NOMBRE_RECURSO);
			for (Pelicula pelicula : peliculas) {
				System.out.println("Pelicula = " + pelicula);
			}
		} catch (AccesoDatosEx ex) {
			System.out.println("Error de acceso a datos en el mètodo de listarPeliculas");
			ex.printStackTrace(System.out);
		}
	}

	@Override
	public void buscarPelicula(String buscar) {
		String resultado = null;
		try {
			resultado = this.datos.buscarPeliculas(NOMBRE_RECURSO, buscar);
		} catch (AccesoDatosEx ex) {
			System.out.println("Error de acceso a datos en el mètodo de buscarPelicula");
			ex.printStackTrace(System.out);
		}
		System.out.println("Resultado = " + resultado);

	}

	@Override
	public void iniciarCatalogoPeliculas() {
		try {
			if (this.datos.revisarExistenciaRecurso(NOMBRE_RECURSO)) {
				datos.borrarArchivo(NOMBRE_RECURSO);
				datos.crearArchivo(NOMBRE_RECURSO);
			} else {
				datos.crearArchivo(NOMBRE_RECURSO);
			}
		} catch (AccesoDatosEx ex) {
			System.out.println("Error al iniciar catálogo de películas");
			ex.printStackTrace(System.out);
		}
	}

}
