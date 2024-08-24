#include <iostream>
#include <set>

using namespace std;


void solve(){
	//len1 	: length of area 1
	//len2 	: length of area 2
	//s1 	: start of small area
	//s2 	: start of small area
	//b1 	: start of small area
	//b1 	: start of small area
	int a,b,c,d,len1,len2;
	int s1,s2,b1,b2;
	cin>>a>>b>>c>>d;
	set<int> area1,area2;
	len1 = max(a,b) - min(a,b);
	len2 = max(c,d) - min(c,d);  


	//if both areas have equal length, then both lines 
	if(len1==len2){
		cout<<"YES";
		return;
	}
	else if(len1<len2){
		s1=min(a,b);
		s2=max(a,b);
		b1=min(c,d);
		b2=max(c,d);
		cout<<"len1"<<endl;
	}else{
		s1=min(c,d);
		s2=max(c,d);
		b1=min(a,b);
		b2=max(a,b);
		cout<<"len2"<<endl;
	}
	int start = s1;
	int stop = s2;
	int current = start;
	while(1){
		current=current+1;
		if(current==stop+1) break;
		area1.insert(current);
	}
	current-=1;
	while(1){
		current=(current+1)%13;
		if(current==start+1) break;
		area2.insert(current);
	}
	set<int>& smallerArea = area1.size()<area2.size()?area1:area2;
	set<int>& biggerArea = area1.size()<area2.size()?area2:area1;
	for(auto &i:smallerArea){
//		cout<<i<<"-";
	}
//	cout<<endl;
	if(smallerArea.find(b1) != smallerArea.end() || smallerArea.find(b2) != smallerArea.end()){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}

int main(){
	int cases;
	cin>>cases;
	while(cases--){
		solve();
		cout<<endl;
	}

}
