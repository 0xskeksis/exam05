#include "vect2.hpp"

int main(){
	vect2		v1;
	vect2		v2(1, 2);
	const vect2	v3(v2);
	vect2		v4 = v2;
 
	std::cout << "v2(1,2) + v2(1,2) = " << v2 + v2 << std::endl;
	std::cout << "v2(1,2) - v2(1,2) = " << v2 - v2 << std::endl;

	v2 = v2 * 6;
	std::cout << "v2(1,2) * 6 = " << v2 << std::endl;
	v2 = 6 * v2;
	std::cout << "6 * v2(6,12) = " << v2 << std::endl;

	std::cout << "v2[0] = " << v2[0] << std::endl;
	std::cout << "v2[1] = " << v2[1] << std::endl;

	v2[0] = 12;
	std::cout << "After v2[0] = 12:\n";
	std::cout << "v2[0] = " << v2[0] << std::endl;

	std::cout << "-v2 = " << -v2 << std::endl;

	std::cout << "++v2 = "<< ++v2 << "v2++ = " << v2++ << std::endl;
	std::cout << "--v2 = "<< --v2 << "v2-- = " << v2-- << std::endl;

	std::cout << "v2 += v2 = " << (v2 += v2) << std::endl;
}
