#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> ma;
long long n=0;
long long a=0;
vector<long> sum_11;
long long sum_a = 0;

long long work(long long x, long long y) {
    long long res = 0;
    ma.clear();
    long long as = 0;
    for (long long i = 0; i < n - 1; i++) {
        as += sum_11[i];
        
        if(as == x + y) {
            res += ma[x];
        }
        ma[as]++;
    }
    return res;
}

int main(void) {
    cin >> n;
    sum_11.reserve(n);

    for(long long i=0;i<n;i++){
        scanf("%lld",&a);
        //arr.push_back(a);
        sum_a = sum_a + a;
        sum_11.push_back(a);
    }
    int yu = sum_a%3;
    if(yu<0) yu = 3 + yu;

    long long x = (sum_a-yu)/3;
    long long result = 0;
    
    if(yu == 0)
        result = work(x,x);
    if(yu == 1)
        result = work(x,x)+work(x+1,x)+work(x,x+1);
    if(yu == 2)
        result = work(x,x+1)+work(x+1,x+1)+work(x+1,x);

    cout << result;
    return 0;
}

