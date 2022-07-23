#include <deque>
#include <iostream>
#include <cstdlib>

using namespace std;
int cmp(int a, int b){
    if(abs(a) < abs(b))
        return 1;
    else if (abs(a) == abs(b)){
        if (a < b)
            return 1; 
    }
    return 0;
}
// void print_heap ( deque <int> heap){
//     cout << "[";
//     for(int i = 0 ; i < heap.size() ; i++){
//         cout << heap[i] << " " ;
//     }
//     cout << "]" << endl;
// }

int main(void){
    deque <int> heap;
    int T, n;

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;

        if(n){
            heap.push_back(n);
            int idx = heap.size()-1;
            int parent = (int)(idx-1)/2;

            while(idx > 0){
                if(cmp(heap[idx], heap[parent])){
                    swap(heap[idx], heap[parent]);
                    idx = parent;
                    parent = (int)(idx-1)/2;
                }
                else break;
            }
        }else{
            if (heap.empty()){
                printf("0\n");
                continue;
            }
            cout << heap.front() << endl;
            heap.pop_front();
            
            heap.push_front(heap.back());
            heap.pop_back();

            int idx = 0;
            int left_child = (idx + 1) * 2 - 1;
            int right_child = (idx + 1) * 2;

            if(heap.size() == 2){
                if(cmp(heap[left_child], heap[idx]))
                    swap(heap[left_child], heap[idx]);
            }

            while (right_child < heap.size()){
                if(cmp(heap[left_child], heap[idx]) || cmp(heap[right_child], heap[idx])){
                    if(cmp(heap[left_child], heap[right_child])){
                        swap(heap[left_child], heap[idx]);
                        idx = left_child;
                    }else{
                        swap(heap[right_child], heap[idx]);
                        idx = right_child;
                    }
                    left_child = (idx + 1) * 2 - 1;
                    right_child = (idx + 1) * 2;
                }else break;

            }


        }

    }




    return 0;
}
