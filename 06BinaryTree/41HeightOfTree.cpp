int height(struct Node *node)
{
    // code here
    if (node == NULL)
        return 0;
    int ans1 = height(node->right);
    int ans2 = height(node->left);
    return 1 + max(ans1, ans2);
}