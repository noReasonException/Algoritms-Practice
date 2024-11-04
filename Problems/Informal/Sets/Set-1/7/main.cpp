#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
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
			cout<<prefix<<every<<"\n";
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
 * The idea is simple and inefficient
 * 		if a candidate can fit 'exacly'
 * 			we split the string to segments of size k
 * 				every character of each segment should match  
 * 																		Seg-1    Seg-2 
 * 																	stormflame stornflame
 * 																	|		   |
 * 				has always offset = k.size()--->					------------
 * * 																stormflame stornflame
 * 																	 |		    |
 * 																	 ------------
 * 																		....
 * 																		....
 * * 																stormflame stornflame
 * 																	         |		    |
 * 																	          ------------
 */ 
bool isOk(ui k_size,string &s){
	ui confict = false;
	ui s_size = s.size();
	for(ui segment=1;segment<(s_size/k_size);segment+=1){
		for(ui each_char=0;each_char<k_size;each_char+=1){
			if(s[each_char] != s[(segment*k_size)+each_char]){
				if(!confict) confict=true;
				else return false;
			}
		}
	}
	return true;
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
			if(isOk(i,s)){
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