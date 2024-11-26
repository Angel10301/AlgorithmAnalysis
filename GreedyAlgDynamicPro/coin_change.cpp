#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX 

using namespace std;

int greedy_algorithm(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order to prioritize the largest denomination first

    int answer = 0; // Counter for the number of coins used

    
    for (int coin : coins) { // Iterate through the sorted coin denominations
        if (amount == 0) break; // If amount is already 0, stop

        answer += amount / coin; // Add the number of coins used
        amount %= coin;          // Update the remaining amount
    }

   
    return (amount == 0) ? answer : -1; // If there is leftover amount that cannot be represented, return -1
}


int dynamic_programming(vector<int>& coins, int amount) { // Dynamic Programming Implementation
    vector<int> dp(amount + 1, INT_MAX); // Initialize with a large value (infinity)
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

   
    for (int coin : coins) { // Iterate through each coin denomination
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1); // Update with the smaller value
            }
        }
    }

 
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];   // If dp[amount] is still INT_MAX, it means no solution exists
}

int main() {

    vector<int> coins1 = {1, 2, 5};  // 5 + 5 + 1
    const int amount1 = 11;

    vector<int> coins2 = {2};        
    const int amount2 = 3;

    vector<int> coins3 = {1};        
    const int amount3 = 0;

    vector<int> coins4 = {1, 4, 6};  
    const int amount4 = 8;

    cout << greedy_algorithm(coins1, amount1) << endl; // 3 expected
    cout << greedy_algorithm(coins2, amount2) << endl; // -1 expected
    cout << greedy_algorithm(coins3, amount3) << endl; // 0 expected
    cout << greedy_algorithm(coins4, amount4) << endl; // 3 expected 

    cout << "------------------" << endl;

    cout << dynamic_programming(coins1, amount1) << endl; // 2 expected
    cout << dynamic_programming(coins2, amount2) << endl; // -1 expected
    cout << dynamic_programming(coins3, amount3) << endl; // 0 expected
    cout << dynamic_programming(coins4, amount4) << endl; // 2 expected

    return 0;
}
