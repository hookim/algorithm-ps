#include <iostream>

using namespace std;

string quadZip(string* vid, int y, int x, int size){
    if(size == 1){
        string s(1, vid[y][x]);
        return s; 
    }
    int new_size = size / 2;
    string s1 = quadZip(vid, y, x, new_size);
    string s2 = quadZip(vid, y, x + new_size, new_size);
    string s3 = quadZip(vid, y + new_size, x, new_size);
    string s4 = quadZip(vid, y + new_size, x + new_size, new_size);

    
    if(s1[0] == '(' || s2[0] == '(' || s3[0] == '(' || s4[0] == '(')
        return "(" + s1 + s2 + s3 + s4 + ")";
    else{
        if(s1[0] == '1' && s2[0] == '1' && s3[0] == '1' && s4[0] == '1')
            return "1";
        else if(s1[0] == '0' && s2[0] == '0' && s3[0] == '0' && s4[0] == '0')
            return "0";
        else 
            return "(" + s1 + s2 + s3 + s4 + ")";

    }
        
}

int main(void){
    int N;
    cin >> N;
    string* vid = new string[N]; 
    for(int i = 0; i < N; i++){
        string row;
        cin >> row;
        vid[i] = row;
    }
    cout << quadZip(vid, 0, 0, N) << endl; 

    return 0;
}
