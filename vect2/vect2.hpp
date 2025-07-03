#pragma once

#include <iostream>

class vect2{
	public:
		vect2();
		vect2(int, int);
		~vect2();
		vect2(const vect2 &);
		vect2 &operator=(const vect2 &);

		int	getFirst() const;
		int	getSecond() const;
		
		vect2 operator+(vect2 const &);
		vect2 operator+(int);

		vect2 operator*(vect2 const &) const;
		vect2 operator*(int) const;
		
		vect2 operator-(vect2 const &);
		vect2 operator-(int);
		vect2 operator-();

		int operator[](size_t) const;
		int& operator[](size_t);

		vect2 operator++(int);
		vect2& operator++(void);
		
		vect2 operator--(int);
		vect2& operator--(void);
		

	private:
		int	_first;
		int	_second;
};

std::ostream &operator<<(std::ostream &os, vect2 const &);
vect2 operator*(int, const vect2&);
