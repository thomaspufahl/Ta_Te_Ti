//
// Created by Thomas Pufahl on 9/10/2022.
//

#ifndef TA_TE_TI_ALGORITMO_H
#define TA_TE_TI_ALGORITMO_H

#endif //TA_TE_TI_ALGORITMO_H
//1 PARA GANA J1
//2 PARA GANA J2
//3 PARA NO HAY ESPACIO EN TABLERO
//i = valor de fila
//j = valor de columna

int tateti(char matriz[][3], int cont) {
    int rta=0;
    ///FORMA DE TESTEAR
    //if (matriz[0][0]=='x') {rta=2;}
    if (cont==9) {rta=3;}
    ///TENGO QUE ENCONTRARLE LA VUELTA A ESTA SOLUCION
    /* PRIMER VERSION
    int repe=0;
    if (matriz[0][0]=='x')
    {
        for (int i = 0; i < 3; ++i) {
            if (matriz[0][i]=='x') {repe++;}
        }
    }
    if (repe == 3) {rta=1;}
    */

    ///la version que sigue no esta buena jaja, tengo que consultar por recorrer matrices y valores repetidos
    //SEGUNDA V PARA EL CASO DE GANA X
    // CONDICIONES HORIZONTALES
    if (matriz[0][0]==matriz[0][1]&&matriz[0][1]==matriz[0][2]&&matriz[0][0]=='x') {rta=1;}
    if (matriz[1][0]==matriz[1][1]&&matriz[1][1]==matriz[1][2]&&matriz[1][0]=='x') {rta=1;}
    if (matriz[2][0]==matriz[2][1]&&matriz[2][1]==matriz[2][2]&&matriz[2][0]=='x') {rta=1;}
    //CONDICIONES VERTICALES
    if (matriz[0][0]==matriz[1][0]&&matriz[1][0]==matriz[2][0]&&matriz[0][0]=='x') {rta=1;}
    if (matriz[0][1]==matriz[1][1]&&matriz[1][1]==matriz[2][1]&&matriz[0][1]=='x') {rta=1;}
    if (matriz[0][2]==matriz[1][2]&&matriz[1][2]==matriz[2][2]&&matriz[0][2]=='x') {rta=1;}
    //CONDICIONES DIAGONAL
    if (matriz[0][0]==matriz[1][1]&&matriz[1][1]==matriz[2][2]&&matriz[0][0]=='x') {rta=1;}
    if (matriz[0][2]==matriz[1][1]&&matriz[1][1]==matriz[2][0]&&matriz[0][2]=='x') {rta=1;}

    //PARA EL CASO GANA O ...
    // CONDICIONES HORIZONTALES
    if (matriz[0][0]==matriz[0][1]&&matriz[0][1]==matriz[0][2]&&matriz[0][0]=='o') {rta=2;}
    if (matriz[1][0]==matriz[1][1]&&matriz[1][1]==matriz[1][2]&&matriz[1][0]=='o') {rta=2;}
    if (matriz[2][0]==matriz[2][1]&&matriz[2][1]==matriz[2][2]&&matriz[2][0]=='o') {rta=2;}
    //CONDICIONES VERTICALES
    if (matriz[0][0]==matriz[1][0]&&matriz[1][0]==matriz[2][0]&&matriz[0][0]=='o') {rta=2;}
    if (matriz[0][1]==matriz[1][1]&&matriz[1][1]==matriz[2][1]&&matriz[0][1]=='o') {rta=2;}
    if (matriz[0][2]==matriz[1][2]&&matriz[1][2]==matriz[2][2]&&matriz[0][2]=='o') {rta=2;}
    //CONDICIONES DIAGONAL
    if (matriz[0][0]==matriz[1][1]&&matriz[1][1]==matriz[2][2]&&matriz[0][0]=='o') {rta=2;}
    if (matriz[0][2]==matriz[1][1]&&matriz[1][1]==matriz[2][0]&&matriz[0][2]=='o') {rta=2;}

    return rta;
}
