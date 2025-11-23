#include<iostream>

using namespace std;


struct Point
{
	long long x;
	long long y;
};


long long CCW(Point& A, Point& B, Point& C)
{
	long long S = (A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x);

	if (S > 0)
	{
		return  1;

	}
	else
	{
		return -1;
	}
}


int main()
{
	Point p1, p2, p3, p4;

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;
	cin >> p4.x >> p4.y;

	long long abc = CCW(p1, p2, p3);
	long long abd = CCW(p1, p2, p4);
	long long cda = CCW(p3, p4, p1);
	long long cdb = CCW(p3, p4, p2);


	if (abc * abd < 0 && cda * cdb < 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}




	return 0;

}