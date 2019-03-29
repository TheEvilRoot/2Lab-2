#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student_descriptor.h"
#include "input.h"
#include "student.h"

int main(const int argc, const char *argv[]) {

	Student **students = (Student**) malloc(sizeof(Student*));
	int length = 0;

	do {
		students[length] = entrerStudent("Enter new student");
		
		if (students[length] == NULL) {
			printf("Error: unable to allocate memory for new student. Sorry for inconveniences.");
			break;
		}

		length++;

		students = (Student**) realloc(students, sizeof(Student*) * (length + 1));

		if (students == NULL) {
			printf("Error: unable to proceed student inserting. Program will stop.");
			return 0;
		}
		
		char confirm = enterChar("Do you want to add another student?\n[y] - Yes\n[n] - No");

		if (confirm != 'y') {
			break;
		}
	} while(1);

	while (getchar() != '#');

	return 0;
}
