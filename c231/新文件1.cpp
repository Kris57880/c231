//231 
#include<iostream>
#include<utility>
#include<List>
 
#include<algorithm>
using namespace std;
int cmp(pair<int,int>&a,pair<int,int>&b){
	if(a.first==b.first)	return a.second>b.second;
	else	return a.first>b.first;
}

int main()
{
	int a,b,c;
	while(scanf("%d,%d,%d",&a,&b,&c)!=EOF){
		list< pair<int,int> > Bomb_Address;
		int x,y;
		for(int i=0;i!=c;i++){
			scanf("%d,%d",&x,&y);
			Bomb_Address.push_front(make_pair(x,y));
		}
		Bomb_Address.sort(cmp);
	}
	

  return 0;
}

