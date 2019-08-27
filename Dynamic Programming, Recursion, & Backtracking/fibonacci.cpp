

#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
    static int fib(int N){
        if(N==0) return 0;
        if(N==1) return 1;
        
        int arr[N+1];
        arr[0]=0;
        arr[1]=1;
        
        for (int i=2; i<=N ;++i){
            arr[i] = arr[i-2] + arr[i-1];
        }
        
        return arr[N];
    }
};


int main() {
    
    cout << Solution::fib(10) << endl;
    
    return 0;
}
