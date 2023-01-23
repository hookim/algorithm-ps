#include <iostream>
#include <queue>

using namespace std;

short visited[100001];
int isOk(int x){
  if(x >= 0 && x <= 100000 && !visited[x])  
    return 1;
  return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <pair <int, int> > q;
    int N, K, a, b;

    cin >> N >> K;
    
    q.push(make_pair(N, 0));
    while (!q.empty()){
      a = q.front().first;
      b = q.front().second;
      q.pop();
      if(a == K)
        break;
        
      if(isOk(a+1)){
        visited[a+1] = 1;
        q.push(make_pair(a+1, b+1));
      }
      if(isOk(a-1)){
        visited[a-1] = 1;
        q.push(make_pair(a-1, b+1));
      }
      if(isOk(a*2)){
        visited[a*2] = 1;
        q.push(make_pair(a*2, b+1));
      }
    }
    cout << b << endl;

    return 0;
}
