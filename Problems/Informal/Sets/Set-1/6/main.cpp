


#include <iostream>
#include <sstream>

using namespace std;

/***
 * 
 */ 

void line(bool state,int n){
	stringstream line;
	for(int i=0;i<n;i++){
		line<<((state)?".":"#");
		line<<((state)?".":"#");
		state=!state;
	}
	string li = line.str();
	cout<<li<<endl<<li<<endl;

}
void solve(){
	int n;
	cin>>n;
	bool state=0;
	for(int i=0;i<n;i++){
		line(state,n);
		state=!state;
	}

}

int main(){
	int t; 
	cin >> t;
	while(t--){
		solve();
	}
}