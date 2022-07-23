// 21 12 23 백준 1029번 그림교환

#include<iostream>
#include<set>
using namespace std;

int promising(int from, int to, set<int> path, int price, int** prices){
    if(!path.count(to) && prices[from][to] >= price) return 1;
    else return 0;
}

void tradeArt(int num, int to, set<int> path, int price, int** prices, int* max ){
    for(int i = 0; i < num; i++){
        if(promising(to, i, path, price, prices)){
            path.insert(i);
            tradeArt(num, i, path, prices[to][i], prices, max); 
            path.erase(i);
        }

        if(* max < path.size()) * max = path.size();
        
    }

}

int main(void){
    int num;
    cin >> num;
    int** prices;
    prices = new int*[num];
    for(int i= 0; i < num; i++){
        prices[i] = new int[num];
        int row;
        cin >> row;
        for(int j= num-1; j >= 0; j--){
            prices[i][j]  = row % 10;
            row = (int)(row / 10);
        }
    }
    int max = 0; 
    set<int> path;
    path.insert(0);
    tradeArt(num, 0, path, 0, prices, &max);

    

    cout << max << endl;

    return 0;

}