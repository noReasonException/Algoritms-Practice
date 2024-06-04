#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm> 
using namespace std;



int refl(int index,int size){
	int half = size%2?((size-1)/2):(size/2);
	if(index<half) return size-1-index;
	else return half-(index-half)-(!(size%2));
}

void solve(){
	int size;
	string s;
	cin>>size;
	cin>>s;

	set<char> r_temp;
	
	stringstream result;
	int curr_index,refl_index;

	//populate set
	for(int i=0;i<size;i++){
		r_temp.insert(s[i]);
	}
	vector<char> r (r_temp.begin(),r_temp.end());
	for(int i=0;i<size;i++){
		//the index of this character into r
		curr_index = find(r.begin(),r.end(),s[i]) - r.begin();
		refl_index = refl(curr_index,r.size());
		result<<r[refl_index];
		//result<<
	}
	cout<<result.str()<<endl;


}

int main(){
	int size;
	cin>>size;
	while(size--) solve();
	cout<<endl;
}