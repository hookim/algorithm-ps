#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int S, P, a, b, t, ans;  
    string dna;
    map <char, int> req;

    cin >> S >> P >> dna;
    cin >> req['A'];
    cin >> req['C'];
    cin >> req['G'];
    cin >> req['T'];
    
    a = 0, b = 0, ans = 0;
    
    while(b < P){
      req[dna[b++]]--;
    }
    b--;

    if(req['A'] <= 0 && req['C'] <= 0 && req['G']<=0 && req['T'] <= 0)
      ans++;

    while(b < S - 1){
      req[dna[++b]]--;
      req[dna[a++]]++;

      if(req['A'] <= 0 && req['C'] <= 0 && req['G']<=0 && req['T'] <= 0)
        ans++;
    }
    cout << ans << endl;
    return 0;
}
