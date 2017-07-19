#include <iostream>
//#include <vector>
#include <math.h>
#include <cstdlib>
using namespace std;

int main(void) {
    long int N=0;
    long int a;
    //vector<long int> arr;
    cin >> N;
    long int n = N;
    long int arr[n];
    while(N>0){
        cin >> arr[n-N];
        N--;
    }
    long int sum_a = 0;
    for(int i=0;i<n;i++){
        sum_a = sum_a + arr[i];
    }

    double avg_min = floor(sum_a/3.0);
    double avg_max = ceil(sum_a/3.0);
        
    long int sum_1 = 0;
    long int sum_2 = 0;
    long int sum_3 = 0;
    long int count = 0;
    for(int i=0;i<n;i++){
        sum_1 = sum_1 + arr[i];
        if(sum_1 < avg_min || sum_1 > avg_max)
            continue;
        sum_2 = 0;
        for(int j=i+1;j<n-1;j++){
            sum_2 = sum_2+arr[j];
            if(sum_2 < avg_min || sum_2 > avg_max)
                continue;
            sum_3 = sum_a - sum_1 - sum_2;
            if(abs(sum_1-sum_2) <= 1 && abs(sum_1-sum_3) <=1 && abs(sum_2-sum_3) <=1)
                count = count + 1;
        }
    }   
    cout << count;
    return 0;
}