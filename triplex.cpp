#include <iostream>
#include <cstdlib>
#include <ctime>

void Intro(int difficulty){
    if (difficulty == 1){
        std::cout << "\nWelcome, you are a hacker!\n\n";
    }
}

bool Playgame(int difficulty){

    Intro(difficulty);

    std::cout << "You are now on Level: " << difficulty << "\n";
    std::cout << "You must choose 3 numbers that...\n";

    const int firstAns = rand() % difficulty + difficulty;
    const int secondAns = rand() % difficulty + difficulty;
    const int thirdAns = rand() % difficulty + difficulty;

    const int sumAns = firstAns + secondAns + thirdAns;
    const int multAns = firstAns * secondAns * thirdAns;

    std::cout << "+ add to: "  << sumAns << "\n";
    std::cout << "+ multiply to: " << multAns << "\n";

    // declare the answers from the user
    int firstGuess;
    int secondGuess;
    int thirdGuess;

    int guessSum;
    int guessMult;

    // get the input from the user
    std::cin >> firstGuess;
    std::cin >> secondGuess;
    std::cin >> thirdGuess;

    guessSum = firstGuess + secondGuess + thirdGuess;
    guessMult = firstGuess * secondGuess * thirdGuess;

    if (guessSum == sumAns && guessMult == multAns){

        std::cout << "\nGood job you passed this level! \n\n";
        return true;
    }
    else{
        std::cout << "This is incorrect, please try again.";
        return false;
    }
}

int main(){

    srand(time(NULL));

    int difficulty = 1;
    int max_difficulty = 5;

    while(difficulty <= max_difficulty){   
        
        bool play = Playgame(difficulty);
        std::cin.clear();
        std::cin.ignore();

        if (play){
            difficulty++;
        }
    }
    std::cout << "Congratulations! You win!\n";
    return 0;
} 
