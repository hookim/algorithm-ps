#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, a;
    long long ans, prev_sum;
    priority_queue <long long> cards;

    cin >> N;
    while(N--){
      cin >> a;
      cards.push(-a);
    }

    if(cards.size() == 1){
      cout << 0 << endl;
      return 0;
    }
    ans = 0;
    do{
      prev_sum  = cards.top(); cards.pop();
      prev_sum += cards.top(); cards.pop();
      ans += prev_sum;
      cards.push(prev_sum);
    }while(cards.size() > 1);
  
    cout << -ans << endl;

    return 0;
}
