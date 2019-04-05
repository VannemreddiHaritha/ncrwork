#include<iostream>
namespace add_sub
{
	class c_add_sub
	{
		double sum ;
		double difference;
	public:
		double add(int num1, int num2)
		{
			double result=0;
			result = num1 + num2;
			return result;
		}
		double sub(int num1, int num2)
		{
			double result = 0;
			result = num1 - num2;
			return result;

		}

	};
}
