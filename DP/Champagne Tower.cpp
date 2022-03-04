class Solution
{
public:
    double champagneTower(int poured, int row, int glass)
    {

        vector<vector<double>> res(101, vector<double>(101, 0.0));
        res[0][0] = poured / 1.0;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (res[i][j] >= 1)
                {
                    res[i + 1][j] += (res[i][j] - 1) / 2.0;
                    res[i + 1][j + 1] += (res[i][j] - 1) / 2.0;
                    res[i][j] = 1.0;
                }
            }
        }
        return res[row][glass];
    }
};

// space optimization

class Solution
{
public:
    double champagneTower(int poured, int row, int glass)
    {
        vector<double> res(101);
        res[0] = poured;
        for (int i = 1; i <= row; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                res[j] = max(0.0, (res[j] - 1) / 2.0);
                res[j + 1] += res[j];
            }
        }
        return min(1.0, res[glass]);
    }
};