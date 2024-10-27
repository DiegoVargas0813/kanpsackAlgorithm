#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n){ // Computational Complexity: O(n*W), where n is the number of items and W is the maximum weight capacity of the knapsack. Two loops are used, this implies a multiplication of n and w. Also, the space complexity is O(n*W), where the 2D Vector requires storing (n + 1) × (W + 1).

    // Create a 2D vector to store the maximum benefit at each step
    vector<vector<int>> B(n + 1, vector<int>(W + 1, 0));

    // Build the table B[][] in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Check if the current item can be included in the knapsack
            if (weights[i - 1] <= w) {
                // Include the current item and check if it gives a better value than excluding it
                B[i][w] = max(values[i - 1] + B[i - 1][w - weights[i - 1]], B[i - 1][w]);
            } else {
                // Exclude the current item
                B[i][w] = B[i - 1][w];
            }
        }
    }

    // The answer will be in B[n][W], i.e., the maximum value for n items and total weight W
    return B[n][W];
}

int main() {
    int n, W;
    
    // Input number of items and maximum weight capacity
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Input the weights and values of each item
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    // Call the knapsack function and display the result
    int maxValue = knapsack(W, weights, values, n);
    cout << "The maximum value that can be obtained: " << maxValue << endl;

    return 0;
}