#include <iostream>

using namespace std;

class Point {
public:
	Point(int xval): _x(xval) {};
	virtual ~Point() {};

	float x() const { return _x; }
	static int PointCount() { return _point_count };


protected:
	virtual ostream& print(ostream &os) const {
		os << "(" << _x << ")";
		return os;
	};

	float _x;
	static int _point_count;
};

int Point::_point_count = 10;

int main(int argc, char const *argv[])
{
	
	Point pt(10);

	pt.print(std::cout) << std::endl;

	std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
	std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
	std::cout << "sizeof(int *) = " << sizeof(int *) << std::endl;

	std::cout << "size = " << sizeof(pt) << std::endl; // 字节对齐 8 + 4  = 12, 对齐 + 4 = 16

	std::cout << "&pt = " << &pt << std::endl;

	std::cout << "&(pt._x) = " << &pt._x << std::endl;

	std::cout << "&(Point::_point_count) = " << &Point::_point_count << std::endl;

	return 0;
}