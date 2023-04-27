#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char cero = '0';
const char numeros[9] = {'1','2','3','4','5','6','7','8','9'};
const char equis[2] = {'x','X'};
const char letras[12] = {'a','b','c','d','e','f','A','B','C','D','E','F'};

int busqueda_lineal(char caracter, const char array[], int n) {
  for (int i=0; i<n; i++) {
    if (caracter==array[i])
      return 1;
  }
  return 0;
}

char* automata_finito_deterministico(char* constante) {
  // 0
  if (constante[0]==cero) {
    // x,X
    if (busqueda_lineal(constante[1], equis, 2)) {
      // [0-9a-fA-F]
      for (int i=2; i<strlen(constante); i++) {
        if (constante[i]!=cero && !busqueda_lineal(constante[i], numeros, 9) && !busqueda_lineal(constante[i], letras, 12))
          return "NO RECONOCIDA";
      }
      return "HEXADECIMAL";
    }
    // [0-7]
    for (int i=1; i<strlen(constante); i++) {
      if (constante[i]!=cero && !busqueda_lineal(constante[i], numeros, 7))
        return "NO RECONOCIDA";
    }
    return "OCTAL";
  // [1-9]
  } else if (busqueda_lineal(constante[0], numeros, 9)) {
    // [0-9]
    for (int i=1; i<strlen(constante); i++) {
      if (constante[i]!=cero && !busqueda_lineal(constante[i], numeros, 9))
        return "NO RECONOCIDA";
    }
    return "DECIMAL";
  } else
    return "NO RECONOCIDA";
}

int main()
{
  char leido[64];
  char* parsed;
  FILE* entrada = fopen("entrada.txt", "r");
  if (entrada == NULL) {
		printf("¡No se pudo abrir el archivo entrada.txt!\n");
		exit(1);
	}
  FILE* salida = fopen("salida.txt", "w");
  if (salida == NULL) {
		printf("¡No se pudo abrir el archivo salida.txt!\n");
    fclose(entrada);
		exit(1);
	}
  fgets(leido, 64, entrada);
  parsed = strtok(leido, ",");
  while(parsed) {
    char* clasificacion = automata_finito_deterministico(parsed);
    fprintf(salida, "%s:\t%s\n", parsed, clasificacion);
    parsed = strtok(NULL, ",");
  }
  fclose(entrada);
  fclose(salida);
  return 0;
}
