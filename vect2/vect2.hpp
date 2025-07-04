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
		vect2 operator-();		//you need this to do the -vec expression

		int operator[](size_t) const;
		int& operator[](size_t); //you need this to do the vec[0] = 12 expression

		vect2 operator++(int);
		vect2& operator++(void);
		
		vect2 operator--(int);
		vect2& operator--(void);

		bool	operator==(vect2 const &);
		bool	operator!=(vect2 const &);

		vect2	operator+=(vect2 const &);
		vect2	operator-=(vect2 const &);

	private:
		int	_first;
		int	_second;
};

std::ostream &operator<<(std::ostream &os, vect2 const &);

vect2 operator*(int, const vect2&); // you need this to do the 6 * vec expression. (outside of the class is important)
