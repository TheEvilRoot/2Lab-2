#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "student_descriptor.h"

StudentDescriptor newDescriptor(char *firstName, char *lastName, char *middleName, int semester) {
	
	StudentDescriptor d;

	int length = len(firstName);

	d.firstName = (char*) malloc(sizeof(char) * length);

	for (int i = 0; i < length; i++) {
		d.firstName[i] = firstName[i];
	}

	length = len(lastName);

	d.lastName = (char*) malloc(sizeof(char) * length);

	for (int i = 0;i < length; i++) {
		d.lastName[i] = lastName[i];
	}

	length = len(middleName);

	d.middleName = (char*) malloc(sizeof(char) * length);

	for (int i = 0; i < length; i++) {
		d.middleName[i] = middleName[i];
	}

	d.semester = semester;

	return d;
}

void printDescriptor(StudentDescriptor d) {
	printf("First name:\t'%s'\n", d.firstName);
	printf("Middle name:\t'%s'\n", d.middleName);
	printf("Last name:\t'%s'\n", d.lastName);
	printf("Semester:\t%d\n", d.semester); 
}
