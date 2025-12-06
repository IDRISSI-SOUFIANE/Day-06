#include <iostream>
#include "../ex00/ScalarConverter.hpp"

int	main()
{
	// ---------- TEST: --------------
	/*
		float num = '+';

		std::cout << "num: " << num << std::endl;
	*/


	/* ---------- TEST: --------------
		double value = std::numeric_limits<float>::quiet_NaN();

		std::cout << "value: " << value  << "\n";

		if (value == value)
			std::cout << "YES: EQUAL\n";
		else
			std::cout << "NO: NOT EQUAL\n";
	*/

	/* ---------- TEST: --------------
	//	double	8	none	1.7E +/- 308 (fifteen digits)
		double valueInt = std::numeric_limits<int>::max();
		double valueDouble = std::numeric_limits<double>::max();
		float	valueFloat = 2147483648;

		std::cout << valueFloat << "\n";
		
		std::cout << "valueInt: " << valueInt << std::endl;
		std::cout << "valueDouble: " << valueDouble << std::endl;
	*/

	/*---------- TEST: --------------
		if ("042" == "42")
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;

		std::cout << 0042 << "\n";
	*/

	// std::string s = "42.2f";

	// std::cout << "lenght s: " << s.length() << "\n";
	// std::string t = s.substr(0, s.length() - 1);

	// std::cout << "t: " << t << "\n";




	/*---------- TEST: --------------*/
	// std::string str = "+hello";

	// str = str.substr(2);

	// std::cout << str << "\n";

	/*---------- TEST: --------------*/
	// float f = std::numeric_limits<float>::infinity();

	// std::cout << f << "\n";


	// float ff = static_cast<float>('+');

	// std::cout << "ff: " << ff << "\n";


	// char c = static_cast<char>(65.7);

	// std::cout << c << "\n";


	/*---------- TEST: --------------*/
	// double v = 65.7;
	// char c = v;

	// std::cout << c << "\n";
	
	/*---------- TEST: --------------*/
	// int x = 10;
	// int y = 20;
	// double result = x / y;
	// std::cout << result <<  "\n";

	/*---------- TEST: --------------*/
	// double y = 65.7;
	// char c = y; 

	// std::cout << "c: " << c <<"\n";

	/*---------- TEST: --------------*/
	double big = 2147483650.0; // bigger than int max
	int x = static_cast<int>(big);

	std::cout << "x: " << x << "\n";


}
