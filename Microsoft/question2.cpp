#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
using namespace std;

string s, t;
int n;
int res,num;
void work(int p, int c) {
    if(p >= n) {
        res = min(res, c);
        return;
    }
    if(s[p] == t[p]) work(p + 1, c);
    else {
        for (int j = p + 1; j < n; j++) {
            if(s[j] == t[p]) {
                swap(s[p], s[j]);
                work(p + 1, c + 1);
                swap(s[p], s[j]);
            }
        }
    } 
}
int main() {
    cin >> num;
    while(num--){
    cin >> s >> t;
    n = s.size();
    res = s.size();
    work(0, 0);
    cout << res << endl;
    }
}