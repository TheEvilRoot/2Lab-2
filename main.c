#include <stdlib.h>
#include <stdio.h>

#include "student_descriptor.h"
#include "input.h"
#include "student.h"

int main() {

	Student *student = enterStudent("New student\n");

	printStudent(student);

	while (getchar() != '#');

	return 0;
}
