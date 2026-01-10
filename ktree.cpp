#include <iostream>

long long int md = 1e9 + 7;
//TODO
using namespace std;
int main(){
    int n, k, d;
    cin >> n >> k >> d;
    int tsum[n+1];
    tsum[1] = 1;

    for(int i = 2; i <= n; i++){
        tsum[i] = 1;
        for(int j = i-1; j>= 1; j--)
            tsum[i] += tsum[j];
    }

    return 0;
}