class Solution
{
public:
    int count;
    vector<int> par;
    vector<int> rank;
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unin(int x, int y)
    {
        int lx = find(x);
        int ly = find(y);

        if (lx != ly)
        {
            if (rank[lx] > rank[ly])
                par[ly] = lx;
            else if (rank[ly] > rank[lx])
                par[lx] = ly;
            else
            {
                par[lx] = ly;
                rank[ly]++;
            }
        }
        else
            count++;
    }

    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int dots = n + 1;

        par = vector<int>(dots * dots);
        rank = vector<int>(dots * dots);
        count = 1;
        for (int i = 0; i < par.size(); i++)
        {
            par[i] = i;
        }
        for (int i = 0; i < dots; i++)
        {
            for (int j = 0; j < dots; j++)
            {
                if (i == 0 || j == 0 || i == dots - 1 || j == dots - 1)
                {
                    int cellno = i * dots + j;
                    if (cellno != 0)
                        unin(0, cellno);
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            string str = grid[i];
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] == '/')
                {
                    int cellno1 = i * dots + j + 1;
                    int cellno2 = (i + 1) * dots + j;

                    unin(cellno1, cellno2);
                }
                else if (str[j] == '\\')
                {
                    int cellno1 = i * dots + j;
                    int cellno2 = (i + 1) * dots + (j + 1);
                    unin(cellno1, cellno2);
                }
            }
        }
        return count;
    }
};