#include <iostream>
//#include <vector>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(void) {
    long int n=0;
    cin >> n;
    string a,b;
    int end_flag = 0;
    while(n--) {
        long int tmp_i,tmp_j=0;
        char tmp;
        long int count = 0;
        cin >> a >> b;
        //cout << b.size() << endl;
        for(int i=0;i<b.size();i++){
            //cout << "String B: "<< i << endl;
            if(end_flag == 1)
                break;
            if(b[i] == a[i]){
            //    cout << "Same" << endl;
                continue;
            }
            for(int j=i;j<a.size();j++){
            //    cout << j << endl;
                if (b[i] == a[j] && a[i] == b[j] && i != j){
                    cout << "MARK1" << " ";
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    cout << i << " "<< j <<" "<< a << " " << b << endl;
                    count = count + 1;
                    if(strcmp(a.c_str(),b.c_str())==0){
                        cout << count << endl;
                        end_flag = 1;
                        break;
                    }
                    break;
                }
                if(b[i] == a[j] && i != j){
            //        cout << "MARK2" << " ";
                    tmp_i = i;
                    tmp_j = j;
            //        cout << i << j << endl;
                }
            }
                if(tmp_i >= 0 && tmp_j >= 0 && end_flag == 0){
                    tmp = a[tmp_i];
                    cout << "MARK3" << " ";
                    a[tmp_i] = a[tmp_j];
                    a[tmp_j] = tmp;
                    count = count + 1;
                    cout << tmp_i << " "<< tmp_j <<" "<< a << " " << b << endl;
                    if(strcmp(a.c_str(),b.c_str())==0){
                        cout << count << endl;
                        end_flag = 1;
                    }
                }
                }
        }
    }