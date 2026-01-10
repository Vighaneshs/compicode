#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq;

    long long int ct = 0;
    int pt = 0;

    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            ct += a[i];
            pt++;
        } else {
            if(ct + a[i] >= 0){
                pt++;
                ct += a[i];
                pq.push(a[i]);
            } else{
                if(!pq.empty() && a[i] <= pq.top()) continue;
                else if(!pq.empty()){
                    int curr = pq.top();
                    pq.pop();
                    ct += a[i] - curr; 
                    pq.push(a[i]);
                }
            }
        }

    }
    cout << pt;


    return 0;
}