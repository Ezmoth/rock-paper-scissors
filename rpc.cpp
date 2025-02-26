#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

void greet() {
    cout << "Welcome to the game!" << endl;
    cout << "Press 1 to play" << endl;
    cout << "Press 2 to see the score" << endl;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu() {
    cout << "/-----\\" << endl;
    cout << "\\-----/" << endl;
}

int computer_choice() {
    int choice = rand() % 3;
    return choice;
}

int player_choice() {
    int choice;
    cin >> choice;
    if (choice > 3 || choice < 1) {
        cout << "Invalid number! Must be 1, 2 or 3" << endl;
        return player_choice();
    }
    clearInput();
    return choice;
}

void game() {
    string choice[3] = {"Rock", "Paper", "Scissors"};
    cout << "Enter your choice: ";
    int pl_choice = player_choice()-1;
    int comp_choice = computer_choice();

    cout << "You have chosen " << choice[pl_choice] << "!" << endl;
    cout << "Computer throws... " << choice[comp_choice] << "!" << endl;

    if (pl_choice == 0 && comp_choice == 2) {
        cout << "You have won!" << endl;
    } else if (pl_choice == 1 && comp_choice == 0) {
        cout << "You have won!" << endl;
    } else if (pl_choice == 2 && comp_choice == 1) {
        cout << "You have won!" << endl;
    } else if (pl_choice == 0 && comp_choice == 1) {
        cout << "You lose!" << endl;
    } else if (pl_choice == 1 && comp_choice == 2) {
        cout << "You lose!" << endl;
    } else if (pl_choice == 2 && comp_choice == 0) {
        cout << "You lose!" << endl;
    } else {
        cout << "It's a draw!";
    }
}

int main() {
    srand(time(0));
    //greet();
    //menu();
    game();

    return 0;
}