#ifndef _student_descriptor_h
#define _student_descriptor_h

#include <stdlib.h>

typedef struct {

	char *firstName;
	char *lastName;
	char *middleName;

	int semester;

} StudentDescriptor;

StudentDescriptor newDescriptor(char *firstname, char *lastname, char *middlename, int semester);

void printDescriptor(StudentDescriptor d);

#endif
