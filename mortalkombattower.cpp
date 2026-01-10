#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int t;
    cin >> t;

    for(int s = 0; s < t; s++){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        int dp[2][n];
        dp[0][0] = (a[0] == 1)? 1: 0;
        dp[1][0] = n+1;

        if(n == 1) cout <<  dp[0][0] << endl;
        else{
            
            dp[0][1] = (a[1] == 1)? 1 + dp[0][0]: dp[0][0];
            dp[1][1] = dp[0][0];


            for(int i = 2; i < n; i++){
                dp[0][i] = min(a[i-1] + a[i] + dp[1][i-2], a[i] + dp[1][i-1]);
                dp[1][i] = min(dp[0][i-2], dp[0][i-1]);
            }
            cout << min(dp[0][n-1], dp[1][n-1]) << endl;
        }
    }
}