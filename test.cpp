#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	char mat[10][10];
	int N;
	
	cin >> N;
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mat[i][j];
      mat[i][j] -= '0'	;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	
  vector<int> a;
	return 0;
}
