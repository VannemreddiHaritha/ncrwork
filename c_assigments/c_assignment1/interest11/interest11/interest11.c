#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double SI, annualCI,semianualCI,quaterCI,monthCI,weekCI,dailyCI,A1,A2,A3,A4,A5,A6;
	int p, t, r;
	scanf_s("%d%d%d", &p, &t, &r);
	SI = p * t*r / 100;
	
	A1 = pow(p*(1 + r / 1), 1*t);
	A2 = pow(p*(1 + r / 2), 2 * t);
	A3 = pow(p*(1 + r / 4), 4 * t);
	A4 = pow(p*(1 + r / 12), 12 * t);
	A5 = pow(p*(1 + r / 52), 52 * t);
	A6 = pow(p*(1 + r / 365),365 * t);
	annualCI = A1 - p;
	semianualCI = A2- p;
	quaterCI = A3 - p;
	monthCI = A4 - p;
	weekCI = A5 - p;
	dailyCI = A6 - p;

	printf("SI=%lfannaul=%lfsemiannual=%lfquater=%lfmonthly=%lfweek=%lfdaily=%lf", SI, annualCI, semianualCI, quaterCI, monthCI, weekCI, dailyCI);
	
	getch();
	return 0;
}
