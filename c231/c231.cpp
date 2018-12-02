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
		mine.sort(cmp);         //�a�p�̷�x�Ѥp��j�A�A�̷�y�Ѥp��j
		while (mine.size() > 0) {
			qu.push_back(mine.front());  //�qmine���X���qu�Aqu��ܥثe�i�H���z���a�p
			mine.pop_front();   //mine�R�������X���qu���a�p�A�קK���ƭp��
			while (qu.size() > 0) {    //�i�H�s��������a�p���qu
				tmp = qu.front();   //���X�qqu���X�Ĥ@�ө��tmp
				qu.pop_front();    //qu�R���Ĥ@�Ӥ���
				for (list<Node>::iterator it = mine.begin(); it != mine.end();) {  //�j�餤�R��it++�A�Ѳ�43�P45��B�z
					if (((*it).x - tmp.x) > 2) break;   //�]��mine�̷�x�Ѥp��j�ƧǡAx�y�Юt�W�L2�N���_�j��
					if (rel(tmp, *it)) {  //�P�_tmp�P*it�O�_�O�s��a�p
						qu.push_back(*it);   //�Y�O�s��a�p�[�Jqu
						it = mine.erase(it);   //�qmine�R��it�A�|�۰ʦ^�ǧR���������U�@�Ӥ�����}��it�A�ҥH����it++
					}
					else {
						it++;     //��U�@��
					}
				}
			}
			count++;
		}
		printf("%d\n", count);
	}
}
