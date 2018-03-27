#include"GeometricObject.h"
GeometricObject::GeometricObject(){
	_color = "white";
	_filled = false;
}
GeometricObject::GeometricObject(const string &color, bool filled){
	_color = color;
	_filled = filled;
}
string GeometricObject::getColor() const{
	return _color;
}
void GeometricObject::setColor(const string &color){
	_color = color;
}
bool GeometricObject::isFilled() const{
	return _filled;
}
void GeometricObject::setFilled(bool filled){
	_filled = filled;
}
string GeometricObject::toString() const{
	return "GeometricObject";
}
