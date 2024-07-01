# Sistema de Gestión de Estudiantes

Este proyecto es una implementación de un sistema de gestión de estudiantes utilizando Java y Spring Boot. La solución incluye el manejo de datos para listar, buscar, agregar, modificar y eliminar estudiantes. Este proyecto fue desarrollado como parte de un ejercicio práctico para mejorar las habilidades en el uso de Spring Boot y JPA.

## Contenido

El proyecto está organizado en varios paquetes, cada uno con su propósito específico:

### 1. **gm.estudiantes**

Este es el paquete principal que contiene la clase de arranque de la aplicación.

- `EstudiantesApplication.java`: Clase principal que levanta la aplicación Spring Boot y permite la interacción con el usuario a través de un menú en consola.

### 2. **gm.estudiantes.modelo**

Define la entidad Estudiante:

- `Estudiante.java`: Clase que representa a un estudiante con sus atributos (id, nombre, apellido, teléfono, email).

### 3. **gm.estudiantes.repositorio**

Contiene la interfaz para el acceso a la base de datos:

- `EstudianteRepositorio.java`: Interfaz que extiende JpaRepository para la gestión de estudiantes en la base de datos.

### 4. **gm.estudiantes.servicio**

Contiene las clases e interfaces para los servicios de gestión de estudiantes:

- `EstudianteServicio.java`: Implementación de la interfaz IEstudianteServicio que gestiona las operaciones del sistema de estudiantes.
- `IEstudianteServicio.java`: Interfaz que define las operaciones del sistema de gestión de estudiantes.

## Experiencia Personal

En mi experiencia personal, este proyecto resultó ser un poco tedioso debido a la aparición de numerosos errores inesperados, a pesar de tener experiencia previa con Spring Boot. Los problemas principales estuvieron relacionados con la base de datos, que frecuentemente no permitía la conexión. Además, algunas dependencias no funcionaban correctamente. Aunque el proyecto en sí era sencillo, estos problemas hicieron que recurriera a Stack Overflow con mucha frecuencia.





