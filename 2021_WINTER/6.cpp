#include <iostream>

using namespace std;

class fib{
    public:
    int zero;
    int one;
};

int main(int argc, const char * argv[]){
    int Test;
    cin >> Test;

    for(int t = 0 ; t < Test ; t ++){
        int T;
        cin >> T;
        fib dpTable[T];
        dpTable[0].zero = 1;
        dpTable[0].one = 0;
        dpTable[1].zero = 0;
        dpTable[1].one = 1;

        if(T >=2){ 
            int prevprev0, prev0, prevprev1, prev1;
            for(int i = 2; i <= T; i++){
                prevprev0 = dpTable[i-2].zero;
                prev0 = dpTable[i-1].zero;
                prevprev1 = dpTable[i-2].one;
                prev1 = dpTable[i-1].one;

                dpTable[i].zero = prevprev0 + prev0;
                dpTable[i].one = prevprev1 + prev1; 
            }
        }

        cout<<dpTable[T].zero << " " << dpTable[T].one << endl;

    }
    return 0;
}