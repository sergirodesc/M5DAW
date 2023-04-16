#include "Barca.h"
#include <iostream>	
#include <windows.h>
#include <mmsystem.h>
#include <random>
#pragma comment(lib, "winmm.lib")

int turnos = 0;
int random;
int choice;
int num;
barca barca1("MOHA ", 0, 0, 1), barca2("AHMED", 0, 0, 1);

void inicioJuego() {
	std::cout << " Que comience la carrera de Barcas " << std::endl;
	std::cout << " Por el lado derecho tenemos al concursante numero 1, la " << barca1.getName() << std::endl;
	std::cout << " Y Por el otro lado  tenemos al concursante numero 2, la " << barca2.getName() << std::endl;
	std::cout << " La carrera empezara en breves ..." << std::endl;
	Sleep(800);
	std::cout << " PREPARADOS " << std::endl;
	Sleep(800);
	std::cout << " LISTOS " << std::endl;
	Sleep(900);
	std::cout << " YA " << std::endl; PlaySound(TEXT("Disparo.wav"), NULL, SND_FILENAME);

}





int main() {
	srand(time (NULL));
	inicioJuego();

	while (turnos < 5)
	{
		std::cout << " $$$$$$$$$$$$$$$$$$$$$$$$    RONDA " << turnos << "    $$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
		

		barca1.dadoVel();
		barca2.dadoVel();

		barca1.distanciaLancha();
		barca2.distanciaLancha();

		barca1.turbo();
		barca2.turbo();

		barca1.printStats();
		barca2.printStats();


		turnos++;
	}
	return 0;


}