int maxIndexDiff(int a[], int n)
{
    // Your code here
    int leftMin[n], rightMax[n];
    leftMin[0] = a[0];
    rightMax[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        leftMin[i] = min(leftMin[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], a[i]);
    }

    int answer = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (rightMax[j] >= leftMin[i])
        {
            answer = max(answer, j - i);
            j++;
        }
        else
            i++;
    }
    return answer;
}