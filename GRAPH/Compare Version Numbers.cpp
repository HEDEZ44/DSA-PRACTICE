class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0;
        int m = version1.length();
        int j = 0;
        int n = version2.length();
        int a = 0, b = 0;

        while (i < m || j < n)
        {

            while (i < m && version1[i] != '.')
            {
                a += a * 10 + (version1[i] - '0');
                i++;
            }

            while (j < n && version2[j] != '.')
            {
                b += b * 10 + (version2[j] - '0');
                j++;
            }
            if (a > b)
                return 1;
            else if (b > a)
                return -1;

            a = 0;
            b = 0;
            i++;
            j++;
        }
        return 0;
    }
};