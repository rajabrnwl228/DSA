// You are given an array of N+2 integer elements. All elements of the array are in the range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

// Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X repeats twice before Y repeating twice, then the order should be (X, Y).

// Example 1:

// Input:
// N = 4
// array[] = {1,2,1,3,4,3}
// Output: 1 3

vector<int> twoRepeated(int arr[], int n)
{
    // Your code here
    int xory = 0;
    for (int i = 0; i < n + 2; i++)
    {
        xory ^= arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        xory ^= (i + 1);
    }
    int rmsb = xory & (-xory);
    int x = 0, y = 0;
    for (int i = 0; i < n + 2; i++)
    {
        if ((rmsb & arr[i]) == 0)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if ((rmsb & (i + 1)) == 0)
        {
            x ^= (i + 1);
        }
        else
        {
            y ^= (i + 1);
        }
    }
    int countx = 0, county = 0;
    for (int i = 0; i < n + 2; i++)
    {
        if (arr[i] == x)
        {
            countx++;
            if (countx == 2)
                return {x, y};
        }
        else if (arr[i] == y)
        {
            county++;
            if (county == 2)
                return {y, x};
        }
    }
}