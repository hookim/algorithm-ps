#include <iostream>
#include <string>

using namespace std;

string cmd;
string ans = "";
string tok;
int i = 0;

void parse(){

  for(; i < cmd.size(); i++){
    tok = cmd[i];
    ans  = "<" + tok + ">\n";
    i++;
    if(i == cmd.size()){
      ans = "</" + tok + ">\n";
      break;
    }
    else if(tok == ">"){

    }else if(tok == "*"){

    }else if (tok == "+"){

    }else{

    }

  }
}

void o_include() {
  
}

void o_sibling() {

}

void o_copy() {

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin >> cmd;

    parse(cmd);
    
    return 0;
}
