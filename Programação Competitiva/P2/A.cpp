#include <algorithm>
#include <cstdio>
#include <functional>
#include <stdio.h>
#include <bits/stdc++.h>
//#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void print_num(vector<char> num) {
	bool is_firt = true;
	for (int i = 0; i < (int)num.size(); i++) {
		if(is_firt && num[i] == '0') continue;
		printf("%c", num[i]);
		is_firt = false;
	}
}

bool is_num(char c) {
	return c >= '0' && c <= '9';
}

int main() {
	//priority_queue<char, vector<char>, greater<char>> s;
	priority_queue<char> s;
	vector<char> a;
	int tam = 0;
	char aux;
	while (scanf("%c", &aux)) {
		if(!is_num(aux)) break;
		a.push_back(aux);
	}
	while (scanf("%c", &aux) == 1) {
		if(!is_num(aux)) break;
		s.push(aux);
		tam++;
	}
	for(int i = 0; i < (int)a.size(); i++) {
		if(s.empty()) break;
		int top = s.top();
		if(a[i] < top) {
			a[i] = top;
			s.pop();
			tam--;
		} else if(a[i] == top) continue;
		else break;
	}
	print_num(a);
	printf("\n");
	
	return 0;
}