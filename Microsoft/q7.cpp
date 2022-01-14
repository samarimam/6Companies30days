#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>> &a, int i, int j, int n, int m, int &count)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        if (a[i][j] == 0)
            return;
        count++;
        a[i][j] = 0;
        dfs(a, i + 1, j, n, m, count);
        dfs(a, i - 1, j, n, m, count);
        dfs(a, i, j + 1, n, m, count);
        dfs(a, i, j - 1, n, m, count);
        dfs(a, i + 1, j - 1, n, m, count);
        dfs(a, i - 1, j - 1, n, m, count);
        dfs(a, i + 1, j + 1, n, m, count);
        dfs(a, i - 1, j + 1, n, m, count);
    }
    int findMaxArea(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = 0;
                if (a[i][j] == 1)
                    dfs(a, i, j, n, m, count);
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends