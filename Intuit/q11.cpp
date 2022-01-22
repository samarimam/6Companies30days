class Solution
{
public:
    Node *helper(vector<vector<int>> &grid, int y, int x, int lim)
    {
        Node *node = new Node(true, false);
        if (lim == 1)
        {
            node->val = bool(grid[y][x]);
            node->isLeaf = true;
        }
        else
        {
            lim = lim >> 1;
            node->topLeft = helper(grid, y, x, lim);
            node->topRight = helper(grid, y, x + lim, lim);
            node->bottomLeft = helper(grid, y + lim, x, lim);
            node->bottomRight = helper(grid, y + lim, x + lim, lim);

            if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf &&
                node->topLeft->val == node->topRight->val && node->topLeft->val == node->bottomLeft->val && node->topLeft->val == node->bottomRight->val)
            {
                node->val = node->topLeft->val;
                node->isLeaf = true;
                node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = NULL;
            }
        }
        return node;
    }

    Node *construct(vector<vector<int>> &grid)
    {
        return helper(grid, 0, 0, grid.size());
    }
};