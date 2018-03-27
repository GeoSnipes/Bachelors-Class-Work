#include<iostream>
#include"Triangle.h"
#include"GeometricObject.h"
#include"DerivedCircle.h"
using namespace std;

void main(){
	Triangle tri(1.0,1.5,1.0);
	tri.setColor("yellow");
	tri.setFilled(true);
	cout << "Triangle" << endl <<
		" color: " << tri.getColor() <<endl<<
		" filled: " << (tri.isFilled() ? "true" : "false") <<endl<<
		" area: "<<tri.getArea()<<endl<<
		" perimeter: "<<tri.getPerimeter()<<endl;
}