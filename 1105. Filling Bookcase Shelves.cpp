#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // Base case: no books require 0 height

        for (int i = 1; i <= n; ++i)
        {
            int total_width = 0;
            int max_height = 0;
            for (int j = i; j > 0; --j)
            {
                total_width += books[j - 1][0];
                if (total_width > shelfWidth)
                {
                    break;
                }
                max_height = max(max_height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + max_height);
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sl;

    vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;

    cout << sl.minHeightShelves(books, shelfWidth);

    return 0;
}
