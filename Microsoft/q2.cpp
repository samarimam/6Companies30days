// } Driver Code Ends
class Solution
{
public:
    bool dfs(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &stack)
    {

        stack[vertex] = true;
        if (!vis[vertex])
        {
            vis[vertex] = true;
            for (auto child : adj[vertex])
            {
                if (!vis[child] && dfs(child, adj, vis, stack))
                    return true;
                if (stack[child])
                    return true;
            }
        }
        stack[vertex] = false;
        return false;
    }
    bool isPossible(int V, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> adj[V];

        for (auto &it : prerequisites)
        {
            adj[it.first].push_back(it.second);
        }
        vector<int> vis(V, false);
        vector<int> stack(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, stack))
                    return 0;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends