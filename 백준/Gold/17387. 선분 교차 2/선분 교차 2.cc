#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

struct Point
{
	long x;
	long y;

};



Point MakeVector(Point& A, Point& B)
{
	return { B.x - A.x , B.y - A.y };
}

long long ccw(Point& A, Point& B, Point& C)
{
	long long S = (A.x * B.y + B.x * C.y + C.x * A.y) - (B.x * A.y + C.x * B.y + A.x * C.y);

	if (S > 0)
	{
		return 1;
	}
	else if (S < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
	
}

bool cmpPoint(Point& A, Point& B)
{
	if (A.x != B.x)
	{
		return A.x < B.x;
	}
	return A.y < B.y;
}

int main()
{

	Point A;
	Point B;
	Point C;
	Point D;

	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

	long long abc = ccw(A, B, C);
	long long abd = ccw(A, B, D);
	long long cda = ccw(C, D, A);
	long long cdb = ccw(C, D, B);

	long long ab = abc * abd; //음수면 교차 양수면 둘다 왼쪽이거나 오른쪽에 위치 , 0일때는 일직선상에 위치할수있음 
	long long cd = cda * cdb;

	if (ab == 0  && cd ==0)
	{
		//일직선상에서는 각 좌표 위치가 중요하다. 
		if (cmpPoint(B, A))
		{
			swap(A, B);
		}
		if (cmpPoint(D, C))
		{
			swap(C, D);
		}

		bool overlap = !(cmpPoint(B, C) || cmpPoint(D, A));

		cout << (overlap ? 1:0);

	}
	else if (ab <= 0 && cd <= 0)
	{
		cout << 1; //교차한다.
	}
	else
	{
		cout << 0;
	}






}

