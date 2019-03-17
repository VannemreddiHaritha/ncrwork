#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double power(double a, double b)
{
	double result=1;
	for (int i = 0;i < b;i++)
		result = result * a;
	return result;

}
int main()
{
	
	double SI, annualCI, semianualCI, quaterCI, monthCI, weekCI, dailyCI, A1, A2, A3, A4, A5, A6;
	double p, t, r;
	printf("enter p,t,r values\n");

	scanf_s("%lf%lf%lf", &p, &t, &r);
	
	SI = p * t*r / 100;
	
	A1 = p * (pow((1 + (r / 100)), (1 * t)));
	
	A2 = p *( pow((1 + (r / 200)), (2 * t)));
	A3 = p * (pow((1 + (r / 400)), (4 * t)));
	
	A4 = p * (pow((1 + (r / 1200)), (12 * t)));
	A5 = p * (pow((1 + (r / 5200)), (52 * t)));
	A6 = p * (pow((1 + (r / 36500)), (365 * t)));
	
	annualCI = A1 - p;
	
	semianualCI = A2 - p;
	
	quaterCI = A3 - p;
	
	monthCI = A4 - p;
	
	weekCI = A5 - p;
	dailyCI = A6 - p;

	printf("SI=%lf\nannaul=%lf\nsemiannual=%lf\nquater=%lf\nmonthly=%lf\nweek=%lf\ndaily=%lf\n", SI, A1, semianualCI, quaterCI, monthCI, weekCI, dailyCI);

	getch();
	return 0;
}
