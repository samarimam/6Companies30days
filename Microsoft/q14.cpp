#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSteps(int D)
    {
        // code here
        if (D == 0 or D == 1)
            return D;
        int sum = 0, cnt = 1;
        while (1)
        {
            sum += cnt;
            if (sum == D)
                return cnt;
            if (sum > D and (sum - D) % 2 == 0)
                return cnt;
            cnt++;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
} // } Driver Code Ends