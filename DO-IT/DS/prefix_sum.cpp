#include <iostream>
#include <vector>


#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}


using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, sum, t, i, a, b;
    vector<int> psums;
    
    cin >> N >> Q;
    psums.push_back(0);
    for(sum=0,i=0; i < N; i++){
      cin >> t;
      sum += t;
      psums.push_back(sum);
    }
    
    for(i = 0; i < Q; i++){
      cin >> a >> b;
      cout << psums[b] - psums[a-1] << "\n";
    }

    return 0;
}