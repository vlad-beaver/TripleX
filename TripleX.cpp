#include <iostream>     
#include <ctime>

// Print welcome messages to the terminal
void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\n           boing         boing         boing              \n";
    std::cout << " e-e           . - .         . - .         . - .          \n";
    std::cout << "(\\_/)\\       '       `.   ,'       `.   ,'       .        \n";
    std::cout << " `-'\\ `--.___,         . .           . .          .       \n";
    std::cout << "    '\\( ,_.-'                                             \n";
    std::cout << "       \\               "             "                \n";
    std::cout << "       ^'\n";
    std::cout << "You are a starve dinosaur hacking into a level " << Difficulty;
    std::cout << " fridge lock...\nEnter the correct code to continue...\n\n";
}

// Starting the game
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The numbers add-up to: " << CodeSum;
    std::cout << "\n+ The numbers multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    system("cls");  // Clear terminal

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Great! You hacked into a level " << Difficulty << " fridge lock! Keep going! ***";
        return true;
    }
    else 
    {
        std::cout << "\n*** You entered the wrong code! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL));  // Creates new random sequance based on the time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty)    // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   // Clears any errors
        std::cin.ignore();  // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }

    std::cout << "\n*** Congratulations! You hacked all fridge locks and finally don't starve! ***\n";
    
    return 0;
}