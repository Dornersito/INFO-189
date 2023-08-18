# Trabajo 1 - Sistema Operativo y Programación

## Descripción
Este programa implementa una aplicación que permite gestionar permisos de usuarios y realizar diferentes operaciones numéricas en base a permisos otorgados.

## Compilación
Para compilar el programa, utiliza el siguiente comando en la terminal:

```bash
make
```
# Ejecución
Una vez compilado, puedes ejecutar el programa proporcionando el nombre de usuario y el vector correspondiente. Aquí tienes un ejemplo:

```bash
./ej -u [edgardo] -v [1,2,3]
```
Esto ejecuta el programa asignando como nombre de usuario "edgardo" y el vector {1, 2, 3}

# Base de Datos
La información de usuarios y permisos se almacena en dos archivos de texto: usuarios.txt y permisos.txt. Estos archivos siguen el siguiente formato:

#### usuarios.txt
El archivo usuarios.txt contiene los nombres de usuario separados por punto y coma (;).
Ejemplo:
```bash
vicho;mati;edgardo
```

#### permisos.txt
El archivo permisos.txt almacena los permisos asignados a cada usuario. Cada línea contiene el nombre de usuario seguido de los números de permisos separados por comas (,).

Ejemplo:
```bash
vicho;1,2,3
edgardo;1,2,4
mati;3,4
```

## Ejecución
- **Si el usuario se encuentra en la base de datos.**
El programa le dará las opciones a ejecutar en el vector correspondientes a sus permisos.
Si el usuario no tiene permiso a ejecutar una opción, se le negará.

- **Si el usuario no se encuentra en la base de datos**
El programa dará la opción para agregarlo a la base de datos, además solicitará los permisos que quiere que tenga este nuevo usuario.
Posteriormente, se ejecutará el resto del programa.
