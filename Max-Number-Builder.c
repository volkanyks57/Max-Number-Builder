#include <stdio.h>
#include <stdlib.h>
char *getMaxNumber(char *, int);

int main(void)
{
	char *n = (char *)malloc(50 * sizeof(char));
	int r;
	printf("enter a number: ");
	scanf("%s", n);
	printf("how many digits you want to remove: ");
	scanf("%d", &r);
	printf("maximum number after removing %d digits is %s\n", r, getMaxNumber(n, r));
	return 0;
}


char *getMaxNumber(char *n, int r)
{
	// your code here
    int k = strlen(n);
    int size = k - r;
    char *stack = (char *)malloc((k + 1) * sizeof(char));
    int m = 0;
    for (int i = 0; i < k; i++)
    {
        while (m > 0 && stack[m - 1] < n[i] && r > 0)
        {
            m--;
            r--;
        }
        stack[m++] = n[i];
    }
    while (m > 0 && r > 0)
    {
        m--;
        r--;
    }
    char *result = (char *)malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++)
    {
        result[i] = stack[i];
    }
    result[size] = '\0';

    free(stack);

    return result;
}
