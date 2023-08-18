# Trabajo 1 - Sistema Operativo y Programación

## Descripción
Este programa implementa una aplicación que permite gestionar permisos de usuarios y realizar diferentes operaciones numéricas en base a permisos otorgados.

## Compilación
Para compilar el programa, utiliza el siguiente comando en la terminal:

```bash
g++ -o programa main.cpp -std=c++11
```
# Ejecución
Una vez compilado, puedes ejecutar el programa proporcionando el nombre de usuario y el vector correspondiente. Aquí tienes un ejemplo:

```bash
./programa edgardo:1,2,3
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
