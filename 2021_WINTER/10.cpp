//21 12 24 백준 18870번 좌표압축문제

#include<iostream>
#include<cstdlib>
using namespace std;

int compare(const void *  x, const void * y){
    if(*(int *)x < *(int *)y) return -1;
    else if(*(int *) x == *(int *)y) return 0;
    else return 1;
}
void bsearch(int target, int array[], int start, int end, int* idx){
    int mid = (start + end) / 2;
    if(start == end){ 
        if(array[start] == target)*idx = start;
    }else{
        if(array[mid] > target) bsearch(target,array,start,mid-1,idx);
        else if(array[mid] < target) bsearch(target,array,mid+1,end,idx);
        else *idx = mid;
    }
}

int main(void){

    int N;
    cin >> N;

    int c[N];
    int d[N];
    
    for(int i = 0; i < N; i++){
        cin >> c[i];
        d[i] = c[i];
    }

    qsort(c, N, sizeof(int), compare);

    int nd[N]; 
    int count = 1;
    nd[0] = c[0];
    for(int i = 1 ; i < N ; i++){
        if(c[i] != c[i-1]) nd[count++] = c[i];
    }   

    int idx;
    for(int i =0; i< N; i++){
        idx = -1;
        bsearch(d[i], nd, 0, count-1, &idx);
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}