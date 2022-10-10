//
// Created by Thomas Pufahl on 9/10/2022.
//

#ifndef V1_FUNCIONES_H
#define V1_FUNCIONES_H

#endif //V1_FUNCIONES_H

#include "algoritmo.h"

void label(const char* texto, int x, int y, bool seleccionado){
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    rlutil::locate(x, y);
    std::cout << texto << std::endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void matrizZero(char matriz[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matriz[i][j]='*';
        }
    }
}

void mostrarMatriz(char matriz[][3]) {
    int cont=2;
    for (int i = 0; i < 3; ++i) {
        rlutil::locate(45, cont);
        cont+=3;
        for (int j = 0; j < 3; ++j) {
            if (j==2) {
                if (matriz[i][j]=='x'){
                    rlutil::setColor(rlutil::RED);
                } else if(matriz[i][j]=='o') {
                    rlutil::setColor(rlutil::BLUE);
                }
                std::cout << "\t" << matriz[i][j] << std::endl;
                rlutil::setColor(rlutil::WHITE);
            } else {
                if (matriz[i][j]=='x'){
                    rlutil::setColor(rlutil::RED);
                } else if (matriz[i][j]=='o'){
                    rlutil::setColor(rlutil::BLUE);
                }
                std::cout << "\t" << matriz[i][j];
                rlutil::setColor(rlutil::WHITE);
            }
        }
        std::cout << std::endl;
    }

}

int cargarMatriz (char matriz[][3], char vec[][35]) {
    //TURNO TRUE = JUGADOR 1 || vec[0]
    //TURNO FALSE = JUGADOR 2 || vec[1]
    bool bTurno = true;
    int fila;
    int columna;
    int rta;
    int turnos=0;
    rta = tateti(matriz, turnos);
    while (rta==0) {
        turnos++;
        rlutil::setColor(rlutil::WHITE);
        mostrarMatriz(matriz);
        if (bTurno) {
            rlutil::setColor(rlutil::RED);
            rlutil::locate(47, 12);
            std::cout << "\tJUEGA " << strupr(vec[0]) << std::endl;
            rlutil::locate(49, 14);
            std::cout << "Fila(-): ";
            std::cin >> fila;
            rlutil::locate(49, 15);
            std::cout << "Columna(|): ";
            std::cin >> columna;
            matriz[fila-1][columna-1]='x';
            rlutil::cls();
            bTurno = false;
        } else {
            std::cout << std:: endl;
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(47, 12);
            std::cout << "\tJUEGA " << strupr(vec[1]) << std::endl;
            rlutil::locate(49, 14);
            std::cout << "Fila(-): ";
            std::cin >> fila;
            std::cout << std:: endl;
            rlutil::locate(49, 15);
            std::cout << "Columna(|): ";
            std::cin >> columna;
            matriz[fila-1][columna-1]='o';
            rlutil::cls();
            bTurno = true;
        }
        std::cout << std:: endl;
        rta = tateti(matriz, turnos);
    }
    return rta;
}