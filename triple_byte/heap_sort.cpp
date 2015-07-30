#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class HeapSort {
private:
    vector<int> arr;
public:
    void insert(int ele);
    vector<int> hsort();
    void print_arr();
    void insert_at_right_pos();
};


void HeapSort::insert(int ele) {
    // Push the element at the end
    arr.push_back(ele);
    // Send it to it's right place
    int i = arr.size() - 1;
    while (i > 0) {
        if(arr[i] >= arr[(i-1)/2]) {
            int temp = arr[i];
            arr[i] = arr[(i-1)/2];
            arr[(i-1)/2] = temp;
        }
        i = (i-1)/2;
    }
}




void HeapSort::insert_at_right_pos() {
    if(arr.size() <= 0) return;
    else {
       int i = 0;
       while(i < arr.size()) {
            int child1 = (2*i) + 1;
            int child2 = (2*i) + 2;
            
            if(child1 < arr.size() && child2 < arr.size()) {
                int index;
                if(arr[child1] > arr[child2])
                    index = child1;
                else
                    index = child2;
                
                if(arr[i] < arr[index]) {
                   swap(arr[i], arr[index]);
                   i = index;
                }
                else 
                   break;
            }
            else {
                int index;
                if(child1 < arr.size())
                   index = child1;
                else if(child2 < arr.size())
                   index = child2;
                else
                   break;
                if(arr[i] < arr[index]) {
                    swap(arr[i], arr[index]);
                    i = index;
                }
                else
                    break;
            }
       }
    }
}
            
                       
vector<int> HeapSort::hsort() {
    vector<int> result;
    while(arr.size() > 0) {
        int ele = arr[0];
//        cout << ele << endl;
        result.push_back(ele);
        
        // now replace this with bottom element 
        int temp = arr[0];
        arr[0] = arr[arr.size() -1];
        arr[arr.size() - 1] = temp;

        arr.pop_back();
        insert_at_right_pos();
    }
    return result;
}


void HeapSort::print_arr() {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
     

int main() {
//    int n;
//    cin >> n;
    HeapSort h;
    vector<int> input(1000);
    for(int i=0; i<1000; i++) {
//        cin >> input[i];
       input[i] = rand()%1000 + 1;
       h.insert(input[i]);
    }

    sort(input.begin(), input.end());
//    h.print_arr();
    
    vector<int> res = h.hsort();
    reverse(res.begin(), res.end());

    for(int i=0; i<res.size(); i++)
            cout << res[i] << " ";
    cout << endl;

    if(input == res)
       cout << "Yayy!!! They are equal" << endl;
    else
       cout << "Ooops!! There is a problem" << endl;

    return 0;
}

