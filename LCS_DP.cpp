#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();

    // Create a 2D DP array to store the length of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the LCS is stored in dp[m][n]
    return dp[m][n];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";

    int lcsLength = longestCommonSubsequence(text1, text2);

    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}
