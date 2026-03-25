# Analizar códigos de C++ con LEX
------

                                            Pérez García Alejandro Maximo



## Reporte de Proyecto: Analizador Léxico para C

## 1. Introducción

Este reporte presenta la implementación, resultados y desarrollo de un *analizador léxico en C*, tomando en cueunta el analizador lexico de la practica anterior (desarrollado en Java). La función principal de este analizador es la de poder leer un código escrito en c y poder clasificar los *tokens* (simbolos o palabras que se asocian con un valor) en su tipo correspondiente.

Este analizador procesa un código originalmente escrito en el lenguaje C, separando y clasificando elementos como palabras reservadas, identificadores, literales, operadores y separadores. El analizador es capaz de saber en la línea de código de cada token encontrado, ignorando los espacios en blanco y manejando la clasificación de los tokens en base a la **regla de prioridad** o tambien conocida como **precedencia de reglas.**

---

## 2. Desarrollo del analizador

Como lo mencionamos anteriormente, se construyó el analizador siguiendo la precedencia de reglas para que cumpliera su función correctamente (que sea capaz de diferenciar entre un identificador de una palabra reservada).

Para que el código de C pudiera funcionar, se importaron las librerias `<stdio.h>` y `<stdlib.h>` las cuales incluyen funciones de entrada y salida y herramientas de uso general.

`FILE *out_file` es un puntero por extención en Flex que le indica a que espacio de memoria se van a enviar los datos que se van a ir obteniendo.

La sección de reglas se definió haciendo uso de las **expreciónes regulares** que hemos visto durente el curso.

Para poder enviar los datos que fueron optenidos despues de analizar el código de ejemplo, se necesita hacer uso de la linea `fprintf` que es parecido a la función `printf` que imprime en consola, pero la f al principio le esta haciendo saber que va a imprimir en un archivo (file), para hacer uso de este token, se necesitan ciertos parametros, el primero de ellos es el de `out_file` que le indica en qué archivo escribir, el cual le llamamos `MyScanner.txt`; el siguiente parametro es `"[Ln: %04d] -> %-25s | %s\n"`, lo que es texto plano se va a escribir tal cual (`[Ln:, ->, y |`) para despues hacer uso de **especificadores de formato** estos ya los hemos usado antes para hacer códigos menos complejos en Flex, los especificadores que usé fueron:

* **%04d**: Para un número entero (por eso la d de decimal)
    * El 4 significa que ocupará exactamente 4 espacios.
    * El 0 le dice que, si el número es menor a 4 dígitos, lo rellene con ceros a la izquierda

* **%-25s**: Es para texto (s de string/cadena).
    * El 25 significa que reservará un bloque de 25 caracteres de ancho.
    * El `-` significa alinear a la izquierda. Si el texto mide menos de 25 letras, rellenará el resto con espacios en blanco hacia la derecha.

* **%s:** Es para texto, pero sin formato especial.
* **\n** Es para hacer el salto de linea.

Estos especificadores son usados para mostrar los resultados obtenidos en el archivo de salida.

Ya por último la función `main` es la función principal del programa y la que va a ejecutar el código, las partes que lo componen son los dos argumentos principales que le pasamos `argc` y `argv`; el primero guarda el argumento que escribimos en la terminal cuando ejecutamos este programa y el segundo parametro, almacena las palabras de la terminal en un arreglo para poder analizar el código de ejemplo "lo que hace es que si en la terminal escribimos solo el ./scanner (que fue como lo llamé al archivo final despues de hacer sido compilado) va a usar el nombre por defecto que escribimos en el main, pero si viene acompañado de una segunda palabra (lo cual va a hacer que el parametro `argv` sea de [1]) entonces analiza ese segundo código que se está pidiendo". 
Se usa `yyin` para darle lo que va a analizar el código (yyin es una variable de Flex), luego se abre el archivo en modo lectura para revisar linea por linea y despues generar un archivo de nombre `MyScanner.txt` en modo de escritura y ahí guardar todos los resultados.

---

## 3. Resultados de Pruebas

El analizador léxico fue probado con un archivo de código (`codigoEjemplo.c`). Los resultados obtenidos validan la correctitud del algoritmo:

- **Categorización Exitosa:** El sistema es capaz de clasificar todas las categorías definidas en la enumeración sin confundir las palabras reservadas con identificadores. 

- **Tiempos de Ejecución:** Gracías a que C es uno de los lenguajes más veloces en tiempo de ejecución, el analisis fue bastante rapido incluyendo la creación del nuevo archivo.

## 4. Conclusión
El analizador léxico en C cumplio con los requisitos y además tiene la misma funcionalidad que su antecesor en Java haciendo un uso correcto en cuanto a reglas y variables propias de Lex/Flex.
