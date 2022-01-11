#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i]; //finding range
        }

        vector<int> v; //to store last row elements

        bool dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = true;
                }
                else if (i == 0)
                {
                    dp[i][j] = false;
                }
                else if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[n][i])
            {
                v.push_back(i);
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < v.size(); i++)
        {
            ans = min(ans, abs(sum - 2 * v[i]));
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends