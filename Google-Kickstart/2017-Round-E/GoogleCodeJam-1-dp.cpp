#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int min_n = 0;

struct Step{
	int n,pos;
	string cp;
	string str;
	string str_obj;
	Step(){
		n = 0;
		pos = 0;
		cp = "";
		str = "";
		str_obj = "";
	}
};



void minStep(Step s)
{
	if (strcmp(s.str.c_str(), s.str_obj.c_str()) == 0){
		if (s.n < min_n) min_n = s.n;
		return;
	}
	else{
		Step ss = s;
		//type
		ss.n = ss.n + 1;
		ss.pos = ss.pos + 1;
		ss.str.push_back(ss.str_obj[ss.str.size()]);
		if (ss.n < min_n)
		minStep(ss);

		ss = s;
		//copy
		//paste
		int flag = 0;
		int max_length = 0;
		string cp_temp = "";
		for (int i = 0; i < ss.str.size(); i++){
			if (ss.str_obj[ss.pos] == ss.str[i]){
				int j = 1;
				flag = 1;
				while (i + j < ss.str.size() && ss.pos + j < ss.str_obj.size() && ss.str_obj[ss.pos + j] == ss.str[i + j])
					j++;
				if (j > max_length)
				{
					max_length = j;
					cp_temp = "";
					for (int k = 0; k < max_length; k++) cp_temp.push_back(ss.str_obj[ss.pos + k]);
				}
			}
		}

		if (flag == 0 || max_length < 2){
			//ss.n = ss.n + 1;
			//ss.pos = ss.pos + 1;
			//ss.str.push_back(ss.str_obj[ss.str.size()]);
		}
		else{
			//strcmp(aa1.c_str(), bb2.c_str()) == 0
			if (strcmp(ss.cp.c_str(), cp_temp.c_str()) == 0)
				ss.n = ss.n + 1;
			else
				ss.n = ss.n + 2;
			ss.cp = cp_temp;

			for (int i = 0; i < max_length; i++)
				ss.str.push_back(ss.str_obj[ss.pos + i]);
			ss.pos = ss.pos + max_length;
			if (ss.n < min_n)
			minStep(ss);
		}
		return;
	}
}

int main()
{
	int num, pos, count, index;
	string str, str_new;
	cin >> num;
	index = 0;
	
	while (cin >> str){
		Step s;
		index = index + 1;
		s.str_obj = str;

		min_n = str.size();

		minStep(s);

		cout << "Case #" << index << ": " << min_n << endl;

	}

	return 0;
}