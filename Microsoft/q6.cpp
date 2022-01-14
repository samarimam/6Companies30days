#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int digits[], int n, int index, string output, vector<string> &ans, string arr[])
    {
        if (index == n)
        {
            ans.push_back(output);
            return;
        }
        int digit = digits[index];
        string temp = arr[digit];
        for (int i = 0; i < temp.length(); i++)
        {
            output.push_back(temp[i]);
            solve(digits, n, index + 1, output, ans, arr);
            output.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        if (N == 0)
            return ans;
        int index = 0;
        string output = "";
        string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(a, N, index, output, ans, arr);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; //testcases

    while (T--)
    { //while testcases exist
        int N;

        cin >> N; //input size of array

        int a[N]; //declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends