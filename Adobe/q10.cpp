#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        unordered_map<string, int> hm;
        for (int i = 0; i < n; i++)
            hm[arr[i]]++;

        int maxVote = hm[arr[0]];
        string winner = arr[0];
        for (int i = 1; i < n; i++)
        {
            int currVote = hm[arr[i]];
            string name = arr[i];
            if (currVote > maxVote)
            {
                maxVote = currVote;
                winner = name;
            }
            else if (currVote == maxVote && winner > name)
                winner = name;
        }

        vector<string> res;
        res.push_back(winner);
        res.push_back(to_string(maxVote));
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}