#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    vector<string> v;
    void generate(string &s, int l, int r)
    {
        if (l == 0 && r == 0)
        {
            v.push_back(s);
            return;
        }
        if (l > 0)
        {
            s.push_back('(');
            generate(s, l - 1, r);
            s.pop_back();
        }
        if (r > 0)
        {
            if (l < r)
            {
                s.push_back(')');
                generate(s, l, r - 1);
                s.pop_back();
            }
        }
    }
    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        string s = "";
        generate(s, n, n);
        return v;
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
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends