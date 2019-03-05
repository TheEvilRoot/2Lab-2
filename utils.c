#include <stdlib.h>

#include "utils.h"

int len(char *str) {
	
	int l = 0;

	for (; str[l] != '\0'; ++l);

	return l;

}
