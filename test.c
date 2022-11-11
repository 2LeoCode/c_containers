#include "error/error.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	err_catch((err) ({
		puts(err);
		exit(1);
	}));
	printf("Hello, World!\n");
	err_throw("An error occured");
	return 0;
}
