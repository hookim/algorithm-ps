#include <vector>
#include <iostream>
    
using namespace std;

class Node {
    int val;
    Node * left;
    Node * right;
public: 
    Node(int n);
    int getVal();
    void setLeft(Node* leftNode); void setRight(Node* rightNode);
    Node* getLeft(); Node* getRight();
};
Node::Node(int n){val = n;left = NULL; right = NULL;}
int Node::getVal(){return val;}
void Node::setLeft(Node* leftNode){left = leftNode;}
void Node::setRight(Node* rightNode){right = rightNode;}
Node* Node::getLeft(){return left;}
Node* Node::getRight(){return right;}

void tree_restructure(vector <int> &post, vector <int> &in, int begin, int end, Node* root, bool isLeft){
    if(!post.size()) return;

    int rootVal = post.back();
    post.pop_back();    
    Node *node = new Node(rootVal);

    if(isLeft) root->setLeft(node); else root->setRight(node);
    int rootIdx;
    for(int i = begin ; i <= end ; i++){
        if(in[i] == rootVal){
            rootIdx = i;
            in[rootIdx] = -1;
            break;
        }
    }

    if (end <= begin) return;

    if (rootIdx + 1 < in.size() && in[rootIdx + 1] != -1)
        tree_restructure(post, in, rootIdx + 1 , end, node, false);
    if (rootIdx - 1 >= 0 && in[rootIdx -1] != -1)
        tree_restructure(post, in, begin, rootIdx - 1 , node, true);
}
void preorder(Node *root){
    Node * left, * right;
    printf("%d ", root->getVal());
    if(left = root->getLeft()) preorder(left);
    if(right = root->getRight()) preorder(right);
}
int main(void){
    int N ; cin >> N; vector <int> post(N), in(N);  
    for(int i = 0; i < N ; i++){scanf("%d", &in[i]);}
    for(int i = 0; i < N ; i++){scanf("%d", &post[i]);}
    Node* root = new Node(-1);
    tree_restructure(post, in, 0, N-1, root, true);
    preorder(root->getLeft());
    printf("\n");

    return 0;
}
