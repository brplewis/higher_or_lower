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

// Player and Game Variables 

// Line break used to split rounds visually
string line_break = "========================================";

// Number of correct answers
int num_correct = 0;

// Previous card
int previous_card = 0;

// Whether to keep the game running
bool play_game = true;

// Player lost
bool player_lost = false;

// Game Functions 

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

char make_a_guess() {
    // Asks user for h or l and repeats 
    // if an incorrect answer is given

    while(true) {
        string answer;
        cin >> answer; 
        if (answer.find('h') != string::npos) { 
            char guess = 'h';
            cout << "You choose higher! " << endl;
            return guess;
        } else if (answer.find('l') != string::npos) {
            char guess = 'l';
            cout << "You choose lower! " << endl;
            return guess;
        } else if (answer.find('s') != string::npos) {
            char guess = 's';
            cout << "You choose same! " << endl;
            return guess;
        } else {
            cout << "Please make a guess by typing h for higher or l for lower." << endl;
        }
    }
}

int draw_card() { 
    // Choose a random number between 1 & 10
    srand((unsigned int)time(NULL));
    int card_num = rand() % 10 + 1;
    return card_num;
}

bool check_cards(int previous_card, int current_card, char player_guess) {
    if (current_card < previous_card && player_guess == 'l') {
        return true;
    } else if (current_card > previous_card && player_guess == 'h') {
        return true;
    } else if (previous_card == current_card && player_guess == 's') {
        return true;
    } else {
        return false;
    }
}

bool play_round() {
    cout << line_break << endl;
    if (previous_card == 0) {
        // Draw initial card 
        previous_card = draw_card();
        cout << "The first card drawn is a : " + to_string(previous_card) << endl;   
    } else {
        cout << "The last card was a : " + to_string(previous_card) << endl;
    }
     // Player makes a guess
    cout << "Do you think the next card will be higher, lower or the same? (type h, l or s) " << endl;
    char player_guess = make_a_guess();
    cout << "Drawing a new card..." << endl;
    int current_card = draw_card();
    cout << "The card drawn is a : " + to_string(current_card) << endl;
    if (check_cards(previous_card, current_card, player_guess)) {
        // If the guess was correct
        cout << "You guessed correctly!" << endl;
        previous_card = current_card;
        return true;
    } else {
        // If the guess was wrong
        cout << "Bad luck!" << endl;
        return false;
    }
}

int main() {
    cout << "Higher or Lower!" << endl;
    while (play_game) { 
        player_lost = false;
        cout << "Would you like to play? " << endl; 
        if (yes_or_no()) {
            while(!player_lost)
                if (play_round()) {
                    num_correct += 1; 
                } else {
                    cout << "You guessed " + to_string(num_correct) + " correctly";
                    if(num_correct > 0) {
                        cout << "!" << endl;
                        if (num_correct > 10) {
                            cout << "Well done!" << endl;
                        }
                    } else {
                        cout << "." << endl;
                    } 
                    cout << line_break << endl;
                    player_lost = true;
                }
        } else {
            cout << "Bye! Thanks for playing!" << endl;
            play_game = false;
        }
    }
    return 0;
}