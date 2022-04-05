class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = INT_MIN;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else
                left++, right--;
        }
        return ans;
    }
};