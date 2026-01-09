#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    long long int pre[n];
    pre[0] = a[0];

    for(int i = 1 ; i < n; i++){ pre[i] = pre[i-1] + a[i];}

    if(pre[n-1]%3) cout << 0;
    else{
        long long int tsum = pre[n-1]/3;
        int i = 0;
        long long int tc = 0;

        long long int rc = 0;
        while(i < n-1){
            
            if(pre[i] == 2*tsum){
                tc += rc;
            } 
            if(pre[i] == tsum){
                rc++;
            }  
            i++;
        }
        cout << tc;
    }
    return 0;
}