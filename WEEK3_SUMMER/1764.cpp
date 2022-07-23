#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(void){

    int N, M;
    scanf("%d %d", &N, &M);
    unordered_map <char * , int> umap;
    char name[21] = {0};
    for(int i = 0 ; i < N; i++){
        scanf("%s", name);
        umap[name] = 1;
    }
    int count =0;
    vector <char *> ans;
    for(int j = 0 ; j < M; j++){
        scanf("%s", name);
        if(umap.find(name) != umap.end()){
            count++;
            ans.push_back(name);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", count);
    for(int i =0 ; i < ans.size(); i++){
        printf("%s", ans[i]);
    }


    return 0;
}
