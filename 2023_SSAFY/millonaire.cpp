#include<iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, a;
    long long res  = 0;
        cin >> N;
        stack <int> S;
        for (int i = 0; i < N; i++){
            cin >> a;
            S.push(a);
        }
        int m = S.top();
        S.pop();
        res = 0;
        while(!S.empty()){
            int x = S.top();
            S.pop();
            if(m < x)
                m = x;
            else
                res += (m - x);      	
        }
        
        cout << "#" << test_case << " " << res << endl; 
        
        


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}