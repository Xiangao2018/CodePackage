#include <iostream>
#include <assert.h>

using namespace std;

// typedef struct point3d
// {
// 	float x;
// 	float y;
// 	float z;
// } Point3d;


// #define X(p, xval) (p.x) = (xval);

// void Point3d_print(const Point3d& point3d)
// {
// 	std::cout << "x = " << point3d.x << ", y = " << point3d.y << ", z = " << point3d.z << std::endl;
// }

// #define Point3d_PRINT(point3d) \
// 	std::cout << "x = " << point3d.x << ", y = " << point3d.y << ", z = " << point3d.z << std::endl;


class Point3dV1
{
public:
	Point3dV1(float x = 0.0, float y = 0.0, float z = 0.0) : _x(x), _y(y), _z(z) { }

	float x() const { return _x; }
	float y() const { return _y; }
	float z() const { return _z; }

	void x(float xval) { _x = xval; }
	void y(float yval) { _y = yval; }
	void z(float zval) { _z = zval; }

private:
	float _x;
	float _y;
	float _z;
};

inline ostream&  operator << (ostream &os, const Point3dV1 &pt)
{
	os << "(" << pt.x() << ", " << pt.y() << ", " <<  pt.z() << ")";

	return os;
}


class Point 
{

public:
	Point(float x = 0.0): _x(x) {}

	float x() const { return _x; }
	void x(float xval) { _x = xval; }

private:
	float _x;

};

class Point2d : public Point
{

public:
	Point2d(float x = 0.0, float y = 0.0): Point(x), _y(y) {}

	float y() const { return _y; }
	void y(float yval) { _y = yval; }

private:
	float _y;

};

class Point3dV2 : public Point2d
{

public:
	Point3dV2(float x = 0.0, float y = 0.0, float z = 0.0): Point2d(x, y), _z(z) {}

	float z() const { return _z; }
	void z(float zval) { _z = zval; }

private:
	float _z;
};

inline ostream&  operator << (ostream &os, const Point3dV2 &pt)
{
	os << "(" << pt.x() << ", " << pt.y() << ", " <<  pt.z() << ")";

	return os;
}


template <class Type>
class Point3dV3 
{
public:
	Point3dV3(Type x = 0.0, Type y = 0.0, Type z = 0.0) : _x(x), _y(y), _z(z) { }

	Type x() const { return _x; }
	Type y() const { return _y; }
	Type z() const { return _z; }

	void x(Type xval) { _x = xval; }
	void y(Type yval) { _y = yval; }
	void z(Type zval) { _z = zval; }

private:
	Type _x;
	Type _y;
	Type _z;
};

template <class Type>
inline ostream&  operator << (ostream &os, const Point3dV3<Type> &pt)
{
	os << "(" << pt.x() << ", " << pt.y() << ", " <<  pt.z() << ")";

	return os;
}


template <class Type, int dim = 3>
class PointV2
{
public:
	PointV2();

	PointV2(Type coords[dim] ) {
		for (int i = 0; i < dim; i++) {
			_coords[i] = coords[i];
		}
	}

	Type operator[](int index) const {
		assert( index < dim && index >= 0);
		return _coords[index];
	}

private:
	Type _coords[dim];
};


template <class Type, int dim>
inline ostream& operator<< (ostream& os, const PointV2<Type, dim> &pt)
{
	os << "(";
	for(int i = 0; i < dim-1; i++) {
		os << pt[i] << ", ";
	}

	os << pt[dim -1];
	os << ")";

	return os;
}

int main(int argc, char const *argv[])
{

	// Point3d pd;
	// pd.x = 10;
	// pd.y = 20;
	// pd.z = 30;

	// X(pd, 50);

	// Point3d_print(pd);

	// Point3d_PRINT(pd);


	Point3dV1 ptv1(10, 20 ,30);
	std::cout << ptv1 << ", size = " << sizeof(ptv1) << std::endl;

	Point3dV2 ptv2(100, 200 ,300);
	std::cout << ptv2 << ", size = " << sizeof(ptv2) << std::endl;

	Point3dV3<int> ptv3(1000, 2000, 3000);
	std::cout << ptv3 << ", size = " << sizeof(ptv3) << std::endl;

	int coords1[3] = {1, 2, 3};
	PointV2<int> ptv4(coords1);
	std::cout << ptv4 << ", size = " << sizeof(ptv4) << std::endl;




	return 0;
}