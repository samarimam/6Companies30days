class Solution
{
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<int>> &heights, int i, int j, int prev, int r, int c, vector<vector<bool>> &ocean)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || ocean[i][j] || heights[i][j] < prev)
            return;

        ocean[i][j] = true;
        for (auto d : dir)
        {
            dfs(heights, i + d[0], j + d[1], heights[i][j], r, c, ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> v;

        if (heights.size() == 0 || heights[0].size() == 0)
            return v;

        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
            dfs(heights, i, 0, INT_MIN, r, c, pacific);
            dfs(heights, i, c - 1, INT_MIN, r, c, atlantic);
        }
        for (int j = 0; j < c; j++)
        {
            dfs(heights, 0, j, INT_MIN, r, c, pacific);
            dfs(heights, r - 1, j, INT_MIN, r, c, atlantic);
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    v.push_back({i, j});
                }
            }
        }
        return v;
    }
};