// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and
// smallest positive missing number is 1.
// Example 2:

// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2

vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    int xory = 0;
    for (int i = 0; i < n; i++)
    {
        xory ^= arr[i];
        xory ^= (i + 1);
    }
    int rmsb = xory & (-xory);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((rmsb & arr[i]) == 0)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
        if ((rmsb & (i + 1)) == 0)
        {
            x ^= (i + 1);
        }
        else
        {
            y ^= (i + 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return {x, y};
        }
    }
    return {y, x};
}