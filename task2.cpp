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

void take_turn(string game_state[3][3], char playerTurn) {
}

int main() {

	string game_state[3][3] = { {" "," "," "},
							{" "," "," "},
							{" "," "," "} };

	print_state(game_state);

}