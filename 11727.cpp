#include <stdio.h>

int d[1001];

int	main(void)
{
	int n;

	scanf("%d", &n);
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2] * 2) % 10007;
	printf("%d", d[n]);
	return (0);
}
