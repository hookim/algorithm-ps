#include <iostream>
#include <vector>
using namespace std;

/*
    <5g 기지국 설치>
1. N이 2억! 좀 많다. 
2. 수학 수식으로 풀어낼 수 있는거 아닌가? 그렇다면 손쉽게 풀 수 있을 듯.
3. 우선 stations가 정렬 되어 있으니까. 하나씩 순회 하면서 남은 공간을 기지국 coverage만큼 나눈다. 그리고 그 몫을 구한다.
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int beg = 0;
    int coverage =  2 * w + 1;
    
    for(auto station : stations){
        int span = (station - w - 1) - beg;
        
        if(span > 0)
            answer += ((span / coverage) + (span % coverage ? 1 : 0));
        
        beg = station + w;
    }
    
    if(beg < n) {
        int span = (n - beg);
        answer += ((span / coverage) + (span % coverage ? 1 : 0));
    }        
    
    return answer;
}