#include <stdlib.h>
#include <stdio.h>

#include "student.h"

Student * newStudent(StudentDescriptor descriptor, Payload payload) {
	Student *student = (Student*) malloc(sizeof(Student));

	student->descriptor = descriptor;
	student->payload = payload;

	return student;
}

void printStudent(Student *student) {
	printf("\n");
	printDescriptor(student->descriptor);
	printf("Payload: %d\n", student->payload.data);
}
