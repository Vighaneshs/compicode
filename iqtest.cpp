#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 1; i < n-1; i++){
        if(a[i]%2 != a[i-1]%2 && a[i]%2 != a[i+1]%2){
            cout << i+1;
            return 0;
        }
    }
    if(a[0]%2 != a[1]%2 && a[n-1]%2 == a[n-2]%2){cout << 1; return 0;}
    cout << n;
    return 0;
}

