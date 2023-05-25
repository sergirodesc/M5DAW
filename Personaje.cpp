#include "Personaje.h"

//constructor 
Personaje::Personaje(std::string pName, int pVida, int pAtaque, int pPosicionX, int pPosicionY) {
	name = pName;
	vida = pVida;
	ataque = pAtaque;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
}

//getters
std::string Personaje::getName() {
	return name;
}

int Personaje::getVida() {
	return vida;
}

int Personaje::getAtaque() {
	return ataque;
}

int Personaje::getPosicionX() {
	return posicionX;
}

int Personaje::getPosicionY() {
	return posicionY;
}

//setters

void Personaje::setName(std::string pName) {
	name = pName;
}

void Personaje::setVida(int pVida) {
	vida = pVida;
}

void Personaje::setAtaque(int pAtaque) {
	ataque = pAtaque;
}

void Personaje::setPosicionX(int pPosicionX) {
	posicionX = pPosicionX;
}
void Personaje::setPosicionY(int pPosicionY) {
	posicionY = pPosicionY;
}



//Methods

void Personaje::printStats() {
	std::cout << "K";
}
