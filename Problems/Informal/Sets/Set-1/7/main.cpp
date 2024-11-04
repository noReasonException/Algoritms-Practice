#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <set>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define b char


using namespace std;

//forward refs
template <typename container> void cinfoCon(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	#define cinfo cout
	#define add <<
	template <typename container> void cinfoCon(container& genericSequence,string id, int depth){
		cout<<"=============cinfoCon Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<"--->>"<<every<<"\n";
		}
		cout<<"=============cinfoCon Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	#define cinfo ;
	#define add ;
	template <typename container> void cinfoCon(container& genericSequence,string id, int depth){
		return ;
	}

#endif
/***
 */ 
bool isOk(ui k_size,string &s,ui n){
	ui confict = 0;
	for(ui each_char=0;each_char<k_size;each_char++){
		for(ui each_segment=1;each_segment<(n/k_size);each_segment+=2){
			if(s[((each_segment-1)*k_size)+each_char] != s[(each_segment*k_size)+each_char]){
				confict+=1;
			}
		}
	}
	return confict<2;
}
//A given candidate string k can only have a chance of being the minimum valid k if s.size() % k.size() == 0 (i.e 'fits exacly')
void solve(){
	ui n;
	string s;
	cin >> n;
	cin >> s;
	for(ui i=1;i<=n;i++){
		//does the current fit?
		if(!(n%(i))){ //yeap
			if(isOk(i,s,n)){
				cout<<i;
				return;
			}
		}
	}
	cout<<s.size();
}

int main(){
	ui t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}