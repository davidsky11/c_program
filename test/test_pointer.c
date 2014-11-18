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
	printf("############ strlen ############\n");
	char *s = NULL;
	int len;
	
	len = strlength(s);
	printf("%d\n", len);						// 0
	
	printf("############ pointer + 1 ############\n");
	char a[] = "abcde";							// a = 0x7fffffffdf50
	char *p1 = (char *) &a;						// p1 = 0x7fffffffdf50
	char *p2 = (char *) (&a+1);					// p2 = 0x7fffffffdf56
	
	printf("%d - %ld\n", (int) strlength(a), sizeof(a));		
												// 5 - 6
	printf("%p - %p\n", p1, p2);				// 0x7fffff79fda0 - 0x7fffff79fda6
	printf("%s - %s\n", p1, (p2-sizeof(a)));	// abcde - abcde
	
	char *st = "abcde";							// st = 0x40085c
	char *q1, *q2;
	q1 = st;									// q1 = 0x40085c
	q2 = st + 1;								// q2 = 0x40085d
	
	printf("%s - %s\n", q1, q2-1);				// abcde - bcde
	
	char *str = "abcde";						// str = 0x40085c
	char **p3 = (char **) &str;					// p3 = 0x7fffffffdef0
	char **p4 = (char **) (&str + 1);			// p4 = 0x7fffffffdef8	移动的单位是 sizeof(char **) * 1
	printf("%s - %s\n", *p3, *(p4-1));			// p4-1 的地址 = p4的地址 - sizeof(char **) * 1
	printf("%ld\n", sizeof(char **));			// sizeof(char **) = 8
	
	int *p5 = (int *) &str;						// p5 = 0x7fffffffdef0
	int *p6 = (int *) (&str+1);					// p6 = 0x7fffffffdef8
	
	printf("%s - %s\n", *p5, *(p6-sizeof(int *)/sizeof(int)));
	
	printf("############ * and ** ############\n");
	
	int *p1_ = (int *)0x7ffff5579fb1;
	int *q1_ = p1_+1;
	
	printf("%p\n", q1_);
	
	char *p2_ = (char *)0x7ffff557ffa1;		// p2_ -> 0x7ffff557ffa1
	char *q2_ = p2_+1;						// q2_ -> 0x7ffff557ffa2
	
	printf("%p\n", q2_);
	
	int a_ = 45;
	int *p3_ = &a_;							// p3_ -> &a_	/ *p3_ -> a_
	int **q3_ = &p3_;						// q3_ -> &p3_	/ *q3_ -> p3_ -> &a_
	
	printf("%d - %d\n", **q3_, *p3_);
	
	printf("###############################\n");
	
	int m[4] = {1, 2, 3, 4};
	
	int *ptr1 = (int *) (&m + 1);
	int *ptr2 = (int *) (m);
	
	
	printf("%x, %x\n", ptr1[-1], *(ptr2+1));
	
	return 0;
}
