#include <stdio.h>
#include <errno.h>
#include <string.h>

extern void my_perror(const char *str)
{
	if(str == NULL)
		printf("%s",sterror(errno));
	else
		printf("%s : %s",str,strerror(errno));
}
