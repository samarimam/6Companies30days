class Solution
{
public:
    double r, x, y;
    Solution(double radius, double x_center, double y_center)
    {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint()
    {
        if (r == 0.0)
            return {x, y};
        double h, k;

        do
        {
            h = (x - r) + double(rand()) / RAND_MAX * ((x + r) - (x - r));
            k = (y - r) + double(rand()) / RAND_MAX * ((y + r) - (y - r));
        } while (((h - x) * (h - x) + (k - y) * (k - y)) >= r * r);

        return {h, k};
    }
};