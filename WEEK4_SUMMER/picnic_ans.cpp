#include <iostream>

using namespace std;
int n;
int m;
bool friends[10][10] = {false}; 

int pairFriend(int checked[10]){
    int firstFree = -1;
    for(int i =0 ; i < n; i++){
        if(!checked[i]){
            firstFree = i;
            break;
        }
    }
    
    if(firstFree == -1){
        return 1;
    }

    int ret = 0;

    for(int pairWith =firstFree+1 ; pairWith < n; pairWith++){
        if(!checked[pairWith] && friends[firstFree][pairWith]){
            checked[firstFree] = checked[pairWith] = true;
            ret += pairFriend(checked);
            checked[firstFree] = checked[pairWith] = false;
        }
    }
    return ret;
}

int main(void){
    int checked[10] = {0};
    scanf ("%d %d", &n, &m);
    for(int i =0; i < m ; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        friends[a][b] = true;
        friends[b][a] = true;
    }
 
    int ret = pairFriend(checked);
    cout << ret << endl;

    return 0;
}
