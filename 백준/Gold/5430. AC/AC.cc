#include <iostream>
#include <cstring>
#include <sstream>
#include <list>

using namespace std;

int n, T;
string comm, arrstr, buffer;

int main(void){
  cin >> T;
  for(int t = 0 ; t < T; t++){
    bool front = true;
    list<int> arr;
    bool flag = true;
    cin >> comm; 
    cin >> n;
    cin >> arrstr;

    
    istringstream str(arrstr.substr(1, arrstr.size()-2));
    while(getline(str, buffer, ',')){
      arr.push_back(stoi(buffer));
    }
    
    for(int i = 0; i < comm.size(); i++){
      if(comm[i] == 'R'){
        front = !front;
      }
      if(comm[i] == 'D'){
        if(arr.empty()){
          flag = false;          
          break; 
        }
        if(front){
         arr.pop_front();
        }
        else{
          arr.pop_back();
        }
      }
    }
    
    if(!front){
      arr.reverse();
    }

    int size = arr.size();
    
    if(flag){
      cout << "[";
      for(int i = 0; i < size - 1; i++){
        cout << arr.front() << ',';
        arr.pop_front();
      }
      if(!arr.empty()){
        cout << arr.front(); 
        arr.pop_front();
      }
      cout << "]\n";
      
    }
    else{
      cout << "error\n"; 
    }


  }

  return 0;
}