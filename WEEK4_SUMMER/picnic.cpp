#include <iostream>

using namespace std;
void isFriend(int idx, int checked[10], int fd[10][10],  int size, int & ans){
    if(idx == size-1){
        if(checked[idx]){
            ans++;
            return;
        }else{
            return;
        }
    }

    if(checked[idx]){
        isFriend(idx+1, checked, fd, size, ans);
    }else{
        checked[idx] = 1;
        for(int i =idx+1 ; i < size; i++){
            if(fd[idx][i] && !checked[i]){
                checked[i] = 1;
                isFriend(idx+1, checked, fd, size, ans);
                checked[i] = 0; 
            }
        }
        checked[idx] = 0;
    }
}

int main(void){
    int T;
    cin >> T;
    for(int i =0 ; i < T; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        int fd[10][10] = {0};
        for(int j = 0; j < m; j++){
            int a,b;
            scanf("%d %d", &a, &b);
            fd[a][b] = 1;
            fd[b][a] = 1;
        }
        
        int checked[10] = {0};
        int ans = 0;
        isFriend(0, checked, fd, n, ans);
        printf("%d\n", ans);
    }

    return 0;
}

