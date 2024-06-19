#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> mapper;
int arr[50][50];
int ans[50];
int giftidx[50];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int n = 0;
    for(auto v : friends){
        mapper[v] = n++;
    }
    
    for(auto v : gifts){
        string a = v.substr(0, v.find(" "));
        string b = v.substr(v.find(" ") + 1, v.size());
        arr[mapper[a]][mapper[b]]++;
    }
        
    for(auto v : friends){
        int a = 0, b = 0;
        for(int i = 0; i < friends.size(); i++){
            if(i == mapper[v]) continue;
            a += arr[mapper[v]][i];
            b += arr[i][mapper[v]];
        }
        giftidx[mapper[v]] = a - b;
    }
    
    for(int i = 0; i < friends.size()-1; i++){
        for(int j = i+1; j < friends.size(); j++){
            int a = arr[i][j];
            int b = arr[j][i];
            
            if(a > b){
                ans[i] ++;
            }
            else if(a < b){
                ans[j] ++;
            }
            else{
                if(giftidx[i] > giftidx[j]){
                    ans[i]++;
                }
                if(giftidx[i] < giftidx[j]){
                    ans[j]++;
                }
            }
        }
    }
    sort(ans, ans + friends.size());
    
    answer = ans[friends.size()-1];
    return answer;
}