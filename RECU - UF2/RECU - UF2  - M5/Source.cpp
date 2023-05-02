// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>


#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

//Atributos del juego 
int choiceenemy;
int choiceattack = 0;

// Atributos del enemigo
int enemyHP = 200;
int enemyDMG;
string enemyName = "Creeper";
bool enemyStatus = true;

//AAtributos del enemigo2
int enemyHP2 = 200;
int enemyDMG2;
string enemyName2 = "ElXocas";
bool enemyStatus2 = true;

// Atributos Heroe
int heroHP = 800;
string heroName;
int heroDamage;
bool heroStatus = true;
string Terratemblor = "Terratemblor";
int  heroattack1 = 50;
string GolpeFuria = "Golpe Furia";
int  heroattack2 = 100;
string Rayo = "Rayo";
int  heroattack3 = 70;

// ATRIBUTOS DE APLICACION 
int y = 50;
int& x = y;




void startgame() {
    cout << "El combate contra el " << enemyName << " y el " << enemyName2 << "va a empezar\n";
    Sleep(500);
    cout << "PREPARATE\n";
    cout << "Introduce el nombre de tu Heroe:\n";
    cin >> heroName;
    cout << "El nombre del Heroe es: " << heroName << "\n";
}
int enemyDamage(int x) {
    srand(time(NULL));
     enemyDMG = rand() % 100 + 1;

}
int enemyDamage2(int x) {
     enemyDMG2 = rand() % 100 + 1;


}
int enemyattackall(int x) {
    return heroHP = heroHP - (enemyDamage(enemyDMG) + enemyDamage2(enemyDMG2));
}
bool heroalive() {
    if (heroHP <= 0) {
        //--> heroHP = 0;
        cout << "El enemigo te ha matado\n";
        return false;

    }
    else if (heroHP > 0) {
        cout << "El enemigo te ha atacado, te quedan " << heroHP << " puntos de vida\n";
        return true;
    }

}
void eligeenemigo() {

  
    if (enemyStatus == true && enemyStatus2 == true) {
        cout << " [1] -- " << enemyName << "\n";
        cout << " [2] -- " << enemyName2 << "\n";
    }
    if (enemyStatus == true && enemyStatus2 == false) {
        cout << " [1] -- " << enemyName << "\n";

    }
    else if (enemyStatus == false && enemyStatus2 == true) {
        cout << " [2] -- " << enemyName2 << "\n";

    }
    cout << "A que enemigo quieres atacar?\n";
    cin >> choiceenemy;
}
void tipoataque() {

    if (choiceenemy == 1) {
        cout << "Que ataque quieres hacerle a " << enemyName << "\n";
        cout << " [1] -- " << Terratemblor << "\n";
        cout << " [2] -- " << GolpeFuria << "\n";
        cout << " [3] -- " << Rayo << "\n";
        cin >> choiceattack;
    }

    else if (choiceenemy == 2) {
        cout << "Que ataque quieres hacerle a " << enemyName2 << "\n";
        cout << " [1] -- " << Terratemblor << "\n";
        cout << " [2] -- " << GolpeFuria << "\n";
        cout << " [3] -- " << Rayo << "\n";
        cin >> choiceattack;
    }
}
void enemyataque() {
    // ATAQUES ENEMIGO 1------------------------------------------------------------------------------------------------------------------------------------------------// 

    if (choiceenemy == 1) {


        if (choiceattack == 1) {

            enemyHP = enemyHP - heroattack1;
            cout << "Has atacado al enemigo con " << Terratemblor << "\n";
        }
        else if (choiceattack == 2) {
            enemyHP = enemyHP - heroattack2;
            cout << "Has atacado al enemigo con " << GolpeFuria << "\n";
        }

        else if (choiceattack == 3) {
            enemyHP = enemyHP - heroattack3;
            cout << "Has atacado al enemigo con " << Rayo << "\n";
        }
    }
    // ATAQUES ENEMIGO 2----------------------------------------------------------------------------------------------------------------------------------------------// 

    else if (choiceenemy == 2) {

        if (choiceattack == 1) {

            enemyHP2 = enemyHP2 - heroattack1;
            cout << "Has atacado al enemigo con " << Terratemblor << "\n";
        }
        else if (choiceattack == 2) {
            enemyHP2 = enemyHP2 - heroattack2;
            cout << "Has atacado al enemigo con " << GolpeFuria << "\n";
        }

        else if (choiceattack == 3) {
            enemyHP2 = enemyHP2 - heroattack3;
            cout << "Has atacado al enemigo con " << Rayo << "\n";
        }
    }
}
void ataquealheroe() {
    heroHP = heroHP - enemyDMG;
}
void enemydamage() {

    //daño al enemigo
        // enemyHP = enemyHP - heroDamage;
    enemyDMG = rand() % 100 + 1;
    srand(time(NULL));

    // enemyHP2 = enemyHP2 - heroDamage;
    enemyDMG2 = rand() % 100 + 1;
    srand(time(NULL));

    if (enemyHP <= 0)
    {
        cout << "Te acabas de cargar al " << enemyName << "\n";
        enemyStatus = false;
    }

    if (enemyHP2 <= 0)
    {
        cout << "Te acabas de cargar al " << enemyName2 << "\n";
        enemyStatus2 = false;
    }

    else
    {

        cout << "Al " << enemyName << " le quedan " << enemyHP << " puntos de vida.\n";
        cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";
    }
}
int main() {

    startgame();


    //mientras los 2 esten vivos tienen que luchar. (se puede eliminar el "== true")
    while ((enemyStatus == true || enemyStatus2 == true) && heroStatus == true)
    {
        enemyattackall(heroHP);
        heroStatus = heroalive();
        if (heroStatus = true)

        eligeenemigo();
        tipoataque();
        enemyataque();
        enemydamage();


            if (enemyHP2 <= 0 && enemyHP <= 0) {
                heroHP = 0;
                cout << "Han muerto todos los enemigos\n";

            }
            else if (enemyHP2 > 0 && enemyHP > 0) {
                heroHP = 0;
                cout << "Los dos enemigos estan vivos, atacales\n";
            }
            
          
           
    }
}
