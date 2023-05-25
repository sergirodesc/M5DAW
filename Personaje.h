#pragma once
#include <iostream>

class Personaje
{

	private:
		std::string name;
		int vida;
		int ataque;
		int posicionX;
		int posicionY;


	public:

		//Constructor 
		Personaje(std::string pName, int pVida, int pAtaque, int pPosicionX, int pPosicionY);

		//Getters
		std::string getName();
		int getVida();
		int getAtaque();
		int getPosicionX();
		int getPosicionY();


		//Setters
		void setName(std::string pName);
		void setVida(int pVida);
		void setAtaque(int pAtaque);
		void setPosicionX(int pPosicionX);
		void setPosicionY(int pPosicionY);

		//Methods
		void printStats();
	};


