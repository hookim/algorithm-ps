#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int findDigit(int begin, int end, bool btns[10], bool isMax){
    if(isMax){
        int max = -1;
        for(int i = end; i >= begin; i--){
            if(btns[i] && i > max){
                max =  i;
                break;
            }
        }
        return max;
    }
    else{
        int min = 10;
        for(int i = begin; i <= end; i++){
            if(btns[i] && i < min){
                min = i;
                break;
            }
        }
        if(min == 10)
            min = -1;
        return min;
    }
}

void minClicks(string num, string goal, int delta, int count, bool btns[10], int & min){
    if(num.length() == goal.length()){
        for(int i = 0; i < goal.size(); i++){
            if(num[i] == '0')
                count--;
            else
                break;
        }
        if(goal != num){
            count += abs(stoi(num) - stoi(goal));
        }

        if(min > count){
            min = count;
        }

        return;
    }
    int d = num.length();
    int curDigit = goal[d] - '0';
    //if very first or prev digit was equal
    if(d == 0 || delta == 0){
        int upperAbs = findDigit(curDigit, 9, btns, false); //find btn of larger nearest to curDigit
        int lowerAbs = findDigit(0, curDigit, btns, true); //find btn of smaller nearest to curDigit

        //if they are equal means upper == lower == curDigit
        if(upperAbs == curDigit){
            minClicks(num+goal[d], goal, 0, count+1, btns, min);
        }
        //if no match
        else{
            //pick nearer one. either upperAbs, lowerAbs. but make sure they are valid
            if(upperAbs >= 0 && lowerAbs >= 0){
                //they can be both used if their diff abs are same
                if((upperAbs - curDigit) <= (curDigit - lowerAbs))
                    minClicks(num+char(upperAbs + '0'), goal, 1, count+1, btns, min);
                if((curDigit- lowerAbs) <= (upperAbs - curDigit))
                    minClicks(num+char(lowerAbs + '0'), goal, -1, count+1, btns, min);
            }
            //if not only pick valid one, at least one is valid
            else{
                if(upperAbs >= 0)
                    minClicks(num+char(upperAbs + '0'), goal, 1, count+1, btns, min);
                else
                    minClicks(num+char(lowerAbs + '0'), goal, -1, count+1, btns, min);
            }
        }
    }
    //prev digit was larger than goal digit find least digit
    else if (delta > 0){
        int newDigit = findDigit(0, 9, btns, false);
        minClicks(num+char(newDigit + '0'), goal, delta, count+1, btns, min);
    }

    else{
        int newDigit = findDigit(0, 9, btns, true);
        minClicks(num+char(newDigit + '0'), goal, delta, count+1, btns, min);
    }
}

int main(void){
    string N;
    int C; 
    cin >> N;
    cin >> C;
    bool btns[10] ={1,1,1,1,1,1,1,1,1,1};
    
    for(int i = 0;  i <  C; i++){
        int k;
        cin >> k;
        btns[k] = false;
    }
    
    int default_diff = abs(stoi(N) - 100);
    int min = 5000000;
    if(findDigit(0,9,btns,true) >= 0)
        minClicks("", N, 0, 0, btns, min);
    
    if(min > default_diff)
        min = default_diff;

    cout << min << endl;


    return 0;
}
