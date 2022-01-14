#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> arr, int r, int c)
    {
        // code here
        vector<int> v;

        int rowStart = 0;
        int rowEnd = arr.size() - 1;
        int colStart = 0;
        int colEnd = arr[0].size() - 1;

        while (rowStart <= rowEnd && colStart <= colEnd)
        {

            for (int i = colStart; i <= colEnd; i++)
            {
                if (rowStart > rowEnd || colStart > colEnd)
                    break;
                v.push_back(arr[rowStart][i]);
            }
            rowStart++;

            for (int i = rowStart; i <= rowEnd; i++)
            {
                if (rowStart > rowEnd || colStart > colEnd)
                    break;
                v.push_back(arr[i][colEnd]);
            }
            colEnd--;

            for (int i = colEnd; i >= colStart; i--)
            {
                if (rowStart > rowEnd || colStart > colEnd)
                    break;
                v.push_back(arr[rowEnd][i]);
            }
            rowEnd--;

            for (int i = rowEnd; i >= rowStart; i--)
            {
                if (rowStart > rowEnd || colStart > colEnd)
                    break;
                v.push_back(arr[i][colStart]);
            }
            colStart++;
        }
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends