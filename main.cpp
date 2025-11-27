#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to create the deck
void Create_the_Deck(string deck[52]) {
    string ranks[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string suits[] = {"Spades","Hearts","Diamonds","Clubs"};
    int index = 0;
//  nested for loop for results
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[index] = ranks[i] + " of " + suits[j];
            index++;
        }
    }
}

// Function to shuffle the deck
void Shuffle_the_Deck(string deck[52]) {
    srand(time(0));
    
    for (int i = 0; i < 52; i++) {
        int r = rand() % 52;
        swap(deck[i], deck[r]);
    }
}

// Function to get rank value or To give an numeric value to each rank
int Get_Value_of_Rank(string card) {
    string ranks[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string rank = card.substr(0, card.find(" "));
    
    for (int i = 0; i < 13; i++)
        if (rank == ranks[i]){
            return i + 2; // 0+2=2
        }
    return 0;
}

// Function to get suit value or To give numeric value to each suit
int Get_Value_of_Suit(string card) {
    string suits[] = {"Spades","Hearts","Diamonds","Clubs"};
    
    for (int i = 0; i < 4; i++) {
        if (card.find(suits[i]) != string::npos)
            return 4 - i; // 4 - 0 = 4 for values according to suits
    }
    return 0; // if no match found
}

// Function that compares two cards and returns the winner
string Compare_the_Cards(string User_Card, string Computer_Card) {
    
    int User_Rank = Get_Value_of_Rank(User_Card);
    int Computer_Rank = Get_Value_of_Rank(Computer_Card);

    // Comparing ranks to find round winner
    if (User_Rank > Computer_Rank) {
        return "User";
    }else if (Computer_Rank > User_Rank) {
        return "Computer";
    }else {
        int User_Suit = Get_Value_of_Suit(User_Card);
        int Computer_Suit = Get_Value_of_Suit(Computer_Card);
        // Comparing suits to find round winner
        if (User_Suit > Computer_Suit) {
            return "User";
        }else{
            return "Computer";}
    }
}

// Main game function
void Main_Game() {
    string deck[52];
    Create_the_Deck(deck);
    Shuffle_the_Deck(deck);

    int mix = 0, User_Score = 0, Computer_Score = 0;
    int round = 1;
//   best of three concept
    while (User_Score < 2 && Computer_Score < 2) { // best of 3
        string User_Card = deck[mix++];
        string Computer_Card = deck[mix++];

        cout << "\nRound " << round << ":\n";
        // displaying drawn card for both the user and computer
        cout << "User draws: " << User_Card << endl;
        cout << "Computer draws: " << Computer_Card << endl;

        string winner = Compare_the_Cards(User_Card, Computer_Card);
// displaying who won the round
        if (winner == "User") {
            cout << "You win this round!\n";
            User_Score++;
        } else {
            cout << "Computer wins this round!\n";
            Computer_Score++;
        }

        // Show who is leading in the round
        cout << "Current Score:  Player: " << User_Score << " | Computer: " << Computer_Score << endl;
        if (User_Score > Computer_Score){
            cout << "Player is leading!\n";
        }else if (Computer_Score > User_Score){
            cout << "Computer is leading!\n";
        }else{
            cout << "It's a tie so far!\n";
        }

        round++;
            
    }

    cout << "\nFinal Scores:\n";
    cout << "Player: " << User_Score << "  |  Computer: " << Computer_Score << endl;
    
// displaying who's the winner of the game
    if (User_Score > Computer_Score){
        cout << "Congratulations! You win the game!\n";
    }else{
        cout << "Try again! Computer wins the game!\n";
    }
}

// main function
int main() {
    
    char input;
    // Welcome message
    cout << "Welcome to the Card Game!\n";

    // Trying again loop
    do {
        cout << "\nStart the Game? (Press Y to continue or any other key to Exit): ";
        cin >> input;
        
        if (input == 'y' || input == 'Y'){
            Main_Game();  // main game of card or function called
        }else{
            cout << "Thanks, see you soon!\n";
        }
    } while (input == 'y' || input == 'Y');

    return 0;
        
}

