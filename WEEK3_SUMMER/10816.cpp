#include <unordered_map>
#include <iostream>

using namespace std;

int main(void){
    unordered_map <int, int> umap;
    int N, k;
    scanf("%d", &N);
    for(int i =0 ; i < N; i++){
        scanf("%d", &k);
        if(umap.find(k) == umap.end())
            umap[k] = 1;
        else
            umap[k] += 1;
    }
    scanf("%d", &N);
    for(int i =0 ; i < N; i++){
        scanf("%d", &k);
        if(umap.find(k) == umap.end())
            printf("0 ");
        else
            printf("%d ", umap[k]);
    }
    printf("\n");

    return 0;
}


