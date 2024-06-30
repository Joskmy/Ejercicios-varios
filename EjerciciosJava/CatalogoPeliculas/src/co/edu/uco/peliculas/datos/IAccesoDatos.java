package co.edu.uco.peliculas.datos;

import java.util.List;

import co.edu.uco.peliculas.domain.Pelicula;
import co.uco.edu.peliculas.excepciones.AccesoDatosEx;
import co.uco.edu.peliculas.excepciones.EscrituraDatosEx;
import co.uco.edu.peliculas.excepciones.LecturaDatosEx;

public interface IAccesoDatos {
	boolean revisarExistenciaRecurso(String nombreRecurso) throws AccesoDatosEx;

	List<Pelicula> listarPelicula(String nombreRecurso) throws LecturaDatosEx;
	
	void escribirInformacion(Pelicula pelicula, String nombreRecurso, boolean anexar) throws EscrituraDatosEx;

	String buscarPeliculas(String nombreRecurso, String buscar) throws LecturaDatosEx;
	
	void crearArchivo(String nombreRecurso) throws AccesoDatosEx;
	
	void borrarArchivo(String nombreRecurso) throws AccesoDatosEx;
}
