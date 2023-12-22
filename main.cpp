#include <iostream>
#include <vector>

int throw_dice(int N, int faces, int total) {
    // Create a 2D vector to store the number of ways to achieve a certain total
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(total + 1, 0));

    // Initialize the base case when no dice are thrown to get a total of 0
    dp[0][0] = 1;

    // Fill in the DP table to compute the number of ways for each combination
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= total; ++j) {
            // For each face value, calculate the number of ways to get the total
            for (int k = 1; k <= faces && k <= j; ++k) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    return dp[N][total];
}

int main() {
    int N = 3;      // Number of dice
    int faces = 6;  // Number of faces on each die
    int total = 7;  // Desired total

    int ways = throw_dice(N, faces, total);
    std::cout << "Number of ways to throw " << N << " dice with " << faces << " faces each to get a total of " << total << " is: " << ways << std::endl;

    return 0;
}