class Solution
{
public:
    string simplifyPath(string path)
    {
        string res, temp;
        vector<string> st;

        stringstream ss(path);
        while (getline(ss, temp, '/'))
        {
            if (temp == "" or temp == ".")
                continue;
            if (temp == ".." and !st.empty())
                st.pop_back();
            else if (temp != "..")
                st.push_back(temp);
        }

        for (auto str : st)
            res += '/' + str;
        return !res.empty() ? res : "/";
    }
};