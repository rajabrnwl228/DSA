// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

// Example 1:

// Input:
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4

vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int xory = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xory = xory ^ nums[i];
    }
    int rmsb = xory & (-xory);
    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & rmsb) == 0)
            x = x ^ nums[i];
        else
            y = y ^ nums[i];
    }
    if (x < y)
    {
        return {x, y};
    }
    return {y, x};
}