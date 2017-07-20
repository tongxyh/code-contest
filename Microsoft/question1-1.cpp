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
    
    int sum_1 = 0;
    int sum_3 = 0;
    int count = 0;
    vector<int> index_1,sum_1c;
    vector<int> index_2,sum_2c;
    for(int i=0;i<n-2;i++){
        sum_1 = sum_1 + arr[i];
        if(sum_1 >= avg_min && sum_1 <= avg_max){
            index_1.push_back(i);
    //        cout << i << " ";
            sum_1c.push_back(sum_1);
        }
    }
    //cout << endl;
    if(index_1.size() > 0){
    for(int j=n-1;j>index_1[0];j--){
        sum_3 = sum_3 + arr[j];
        if(sum_3 >= avg_min && sum_3 <= avg_max){
            index_2.push_back(j-1);
            //cout << j << " ";
            sum_2c.push_back(sum_3);
        }
    }
    }
    //cout << endl;
    int tmp_index =0;
    int sum_tmp,sum_2 =0;
    for(int i=0;i<index_1.size();i++){
        tmp_index = index_1[i];
        sum_tmp = sum_a - sum_1c[i];
        for(int j=0;j<index_2.size();j++)
        {
            sum_2 = sum_tmp - sum_2c[j];
            if(index_2[j] > tmp_index && sum_2 >= avg_min && sum_2 <= avg_max)
                count = count + 1;
        }
    }
    cout << count;
    return 0;
}