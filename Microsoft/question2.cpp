#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(void) {
    long int n=0;
    cin >> n;
    string a,b;
    vector<long int> result;
    while(n--) {
        int end_flag = 0;
        long int tmp_i,tmp_j=-1;
        char tmp;
        long int count = 0;
        cin >> a >> b;
        if(strcmp(a.c_str(),b.c_str())==0){
            cout << count << endl;
            result.push_back(count);
            end_flag = 1;
        }
        //cout << b.size() << endl;
        for(int i=0;i<b.size();i++){
            //cout << "String B: "<< i << endl;
            if(end_flag == 1)
                break;
            if(b[i] == a[i]){
            //    cout << "Same" << endl;
                continue;
            }
            for(int j=0;j<a.size();j++){
            //    cout << j << endl;
                if (b[i] == a[j] && a[i] == b[j] && i != j){
                    //cout << "MARK1" << " ";
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    //cout << i << " "<< j <<" "<< a << " " << b << endl;
                    count = count + 1;
                    if(strcmp(a.c_str(),b.c_str())==0){
                        cout << count << endl;
                        result.push_back(count);
                        end_flag = 1;
                        break;
                    }
                    tmp_i = -1;
                    tmp_j = -1;
                    break;
                }
                else if(b[i] == a[j] && i != j){
            //        cout << "MARK2" << " ";
                    tmp_i = i;
                    tmp_j = j;
            //        cout << i << j << endl;
                }
            }
                if(tmp_i >= 0 && tmp_j >= 0 && end_flag == 0){
                    tmp = a[tmp_i];
                    //cout << "MARK3" << " ";
                    a[tmp_i] = a[tmp_j];
                    a[tmp_j] = tmp;
                    count = count + 1;
                    //cout << tmp_i << " "<< tmp_j <<" "<< a << " " << b << endl;
                    if(strcmp(a.c_str(),b.c_str())==0){
                        cout << count << endl;
                        result.push_back(count);
                        end_flag = 1;
                    }
                    tmp_j = -1;
                    tmp_i = -1;
                }
                }
        }
        //for(int i=0;i<result.size();i++)
        //    cout << result[i] << endl;
    }