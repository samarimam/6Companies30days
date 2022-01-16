#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
        {
            return 0;
        }
        int s = sum / 2;
        int dp[N + 1][s + 1];
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < s + 1; j++)
            {
                if (arr[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j >= arr[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
        return dp[N][s];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends