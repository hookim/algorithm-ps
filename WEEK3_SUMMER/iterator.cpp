#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void print_list(list <int> l, list<int> :: iterator it){
    auto temp = it;
    it = l.begin();
    for(; it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    it = temp;
}

int main(void){
    list <int> l;
    list <int> :: iterator it;
    l.push_back(19);
    l.push_back(96);
    l.push_back(7);
    l.push_back(12);
    l.push_back(99);

    it = l.end();
    cout << *it << endl;
    auto count =1;
    for(it = l.begin(); it != l.end(); it++){
        cout << count++ << ". " << *it << endl; 
    }
    
    
    
    //OLD Data
    
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(3);
    
    // list <int> l2 = list <int>(l);
    // list <int> l3 = list <int>(l);
    // list <int> l4 = list <int>(l);
    // list <int> l5 = list <int>(l);
    // list <int> l6 = list <int>(l);
    // list <int> l7 = list <int>(l);
    

    // //Question 1
    // it = l.begin();
    // l.insert(it, 999);
    // cout << *it << endl;
    // print_list(l,it);

    // //Question 2
    // it = l2.begin();
    // l2.erase(it);
    // cout << *it << endl; 
    // print_list(l2, it);

    // //Question 3
    // it = next(l3.begin(), 1);
    // l3.erase(it);
    // cout << *it << endl; 
    // print_list(l3, it);
    
    // //Question 4
    // it = next(l4.begin(), 2);
    // l4.erase(it);
    // cout << *it << endl; 
    // print_list(l4, it);

    // //Question 5
    // l5.push_back(4);
    // it = next(l5.begin(), 1);
    // l5.erase(it);
    // it++;
    // cout << *(it) << endl;
    // print_list(l4, it);

    // //Question 6
    // it = l6.end();
    // cout << *it << endl;
    // print_list(l6, it);
    
    //Question 7
    // it = l7.end();
    // cout << *it << endl;
    // cout << *it << endl;
    
    // it = next(l7.begin(), 1);
    // cout << *it << endl;
    // l7.push_back(4);
    // cout << *it << endl;





        

    return 0;
}
