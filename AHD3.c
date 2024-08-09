#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void guardarmiElTexto(char *ElTexto, const char *NombreDeMiArchivo) {
    FILE *papux = fopen(NombreDeMiArchivo, "wb");
    if (papux == NULL) {
        printf("Error al abrir el archivo %s.\n", NombreDeMiArchivo);
    }

    fprintf(papux, "%s", ElTexto);
    fclose(papux);
    printf("El texto se guardo %s con exito.\n", NombreDeMiArchivo);
}


void GuardarInfo(char *ElTexto, const char *NombreDeMiArchivo) {
    FILE *papux = fopen(NombreDeMiArchivo, "wb");
    if (papux == NULL) {
        printf("Error al abrir el archivo %s.\n", NombreDeMiArchivo);
    }
    fwrite(ElTexto, sizeof(char), strlen(ElTexto), papux);
    fclose(papux);
    printf("Texto guardado en formato binario %s con exito.\n", NombreDeMiArchivo);
}


int main() {
    char ElTexto[100];
    char NombreDeMiArchivo[100];
    
    int opcion;
    while(opcion){
        printf("1. Ingresar el texto\n");
        printf("2. Guardar el texto en archivo .bin\n");
        printf("3. Guardar El texto en archivo .txt\n");
        printf("4. Salir\n");
        printf("Seleccione la opcion que deseas: ");
        scanf("%d", &opcion);
        getchar();


        switch (opcion) {
            case 1:
                printf("Ingresa una cadena:\n");
                scanf("%[^\n]", ElTexto);
                break;
            case 2:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", NombreDeMiArchivo);
                strcat(NombreDeMiArchivo, ".bin");
                GuardarInfo(ElTexto, NombreDeMiArchivo);
                break;
            case 3:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", NombreDeMiArchivo);
                strcat(NombreDeMiArchivo, ".txt");
                guardarmiElTexto(ElTexto, NombreDeMiArchivo);
                break;
            default:
                printf("Opcion no válida.\n");
        }
    }
}
