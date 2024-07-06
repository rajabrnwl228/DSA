// Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

// Example 1:

// Input:
// N = 5
// A = {1, 1, 2, 5, 5}
// Output: 2

int search(int A[], int N)
{
    // code
    int xory = 0;
    for (int i = 0; i < N; i++)
    {
        xory ^= A[i];
    }
    return xory;
}