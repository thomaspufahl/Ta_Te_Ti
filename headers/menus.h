//
// Created by Thomas Pufahl on 9/10/2022.
//

#ifndef V1_MENUS_H
#define V1_MENUS_H

#endif //V1_MENUS_H

int menuPrincipal() {
    rlutil::setColor(rlutil::WHITE);
    int opc=0;
    int posy = 5;
    do{
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        label("JUGAR", 55, 5, posy==5);
        label("SALIR", 55, 7, posy==7);

        int key = rlutil::getkey();
        //KEY
        //up = 14
        //down = 15
        //enter = 1

        switch (key) {
            case 14:
                if (posy==5) {
                    posy=5;
                } else {posy-=2;}
                break;
            case 15:
                if (posy==7) {
                    posy=7;
                } else {posy+=2;}
                break;
            case 1:
                switch (posy) {
                    case 5:
                        opc=1;
                        break;
                    case 7:
                        opc=2;
                        break;
                    default:
                        opc=5;
                        break;
                }
                break;
            default:
                break;
        }
    }
    while (opc==0);
    return opc;
}

void Jugar() {
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();
    char players[2][35];
    char tablero[3][3];

    //la 'x'
    label("Jugador 1: ", 55, 5, false);
    rlutil::locate(55, 6);
    std::cin >> players[0];
    // la 'o'
    label("Jugador 2: ", 55, 8, false);
    rlutil::locate(55, 9);
    std::cin >> players[1];

    rlutil::cls();
    matrizZero(tablero);
    int fin = cargarMatriz(tablero, players);


    mostrarMatriz(tablero);
    rlutil::setColor(rlutil::YELLOW);
    label("FIN DEL JUEGO", 51, 12, false);
    if (fin == 1) {
        rlutil::locate(49, 14);
        rlutil::setColor(rlutil::RED);
        std::cout << "El ganador es " << strupr(players[0]) << "!" << std::endl;
    } else if (fin == 2) {
        rlutil::locate(49, 14);
        rlutil::setColor(rlutil::BLUE);
        std::cout << "El ganador es " << strupr(players[1]) << "!" << std::endl;
    } else if (fin == 3) {
        rlutil::locate(44, 14);
        std::cout << "Se quedaron sin posibilidades" << std::endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(39, 17);
    std::cout << "Pulsa cualquier tecla para volver al menu...";
    rlutil::anykey();
}
