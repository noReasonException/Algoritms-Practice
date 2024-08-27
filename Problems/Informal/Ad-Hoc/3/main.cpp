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
 *	Biggest -> Smallest
 * 	if break, should rest become biggest every time
 * 	if not -> No
*/
void solve(){
	int n;
	cin >> n;
	vector<int> inp(n);
	bool increasing=true;
	int monotonicSwitch = 0;
	string result="No";
	if(n==2){
		cout<<"Yes";
		return;
	}

	for(int i=0;i<n;i++) {
		cin>>inp[i];
		if(i){

			if(increasing&&inp[i-1]<inp[i]) {
				monotonicSwitch+=1;
				increasing=false;
			}
			else if((!increasing)&&inp[i-1]>inp[1]){
				monotonicSwitch+=1;
				increasing=true;
			}
		}

	}
	cout<<((monotonicSwitch<=2)?"Yes":"No");

}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}