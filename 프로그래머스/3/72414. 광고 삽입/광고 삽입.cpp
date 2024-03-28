#include <string>
#include <vector>
#include <iostream>

using namespace std;


int arr[360000];

int stringToInteger (string str){
    int ret = 0;
    ret += stoi(str.substr(0, 2)) * 60 * 60;
    ret += stoi(str.substr(3, 2)) * 60;
    ret += stoi(str.substr(6, 2));
    
    return ret;
}

string intToString(int n){
    string ret = "";
    ret += (char)((n / 10) + '0');
    ret += (char)((n % 10) + '0');
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int idx = 0;
    for(string s : logs){
        
        int begTime = stringToInteger(s.substr(0, 8));
        int endTime = stringToInteger(s.substr(9, 8));
        
        for(int i = begTime; i < endTime; i++){
            arr[i]++;
        }
        
    }
    
    int ptime = stringToInteger(play_time);
    int atime = stringToInteger(adv_time);
    
    long long mmax = 0;
    int beg = 0, end = atime-1, ans=  0;
    
    for(int i = 0; i < atime; i++){
        mmax += arr[i];     
    }
    
    long long  temp = mmax;
    while(end <= ptime){
        temp-= arr[beg++];
        temp+= arr[++end];
        
        if(mmax < temp){
            mmax = temp;
            ans = beg;
        }
    }
    
    answer += intToString((ans / (60 * 60)));
    answer += ":";
    answer += intToString(((ans % (60 * 60)) / (60) ));
    answer += ":";
    answer += intToString(((ans % (60 * 60)) % (60) ) % 60);
    
    return answer;
}