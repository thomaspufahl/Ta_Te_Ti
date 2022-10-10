#include "../headers/rlutil.h"
#include "../headers/funciones.h"
#include "../headers/menus.h"



int main() {
    int opc;
    do {
        rlutil::cls();
        label("TA-TE-TI!", 53, 2, false);
        opc = menuPrincipal();
        switch (opc) {
            case 1:
                Jugar();
                break;
            case 2:
                return 0;
            default:
                break;
        }
    } while (true);
}
