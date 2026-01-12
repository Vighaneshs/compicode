#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve(long long n, long long k) {
    // Edge case: If we want more apples than we started with
    if (k > n) return -1; 
    
    // Iterate through time 't' (depth of the split tree)
    // Since n <= 10^18, depth will not exceed ~62
    for (int t = 0; t <= 62; ++t) {
        
        // At time t, we have implicitly divided n by 2^t.
        // We use bit shifting for 2^t. 1ULL ensures unsigned long long literal.
        long long div = 1ULL << t; 
        
        // Calculate the range of pile sizes at depth t
        // min_val = floor(n / 2^t)
        // max_val = ceil(n / 2^t) -> using formula (n + div - 1) / div
        long long min_val = n / div;
        long long max_val = (n + div - 1) / div;

        // Check if k exists in this range
        if (k >= min_val && k <= max_val) {
            return t;
        }

        // Optimization:
        // Since pile sizes decrease as t increases, if the LARGEST possible
        // pile at this depth is already smaller than k, we will never find k.
        if (max_val < k) {
            return -1;
        }
    }
    
    return -1;
}

int main() {
    // Example Usage
    long long n = 11, k = 5;
    
    // Trace: 
    // t=0: Range [10, 10] -> No
    // t=1: Range [5, 5]   -> No
    // t=2: Range [2, 3]   -> Yes! Returns 2.
    
    cout << "Minimum time: " << solve(n, k) << endl;
    return 0;
}