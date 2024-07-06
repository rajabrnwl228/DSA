#include<iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
   public:                                                                                                          
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* bulidTreeHelper(BinaryTreeNode*pre,int PreS,int PreE,BinaryTreeNode*in,int InS,int InE){
    int rootdata=pre[PreS];
    if(inS>inE)
        return NULL;
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootdata){
            rootIndex=i;
            break;
        }
    }
    int LinS=InS;
    int LinE=rootIndex-1;
    int RinS=rootIndex+1;
    int RinE=InE;
    int LpreS=PreS+1;
    int LpreE=LpreS+(LinE-LinS);
    int RpreS=LpreE+1;
    int RpreE=PreE;
    BinaryTreeNode<int>*root=new BinaryTreeNode(rootdata);
    root->left=buildTreeHelper(pre,LpreS,LpreE,in,LinS,RinE);
    root->right=bulidTreeHelper(pre,RpreS,RpreE,in,RinS,RinE);
    return root;

}
// buildTree(post, size, in, size);
BinaryTreeNode<int>* buildTree(BinaryTreeNode*pre,int presize,BinaryTreeNode*in,int Insize){
    return buildTree(pre,0,presize-1,in,0,Insize-1);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}