#pragma once
#include<vector>
#include<string>
#include <random>
#include <chrono>
#include<algorithm>
#include<iostream>


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

auto genNull(int minG = 0, int maxG = 1e9, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genCompl(int minG = 0, int maxG = 1e9, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 1));
	for (int i = 0; i < v; i++)ans[i][i] = 0;
	Graph Ans;
	Ans.seed = seed;
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

auto genPseudo(int minG = 0, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	if (v != 1)
		for (int i = 0; i < d; i++) {
			int q = a() % v, w = a() % v;
			ans[q][w] = ans[w][q] = ans[w][q] + 1;
			Ans.edges.emplace_back(q, w);
		}
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

//RegularGraph - Граф с одинаковыми степенями вершин
//		Ген: Рандомное число до количества вершин
//CyclicGraph - граф-цикл
//		Ген: Случайное дерево с дополнительным ребром

/*
	for (int i = 0; i < v; i++) {
			int z;
			int r = a() % v;
			z = g[i];
			g[i] = g[r];
			g[r] = z;
		}
*/
//long long v = a() % (maxG - minG + 1) + minG;
//от minG до maxG


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
