class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &path, int k, int target)
    {
        if (k == target)
        {
            ans.push_back(path);
            return;
        }
        for (auto it : graph[k])
        {
            path.push_back(it);
            dfs(graph, ans, path, it, target);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int target = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        dfs(graph, ans, path, 0, target);

        return ans;
    }
};