#include <iostream>
#include <unordered_map>

using namespace std;

int main(void){
    int N;
    cin >> N;
    int k;
    unordered_map <int ,int> umap;
    for (int i = 0; i < N; i++){
        scanf("%d", &k);
        if (umap.find(k) == umap.end())
            umap[k] = 1;
    }
    int M;
    cin >> M;
    int t;
    for (int i = 0; i < M; i++){
        scanf("%d", &t);
        if (umap.find(t) == umap.end())
            printf("%d\n", 0);
        else
            printf("%d\n", 1);
    }


    return 0;
}

