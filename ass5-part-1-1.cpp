#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate the dice rolls and check if we can advance in columns 3, 8, or 11
bool canAdvance(int dice[]) {
    int combinations[6] = {
        dice[0] + dice[1], dice[0] + dice[2], dice[0] + dice[3],
        dice[1] + dice[2], dice[1] + dice[3], dice[2] + dice[3]
    };
    for (int i = 0; i < 6; i++) {
        if (combinations[i] == 3 || combinations[i] == 8 || combinations[i] == 11) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(0)); // Seed the random number generator

    const int NUM_TRIALS = 1000000; // Number of trials to simulate
    int successfulTrials = 0;

    for (int i = 0; i < NUM_TRIALS; i++) {
        int dice[4];
        for (int j = 0; j < 4; j++) {
            dice[j] = rand() % 6 + 1; // Roll a die (1-6)
        }
        if (canAdvance(dice)) {
            successfulTrials++;
        }
    }

    double probability = static_cast<double>(successfulTrials) / NUM_TRIALS;
    cout << "Probability of advancing in columns 3, 8, or 11: " << probability * 100 << "%" << endl;
    cout << "Probability of busting in columns 3, 8, or 11: " << (1-probability) * 100 << "%" << endl;

    return 0;
}
