//231 
#include<iostream>
#include<utility>
#include<List>
#include<deque> 
#include<algorithm>
using namespace std;
int cmp(pair<int,int>&a,pair<int,int>&b){
	if(a.first==b.first)	return a.second>b.second;
	else	return a.first>b.first;
}
 int main()
{
	list< pair<int,int> > Bomb_Address;
	int a,b,c;
	while(scanf("%d,%d,%d",&a,&b,&c)!=EOF){
		int x,y;
		for(int i=0;i!=c;i++){
			scanf("%d,%d",&x,&y);
			Bomb_Address.push_front(make_pair(x,y));
		}
	
	}
	Bomb_Address.sort(cmp);
	while(Bomb_Address.size() >0){
		int used=0;
		deque<pair<int,int> >BombChain;
		BombChain.push_front(Bomb_Address.pop_front() );
		while(BombChain.size()>0){
			pair<int,int>tmp=BombChain.pop_front();
			for	(deque<pair<int,int> >::iterator it=Bomb_Address.begin();it!=Bomb_Address.end();){
				
				
			}	
		}
		used++
	}
	
   return 0;
}
