#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    vector < pair <int, int> > jewl;
    for(int i = 0 ; i < N; i++){
        int w, v;
        scanf("%d %d", &w, &v);
        jewl.push_back(make_pair(-v, w));
    }
    vector <int> bags_capacity;
    for(int i = 0; i < K; i++){
        int c;
        scanf("%d" , &c);
        bags_capacity.push_back(c);
    }
    sort(jewl.begin(), jewl.end());
    sort(bags_capacity.begin(), bags_capacity.end());

    




    return 0;
}
