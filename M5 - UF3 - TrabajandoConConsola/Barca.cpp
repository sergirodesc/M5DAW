#include "Barca.h"


//constructor 
barca::barca(std::string pName, int pVelocidad, int pDistancia, int pNitro) {
	name = pName;
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;

}

//getters

int barca::getVelocidad() {
	return velocidad;
}

int barca::getDistancia() {
	return distancia;
}

std::string barca::getName() {
	return name;
}

int barca::getNitro() {
	return nitro;
}
//setters

void barca::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}

void barca::setDistancia(int pDistancia) {
	distancia = pDistancia;
}

void barca::setName(std::string pName) {
	name = pName;
}

void barca::setNitro(int pNitro) {
	nitro = pNitro;
}

//Methods

void barca::printStats() {
	std::cout << " VELOCIDAD " << getVelocidad()  << std::endl;
	std::cout << " DISTANCIA RECORRIDA " << getDistancia() << std::endl;

}


void barca::turbo() {
	
	if (getNitro() == 1) {
		std::cout << " Quieres usar el turbo ahora? \n";
		std::cout << " USALO YA [1] \n";
		std::cout << " Mejor lo reservamos para otro momento [2] ";
		int choice = 0;
		std::cin >> choice;
		
		if (choice == 1) {

			if ((rand() % 1) == 0) {
					
				setVelocidad(getVelocidad()  * 2);
			}
			else {
				setVelocidad(getVelocidad()  / 2);
			}

		}
		else if (choice == 2) {
			std::cout << " Sigamos entonces \n";

		}
	}
}

void barca::dadoVel() {
	setVelocidad(getVelocidad() + (rand() % (6 + 1)));
}

void barca::distanciaLancha() {
	setDistancia(getDistancia() + getVelocidad() * 100);
}

