#include <iostream>
#include <map>

using namespace std;

char dna[1000000];
int S,P, ans;

void solution(){
  map<char, int>count, target;
  cin >> S >> P;
  for(int i =0 ; i < S; i++){
    cin >> dna[i];
  }
  cin >> target['A'];
  cin >> target['C'];
  cin >> target['G'];
  cin >> target['T'];

  int p1 = 0, p2 = P-1;
  for(int i = p1 ; i <= p2; i++){
    count[dna[i]]++;
  }
  while(p2 < S){
    if(
    count['A'] >= target['A'] &&
    count['C'] >= target['C'] &&
    count['G'] >= target['G'] &&
    count['T'] >= target['T'] 
    ) ans++;
    count[dna[p1++]]--;
    count[dna[++p2]]++;
  }

  cout << ans << "\n";
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
