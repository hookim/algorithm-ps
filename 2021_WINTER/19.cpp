// 세수 정렬 백준 2752번

#include <iostream>

using namespace std;

int main(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2] ;
    int min = arr[0], mid = arr[0], max = arr[0];
    if(arr[0] > arr[1]){
        min = arr[1]; 
    }else{
        mid = arr[1];
        max = arr[1];
    }
    
    if(arr[1] < arr[2]){
        max = arr[2];
    }else{
        min = arr[2];
    }

    cout << min << " " << mid  << " " << max << endl;
    return 0;
}   