class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        vector<int> tmpcost(n, INT_MAX);
        tmpcost[src] = 0;
        for (int i = 0; i < k + 1; i++)
        {
            for (auto it : flights)
            {
                if (cost[it[0]] == INT_MAX)
                    continue;

                else if (cost[it[0]] + it[2] < tmpcost[it[1]])
                    tmpcost[it[1]] = cost[it[0]] + it[2];
            }

            cost = tmpcost;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};