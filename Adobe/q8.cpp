#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int n = str.size(), p = 0, f = 0;
        for (int i = 0; i < n; i++)
        {
            if ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
                p = p * 10 + (str[i] - '0');
            else if (str[i] == '-')
                f = 1;
            else
                return -1;
        }
        if (f == 0)
            return p;
        else
            return -p;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
} // } Driver Code Ends