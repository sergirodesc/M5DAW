#include "Personaje.h"
#include "EnemigoFinal.h"
#include <iostream>	
#include <windows.h>


const int FILAS = 6;
const int COLUMNAS = 8;
const int NUM_ENEMIGOS = 6;

Personaje Personaje1("himel", 0, 0, 0, 1), EnemigoFinal("AHMED",0, 0, 0, 1);



void mapa(const std::string array[FILAS][COLUMNAS]) {
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


int main() {

        std::string array[FILAS][COLUMNAS];

        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                array[i][j] = "[ ]";
            }
        }

        int posX = 0;
        int posY = 0;
        array[posY][posX] = "\x1B[31m[X]\x1B[0m";  

        srand(static_cast<unsigned int>(time(0)));
        for (int j = 1; j < COLUMNAS - 1; j++) {
            int randFila = rand() % (FILAS - 2) + 1;  
            array[randFila][j] = "\x1B[31m[X]\x1B[0m";  
        }

        int metaColumna = rand() % (COLUMNAS - 2) + 1;  
        array[FILAS - 1][metaColumna] = "\x1B[34m[M]\x1B[0m"; 


        char direccion;
        bool victoria = false;

        while (!victoria) {
            mapa(array);

            std::cout << "Ingrese una dirección (w: arriba, s: abajo, a: izquierda, d: derecha): ";
            std::cin >> direccion;

            if (direccion == 'w' && posY > 0) {
                array[posY][posX] = "[ ]";
                posY--;
            }
            else if (direccion == 's' && posY < FILAS - 1) {
                array[posY][posX] = "[ ]";
                posY++;
            }
            else if (direccion == 'a' && posX > 0) {
                array[posY][posX] = "[ ]";
                posX--;
            }
            else if (direccion == 'd' && posX < COLUMNAS - 1) {
                array[posY][posX] = "[ ]";
                posX++;
            }
            else {
                std::cout << "Dirección no válida. Inténtelo de nuevo." << std::endl;
                continue;
            }

            array[posY][posX] = "[X]";

            if (posY == FILAS - 1 && posX == metaColumna) {
                victoria = true;
                break;
            }
        }
        if (victoria) {
                for (int i = 0; i < 1; ++i)
                {
                    std::cout << "\n\n\033[1;31m             _____                    _____                    _____                    _____                    _____                   _______                   _____ \033[0m" << std::endl;
                    Sleep(50); 
                    std::cout << " \033[1;33m              /\\   \\                 /\\    \\                  /\\    \\                   /\\    \\               /\\    \\                          /::\\    \\                 /\\    \\ \033[0m" << std::endl;
                    Sleep(50);  
                    std::cout << " \033[1;32m             /::\\   \\               /::\\    \\                /::\\____\\                 /::\\    \\             /::\\     \\                       /::::\\    \\               /::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;36m           /::::\\   \\              /::::\\    \\              /::::|   |                  /::::\\    \\            /::::\\     \\                    /::::::\\    \\             /::::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;34m         /::::::\\    \\            /::::::\\    \\             /:::::|   |                /::::::\\    \\           /::::::\\     \\                 /::::::::\\    \\           /::::::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;35m        /:::/\\:::\\   \\          /:::/\\:::\\    \\           /::::::|   |              /:::/\\:::\\    \\        /:::/\\:::\\     \\             /:::/~~\\:::\\    \\         /:::/\\:::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;31m      /:::/  \\:::\\    \\        /:::/__\\:::\\    \\         /:::/|::|   |             /:::/__\\:::\\    \\       /:::/  \\:::\\     \\          /:::/    \\:::\\    \\       /:::/__\\:::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;33m     /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\       /:::/ |::|   |           /::::\\   \\:::\\    \\     /:::/    \\:::\\     \\      /:::/    / \\:::\\    \\     /::::\\   \\:::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;32m    /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\     /:::/  |::|   | _____    /::::::\\   \\:::\\    \\    /:::/    / \\:::\\     \\   /:::/____/   \\:::\\____\\   /::::::\\   \\:::\\    \\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;36m  /:::/    /   \\:::\\ ___ \\  /:::/\\:::\\   \\:::\\    \\  /:::/   |::|   |/\\    \\  /:::/\\:::\\   \\:::\\   \\ /:::/    /   \\:::\\ ___\\ |:::|    |      |:::|    | /:::/\\:::\\   \\:::\\____\\\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;34m/:::/____/  ___\\:::|    |/:::/  \\:::\\   \\:::\\____\\/:: /    |::|   /::\\____\\/:::/  \\:::\\   \\:::\\____\\/:::/____/     \\:::|    ||:::|____|    |:::|    |/:::/  \\:::\\   \\:::|    |\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;35m \\:::\\    \\ /\\  /:::|____|\\::/    \\:::\\  /:::/    /\\::/    /|::|  /:::/    /\\::/    \\:::\\  /:::/    /   \\:::\\    \\     /:::|____| \\:::\\    \\   /:::/    / \\::/   |::::\\  /:::|____|\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;31m \\:::\\    /::\\ \\::/    /  \\/____/ \\:::\\/:::/    /  \\/____/ |::| /:::/    /  \\/____/ \\:::\\/:::/    /     \\:::\\    \\   /:::/    /   \\:::\\    \\ /:::/    /   \\/____|:::::\\/:::/    /\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;33m  \\:::\\   \\:::\\ \\/____/            \\::::::/    /           |::|/:::/    /            \\::::::/    /          \\:::\\    \\ /:::/    /       \\:::\\    /:::/    /          |:::::::::/    /\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;32m   \\:::\\   \\:::\\____\\               \\::::/    /            |::::::/    /              \\::::/    /           \\:::\\    /:::/    /           \\:::\\__/:::/    /           |::|\\::::/    \033[0m" << std::endl;
                    Sleep(50); 
                    std::cout << "  \033[1;36m   \\:::\\   \\::/    /                /:::/    /             |:::::/    /               /:::/    /               \\:::\\/:::/    /                 \\::::::/    /              |::| \\::/____/\033[0m" << std::endl;
                    Sleep(50);
                    std::cout << "  \033[1;34m    \\:::\\   \\::/    /             /:::/    /              |::::/    /               /:::/    /                 \\::::::/    /                     \\::::/    /               |::|  ~|     \033[0m" << std::endl;
                    Sleep(50);
                    std::cout << "  \033[1;35m     \\::::::/    /                /:::/    /               /:::/    /               /:::/    /                  \\::::/    /                         \\::/____/                \\::|   |     \033[0m" << std::endl;
                    Sleep(50); 
                    std::cout << " \033[1;31m       \\::::/    /               /:::/    /               /:::/    /               /:::/    /                    \\::/____/                             ~~                       \\:|   |     \033[0m" << std::endl;
                    Sleep(50);
                    std::cout << " \033[1;33m        \\::/____/              \\::/    /                \\::/    /               \\::/    /                       ~~                                                             \\|___|     \033[0m" << std::endl;
                    Sleep(50);

          
                }

            }
        else {
            std::cout << "¡Has perdido la partida! Te han capturado." << std::endl;
        }

        return 0;
}

