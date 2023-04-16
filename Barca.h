#pragma once
#include <iostream>

class barca
{

private:
	std::string name;
	int velocidad;
	int distancia;
	int nitro;

public:

	//Constructor 
	barca(std::string pName, int pVelocidad, int pDistancia, int pNitro);

	//Getters
	std::string getName();
	int getVelocidad();
	int getDistancia();
	int getNitro();

	//Setters
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	void setName(std::string pName);
	void setNitro(int pNitro);

	//Methods
	void printStats();
	void turbo();
	void dadoVel();
	void distanciaLancha();
};

