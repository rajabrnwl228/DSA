int helper(Node *ptr, int k, vector<int> &ans)
{
    if (ptr == NULL)
        return 0;
    if (ptr->left == NULL && ptr->right == NULL)
    {
        return 1;
    }
    int a = helper(ptr->left, k, ans);
    int b = helper(ptr->right, k, ans);
    if (a + b == k)
        ans.push_back(ptr->data);
    return a + b;
}
vector<int> btWithKleaves(Node *ptr, int k)
{
    // your code here.
    vector<int> ans;
    helper(ptr, k, ans);
    if (ans.size() == 0)
        ans.push_back(-1);
    return ans;
}
