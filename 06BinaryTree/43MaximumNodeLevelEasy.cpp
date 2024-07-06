int maxNodeLevel(Node *root)
{
    // Add your code here
    queue<Node *> q;
    q.push(root);
    int subans = 0, ans = 0, l = 0;
    while (!q.empty())
    {
        int s = q.size();
        if (s > subans)
        {
            subans = s;
            ans = l;
        }
        while (s--)
        {
            Node *t = q.front();
            q.pop();
            if (t->left != NULL)
                q.push(t->left);
            if (t->right != NULL)
                q.push(t->right);
        }
        l++;
    }
    return ans;
}