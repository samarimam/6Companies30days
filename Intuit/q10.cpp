class Solution
{
public:
    void dfs(int currNode, vector<int> &visited, vector<vector<int>> &isConnected)
    {

        visited[currNode] = 1;

        vector<int> currNeighbours = isConnected[currNode];
        for (int i = 0; i < currNeighbours.size(); i++)
        {
            if (currNeighbours[i] == 1 && visited[i] == 0)
                dfs(i, visited, isConnected);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        //Number of Nodes in graph
        int len = isConnected.size();

        vector<int> visited(len, 0);

        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};