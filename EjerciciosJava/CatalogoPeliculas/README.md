# Catálogo de Películas

Este proyecto es una implementación de un sistema de gestión de un catálogo de películas utilizando Java. La solución incluye el manejo de archivos para almacenar, listar, buscar y eliminar películas. Este proyecto fue desarrollado como parte de un curso en Udemy, y en la carpeta `peliculas` se incluye un archivo PDF con los diagramas UML correspondientes.

## Contenido

El proyecto está organizado en varios paquetes, cada uno con su propósito específico:

### 1. **co.edu.uco.peliculas.datos**
Contiene las clases e interfaces necesarias para el acceso y manejo de datos:

- `AccesoDatosImpl.java`: Implementación de la interfaz IAccesoDatos para la gestión de películas en archivos.
- `IAccesoDatos.java`: Interfaz que define las operaciones básicas para el acceso a datos.

### 2. **co.edu.uco.peliculas.domain**
Define la entidad Película:

- `Pelicula.java`: Clase que representa una película con su nombre.

### 3. **co.edu.uco.peliculas.servicio**
Contiene las clases e interfaces para los servicios del catálogo de películas:

- `CatalogoPeliculasImpl.java`: Implementación de la interfaz ICatalogoPeliculas que gestiona las operaciones del catálogo.
- `ICatalogoPeliculas.java`: Interfaz que define las operaciones del catálogo de películas.

### 4. **co.uco.edu.peliculas.excepciones**
Define las excepciones personalizadas para el manejo de errores:

- `AccesoDatosEx.java`: Excepción general para errores de acceso a datos.
- `EscrituraDatosEx.java`: Excepción para errores de escritura de datos.
- `LecturaDatosEx.java`: Excepción para errores de lectura de datos.

### 5. **peliculas**
Contiene la clase principal para la presentación del catálogo de películas y un archivo PDF con los diagramas UML:

- `CatalogoPeliculasPresentacion.java`: Clase principal que permite la interacción con el usuario a través de un menú en consola.
- `diagramasUML.pdf`: Archivo PDF con los diagramas UML del proyecto.

## Experiencia Personal

En mi experiencia personal, este fue un proyecto liviano, ya que anteriormente había interactuado con el framework Spring Boot y utilizando JDBC, lo cual hizo que todo el proceso fuera llevadero. Además, no fue necesario utilizar un enum ni crear clases adicionales para el control de mensajes estáticos y de cada uno de los mensajes de excepciones.


