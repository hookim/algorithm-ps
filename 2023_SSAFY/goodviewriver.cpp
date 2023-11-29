#include<iostream>

using namespace std;

int solution(int a, int b, int x, int c, int d){
  if(x < a || x < b || x < c || x < d) return 0;
  else{
    int m = max(max(a,b), max(c,d));
    return x - m;
  }
}
void shift(int &a, int &b, int &x, int &c, int &d){
  a = b; b = x; x = c; c = d;
}

int main(int argc, char** argv)
{
  int T, test_case;
	T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N;
    int a,b,c,d,x,res;
    a=0;b=0;
    cin >> N;
    cin >> x;N--;
    cin >> c;N--;
    cin >> d;N--;
    res = solution(a,b,x,c,d);
    while(N--){
      shift(a,b,x,c,d);
      cin >> d;
      res += solution(a,b,x,c,d);
    } 
    shift(a,b,x,c,d);d = 0;res += solution(a,b,x,c,d);
    shift(a,b,x,c,d);d = 0;res += solution(a,b,x,c,d);

    cout << "#" << test_case  << " " << res << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}