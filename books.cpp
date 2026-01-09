#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    int a[n];
    vector<int> poss;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int csum = 0;

    int m = 0;
    
    while(r < n){
    
        csum += a[r];

        while(csum > t){
            csum -= a[l];
            l++;
        }
        m = max(m, r-l +1);
        r++;
    }
    
    cout << m << endl;
    
    return 0;
}