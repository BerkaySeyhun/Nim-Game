//Ahmet Berkay Seyhun

#include <iostream>// we define for input output

#include <string>// we define for the using string

using namespace std;

// we define our pile variable as global because we want it to not change
const int NUM_pile = 5; // Number of piles

// Below are the prototypes of the functions. We then write them down in more detail below the main function.

int prompt_pile(const int pile_number); // argument pile_number is the pile number.
bool nim_empty(const int pile[]); // pile[] is the array that contains the number of matchstick in each pile.
int change_player(int player); // player is which player is in his turn (1 or 2).
void drawScreen(const int matchstick); // matchstick is the number of matchstick in the pile.
void initialize_pile(int pile[]); // pile[] is the array that contains the number of matchstick in each pile.
void drawScreen_pile(int pile[]); // pile[] is the array that contains the number of matchstick in each pile.
void move(int player, int pile[], int & remove_element, int & pile_number); // array pile[], the number of matchstick to remove, and the pile number.
void pile_remove(int pile[],
  const int pile_number,
    const int remove_object); // array pile[], the pile number, and the number of matchstick to remove from the specified pile.
void gameWinner(const int player); // player is which player is in his/her turn (1 or 2).
void greetingMessage(string name); //starting message.
void rules(); // printing rules to the screen.

// our main function
int
main() {
  // call the functions
  cout << "Press any key and press ENTER to play" << endl;
  string key; // define key and wait user to enter
  cin >> key; // save the any key value
  greetingMessage(key); // greetingMessage function
  rules(); // printing rules to the screen

  int pile[NUM_pile]; // pile[i] = Number of matchstick in pile number i
  int player(1); // Player 1 or 2
  int pile_number(1); // the pile number: 0, 1, 2, 3, 4
  int remove_matchstick(1); // the number of matchstick to be removed from selected pile
  initialize_pile(pile); // Read number of matchstick in each pile
  drawScreen_pile(pile); // drawScreen pile as rows of *'s

  while (nim_empty(pile) != 1) // runs what we wrote below when stacks are not empty
  {

    move(player, pile, remove_matchstick, pile_number); // Read pile and modify their number of matchsticks to remove from selected pile.

    pile_remove(pile, pile_number, remove_matchstick); // Remove matchstick from selected pile

    if (nim_empty(pile) == true) // When all stacks are empty, it runs what we wrote below.
    {

      gameWinner(player); // When the player wins, it prints the text of the gameWinner to the screen
    } else {

      drawScreen_pile(pile); // Continues the game

      player = change_player(player); // Change to other player or computer (new turn)
    }

  }

} // end of the main function

// We write our functions, whose prototypes we wrote above, in more detail below.

void
initialize_pile(int pile[]) // function that allows us to add * as much as the value we enter into our stacks.
{

  for (int i = 1; i < NUM_pile; i++)

  {

    pile[i] = prompt_pile(i); // i represents the pile number
  }
}

void

drawScreen_pile(int pile[]) // Function that prints *s to the screen from the pile
{

  cout << endl;

  for (int i = 1; i < NUM_pile; i++)

  {

    cout << "Matchstick Pile " << i << ": ";

    drawScreen(pile[i]);

  }
  cout << endl;

}

int

prompt_pile(const int pile_number) // reads in the number of matchstick in each pile from the user and initializes the pile (it must be 2n+1 foremove)
{

  int x;

  cout << "How many matchstick are in pile " << pile_number << ": ";

  cin >> x; // input from user

  while (x <= 0) // it must be higher than zero

  {

    cout << "Sorry, the number of matchstick must be positive." << endl;

    cout << "How many matchstick are in pile " << pile_number << ": ";

    cin >> x;

  }

  return x;

}

void
drawScreen(const int matchstick) // drawScreens the number of matchstick of each pile into the screen.
{

  for (int i = 1; i <= matchstick; i++)

  {

    cout << "|";

  }
  cout << endl;

}

bool nim_empty(const int pile[]) // checks if our piless are empty
{

  for (int i = 0; i < NUM_pile; i++) // for loop for check any matchsticks left

  {

    if (pile[i] != 0)

    {

      return false;

    }

  }

  return true;

}

void
move(int player, int pile[], int & remove_element, int & pile_number) // the user picks what pile and how many matchstick to remove. Also controls associated error messages.
{

  cout << "Player (" << player <<
    ") : Which pile would you like to play? ";

  cin >> pile_number;

  while (pile_number < 0 || pile_number > 4)

  {

    cout << "Invalid pile number. Please try again." << endl;

    cout << "Player (" << player <<

      ") : Which pile would you like to play? ";

    cin >> pile_number;

  }

  while (pile[pile_number] == 0)

  {

    cout << "Pile " << pile_number <<

      " has zero matchstick. Please select a different pile." << endl;

    cout << "Player (" << player <<

      ") : Which pile would you like to play? ";

    cin >> pile_number;

  }

  cout << "Enter number of matchstick to remove (" << pile[pile_number] <<

    " or less) from pile " << pile_number << ": ";

  cin >> remove_element;

  while (remove_element <= 0)

  {

    cout <<

      "Number of matchstick you can remove must be positive. Try again." <<

      endl;

    cout << "Enter number of matchstick to remove (" << pile[pile_number]

      <<
      " or less) from pile " << pile_number << ": ";

    cin >> remove_element;

  }

  while (remove_element > pile[pile_number])

  {

    cout << "There are only " << pile[pile_number] <<

      " matchstick in pile. Try again: ";

    cin >> remove_element;

  }

}

void
pile_remove(int pile[],
  const int pile_number,
    const int remove_object) // removes the chosen number of matchstick from the selected pile
{

  pile[pile_number] = pile[pile_number] - remove_object;

}

void

gameWinner(const int player) // prints the winning player and message to the screen 
{

  cout << "Congratulations! Player " << player << " wins." << endl;

}

int

change_player(int player) // changes the player it moves to the next turn
{

  if (player == 1)

  {

    return 2;

  } else if (player == 2)

  {
	  
    return 1;

  }
  else
  {

    cout << "Player is wrong" << endl;

    return player;

  }

}

void // printin rules to the screen for the user
rules() {

  cout << // game rules
    "To briefly define the game of Nim, it is played by taking at least 1 of the piles and at most the sticks in the deck in order." <<
    endl;

  cout << // game rules
    "It can be played with the computer or between two human players.The player who left with the last matchstick losses the game." <<
    endl;

  cout << // game rules
    ">>-------------------------------------------------------------------------------------------------------------------------------<<" <<
    endl;

  cout << // game rules
    "To play the nim game, you need to type the matchstick that will be found in the pile below (by default it is recommended to type 1-3-5-7)." <<
    endl;

}

void // printing welcome message to the screen

greetingMessage(string name) {

  cout << "----------The Game Of NIM--------------" << endl;

  cout << "Hello " << "Player" << "!" << endl;

}
