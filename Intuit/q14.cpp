class Solution
{
public:
    queue<pair<int, int>> q; // initialising global queue

    void dfs(vector<vector<int>> &grid, int i, int j)
    { // for marking the 1st island visited

        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 2 or grid[i][j] == 0) // checking edge cases
            return;

        grid[i][j] = 2; // marking them visited
        q.push({i, j}); // adding them to queue

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int bfs(vector<vector<int>> &grid)
    { // finding the farthest '0' by bfs

        int d = 0;        // to store distance
        int maxdist = -1; // to store maximum distance

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int n = q.size();

            while (n-- > 0)
            { // going through every level
                auto a = q.front();
                q.pop();

                for (int h = 0; h < 4; h++)
                {
                    int x = dir[h][0] + a.first;
                    int y = dir[h][1] + a.second;

                    if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == 0)
                    { // if the neighbor is 0, then mark it visited and add it to queue and storing maximum distance till that cordinate
                        maxdist = max(maxdist, d);
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
            d++; // increasing each level by distance + 1
        }

        return maxdist == -1 ? maxdist : maxdist + 1; // returning max dist found till end
                                                      // -1 is for the case where there is no answer like all water or land only
    }

    int maxDistance(vector<vector<int>> &grid)
    {

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {                    // found 1st '1' in the matrix
                    dfs(grid, i, j); // dfs for marking the whole island visited
                    q.push({i, j});  // adding cordinate to queue
                }
            }
        }

        return bfs(grid); // using bfs to get max distance
    }
};