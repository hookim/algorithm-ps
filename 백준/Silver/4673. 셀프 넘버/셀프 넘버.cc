#include <iostream>
#include <string>

using namespace std;

bool checks[10001];

int main(void){
  for(int i = 1; i <= 10000; i++){
    string str = to_string(i);
    int n = i;
    for(int j = 0; j < str.length(); j++){
      n += (str[j] - '0');
    }
    checks[n] = true;
  }

  for(int i = 1; i <= 10000; i++){
    if(!checks[i]){
      cout << i << "\n";
    }
  }

  return 0;
}