#include <iostream>
using namespace std;
#define HEIGHT 5
#define WIDTH 3

#define XHEIGHT 1
#define XWIDTH 1

#define YHEIGHT 2
#define YWIDTH 2

//Assumptions. 
// width=height on windows (screen is parallelogram)
//complexity 0(n) 
//proof to follow soon
void solve(){
	int x,y,min_screen,extra_screen,remainder_x_blocks,x_screens,screens;
	cin>>x;
	cin>>y;
	min_screen = (int)(y/2);			//at least those screens due to big blocks
	extra_screen = ((bool)(y%2));		//in case we have leftover big block
	remainder_x_blocks = x - (min_screen*7 + extra_screen*11); //remainders in case we have leftover blocks of size 1x1
	//minimum screens for big blocks + maybe extra screen for leftover big block + nessesary screens to accomodate leftover full 1x1 screens + leftover 1x1
	if(remainder_x_blocks>0) x_screens = ((int)(remainder_x_blocks/15)) + ((bool)((remainder_x_blocks%15)?1:0));
	else x_screens=0;
	screens = min_screen + extra_screen + x_screens; 
	cout<<screens<<endl;
}


int main(){
	int n;
	cin >>n;
	while(n--) solve();
	
}