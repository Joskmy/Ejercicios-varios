package co.edu.uco.peliculas.datos;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import co.edu.uco.peliculas.domain.Pelicula;
import co.uco.edu.peliculas.excepciones.AccesoDatosEx;
import co.uco.edu.peliculas.excepciones.EscrituraDatosEx;
import co.uco.edu.peliculas.excepciones.LecturaDatosEx;

public class AccesoDatosImpl implements IAccesoDatos {

	@Override
	public boolean revisarExistenciaRecurso(String nombreRecurso) throws AccesoDatosEx {
		File archivo = new File(nombreRecurso);
		return archivo.exists();
	}

	@Override
	public List<Pelicula> listarPelicula(String nombreRecurso) throws LecturaDatosEx {
		var archivo = new File(nombreRecurso);
		List<Pelicula> peliculas = new ArrayList<>();
		try {
			var entrada = new BufferedReader(new FileReader(archivo));
			String linea = null;
			linea = entrada.readLine();
			while (linea != null) {
				Pelicula pelicula = new Pelicula(linea);
				peliculas.add(pelicula);
				linea = entrada.readLine();
			}
			entrada.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
			throw new LecturaDatosEx("Exepción al listar películas: " + ex.getMessage());
		} catch (IOException ex) {
			ex.printStackTrace();
			throw new LecturaDatosEx("Exepción al listar películas: " + ex.getMessage());
		}
		return peliculas;
	}

	@Override
	public void escribirInformacion(Pelicula pelicula, String nombreRecurso, boolean anexar) throws EscrituraDatosEx {
		var archivo = new File(nombreRecurso);
		try {
			var salida = new PrintWriter(new FileWriter(archivo, anexar));
			salida.println(pelicula.toString());
			salida.close();
			System.out.println("Se ha escrito información al archivo" + pelicula);
		} catch (IOException ex) {
			ex.printStackTrace();
			throw new EscrituraDatosEx("Exepción al escribir películas: " + ex.getMessage());
		}
	}

	@Override
	public String buscarPeliculas(String nombreRecurso, String buscar) throws LecturaDatosEx {
		var archivo = new File(nombreRecurso);
		String resultado = null;
		try {
			var entrada = new BufferedReader(new FileReader(archivo));
			String linea = null;
			linea = entrada.readLine();
			int indice = 1;
			boolean encontrado = false; // analizar esta lògica para ver si no interfiere con el break
			while (linea != null) {
				if (buscar != null && buscar.equalsIgnoreCase(linea) && encontrado == false) {
					resultado = "Película " + linea + " encontrada en el indice " + indice;
					encontrado = true;
				}
				linea = entrada.readLine();
				indice++;
			}
			entrada.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
			throw new LecturaDatosEx("Exepción al buscar películas: " + ex.getMessage());
		} catch (IOException ex) {
			ex.printStackTrace();
			throw new LecturaDatosEx("Exepción al buscar películas: " + ex.getMessage());

		}
		return resultado;
	}

	@Override
	public void crearArchivo(String nombreRecurso) throws AccesoDatosEx {
		var archivo = new File(nombreRecurso);
		try {
			var salida = new PrintWriter(new FileWriter(archivo));
			salida.close();
			System.out.println("Se ha creado el archivo");
		} catch (IOException ex) {
			ex.printStackTrace();
			throw new AccesoDatosEx("Exepción al crear archivo: " + ex.getMessage());

		}
	}

	@Override
	public void borrarArchivo(String nombreRecurso) throws AccesoDatosEx {
		var archivo = new File(nombreRecurso);
		if (archivo.exists()) {
			archivo.delete();
		}
		System.out.println("Se ha borrado el archivo");
	}

}
