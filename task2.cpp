#include <iostream>
using namespace std;

//Function to display the game board
void print_state(string game_state[3][3]) {

	string display_game = "   0     1     2  \n"
		"      |     |     \n"
		"0  " + game_state[0][0] + "  |  " + game_state[0][1] + "  |  " + game_state[0][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"1  " + game_state[1][0] + "  |  " + game_state[1][1] + "  |  " + game_state[1][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"2  " + game_state[2][0] + "  |  " + game_state[2][1] + "  |  " + game_state[2][2] + "   \n"
		"      |     |     \n";

	cout << display_game;

}

//Function for a player to take their turn. Checks for invalid inputs.
void take_turn(string game_state[3][3], string playerTurn) {
	int row, column;
	bool invalid = true;

	while (invalid) {
		cout << "Player " << playerTurn << " select a row: ";
		cin >> row;

		cout << "Player " << playerTurn << " select a column: ";
		cin >> column;

		if (row < 0 || row > 2 || column < 0 || column > 2 || game_state[row][column] != " ") {
			cout << "Either row or column was incorrect, please select another space between 0 and 2" << endl;
			continue;
		}
		else {
			game_state[row][column] = playerTurn;
			invalid = false;
		}
	}
}

//Return true if player won, false if they did not
bool checkWinner(string game_state[3][3], string playerCheck) {

	//Horiztonal Win Check
	if ((game_state[0][0] == playerCheck && game_state[0][1] == playerCheck && game_state[0][2] == playerCheck) || (game_state[1][0] == playerCheck && game_state[1][1] == playerCheck && game_state[1][2] == playerCheck) || (game_state[2][0] == playerCheck && game_state[2][1] == playerCheck && game_state[2][2] == playerCheck)) {
		return true;
	}

	//Vertical Win Check
	if ((game_state[0][0] == playerCheck && game_state[1][0] == playerCheck && game_state[2][0] == playerCheck) || (game_state[0][1] == playerCheck && game_state[1][1] == playerCheck && game_state[2][1] == playerCheck) || (game_state[0][2] == playerCheck && game_state[1][2] == playerCheck && game_state[2][2] == playerCheck)) {
		return true;
	}

	//Diagonal Win Check
	if ((game_state[0][0] == playerCheck && game_state[1][1] == playerCheck && game_state[2][2] == playerCheck) || (game_state[0][2] == playerCheck && game_state[1][1] == playerCheck && game_state[2][0] == playerCheck)) {
		return true;
	}

	//Return false if the player did not win
	return false;
}

int main() {

	//These three lines will clear the terminal
	string clearTerminal = "clear";
	const char* clearCommand = clearTerminal.c_str();
	system(clearCommand);

	int turnCounter = 0;

	bool gameOver = false;

	string game_state[3][3] = { {" "," "," "},
							{" "," "," "},
							{" "," "," "} };

	cout << "Welcome to tic tac toe!" << endl;
	print_state(game_state);

	while (!gameOver) {
		if (turnCounter % 2 == 0) {
			take_turn(game_state, "X");
		}
		else {
			take_turn(game_state, "O");
		}

		print_state(game_state);

		if (turnCounter >= 4) {
			if (checkWinner(game_state, "X")) {
				gameOver = true;
				cout << "Player X has won the game!" << endl;
				break;
			}
			if (checkWinner(game_state, "O")) {
				gameOver = true;
				cout << "Player O has won the game!" << endl;
				break;
			}
		}

		turnCounter++;

	}

}