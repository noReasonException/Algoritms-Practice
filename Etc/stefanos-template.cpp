#include <iostream>
#include <vector>
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



/**
 *	Why?
*/
void solve(){
	vector<int> in;
	in.push_back(10);
	in.push_back(20);
	cinfoCon(in,"123",1);
	in.push_back(20);
	cinfoCon(in,"456",2);
}

int main(){
	int n;
	cin>>n;
	while(n--)solve();
	return 0;
}