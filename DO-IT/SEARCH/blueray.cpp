#include <iostream>
#include <vector>

using namespace std;


int N, M, a, vmax, vsum, vnum, vbeg, vend, vmid, ans;
vector<int> br;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while(N--){
      cin >> a;
      br.push_back(a);
      vsum += a;
      if(vmax < a) vmax = a; 
    }
    vbeg = vmax;
    vend = vsum;
    while (vbeg <= vend){
      vmid = (int) (vbeg + vend) / 2;
      vnum = 1; vsum = 0;
      for(auto it = br.begin(); it != br.end(); it++){
        vsum += *it;
        if(vsum > vmid){
          vnum++;
          vsum = *it;
        }
      }
      if(vnum <= M){
        ans = vmid;
        vend = vmid -1;
      }
      else
        vbeg = vmid +1;
        
    }
    cout << ans << endl;
    return 0;
}
