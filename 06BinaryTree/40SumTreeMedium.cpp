int helper(Node *root, bool &ans)
{
    if (ans)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->data;
        int a = helper(root->left, ans);
        int b = helper(root->right, ans);
        if (root->data == a + b)
        {
            int x = root->data + a + b;
            return x;
        }
        else
        {
            ans = 0;
            return 0;
        }
    }
}

public:
bool isSumTree(Node *root)
{
    // Your code here
    if (root == NULL)
        return 1;
    bool ans = 1;
    helper(root, ans);
    return ans;
}