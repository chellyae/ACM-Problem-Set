#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX_N X
#define MAX_M X
using namespace std;
int casetotal;
int casenum = 0;
int main(){
	cin >> casetotal;
	while (casenum++ < casetotal){
		if (casenum != 1) cout << endl;
		string a, b;
		cin >> a >> b;
		int sa = a.size();
		int sb = b.size();
		int tt = max(sa, sb) + 1;
		int carry = 0;
		string c="";
		char tmpchar;
		for (int i = 0; i < tt; i++){
			if (i < sa&&i < sb){
				tmpchar = a.at(sa-1 - i) + b.at(sb-1 - i) - '0'+carry;
				if (tmpchar > '9'){
					tmpchar = tmpchar - 10;
					carry = 1;
				}
				else{
					carry = 0;
				}
				c.push_back(tmpchar);
			}
			else if (i >= sa&&i < sb){
				tmpchar = b.at(sb-1 - i) + carry;
				if (tmpchar > '9'){
					tmpchar = tmpchar - 10;
					carry = 1;
				}
				else{
					carry = 0;
				}
				c.push_back(tmpchar);
			}
			else if (i >= sb&&i < sa){
				tmpchar = a.at(sa-1 - i) + carry;
				if (tmpchar > '9'){
					tmpchar = tmpchar - 10;
					carry = 1;
				}
				else{
					carry = 0;
				}
				c.push_back(tmpchar);
			}
			else{
				if (carry == 1){
					c.push_back('1');
				}
			}
		}
		cout << "Case " << casenum << ":" << endl;
		cout << a << " + " << b << " = ";
		for (int i = c.size() - 1; i >= 0; i--){
			cout << c.at(i);
		}
		cout << endl;
		
	}
	return 0;
}
