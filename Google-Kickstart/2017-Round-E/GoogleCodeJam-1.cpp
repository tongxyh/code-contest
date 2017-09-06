#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int num,pos,count,index;
	string str,str_new;
	cin >> num;
	index = 0;
	while (cin >> str){
		index++;
		str_new = "";
		pos = 0;
		count = 0;
		string cp="";
		string cp_temp = "";

		if (str.size() > 0){
			str_new.push_back(str[0]);
			count = count + 1;
			pos = pos + 1;
		}
		else{
			cout << "Case #" << index << ": " << count << endl;
		}

		while (pos < str.size()){
			
			int flag = 0;
			int max_length = 0;
			for (int i = 0; i < str_new.size(); i++){
				if (str[pos] == str_new[i]){
					flag = 1;
					int j = 1;
					while (i+j < str_new.size() && str[pos + j] == str_new[i + j])
						j++;
					if (j > max_length){
						max_length = j;
						cp_temp = "";
						for (int i = 0; i < max_length; i++){
							cp_temp.push_back(str[pos + i]);
						}
					}
				}
			}
			if (flag == 0 || max_length < 2){
				count = count + 1;
				pos = pos + 1;
				str_new.push_back(str[str_new.size()]);
			}
			else{
				//strcmp(aa1.c_str(), bb2.c_str()) == 0
				if (strcmp(cp.c_str(), cp_temp.c_str()) == 0)
					count = count + 1;
				else
					count = count + 2;
				cp = cp_temp;
				
				for (int i = 0; i < max_length; i++)
					str_new.push_back(str[pos + i]);
				pos = pos + max_length;
			}
			cout << str_new << " , count: " <<count <<endl;
		}
		cout << "Case #" << index << ": " << count << endl;
	}
	return 0;
}