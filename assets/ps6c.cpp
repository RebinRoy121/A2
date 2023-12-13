#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void GenerateCpuLocation(int& cpuAxisX, int& cpuAxisY);
void PrintIntro();
void AssignPlayerPosition(int& playerAxisX, int& playerAxisY);
void calcDistance(int& subofX, int& subofY, int& powerofX, int& powerofY, int& distance, int& cpuAxisX, int& cpuAxisY, int& playerAxisX, int& playerAxisY);
void DetermineColour(int& cpuAxisX, int& cpuAxisY, int& playerAxisX, int& playerAxisY);
void PlayerMovement(int& userInput, int& playerAxisX, int& playerAxisY);
void CheckPosition(int& playerAxisX, int& playerAxisY, bool& playerOnBoard);
void PrintWon();

int main() {

    int cpuX = 0;
    int cpuY = 0;
    int playerX = 0;
    int playerY = 0;
    bool onBoard = true;
    int choice = 0;
    int subX = 0;
    int subY = 0;
    int powerX = 0;
    int powerY = 0;
    int result = 0;

    GenerateCpuLocation(cpuX, cpuY);

    PrintIntro();

    AssignPlayerPosition(playerX, playerY);

    while (!(cpuX == playerX && cpuY == playerY)) {
        calcDistance(subX, subY, powerX, powerY, result, cpuX, cpuY, playerX, playerY);

        DetermineColour(cpuX, cpuY, playerX, playerY);

        do {
            onBoard = true;

            PlayerMovement(choice, playerX, playerY);

            CheckPosition(playerX, playerY, onBoard);

        } while (onBoard == false);
    };
    PrintWon();

    return 0;
}



void GenerateCpuLocation(int& cpuAxisX, int& cpuAxisY) {
    srand(time(0));
    cpuAxisX = rand() % 8 + 1;
    cpuAxisY = rand() % 8 + 1;
}
void PrintIntro() {
    cout << "Welcome to the the game" << endl;
    cout << "Your opponent is hiding in this space" << endl;
    cout << "Find and kill your opponent" << endl;
}
void AssignPlayerPosition(int& playerAxisX, int& playerAxisY) {
    do {
        cout << "Choose your position" << endl;
        cout << "Enter your X axis" << endl;
        cin >> playerAxisX;
        cout << "Enter your Y axis" << endl;
        cin >> playerAxisY;
    } while (!((playerAxisX >= 1 && playerAxisX <= 8) && (playerAxisY >= 1 && playerAxisY <= 8)));

}
void calcDistance(int& subofX, int& subofY, int& powerofX, int& powerofY, int& distance, int& cpuAxisX, int& cpuAxisY, int& playerAxisX, int& playerAxisY) {
    subofX = cpuAxisX - playerAxisX;
    subofY = cpuAxisY - playerAxisY;
    powerofX = pow(subofX, 2);
    powerofY = pow(subofY, 2);
    distance = sqrt(powerofX + powerofY);
    cout << " Distance Between you and your opponent is  " << distance << endl;
}
void DetermineColour(int& cpuAxisX, int& cpuAxisY, int& playerAxisX, int& playerAxisY) {
    if ((cpuAxisX + cpuAxisY) % 2 == 0) {
        cout << " OPPONENT is at WHITE square " << endl;
    }
    else {
        cout << " OPPONENT is at BLACK square " << endl;
    }

    if ((playerAxisX + playerAxisY) % 2 == 0) {
        cout << " YOU is at WHITE square " << endl;
    }
    else {
        cout << " YOU is at BLACK square " << endl;
    }
}
void PlayerMovement(int& userInput, int& playerAxisX, int& playerAxisY) {
    enum {
        UP = 1,
        DOWN,
        LEFT,
        RIGHT
    };
    do {
        cout << "Your current position is ( " << playerAxisX << " , " << playerAxisY << " )" << endl;

        cout << "Enter 1 for up" << endl;
        cout << "Enter 2 for down" << endl;
        cout << "Enter 3 for left" << endl;
        cout << "Enter 4 for right" << endl;

        cin >> userInput;
    } while (!(userInput >= 1 && userInput <= 4));

    switch (userInput)
    {
    case UP: {
        playerAxisY += 1;
        break;
    };
    case DOWN: {
        playerAxisY -= 1;
        break;
    };
    case LEFT: {
        playerAxisX -= 1;
        break;
    };
    case RIGHT: {
        playerAxisX += 1;
        break;
    };
    }
}
void CheckPosition(int& playerAxisX, int& playerAxisY, bool& playerOnBoard) {
    if (playerAxisX >= 9 || playerAxisX <= 0 || playerAxisY >= 9 || playerAxisY <= 0) {

        playerOnBoard = false;

    }
}
void PrintWon() {
    cout << endl << endl << "YOU WON!" << endl << endl;
    cout << "....Congrats...." << endl << endl;
}
