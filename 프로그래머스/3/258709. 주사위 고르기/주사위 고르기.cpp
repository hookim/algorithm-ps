#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> diceArr;
vector<int> answer;
bool picks[10], ans[10];
int N, vic;

void allPossible(vector<int> &arr, int start, int s, int d, bool flag){
    if(d == N/2){
        arr.push_back(s);
        return;
    }
    
    for(int i = start; i < N; i++){
        if(picks[i] != flag) continue;
                                                                
        for(int j = 0; j < 6; j++){
            allPossible(arr, i+1, s + diceArr[i][j], d+1, flag);
        }
    }
}

int calc(){
    vector<int> arrA, arrB;
    int idx1 = 0, idx2 =0;
    allPossible(arrA, 0, 0, 0, true);
    allPossible(arrB, 0, 0, 0, false);
    
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end());
    int totalSize = arrA.size();
    int vicA = 0;
    while(idx1 < totalSize && idx2 < totalSize){
        
        if(arrA[idx1] > arrB[idx2]){
            vicA += (totalSize - idx1);
            idx2++;
        }
        else{
            idx1++;
        }
    }
    return vicA;
}

void solve(int start, int d){
    if(d == N/2){
        int temp = calc(); 
        if(vic < temp){
            vic = temp;
            for(int i = 0; i < N; i++){
                ans[i] = picks[i];
            }    
        }
        return;
    }
    
    for(int i = start ; i < N; i++){
        picks[i] = true;
        solve(i+1, d+1);
        picks[i] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    diceArr = dice;
    N = dice.size();
    
    solve(0, 0);
    
    for(int i = 0 ; i < N; i++){
        if(ans[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}