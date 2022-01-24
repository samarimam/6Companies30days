class Solution
{
public:
    bool ispossible(vector<int> &piles, int mid, int h)
    {
        double sa = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            // sa+=ceil((piles[i]*1.0)/mid);
            sa += ceil((double)piles[i] / mid);
        }

        return sa <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int high = 0;
        int low = 0, sum = 0, ans = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            // low=min(low,piles[i]);
            high = max(high, piles[i]);
        }
        if (piles.size() == h)
        {
            return high;
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (ispossible(piles, mid, h))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};