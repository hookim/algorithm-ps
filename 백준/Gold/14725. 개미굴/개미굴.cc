#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>

using namespace std;

int N ,K;
string str;

class Node{
public:
    map<string, Node*> children; 
    Node* get(string str){
        if(children.find(str) == children.end()){
            children.insert({str, new Node() });
        }

        return children[str];
    }
};

void dfs(Node* node, int depth){
    for(auto it = node->children.begin(); it != node->children.end(); it++){
        for(int i = 0; i < depth; i++){
            cout << "--";
        }
        cout << it->first << "\n";
        
        dfs(it->second, depth+1);
    }
}


int main(void){
    
    cin >> N;
    Node* root = new Node();
    Node* cur;
    for(int i = 0 ; i < N ; i++){
        cin >> K;
        cur = root;
        for(int j = 0 ; j < K; j++){
            cin >> str;
            cur = cur->get(str);
        }
    }

    dfs(root, 0);


    return 0;
}

