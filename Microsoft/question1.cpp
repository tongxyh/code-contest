#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    int n,a=0;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);
    int sum_a = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        sum_a = sum_a + a;
        arr.push_back(a);
    }

    int avg_min = floor(sum_a/3.0);
    int avg_max = ceil(sum_a/3.0);
    
    int sum_1=0;
    int sum_2=0;
    int sum_3=0;
    int count = 0;
    vector<int> index_1,sum_1c;
    for(int i=0;i<n-2;i++){
        sum_1 = sum_1 + arr[i];
        if(sum_1 >= avg_min && sum_1 <= avg_max){
            index_1.push_back(i);
            sum_1c.push_back(sum_1);
        }
    }
    
    if(index_1.size() > 0){
    for(int i=n-1;i>index_1[0]+1;i--){
        sum_3 = sum_3 + arr[i];
        if(sum_3 >= avg_min && sum_3 <= avg_max){
            for(int j=0;j<index_1.size();j++){
                sum_2 = sum_a - sum_3 - sum_1c[j];
                if(index_1[j] < i-1 && sum_2 >= avg_min && sum_2 <= avg_max){
                    count = count + 1;
            }
            }
        }
    }
    }
    cout << count;
    return 0;
}