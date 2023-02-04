#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int bs(int a){
  int beg, end, mid;
  beg = 0, end = v.size()-1;
  while(beg <= end){
    mid = (int)(beg + end) / 2;
    if(v[mid] == a)
      return 1;
    else if(v[mid] > a)
      end = mid - 1;
    else 
      beg = mid + 1;
  }
  return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N , a;
    cin >> N;
    while(N--){
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    cin >> N;
    while(N--){
      cin >> a;
      cout << bs(a) << "\n";
    }
    return 0;
}
