class Solution
{
public:
    bool canMeasureWater(int jug1, int jug2, int target)
    {
        if (jug1 + jug2 == target || jug1 == target || jug2 == target)
            return true;
        if (jug1 + jug2 < target)
            return false;
        return target % __gcd(jug1, jug2) == 0;
    }
};