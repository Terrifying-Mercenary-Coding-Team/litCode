#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int s;
    double sums=0;

    MovingAverage(int size): s(size){}
 
    double next(int val) {
        if(q.size()==s){
            sums -= q.front();
            q.pop();
        }
        q.push(val);
        sums += val;

        return sums / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(){
    MovingAverage *m = new MovingAverage(3);
    cout << m->next(1) << endl;
    cout << m->next(10) << endl;
    cout << m->next(3) << endl;
    cout << m->next(5) << endl;
}
