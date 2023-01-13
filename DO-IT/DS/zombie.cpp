#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L, range, damage, ammo, acc_dam,i, zombie, dead;
    queue<int>ammo_history;
    
    cin >> L >> range >> damage >> ammo;
    for(dead = 0, i = 1; i <= L; i++){
      cin >> zombie;
      if(i <= range)
        acc_dam = i;
      else 
        acc_dam = range;
      
      while(!ammo_history.empty() && ammo_history.front()+range < i )
        ammo_history.pop();

      acc_dam -= ammo_history.size();

      if(zombie > acc_dam * damage){
        if(ammo-- <= 0)
          dead = 1;
        ammo_history.push(i);
      }
    }
    cout << (dead ? "NO" : "YES") << endl;

    return 0;
}
