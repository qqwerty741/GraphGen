#pragma once
#include<vector>
//#include <chrono>
//#include<algorithm>
//#include<iostream>


struct Graph
{
	int seed, e, v;
	std::vector<std::vector<int>> mtx;
	std::vector<std::pair<int, int>> edges;
	std::vector<std::vector<int>> listsm;
};

auto genTree(int minG = 0, int maxG = 1e7, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector<int> ans;
	ans.push_back(-1);
	std::vector<std::vector<int>> ans2(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	for (unsigned long long i = 1; i < v; i++) 
		ans.push_back(a() % i);
	for (unsigned long long i = 0; i < ans.size(); i++)
		if (ans[i] != -1) {
			ans2[i][ans[i]] = ans2[ans[i]][i] = 1;
			Ans.edges.emplace_back(i, ans[i]);
		}
	Ans.mtx = ans2;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genGraph(int minG = 0, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	maxS = (maxS > (v * (v - 1)) / 2 ? (v * (v - 1)) / 2 : maxS);
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.listsm.resize(v);
	for (int i = 0; i < d; i++) {
		int q = a() % v, w = a() % v;
		if (q == w)i--;
		else if (ans[q][w] == 1)i--;
		else {
			ans[q][w] = ans[w][q] = 1;
			Ans.edges.emplace_back(q, w);
			Ans.listsm[q].push_back(w);
			Ans.listsm[w].push_back(q);
		}
	}
	Ans.seed = seed;
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genMulti(int minG = 0, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	if(v!=1)
	for (int i = 0; i < d; i++) {
		int q = a() % v, w = a() % v;
		if (q == w)i--;
		else {
			ans[q][w] = ans[w][q] = ans[w][q] + 1;
			Ans.edges.emplace_back(q, w);
		}
	}
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genDirGraph(int minG = 0, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	maxS = (maxS > (v * (v - 1)) / 2 ? (v * (v - 1)) / 2 : maxS);
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	for (int i = 0; i < d; i++) {
		int q = a() % v, w = a() % v;
		if (q == w)i--;
		else if (ans[q][w] == 1)i--;
		else {
			ans[q][w] = 1;
			Ans.edges.emplace_back(q, w);
		}
	}
	Ans.seed = seed;
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genPseudo(int minG = 0, int maxG = 1e9, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	if (v != 1)
		for (int i = 1; i < v; i++) {
			for (int j = 0; j <= i; j++) {
				ans[i][j] = ans[j][i] = a() % 2;
				Ans.edges.emplace_back(i, j);
			}
		}
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genBipart(int minG = 0, int maxG = 1e9, int seed = std::chrono::steady_clock::now().time_since_epoch().count()){
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector <std::vector <int>> g(v, std::vector <int>(v, 0));
	std::vector <int> d(v, 0);
	int e = 0; 
	int dp = 0;
	Graph Ans;
	Ans.listsm.resize(v);
	for (int i = 0; i < v; i++) {
		d[i] = a() % 2;
		dp += d[i];
	}
	for (int i = 1; i < v; i++) {
		for(int j = 0; j < i; j++){
			if(d[i] != d[j]){
				g[i][j] = a() % 2;
				g[j][i] = g[i][j];
				e += g[i][j];
				if (g[i][j] == 1) {
					Ans.listsm[i].push_back(j);
					Ans.listsm[j].push_back(i);
					Ans.edges.emplace_back(i, j);

				}
			}
		}
	}
	Ans.seed = seed;
	Ans.mtx = g;
	Ans.v = v;
	Ans.e = e;
	return Ans;
}

auto genCyclic(int minG = 0, int maxG = 1e7, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector<int> ans;
	ans.push_back(-1);
	std::vector<std::vector<int>> ans2(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	for (unsigned long long i = 1; i < v; i++)
		ans.push_back(a() % i);
	for (unsigned long long i = 0; i < ans.size(); i++)
		if (ans[i] != -1) {
			ans2[i][ans[i]] = ans2[ans[i]][i] = 1;
			Ans.edges.emplace_back(i, ans[i]);
		}
	std::vector<int> r(v, 0);
	for (int i = 0; i < v; i++)
		r[i] = i;
	for (int i = 0; i < v; i++) {
		int z;
		int zf = a() % v;
		z = r[i];
		r[i] = r[zf];
		r[zf] = z;
	}
	int fl = 0;
	for(int i = 1; i < v; i++)
		if(!ans2[r[0]][r[i]]){
			ans2[r[0]][r[i]] = ans2[r[i]][r[0]] = 1;
			fl = 1;
			break;
		}
	if (!fl)
		ans2[r[1]][r[2]] = ans2[r[2]][r[1]] = 1;
	Ans.mtx = ans2;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}
