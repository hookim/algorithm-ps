//2021 12 20 백준 7568번 덩치 문제

#include <iostream>
using namespace std;

class bulk{
    public:
        int weight;
        int height;
        int rank;
};
int main(){
    int N;
    cin >> N;
    bulk people[N];

    for(int i =0; i < N ; i ++){
        cin >> people[i].weight >> people[i].height;
        people[i].rank = 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j && (people[i].weight < people[j].weight && people[i].height < people[j].height)){
                (people[i].rank)++;
            }
        }
    }

    for(int i = 0; i < N ; i++){
        cout << people[i].rank << " ";
    }
    cout << endl;


    return 0;
}