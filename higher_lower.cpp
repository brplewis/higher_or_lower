#include <iostream> 
using namespace std;

/*
######################
   Higher or Lower
######################

This is a version of the card game 
Higher or Lower. The user must guess 
whether the next random number is going
to be higher or lower. 
*/

// num_correct
int num_correct = 0;

// previous_card 
int previous_card = 0;

//game_end
bool game_end = false;

//play_game
bool play_game = true;

int draw_card() { 
    int card_num = rand() % 10;
    return card_num;
}

bool yes_or_no() {
    // Gets answer from user 
    string answer;
    cin >> answer;
    if (answer.find('y') != string::npos) { 
        return true;
    } else {
        return false;
    }
}

int make_a_guess() {
    cout << "Make a guess! Choose a number from 1 - 10: " << endl;
    cin >> guess;
}

bool play_round(guess) {
    //
}

int main() {
    cout << "Higher or Lower!" << endl;
    while (play_game) { 
        cout << "Would you like to play? " << endl; 
        if (yes_or_no()) {
            cout << draw_card();
            cout << endl;
            cout << "good game!" << endl;
        } else {
            //print thanks for playing 
            play_game = false;
        }
    }
    return 0;
}