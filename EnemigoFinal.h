#pragma once
#include "Personaje.h"

class EnemigoFinal : public Personaje
{


	public:

		int ice_attack;
		int fire_attack;


	private:
		EnemigoFinal(std::string pName, int pVida, int pAtaque, int pPosicionX, int pPosicionY, int ice_attack, int fire_attack);


	//getters
		int get_ice_attack();
		int get_fire_attack();


	//setters
		void set_ice_attack(int pIce_attack);
		void set_fire_attack(int pFire_attack);


	//contructores
		


	//methods
};
