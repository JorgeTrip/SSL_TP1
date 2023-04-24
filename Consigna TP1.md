UTN - FRBA
Sintaxis y Semántica de los Lenguaje - 2023

Trabajo Práctico n° 1 - Autómata Finito Determinístico para Constantes Enteras de C
Implementar en C un programa que permita reconocer y clasificar las distintas constantes
enteras de C (Decimal, Octal, Hexadecimal). El mismo deberá leer palabras separadas por
“,” (carácter centinela) de un archivo de entrada (entrada.txt) y generar un archivo de
salida (salida.txt) donde indique qué tipo de constante entera es cada palabra leída o si no fue
reconocida. El programa debe contemplar la implementación de un autómata finito
determinístico (AFD) para el reconocimiento y clasificación de palabras según estado final.
Ejemplo del archivo de entrada.txt (secuencia de caracteres separadas por coma):
0xFF,127,0159,0xaBb1,0Xx,0,010,09,127A,120

Ejemplo del archivo de salida.txt:
0xFF
HEXADECIMAL
127
DECIMAL
0159
NO RECONOCIDA
0xaBb1
HEXADECIMAL
0Xx
NO RECONOCIDA
0
OCTAL
010
OCTAL
09
NO RECONOCIDA
127A
NO RECONOCIDA
120
DECIMAL

La entrega de este trabajo práctico es obligatoria, su fecha límite para consulta, entrega y
revisión es el día domingo 4 de junio. Luego de esa fecha, no se aceptarán más trabajos, y
toda consulta referida quedará para la defensa final que será en el mes de noviembre.

El entorno de programación queda a criterio de cada grupo de trabajo (Eclipse, Dev,
Codeblocks, Visual Studio Code). 

Se recomienda un IDE que esté integrado con Git para
poder realizar el trabajo en equipo de una forma más práctica.

Formará parte de la entrega el archivo fuente (.c) y el archivo ejecutable (.exe). Todo debe
estar en el repositorio GitHub.

La entrega será a través del repositorio de GitHub en la carpeta correspondiente a cada TP

Las consultas podrán ser respondidas a través Discord