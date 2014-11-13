#include <stdlib.h>
#include <stdio.h>

size_t strlength(const char *string)
{
	int length = 0;
	
	if (NULL == string)
		return 0;
	
	while (*string++ != '\0')
		length += 1;
		
	return length;
}

int main(int argc, char *argv[])
{
	char *s = NULL;
	int len;
	
	len = strlength(s);
	printf("%d\n", len);
	
	char a[] = "abcde";		// 0
	
	char *p1 = (char *) &a;
	char *p2 = (char *) (&a+1);
	
	printf("%d - %ld\n", strlength(a), sizeof(a));		// 5 - 6
	printf("%p - %p\n", p1, p2);		// 0x7fffff79fda0 - 0x7fffff79fda6
	printf("%s - %s\n", p1, (p2-6));	// abcde - abcde
	
	char *q1, *q2;
	q1 = a;
	q2 = a + 1;
	
	printf("%s - %s\n", q1, q2);		// abcde - bcde
	
	return 0;
}
