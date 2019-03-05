#include <stdlib.h>
#include <stdio.h>

#include "student_descriptor.h"
#include "input.h"

int main() {

	StudentDescriptor d = enterDescriptor("New student: \n");
	
	printDescriptor(d);

	while (getchar() != '#');

	return 0;
}
