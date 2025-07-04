#include "vect2.hpp"

vect2::vect2(){ _first = 0; _second = 0;}

vect2::vect2(int first, int second){ _first = first; _second = second;}

vect2::~vect2(){}

vect2::vect2(const vect2 &ref){
	_first = ref._first;
	_second = ref._second;
}
int	vect2::getFirst() const{return (_first);}
int	vect2::getSecond() const{return (_second);}



vect2& vect2::operator=(const vect2 &ref){
	_first = ref._first;
	_second = ref._second;
	return (*this);
}

vect2	vect2::operator+(vect2 const &ref){
	return (vect2(_first + ref._first, _second + ref._second));
}

vect2	vect2::operator+(int add){
	return (vect2(_first + add, _second + add));
}

vect2	vect2::operator-(vect2 const &ref){
	return (vect2(_first - ref._first, _second - ref._second));
}

vect2	vect2::operator-(int add){
	return (vect2(_first - add, _second - add));
}

vect2	vect2::operator-(){
	return (vect2(-_first, -_second));
}


vect2	vect2::operator*(vect2 const &ref) const{
	return (vect2(_first * ref.getFirst(), _second * ref.getSecond()));
}

vect2	vect2::operator*(int add) const{
	return (vect2(_first * add, _second * add));
}

int vect2::operator[](size_t index) const{
	if (index == 0) return _first;
	return (_second);
}

int& vect2::operator[](size_t index){
	if (index == 0) return _first;
	return (_second);
}


vect2 vect2::operator++(int){
	vect2 copy(*this);
	++_first;
	++_second;
	return copy;
};

vect2& vect2::operator++(void){
	++_first;
	++_second;
	return *this;
}

vect2 vect2::operator--(int){
	vect2 copy(*this);
	_first--;
	_second--;
	return copy;
};

vect2& vect2::operator--(void){
	_first--;
	_second--;
	return *this;
}

bool vect2::operator==(vect2 const &ref){
	return (_first == ref._first && _second == ref._second);
}

bool vect2::operator!=(vect2 const &ref){
	return !(_first == ref._first && _second == ref._second);
}

vect2	vect2::operator+=(vect2 const & ref){
	return (*this + ref);
}

vect2	vect2::operator-=(vect2 const & ref){
	return (*this + ref);
}

std::ostream& operator<<(std::ostream &os, vect2 const &ref){
	os << "{" << ref.getFirst() << ", " << ref.getSecond() << "}" << std::endl;
	return (os);
}

vect2 operator*(int scalar, const vect2& vec){
	return vect2(vec.getFirst() *scalar, vec.getSecond() * scalar);
}
