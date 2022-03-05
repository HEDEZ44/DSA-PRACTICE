#include <bits/stdc++.h>
using namespace std;

void mex(vector<int> &num, vector<int> &ans)
{
    vector<int> a;
    for (auto it : num)
    {
        if (find(a.begin(), a.end(), it) == a.end())
            a.push_back(it);
    }
    sort(a.begin(), a.end());
    int mex = 0;
    for (auto &e : a)
    {
        if (e == mex)
        {
            mex++;
        }
        else
            break;
    }
    ans[mex]++;
}

void SubArrays(vector<int> arr, int start, int end, vector<int> &ans)
{

    if (end == arr.size())
        return;

    else if (start > end)
        SubArrays(arr, 0, end + 1, ans);

    else
    {
        vector<int> subvector{arr.begin() + start, arr.begin() + end};
        mex(subvector, ans);

        SubArrays(arr, start + 1, end, ans);
    }

    return;
}
int main()
{
    // your code goes here
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> ans(n, 0);
        SubArrays(arr, 0, 0, ans);
        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
    return 0;
}
