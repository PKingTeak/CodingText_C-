#include<iostream>
#include<math.h>

using namespace std;

struct  Point
{
	int x;
	int y;
};

Point MakeVector(Point& from, Point& to)
{
	return { to.x - from.x , to.y - from.y };
}

int Cross(Point& v1, Point& v2)
{
	return { v1.x * v2.y - v1.y * v2.x };
}

int main()
{
	Point p1, p2, p3;

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;


	Point v1 = MakeVector(p1, p2);
	Point v2 = MakeVector(p2, p3);





	int cross = Cross(v1, v2);
	if (cross == 0)
	{
		cout << 0;
	}
	else if (cross < 0)
	{
		cout << -1;
	}
	else
	{
		cout << 1;
	}

}