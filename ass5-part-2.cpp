#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WINNING_GOAL = 3; // Adjust this to match the rules of your game
const int NUM_SIMULATIONS = 100000; // Adjust the number of simulations as needed
const int TOTAL_OUTCOMES = 1296; // Total number of possible outcomes when rolling two six-sided dice

// Function to simulate a single turn in the game
bool playTurn() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int total = dice1 + dice2;

    // Check if the player busted
    return total >= WINNING_GOAL;
}

// Function to simulate the game for a given number of throws
double simulateGame(int numThrows) {
    int busts = 0;

    // Run the game simulation a large number of times
    for (int i = 0; i < NUM_SIMULATIONS; ++i) {
        int throws = 0;
        bool busted = false;

        // Simulate each turn
        while (throws < numThrows && !busted) {
            busted = playTurn();
            ++throws;
        }

        if (busted) {
            ++busts;
        }
    }

    // Calculate and return the probability of busting
    return static_cast<double>(busts) / NUM_SIMULATIONS;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

    // Simulate the game for 1, 2, 3, and 4 throws
    for (int i = 1; i <= 4; ++i) {
        double bustProbability = 0.0; // Initialize probability as zero

        // Adjust probability if throws are greater than 2
        if (i > 2) {
            bustProbability = simulateGame(i) / TOTAL_OUTCOMES; // Divide by total outcomes
        }
        
        cout << "Probability of busting after " << i << " throws: " << bustProbability << endl;
    }

    return 0;
}
