// c231.cpp : Defines the entry point for the console application.
//https://zerojudge.tw/ShowProblem?problemid=c231

#include "stdafx.h"
#pragma warning (default:4996)

#include<cstdio>
#include<algorithm>
#include<deque>
#include<list>
#include<vector>
using namespace std;
struct _node {
	int x;
	int y;
} typedef Node;
bool cmp(Node& a, Node& b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
bool rel(Node a, Node b) {
	if (((a.x - b.x) > -3) && ((a.x - b.x) < 3) && ((a.y - b.y) > -3) && ((a.y - b.y) < 3)) return true;
	else return false;
}

list<Node> mine;
deque<Node> qu;
int main() {
	int r, c, num, count, now, next;
	Node tmp;
	while (scanf("%d", &r) != EOF) {
		scanf("%d %d", &c, &num);
		count = 0;
		for (int i = 0; i<num; i++) {
			scanf("%d %d", &(tmp.x), &(tmp.y));
			mine.push_back(tmp);
		}
		mine.sort(cmp);         //地雷依照x由小到大，再依照y由小到大
		while (mine.size() > 0) {
			qu.push_back(mine.front());  //從mine取出放到qu，qu表示目前可以引爆的地雷
			mine.pop_front();   //mine刪除剛剛取出放到qu的地雷，避免重複計算
			while (qu.size() > 0) {    //可以連鎖反應的地雷放到qu
				tmp = qu.front();   //取出從qu取出第一個放到tmp
				qu.pop_front();    //qu刪除第一個元素
				for (list<Node>::iterator it = mine.begin(); it != mine.end();) {  //迴圈中刪除it++，由第43與45行處理
					if (((*it).x - tmp.x) > 2) break;   //因為mine依照x由小到大排序，x座標差超過2就中斷迴圈
					if (rel(tmp, *it)) {  //判斷tmp與*it是否是連鎖地雷
						qu.push_back(*it);   //若是連鎖地雷加入qu
						it = mine.erase(it);   //從mine刪除it，會自動回傳刪除元素的下一個元素位址到it，所以不用it++
					}
					else {
						it++;     //找下一個
					}
				}
			}
			count++;
		}
		printf("%d\n", count);
	}
}
