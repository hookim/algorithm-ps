#include <queue>
#include <iostream>

using namespace std;

int bfs(char bd[8][8], short visited[8][8], int i, int j, int boundary, string s){
    if(s.size() == 1) 
        return 1;
    int moves_row[8] = {0, 0, 1, 1, 1, -1, -1 , -1 };
    int moves_col[8] = {1, -1, 1, 0, -1, 1, 0 , -1 };
    queue < pair <int ,int> > q;
    pair <int, int> cur;
    
    queue <int> idxs;
    int idx; 

    cur.first = i;
    cur.second = j;
    visited[i][j] = 1;

    q.push(cur);
    idxs.push(0);

    while(!q.empty()){
        cur = q.front();
        idx = idxs.front();
        q.pop();
        idxs.pop();
        
        if(bd[cur.first][cur.second] == 'q'){
            if(idx == s.size() -1){
                continue;
            }else if(s[++idx] != 'u'){
                continue;
            }
            else if(idx == s.size()-1 && s[idx] == 'u')
                return 1;
        }
    
        for(int i =0 ;i < 8; i++){
            pair <int, int> adj = q.front();
            adj.first = cur.first + moves_row[i];
            adj.second = cur.second + moves_col[i];            

            if(adj.first >= 0 && adj.first < boundary && adj.second >= 0 && adj.second < boundary && !visited[adj.first][adj.second]){
                if(idx + 1 < s.size() && bd[adj.first][adj.second] == s[idx+1]){
                    if(idx+1 == s.size()-1)
                        return 1;
                    else{
                        visited[adj.first][adj.second] = 1;
                        q.push(adj);
                        idxs.push(idx+1);
                    }
                }

            }
        }
    }

    return 0;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    string dic[200];
    string temp;

    scanf("%d", &n);
    
    for(int i =0 ; i < n; i ++){
        cin >> dic[i];
    }

    char bd[8][8];
    int k;

    while(1){
        short check[200] = {0};
        scanf("%d", &k);
        if(k == 0){
            break;
        }
        priority_queue < string, vector <string>, greater <string> > ans;
        for(int i = 0; i < k ; i++){
            string s;
            cin >> s;
            for(int j = 0 ; j < k; j++){
                bd[i][j] = s[j];
            }
        }

        for(int i =0; i < k; i++){
            for(int j = 0; j < k ; j ++){

                for(int m = 0; m < n; m++){
                    short visited[8][8] = {{0}};
                    if (!check[m] && bd[i][j] == dic[m][0]) {
                        if (bfs(bd, visited, i, j, k, dic[m])){
                            check[m] = 1;
                            ans.push(dic[m]);
                        }
                    }
                }
            }
        }

        while(!ans.empty()){
            cout << ans.top() << '\n';
            ans.pop();
        }
        cout << "-\n";
    }
    return 0;
}
    


