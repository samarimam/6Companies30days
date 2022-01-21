#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int LIS(vector<int> A, int N)
    {
        if (A.empty())
            return 0;
        vector<int> tail(N, 0);
        int len = 1;
        tail[0] = A[0];
        for (int i = 1; i < N; i++)
        {
            if (A[i] < tail[0])
                tail[0] = A[i];
            else if (A[i] > tail[len - 1])
                tail[len++] = A[i];
            else
            {
                int pos = lower_bound(tail.begin(), tail.begin() + len, A[i]) - tail.begin();
                tail[pos] = A[i];
            }
        }
        return len;
    }

    int minInsAndDel(int A[], int B[], int N, int M)
    {
        vector<int> arr;
        map<int, int> m;
        for (int i = 0; i < M; i++)
            m[B[i]]++;
        for (int i = 0; i < N; i++)
        {
            if (m.find(A[i]) != m.end())
                arr.push_back(A[i]);
        }
        int len = LIS(arr, arr.size());
        return N + M - 2 * len;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
} // } Driver Code Ends