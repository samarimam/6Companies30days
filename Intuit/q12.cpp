class Solution
{
public:
    vector<vector<int>> graph(vector<vector<int>> &p, int n)
    {
        vector<vector<int>> g(n);
        for (auto x : p)
        {
            g[x[1]].push_back(x[0]);
        }
        return g;
    }

    void dfs(int sv, stack<int> &stk, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[sv] = true;

        for (int i = 0; i < adj[sv].size(); i++)
        {
            if (visited[adj[sv][i]] == false)
            {
                dfs(adj[sv][i], stk, adj, visited);
            }
        }
        stk.push(sv);
        return;
    }
    bool iscycle(int sv, vector<vector<int>> &g, vector<bool> &visited, vector<bool> &todo)
    {
        if (todo[sv] == true)
        {
            return true;
        }

        if (visited[sv] == true)
        {
            return false;
        }
        todo[sv] = true;
        visited[sv] = true;

        for (int i = 0; i < g[sv].size(); i++)
        {
            if (iscycle(g[sv][i], g, visited, todo) == true)
            {
                return true;
            }
        }
        todo[sv] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>> &p)
    {

        vector<vector<int>> g = graph(p, n);
        vector<bool> visited(n, false), todo(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false && iscycle(i, g, visited, todo) == true)
            {
                return {};
            }
        }
        vector<int> ans;
        if (p.size() == 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                dfs(i, stk, g, visited);
            }
        }
        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
