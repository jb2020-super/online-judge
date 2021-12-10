#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

class ProblemBase2
{
public:
	virtual int GetInput() = 0;
	virtual void RunAlgorithm() = 0;

	void Loop() {
		while (GetInput() != EOF) {
			RunAlgorithm();
		}
	}
private:
};
struct Plane {
	int w;
	int h;
};

bool ComparePlane(const Plane& a, const Plane& b)
{
	if (a.w == b.w) {
		return a.h < b.h;
	}
	return a.w < b.w;
}

class Box : public ProblemBase2
{
public:

	virtual int GetInput() override
	{
		int ret = 0;
		int w, h;
		for (int i = 0; i < N; ++i) {
			ret = scanf("%d%d", &w, &h);
			// make _w always smaller than _h
			if (w > h) {
				_plane[i].w = h;
				_plane[i].h = w;
			}
			else
			{
				_plane[i].w = w;
				_plane[i].h = h;
			}
		}
		return ret;
	}
	// a <= b <= c
	// a b
	// a b
	// a c
	// a c
	// b c
	// b c
	virtual void RunAlgorithm() override
	{
		std::sort(_plane, _plane + N, ComparePlane);
		bool possible = true;
		for (int i = 0; i < N; i += 2) {
			if (_plane[i].w != _plane[i + 1].w ||
				_plane[i].h != _plane[i + 1].h) {
				possible = false;
				break;
			}
		}

		if (possible) {
			if (_plane[0].w != _plane[2].w ||
				_plane[2].h != _plane[4].h ||
				_plane[0].h != _plane[4].w) {
				possible = false;
			}
		}
		if (possible) {
			printf("POSSIBLE\n");
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
private:
	const static int N = 6;
	Plane _plane[N];
};

int main()
{
	Box bx;
	bx.Loop();
	return 0;
}
/*
2 2
2 2
2 3
2 3
3 3
3 3
*/