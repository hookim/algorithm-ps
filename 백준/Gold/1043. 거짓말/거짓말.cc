#include <iostream>
#include <vector>

using namespace std;

vector<int> party[51];
bool truth[51];
int uf[51];
int N, M, P, T, a, ans;

int find(int x){
    if(uf[x] == x){
        return x;
    }

    return (uf[x] = find(uf[x]));
}

void merge(int x, int y){
    int idx1 = find(x);
    int idx2 = find(y);
    if(truth[idx1]){
        uf[idx2] = idx1;
    }
    else{
        uf[idx1] = idx2;
    }
}


void solve(){
    for(int i = 0; i < M ; i++){    

        for(int j = 1 ; j < party[i].size(); j++){
            merge(party[i][j-1], party[i][j]);
        }
    }
    
    for(int i = 0; i < M; i++){
        bool youCanLie = true;
        for(int j = 0; j < party[i].size(); j++){
            if(truth[find(party[i][j])]){
                youCanLie = false;
                break;
            }
        }
        if(youCanLie)
            ans++;
    }

}

int main (void){
    cin >> N >> M;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> a;
        truth[a] = true;
    }

    for(int i = 0; i < M; i++){
        cin >> P;
        for(int j = 0; j < P; j++){
            cin >> a;
            party[i].push_back(a);
        }
    }

    for(int i = 1; i <= N; i++){
        uf[i] = i;
    }

    solve();
    cout << ans << endl;

    return 0;
}