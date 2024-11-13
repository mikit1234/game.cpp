#include <iostream>
#include <cstdlib>
#include <ctime>

void guessNumberGame() {
    std::cout << "Welcome to the Guess the Number Game!" << std::endl;

    // Set the range for the random number
    const int lowerBound = 1;
    const int upperBound = 100;
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
    int numberToGuess = std::rand() % (upperBound - lowerBound + 1) + lowerBound;
    const int maxAttempts = 10;
    int attempts = 0;

    std::cout << "I have selected a number between " << lowerBound << " and " << upperBound 
              << ". You have " << maxAttempts << " attempts to guess it." << std::endl;

    while (attempts < maxAttempts) {
        int guess;
        std::cout << "Enter your guess: ";
        
        // Input validation
        if (!(std::cin >> guess)) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        attempts++;

        if (guess < lowerBound || guess > upperBound) {
            std::cout << "Please guess a number between " << lowerBound << " and " << upperBound << "." << std::endl;
            attempts--; // Do not count invalid attempts
            continue;
        }

        if (guess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number " << numberToGuess 
                      << " in " << attempts << " attempts." << std::endl;
            return; // Exit the game
        }
    }

    std::cout << "Sorry, you've used all your attempts. The number was " << numberToGuess << "." << std::endl;
}

int main() {
    guessNumberGame();
    return 0;
}