#include <iostream>
#include <vector>
#include <map>
#include <sstream>
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
	int n,m,k;
	cin >> n >> m >> k;
	stringstream key;
	map<string,int> positions;
	cout<<"Start "<<n<<"-"<<m<<"-"<<k<<"-"<<endl;

	//rows
	for(int r = 0;r<n-k+1;r++){
		cout<<"r"<<endl;
		//collumns
		for(int c = 0;c<m-k+1;c++){
			for(int l = 0;l<k;l++){
				for(int j=0;j<k;j++){
					cout<<"\t"<<"c"<<endl;
					key<<r+l<<c+j;
					cout<<"\t\t"<<key.str()<<endl;
					if(positions.find(key.str())!=positions.end()){
						positions[key.str()]=positions[key.str()]+1;
					}
					else {
						positions[key.str()]=1;
					}
					key.str("");
				}
			}

			
		}
	}

	map<string, int>::iterator it = positions.begin();
	while (it != positions.end()) {
        cout << "Key: " << it->first
             << ", Value: " << it->second << endl;
        ++it;
    }

}

int main(){
	int n;
	cin>>n;
	while(n--)solve();
	return 0;
}