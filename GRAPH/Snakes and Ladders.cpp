class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {

        int rows = board.size(), cols = board[0].size(), target = rows * cols, r, c, p;
        vector<int> vis(rows * cols + 1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(make_pair(0, 1));
        vis[1] = 1;

        while (!q.empty())
        {
            auto step_pos = q.top();
            q.pop();
            int s = step_pos.first / 1000 + 1;
            for (int i = 1; i <= 6; i++)
            {
                auto p = step_pos.second + i;
                if (vis[p])
                    continue;
                vis[p] = 1;
                r = rows - (p - 1) / cols - 1;
                c = (p - 1) % cols;
                if ((rows - r - 1) % 2)
                    c = cols - c - 1;
                int ladder = board[r][c];
                if (ladder > 0 && ladder <= target)
                    p = ladder;

                if (p == target)
                    return s;
                q.push(make_pair(s * 1000 + 500 - p, p));
            }
        }
        return -1;
    }
};