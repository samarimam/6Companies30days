class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int n = colors.size();
        if (n <= 2)
            return false;

        int a = 0;
        int b = 0;

        for (int i = 1; i < n - 1; ++i)
        {
            if (colors[i] == 'A' and colors[i - 1] == 'A' and colors[i + 1] == 'A')
                a++;
            if (colors[i] == 'B' and colors[i - 1] == 'B' and colors[i + 1] == 'B')
                b++;
        }
        return a > b;
    }
};