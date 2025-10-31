#include <iostream>

class love
{
	public:
		love()
		{
			std::cout << "Hello class\n";
		};
		static int x;
		~love()
		{
			std::cout << "Bye class LOVE\n";
		};
};

class hate
{
	public:
		int y;
		~hate()
		{
			std::cout << "Bye class Hate\n";
		};
};

int	love::x = 0;

int	main()
{
	{
		love obj;
		love obj2;
		love obj3;
		hate obj4;

		obj.x++;
		std::cout << obj.x << '\n';
		std::cout << obj2.x << '\n';
		obj2.x++;
		std::cout << obj3.x << '\n';
	}
}
