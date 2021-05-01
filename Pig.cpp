#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int playerGrand, playerTurn, pcGrand, pcTurn, playerWins, pcWins, gamesplayed, pcLoss, playerLoss, resignedgames, turns;
string name;
bool playerPlay = false, pcPlay = false;  

void randomstart();
void playerPlaying();
void pcPlaying();
void getname();
void ProgramGreeting();

int main() {
  ProgramGreeting();
}

// Player's turn
void playerPlaying() {
    playerPlay = true;
    char decision, again;
    srand(time(NULL));
    
    // The player repeatedly rolls during their turn
    while (playerPlay) {
        turns++;
        // Specification A1- Main Event Loop- The player has won
        while (playerGrand >= 100){
            // Specification A2- Group Stats
            gamesplayed++;
            playerWins++;
            pcLoss++;

            cout << "You won!!! Do you want to play another game? Enter y for yes or n for no" << endl;
                cin >> again;
            if (again == 'y') {
                randomstart();
            }

            else if (again == 'n') {
                cout << "Goodbye!";
                exit(0);
            }

            else {
                cout << "Incorrect input, please enter y or n" << endl;
                    cin >> again;
            }
        }
        cout << "Your grand total: " << playerGrand << endl;
        cout << "Your turn total: " <<  playerTurn << endl << endl;
        
        // Specification B3- Alpha Menu
        cout << "a. Roll" << endl;
        cout << "b. Hold" << endl;
        cout << "c. Resign" << endl;
        cout << "d. Quit" << endl;
            cin >> decision;
        // Set up random generator and roll
        if (decision == 'a'){
        int roll = (rand()%6);

        // If a 1 is rolled, the turn is over and all turn points are lost
        if (roll == 0){
            cout << "----------------------------------" << endl;
            cout << name << " rolled a 1! Your turn is over.\n" << endl;
            cout << "----------------------------------" << endl;
            playerTurn = 0;
            playerGrand = playerGrand + playerTurn;
            playerPlay = false;
            pcPlaying();
            }
        // When anything other than a 1 is rolled, add it to the turn points
        else if (roll == 1){
            cout << name << " rolled a 2!\n" << endl;
            // Specification B1- Track each turn
            playerTurn = playerTurn + 2;
            }

        else if (roll ==2){
            cout << name << " rolled a 3!\n" << endl;
            playerTurn = playerTurn + 3;
            }

        else if (roll == 3){
            cout << name << " rolled a 4!\n" << endl;
            playerTurn = playerTurn + 4;
            }

        else if (roll == 4){
            cout << name << " rolled a 5!\n" << endl;
            playerTurn = playerTurn + 5;
            }

        else if (roll == 5){
            cout << name << " rolled a 6!\n" << endl;
            playerTurn = playerTurn + 6;
            }
        }
        // Hold option. All turn points are added to the grand total and it is PC's turn now
        if (decision == 'b'){
            playerGrand = playerGrand + playerTurn;
            playerTurn = 0;
            playerPlay = false;
            pcPlaying();
        }

        //Specification B4- Resign Option
        if (decision == 'c') {
            resignedgames++;
            randomstart();
        }
        // Quit option
        if (decision == 'd') {
            cout << "Game over" << endl;
            exit(0); 
        }

        // Specification C4- Bulletproof Menu
        else if (decision != 'a' && decision != 'b' && decision != 'c' && decision != 'd') {
            cout << "----------------------------------" << endl;
            cout << "Incorrect input, please enter a, b, c, or d." << endl;
            cout << "----------------------------------" << endl;
        }
    }
}

// PC's turn
void pcPlaying() {
    char again;
    pcPlay = true;
    //Specification C1- Time Seed
    srand(time(NULL));
    
    // The PC repeatedly rolls during its turn
    while (pcPlay) {
        turns++;
        // Specification A1- Main Event Loop- The PC has won
        while (pcGrand >= 100) {
            gamesplayed++;
            pcWins++;
            playerLoss++;

            cout << "The PC won! Do you want to play another game?" << endl;
            cout << " Enter y for yes or n for no" << endl;
            cin >> again;
                
                if (again == 'y')
                    randomstart();
                
                else if (again == 'n') {
                    cout << "Goodbye!";
                    exit(0);
                }

                else {
                    cout << "Incorrect input, please enter y or n" << endl;
                    cin >> again;
                }
        }

        int roll = (rand()%6);
        // If a 1 is rolled, the turn is over and all turn points are lost
        if (roll == 0) {
            cout << "----------------------------------" << endl;
            cout << "The PC rolled a 1! It's your turn." << endl;
            cout << "----------------------------------" << endl;
            pcTurn = 0;
        }
        // When anything other than a 1 is rolled, add it to the turn points
        else if (roll == 1) {
            cout << "----------------------------------" << endl;
            cout << "The PC rolled a 2! It's your turn." << endl;
            cout << "----------------------------------" << endl;
            pcTurn = pcTurn + 2;
        }

        else if (roll == 2) {
            cout << "----------------------------------" << endl;
            cout << "The PC rolled a 3! It's your turn." << endl;
            cout << "----------------------------------" << endl;
            pcTurn = pcTurn + 3;
        }

        else if (roll == 3) {
            cout << "The PC rolled a 4!\n" << endl;
            pcTurn = pcTurn + 4;
            cout << "PC grand total: " << pcGrand << endl << endl;
            cout << "PC turn total: " << pcTurn << endl << endl;
        }

        else if (roll == 4) {
            cout << "The PC rolled a 5!\n" << endl;
            pcTurn = pcTurn + 5;
            cout << "PC grand total: " << pcGrand << endl << endl;
            cout << "PC turn total: " << pcTurn << endl << endl;
        }

        else if (roll == 5) {
            cout << "The PC rolled a 6!\n" << endl;
            pcTurn = pcTurn + 6;
            cout << "PC grand total: " << pcGrand << endl;
            cout << "PC turn total: " << pcTurn << endl;
        }

        if (roll == 0 || roll == 1 || roll == 2) {
            pcGrand = pcGrand + pcTurn;
            cout << "PC grand total: " << pcGrand << endl << endl;
            pcTurn = 0;
            playerPlaying();
            pcPlay = false;
        }
    }
}

// Specification C2- Student Name
void getname() {
  cout << "\nEnter your name: " << endl;
    getline(cin, name);
  
  randomstart();
}

// Specfication B2- Randomize Start
void randomstart(){
    cout << "=========" << endl;
    cout << "NEW GAME" << endl;
    cout << "=========" << endl;

    playerTurn = 0;
    playerGrand = 0;
    pcTurn = 0;
    pcGrand = 0;

    srand(time(NULL));
    int r = (rand()%2);

    if (r==0) {
        cout << "You're first!\n" << endl;
        playerPlaying();
    }

    else if (r==1) {
        cout << "The computer is first!\n" << endl;
        pcPlaying();
    }
}

void ProgramGreeting(){
    time_t tt;

    struct tm * ti; 
    time (&tt); 

    ti = localtime(&tt); 

    cout << "Greetings! This program is a simple game against AI. The " << endl;
    cout << "first player to reach a score of 100 or greater wins!" << endl;
    // Specification A3- Current Date
    cout << "The current date and time is: " << asctime(ti);
    getname();
}