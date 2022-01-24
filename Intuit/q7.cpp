class Solution
{
public:
    bool ispossible(vector<int> &nums, int mid, int m)
    {
        int sa = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                sa++;
                sum = nums[i];
            }
        }
        return sa <= m;
    }
    int shipWithinDays(vector<int> &nums, int m)
    {
        int maxm = 0, sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxm = max(maxm, nums[i]);
        }
        int low = maxm;
        int high = sum;

        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            if (ispossible(nums, mid, m))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};