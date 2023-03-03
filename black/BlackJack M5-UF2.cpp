
#include <iostream>

using namespace std;

int picas[13];  //CAMBIAR A 13
int corazones[13];
int trebol[13];
int diamantes[13];
int AS[1];


//int AS[1] [11];
int J, K, Q = 10;
bool gameOver = false;

//Player 1
string player1;
int pointsPlayer1 = 0;
bool surrender1 = false;
bool winnerP1 = false;
bool loserP1 = false;

//Player 2
string player2 = "Croupiere";
int pointsPlayer2 = 0;
bool surrender2 = false;
bool winnerP2 = false;
bool loserP2 = false;

void startArray(int(&pArray)[13]) {
    for (int i = 0; i < 13; i++) {
        pArray[i] = 1;
    }
}

void chooseCards(int& totalPoints, string player) {
    bool choosed = false;
    int indCarta = 0;
    string tipoPalo;
    while (!choosed)
    {
        indCarta = rand() % 13;  //3
        int palo = (rand() % 4);  //1
        totalPoints += indCarta + 1;

        if (palo == 0) {
            if (picas[indCarta] == 1) {
                picas[indCarta] == 0;
                choosed = true;
                tipoPalo = "picas";
            }
        }
        else if (palo == 1) {
            if (trebol[indCarta] == 1) {
                trebol[indCarta] = 0;
                choosed = true;
                tipoPalo = "trebol";
            }
        }
        else if (palo == 2) {
            if (corazones[indCarta] == 1) {
                corazones[indCarta] = 0;
                choosed = true;
                tipoPalo = "corazones";
            }
        }
        else {
            if (diamantes[indCarta] == 1) {
                diamantes[indCarta] = 0;
                choosed = true;
                tipoPalo = "diamantes";
            }
        }


    }




    //SI ES UN AS, HAY QUE CONTROLAR SI QUIERO UN 1 O UN 11
    //SI ES J , Q , K PONER QUE VALGA 10

    if (indCarta == 0) {
        cout << " El  " << player << " ha sacado un AS de " << tipoPalo << " y tiene un total de " << totalPoints << "\n";
    }

    if (indCarta == 0) {
        cout << "Elige el valor de tu AS" << endl;
        cout << "[1] Valor 1" << endl;
        cout << "[2] Valor 11" << endl;
        int choice = 0;
        cin >> choice;
        if (choice == 1) {
            indCarta = 1;
            cout << " Como has elegido la opcion 1 ahora tienes un total de " << totalPoints << "\n";

        }
        else if (choice == 2) {
            indCarta = 11;
            cout << " Como has elegido la opcion 2 ahora tienes un total de " << totalPoints + 10 << "\n";

        }
    }

    else if (indCarta == 10 || indCarta == 11 || indCarta == 12) {
        if (indCarta == 10) {
            cout << " El  " << player << " ha sacado un " << indCarta -1<< " de " << tipoPalo << " y tiene un total de " << totalPoints << "\n";

        }
        else if (indCarta == 11) {
            cout << " El  " << player << " ha sacado un " << indCarta  << " de " << tipoPalo << " y tiene un total de " << totalPoints << "\n";
            

        }
        else if (indCarta == 12) {
            cout << " El  " << player << " ha sacado un " << indCarta  << " de " << tipoPalo << " y tiene un total de " << totalPoints << "\n";

        }
       
    }
    else {
        cout << " El  " << player << " ha sacado un " << indCarta +1 << " de " << tipoPalo << " y tiene un total de " << totalPoints << "\n";
    }

}

bool checkPoints(int& points, bool& winner, bool& loser) {
    if (points == 21) {
        winner = true;
        return true;
    }
    else if (points > 21) {
        loser = true;
        return true;
    }
    return false;
}
bool checkWhoWins(int points1, int points2, bool& winner2) {
    if (points2 > points1) {
        winner2 = true;
        return true;
    }
    else {
        return false;
    }
}



int main()
{

    cout << "Vamos a jugar al BLACKJACK\n";
    cout << "¿Como te llamas?\n";
    cin >> player1;
    cout << " Empezemos " << player1 << "\n";



    startArray(picas);
    startArray(diamantes);
    startArray(corazones);
    startArray(trebol);
    srand(time(NULL));

    //reparto

    chooseCards(pointsPlayer1, player1);
    cout << "Se te repartira otra carta....\n";
    chooseCards(pointsPlayer1, player1);



    //surrender

    surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
    chooseCards(pointsPlayer2, player2);

    while (!surrender1) {
        int choice = 0;

        while (choice != 1 && choice != 2) {
            cout << " Tienes " << pointsPlayer1 << " Quieres pedir una carta? \n";
            cout << " Si [1] \n";
            cout << " Me retiro [2] ";
            cin >> choice;
            if (choice != 1 && choice != 2) {
                cout << " Por favor, elije una de las 2 opciones indicadas ";
            }
        }

        if (choice == 1) {
            chooseCards(pointsPlayer1, player1);
            surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
        }
        else {
            surrender1 = true;
        }


    }
    if (winnerP1) {
        cout << " El jugador " << player1 << " gana y la banca pierde ";
    }
    else if (loserP1) {
        cout << " El jugador " << player1 << " pierde y la banca gana ";
    }
    else {
        while (!surrender2) {
            chooseCards(pointsPlayer2, player2);
            surrender2 = checkPoints(pointsPlayer2, winnerP2, loserP2);
            if (!surrender2) {
                surrender2 = checkWhoWins(pointsPlayer1, pointsPlayer2, winnerP2);
            }
        }
        if (winnerP2) {
            cout << " La banca gana y el jugador " << player1 << " pierde ";
        }
        else if (loserP2) {
            cout << " La banca pierde y el jugador " << player1 << " gana";
        }
    }



}

