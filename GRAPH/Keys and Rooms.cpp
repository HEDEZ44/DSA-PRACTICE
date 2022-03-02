class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {

        vector<int> keys;
        keys.push_back(0);
        queue<vector<int>> q;
        q.push(rooms[0]);
        while (!q.empty())
        {
            vector<int> num = q.front();
            q.pop();
            for (int i = 0; i < num.size(); i++)
            {
                if (find(keys.begin(), keys.end(), num[i]) != keys.end())
                    continue;
                keys.push_back(num[i]);
                q.push(rooms[num[i]]);
            }
        }
        return keys.size() == rooms.size();
    }
};