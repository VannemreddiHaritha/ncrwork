#include<stdio.h>
int invertponwards(int, int, int);
int main()
{
	int X, P, N, RESULT;
	printf("enter xnumber,ending position,starting position n value");
	scanf_s("%d %d %d", &X, &P, &N);
	printf("Coverted binary value of %d is\t", X);
	RESULT = invertponwards(X, P, N);
	getch();
	return 0;
}

int invertponwards(int X, int P, int N)
{
	int I, Y, LIMIT, LEN, BIN[15];
	LEN = 0;
	while (X > 0)
	{
		BIN[LEN] = X % 2;
		X = X / 2;
		LEN++;
	};

	for (I = LEN - 1; I > -1; I--)
	{
		printf("%d ", BIN[I]);
	}
	printf("\n");
	LIMIT = P + N;
	if (LIMIT < LEN)
	{
		for (I = P + N - 1;I > P - 1; I--)
		{
			if (BIN[I] == 0)
				BIN[I] = 1;
			else
				BIN[I] = 0;
		}
	}
	else
	{
		printf("YOU HAVE ENTERED LARGE VALUE FOR P AND N");
	}

	printf("Inverted integer in binary form is \t");
	for (I = LEN - 1; I > -1; I--)
	{
		printf("%d ", BIN[I]);
	}

}