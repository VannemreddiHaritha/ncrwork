namespace absolute_add_sub
{
	class c_absolute_add_sub
	{
		double sum;
		double difference;
	public:
		double add(int num1, int num2)
		{
			double result = 0;
			if (num1 < 0)
				num1 = num1 * (-1);
			if (num2 < 0)
				num2 = num2 * (-1);
			result = num1 + num2;
			return result;
		}
		double sub(int num1, int num2)
		{
			double result = 0;
			if (num1 < 0)
				num1 = num1 * (-1);
			if (num2 < 0)
				num2 = num2 * (-1);
			result = num1 - num2;
			return result;

		}

	};
}
