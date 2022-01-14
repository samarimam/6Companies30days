#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the maximum money the thief can get.
    int recur(int arr[], int n, int sum, vector<int> &dp)
    {
        if (n < 0)
            return sum;

        if (dp[n] != -1)
            return sum + dp[n];

        return dp[n] = max(recur(arr, n - 2, sum + arr[n], dp), recur(arr, n - 1, sum, dp));
    }

    int FindMaxSum(int arr[], int n)
    {
        // Your code here

        vector<int> dp(n, -1);

        dp[0] = arr[0];

        return recur(arr, n - 1, 0, dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking number of houses
        int n;
        cin >> n;
        int a[n];

        //inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        //calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends