#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void marquesina() {
    printf("++++++++++++++++++++++++++++++++++++++\n");
    printf("            Trileros               \n");
    printf("++++++++++++++++++++++++++++++++++++++\n");
}

void pintaTablero(char m[3]) {
    printf("Tablero: [");
    for (int i = 0; i < 3; i++) {
        printf("%c", m[i]);
        if (i < 2) printf(", ");
    }
    printf("]\n");
}

void rellenaTablero(char m[3]) {
    for (int i = 0; i < 3; i++) {
        m[i] = 'X';
    }
}

void revisarApuesta(int b, int u, int* c, int* c1) {
    if (b == u) {
        printf("Lo has adivinado! La bola estaba en la posicion %d.\n", b);
        (*c)++;
    }
    else
    {
        printf("No lo has adivinado. La bola estaba en la posicion %d.\n", b);
        (*c1)++;
    }
}

int main () {

    char tablero[3];
    int bola, usuario, contadorUsuario = 0, contadorOrdenador = 0;
    char seguir;

    srand(time(NULL));

    marquesina();

    do {

        rellenaTablero(tablero);
        bola = rand() % 3;
        tablero[bola] = '0';

        pintaTablero(tablero);
        printf("Donde podria estar la bola? (0, 1, 2): ");
        scanf("%d", &usuario);

        revisarApuesta(bola, usuario, &contadorUsuario, &contadorOrdenador);

        printf("Partidas ganadas - Usuario: %d, Ordenador: %d\n", contadorUsuario, contadorOrdenador);

        printf("Quieres jugar otra vez? (s/n): ");
        scanf(" %c", &seguir);

    } while (seguir == 's' || seguir == 'S');

    printf("Gracias por jugar:\n");
    printf("Usuario: %d victorias\n", contadorUsuario);
    printf("Maquina: %d victorias\n", contadorOrdenador);

    if (contadorOrdenador > contadorUsuario) {
        printf("La maquina ha ganado\n");
    }
    else if (contadorOrdenador < contadorUsuario) {
        printf("Ganaste, felicidades!\n");
    }
    else {
        printf("Es empate!\n");
    }

    return 0;

}
