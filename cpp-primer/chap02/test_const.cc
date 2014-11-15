#include <iostream>
main()
{
	double dval = 3.14;
	const int &ri = dval;
	std::cout << ri << " " << dval << std::endl;
}
