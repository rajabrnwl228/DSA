#include <iostream>
#include <climits>
using namespace std;
#include <vector>
#include <queue>
template <typename T>
class TreeNode
{
public:
  T data;
  vector<TreeNode<T> *> children;

  TreeNode(int data)
  {
    this->data = data;
  }
  ~TreeNode()
  {
    for (int i = 0; i < children.size(); i++)
    {
      delete children[i];
    }
  }
};

TreeNode<int> *takeInput()
{
  int rootdata;
  //   cout << "Enter data" << endl;
  cin >> rootdata;
  TreeNode<int> *root = new TreeNode<int>(rootdata);
  int n;
  //   cout << "Enter Number of children of " << rootdata << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    TreeNode<int> *child = takeInput();
    root->children.push_back(child);
  }
  return root;
}

// takeInput better way
TreeNode<int> *takeInputLevelWise()
{
  int rootdata;
  cout << "Enter the data :" << endl;
  cin >> rootdata;
  TreeNode<int> *root = new TreeNode<int>(rootdata);

  // create queue
  queue<TreeNode<int> *> queNod;
  queNod.push(root);

  while (queNod.size() != 0)
  {
    TreeNode<int> *front = queNod.front();
    queNod.pop();
    // take number of child data
    int NumChild;
    // cout << "Enter number of child of " << rootdata << endl;
    cin >> NumChild;
    for (int i = 1; i <= NumChild; i++)
    {
      // take child data
      int childdata;
      //   cout << "Enter the " << i << "th child data of " << front->data << endl;
      cin >> childdata;
      // create tree node of children
      TreeNode<int> *child = new TreeNode<int>(childdata);
      // push children in root
      front->children.push_back(child);
      queNod.push(child);
    }
  }
  return root;
}
void preorder(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << endl;
  for (int i = 0; i < root->children.size(); i++)
    preorder(root->children[i]);
}
void postorder(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    postorder(root->children[i]);
  }
  cout << root->data << endl;
}
void printTree(TreeNode<int> *root)
{
  // edge case not a base case
  if (root == NULL)
  {
    return;
  }

  cout << root->data << ": ";
  for (int i = 0; i < root->children.size(); i++)
  {
    cout << root->children[i]->data << ", ";
  }
  cout << endl;
  for (int i = 0; i < root->children.size(); i++)
  {
    printTree(root->children[i]);
  }
}
// print levelwise
void printLevelWise(TreeNode<int> *root)
{
  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty())
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << front->data << ":";
    for (int i = 0; i < front->children.size(); i++)
    {
      if (i < ((front->children.size()) - 1))
      {
        cout << front->children[i]->data << ",";
      }
      else
      {
        cout << front->children[i]->data;
      }
      pendingNodes.push(front->children[i]);
    }
    cout << "\n";
  }
}

void printAtlevel(TreeNode<int> *root, int k)
{
  if (root == NULL)
    return;
  if (k == 0)
  {
    cout << root->data;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    printAtlevel(root->children[i], k - 1);
  }
}
int numberOfNodes(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int count = 1;
  for (int i = 0; i < root->children.size(); i++)
  {
    count += numberOfNodes(root->children[i]);
  }
  return count;
}
int sumOfNodes(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int count = root->data;
  for (int i = 0; i < root->children.size(); i++)
  {
    count += sumOfNodes(root->children[i]);
  }
  return count;
}
int getHeight(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < root->children.size(); i++)
  {
    int subans = getHeight(root->children[i]);
    ans = max(ans, subans);
  }
  return ans + 1;
}

void printLeafNode(TreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  if (root->children.size() == 0)
  {
    cout << root->data << " ";
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    printLeafNode(root->children[i]);
  }
}
// to find maximum node data in tree
TreeNode<int> *Maximum(TreeNode<int> *root)
{
  if (root == NULL)
    return NULL;
  TreeNode<int> *maxi = root;
  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *child = Maximum(root->children[i]);
    if (child->data > maxi->data)
      maxi = child;
  }
  return maxi;
}

// whether a node of that data is present or not
bool IsPresent(TreeNode<int> *root, int k)
{
  if (root == NULL)
    return false;
  if (root->data == k)
    return true;
  for (int i = 0; i < root->children.size(); i++)
  {
    bool ans = IsPresent(root->children[i], k);
    if (ans == true)
      return true;
  }
  return false;
}
// count number of node equal or greater than that data
int NumberOfNodeGreater(TreeNode<int> *root, int k)
{
  if (root == NULL)
    return 0;
  int count = 0;
  if (root->data >= k)
    count++;
  for (int i = 0; i < root->children.size(); i++)
  {
    count += NumberOfNodeGreater(root->children[i], k);
  }
  return count;
}
int main()
{

  TreeNode<int> *root1 = takeInput();
  TreeNode<int> *root2 = takeInputLevelWise();
  //   printTree(root1);
  //   printLevelWise(root2);
  //   cout << "Preorder traversal " << endl;
  //   preorder(root2);
  //   cout << "postorder traversal " << endl;
  //   postorder(root2);
  cout << "height of tree is " << getHeight(root2) << endl;
  cout << "Number of nodes is " << numberOfNodes(root2) << endl;
  TreeNode<int> *maxi = Maximum(root2);
  cout << "Maximum data of a Node " << maxi->data << endl;
  int k;
  cout << "Enter the data to find : " << endl;
  cin >> k;
  cout << "Is " << k << " Present : " << IsPresent(root2, k) << endl;

  cout << "Count number of nodes equal or greater than " << k << " " << NumberOfNodeGreater(root2, k) << endl;

  delete root1;
  delete root2;
  return 0;
}

// 1 3 2 2 5 0 6 0 3 0 4 0
// 1 3 2 3 4 2 5 6 0 0 0 0
// 4