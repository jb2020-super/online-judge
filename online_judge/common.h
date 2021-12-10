#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

class ProblemBase
{
public:
	virtual void GetInput() = 0;
	virtual void RunAlgorithm() = 0;
	void Init() {
		scanf("%d", &T);
	}
	void Loop() {
		for (int i = 0; i < T; ++i) {
			GetInput();
			RunAlgorithm();
		}
	}
private:
	int T{ 0 };
};

class ProblemBase2
{
public:
	virtual int GetInput() = 0;
	virtual void RunAlgorithm() = 0;
	
	void Loop() {
		while (GetInput() != EOF){
			RunAlgorithm();
		}
	}
private:
};