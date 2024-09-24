#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 차량의 진입과 진출 지점을 기준으로 정렬하는 비교 함수
bool cmp(const vector<int>& a, const vector<int>& b) {
    // 차량의 나가는 지점으로 오름차순 정렬
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int target = -30001;  // 카메라가 설치된 위치
    
    // 차량의 나가는 지점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), cmp);
    
    // 모든 차량에 대해 카메라 설치 여부를 판단
    for (const auto& route : routes) {
        // 현재 차량의 진입 지점이 마지막 카메라의 위치보다 뒤에 있으면
        if (route[0] > target) {
            // 새로운 카메라 설치
            answer++;
            // 현재 차량의 나가는 지점에 카메라 설치
            target = route[1];
        }
    }
    
    return answer;
}
