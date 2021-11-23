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

class DigitCounting : public ProblemBase
{
public:
	virtual void GetInput() override {
		scanf("%d", &n);
	}
	virtual void RunAlgorithm() override {
		memset(digit_count, 0, sizeof(digit_count));
		for (int i = 1; i <= n; ++i) {
			CountDigits(i);
		}
		Print();
	}
	void CountDigits(int num) {
		while (num > 0) {
			digit_count[num % 10]++;
			num /= 10;
		}
	}
	void Print() {
		printf("%d", digit_count[0]);
		for (int i = 1; i < 10; ++i) {
			printf(" %d", digit_count[i]);
		}
		printf("\n");
	}
private:
	int n{ 0 };
	int digit_count[10]{};
};

int main()
{
	DigitCounting dc;
	dc.Init();
	dc.Loop();
	return 0;
}