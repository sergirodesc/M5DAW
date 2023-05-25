#include "EnemigoFinal.h"
#include "Personaje.h"

using namespace std;

//getters
int EnemigoFinal::get_ice_attack() {
	return ice_attack;
}
int EnemigoFinal::get_fire_attack() {
	return fire_attack;
}



//setters

void EnemigoFinal::set_ice_attack(int pIce_attack ) {
	ice_attack = pIce_attack;
}

void EnemigoFinal::set_fire_attack(int pFire_attack) {
	fire_attack = pFire_attack;
}


//Contructor
EnemigoFinal::EnemigoFinal(string pName, int pVida, int pAtaque, int pPosicionX, int pPosicionY, int pIce_attack, int pFire_attack) 
	:Personaje( pName, pVida, pAtaque, pPosicionX, pPosicionY) {
	ice_attack = pIce_attack; 
	fire_attack = pFire_attack; 
}

//Methods

