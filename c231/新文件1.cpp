#include<iostream>
#include<cstdio>
#include<utility>
#include<list>
#include<deque> 
#include<algorithm>
using namespace std;
int cmp(pair<int,int>&a,pair<int,int>&b){
	if(a.first==b.first)	return a.second>b.second;
	else	return a.first>b.first;
}
int rel(pair<int,int> tmp,pair<int,int> bomb){
	if(tmp.first-bomb.first<=2&&tmp.first-bomb.first>=-2){
		if(tmp.second-bomb.second<=2&&tmp.second-bomb.second>=-2)
			return true	;
	}else	return false;
}
 int main()
{
	list< pair<int,int> > Bomb_Address;
	int a,b,c;
	while(/*scanf("%d,%d,%d",&a,&b,&c)!=EOF*/cin>>a>>b>>c){
		int i,x,y;
		for(i=1;i<=c;i++){
			cin>>x>>y;
			//scanf("%d,%d",&x,&y);
			pair<int,int> tmp(x,y);
			Bomb_Address.push_back(tmp);
		}
		Bomb_Address.sort(cmp);
		/*
		for(list<pair<int,int> >::iterator it=Bomb_Address.begin();it!=Bomb_Address.end();it++)
			cout<<it->first<<it->second;
		*/
		int used=0;
		while(Bomb_Address.empty()==false){
			deque<pair<int,int> >BombChain;
			BombChain.push_front(Bomb_Address.front() );
			Bomb_Address.pop_front(); 
			while(BombChain.size()>0){
				pair<int,int>tmp=BombChain.front();
				BombChain.pop_front();
				for	(list<pair<int,int> >::iterator it=Bomb_Address.begin();it!=Bomb_Address.end();){
					if((*it).first-tmp.first>2) break;
					if(rel(tmp,*it)){
						BombChain.push_back(*it);
						it=Bomb_Address.erase(it);
					}
					else 
						it++;
				}	
			}
			used++;
		}
		//printf("%d\n",used);
		cout<<used<<"\n";
		Bomb_Address.clear();
		   }
   return 0;
}
