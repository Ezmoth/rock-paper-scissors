#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;


void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void view_menu() {
    cout << "/---------------------------------------------------------\\\n";
    cout << "|                                                         |\n";
    cout << "| Welcome to the Rock, Paper Scissors!                    |\n";
    cout << "|                                                         |\n";
    cout << "| 1. Start game!                                          |\n";
    cout << "| 2. View the score.                                      |\n";
    cout << "| 3. Exit.                                                |\n";
    cout << "|                                                         |\n";
    cout << "\\---------------------------------------------------------/" << endl;
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

int game_round() {
    string choice[3] = {"Rock", "Paper", "Scissors"};
    cout << "Enter your choice: ";
    int pl_choice = player_choice()-1;
    int comp_choice = computer_choice();

    cout << "You have chosen " << choice[pl_choice] << "!" << endl;
    cout << "Computer throws... " << choice[comp_choice] << "!" << endl;

    if (pl_choice == 0 && comp_choice == 2) {
        cout << "You have won!" << endl;
        return 1;
    } else if (pl_choice == 1 && comp_choice == 0) {
        cout << "You have won!" << endl;
        return 1;
    } else if (pl_choice == 2 && comp_choice == 1) {
        cout << "You have won!" << endl;
        return 1;
    } else if (pl_choice == 0 && comp_choice == 1) {
        cout << "You lose!" << endl;
        return 2;
    } else if (pl_choice == 1 && comp_choice == 2) {
        cout << "You lose!" << endl;
        return 2;
    } else if (pl_choice == 2 && comp_choice == 0) {
        cout << "You lose!" << endl;
        return 2;
    } else {
        cout << "It's a draw!" << endl;
        return 0;
    }
}

void game() {
    int round = 1;
    int comp_score, pl_score, draw = 0;
    
    while (round <= 3) {
        cout << "Current round: " << round << endl;
        int current_round = game_round();
        if (current_round == 1) {
            pl_score++;
        } else if (current_round == 2) {
            comp_score++;
        } else {
            draw++;
        }
        round++;
    }
    cout << "Player score: " << pl_score << endl;
    cout << "Computer score: " << comp_score << endl;
    cout << "Draws: " << draw << endl;
}

int main() {
    int comp_score, pl_score = 0;
    srand(time(0));
    //view_menu();
    //round();
    game();
    //cin.ignore(); -- Remove comment before ending the project
    return 0;
}