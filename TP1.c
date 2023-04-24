#include <stdio.h>
#include <ctype.h>

enum State { START, OCTAL, HEXADECIMAL, DECIMAL, ERROR };

enum State nextState(enum State currentState, char c) {
    switch(currentState) {
        case START:
            if(c == '0') {
                return OCTAL;
            } else if(isdigit(c)) {
                return DECIMAL;
            } else {
                return ERROR;
            }
        case OCTAL:
            if(c >= '0' && c <= '7') {
                return OCTAL;
            } else if(c == 'x' || c == 'X') {
                return HEXADECIMAL;
            } else if(isdigit(c)) {
                return ERROR;
            } else {
                return ERROR;
            }
        case HEXADECIMAL:
            if(isxdigit(c)) {
                return HEXADECIMAL;
            } else {
                return ERROR;
            }
        case DECIMAL:
            if(isdigit(c)) {
                return DECIMAL;
            } else {
                return ERROR;
            }
        case ERROR:
            return ERROR;
    }
}

enum State classify(char* str) {
    enum State state = START;
    for(int i = 0; str[i] != ',' && str[i] != '\0'; i++) {
        state = nextState(state, str[i]);
    }
    return state;
}

const char* typeToString(enum State type) {
    switch(type) {
        case OCTAL:
            return "Octal";
        case HEXADECIMAL:
            return "Hexadecimal";
        case DECIMAL:
            return "Decimal";
        default:
            return "No reconocida";
    }
}

int main() {
    FILE *entrada, *salida;
    entrada = fopen("entrada.txt", "r");
    salida = fopen("salida.txt", "w");
    if(entrada == NULL || salida == NULL) {
        printf("Error al abrir los archivos");
        return 1;
    }
    char str[100];
    while(fscanf(entrada, "%[^,],", str) == 1) {
        enum State type = classify(str);
        fprintf(salida, "%s: %s\n", str, typeToString(type));
    }
    fclose(entrada);
    fclose(salida);
    return 0;
}
