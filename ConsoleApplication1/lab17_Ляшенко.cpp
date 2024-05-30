#include <iostream>
#include <string.h>
using namespace std;
#include "windows.h"

class vector {
public:
	int coordinate_x, coordinate_y, coordinate_z;
	vector(int cx, int cy, int cz)
	{
		coordinate_x = cx;
		coordinate_y = cy;
		coordinate_z = cz;
	}
	int get_x()
	{
		return coordinate_x;
	}
	int get_y()
	{
		return coordinate_y;
	}
	int get_z()
	{
		return coordinate_z;
	}
	void show_vector()
	{
		cout << "x = " << coordinate_x << endl << "y = " << coordinate_y << endl << "z = " << coordinate_z << endl;
	}
};

class vector_derived : public vector {
public:
	vector_derived(int coordinate_x,int coordinate_y,int coordinate_z):vector(coordinate_x, coordinate_y, coordinate_z)
	{}
	int scalar_product(int x1, int y1, int z1, int x2, int y2, int z2)
	{
		return x1 * x2 + y1 * y2 + z1 * z2;
	}
	int cos(int x1, int y1, int z1, int x2, int y2, int z2)
	{
		return scalar_product(x1, y1, z1, x2, y2, z2) / ((sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2))) * sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2)));
	}
	int length()
	{
		return sqrt(pow(coordinate_x, 2) + pow(coordinate_y, 2) + pow(coordinate_z, 2));
	}
};


int main()
{
	vector_derived v1(1, 2, 3);
	cout << "Coordinates of vector 1:" << endl;
	v1.show_vector();
	cout << endl;

	vector_derived v2(2, 4, 6);
	cout << "Coordinates of vector 2:" << endl;
	v2.show_vector();
	cout << endl;

	cout << "The scalar product of two vektors: " << v1.scalar_product(v1.get_x(), v1.get_y(), v1.get_z(), v2.get_x(), v2.get_y(), v2.get_z()) << endl;
	cout << "The cosine of angel between vectors: " << v1.cos(v1.get_x(), v1.get_y(), v1.get_z(), v2.get_x(), v2.get_y(), v2.get_z()) << endl;
	cout << "The length of first vector:" << v1.length() << endl;
}