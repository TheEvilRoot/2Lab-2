#include <stdlib.h>
#include <stdio.h>

#include "input.h"

char * enterString(const char *message) {

	char *string = (char*) calloc(1,  sizeof(char));

	int i = 0;	
	char c;

	printf("%s", message);

	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
	while ((c = getchar()) != -1) {
		string[i++] = c;

		if (c == '\n') {
			string[i - 1] = '\0';
			break;
		}

		if (!(string = (char*) realloc(string, sizeof(char) * (i + 1)))) {
			string[i - 1] = '\0';
			break;
		}
	}

	return string;

}

int enterInt(const char *message) {
	int ret = 0;
	
	do {
		printf("%s", message);
		fflush(stdin);
		fseek(stdin, 0, SEEK_END);
	} while (!scanf("%d", &ret));

	return ret;
}


StudentDescriptor enterDescriptor(const char *message) {
	printf("%s", message);
	char *first = enterString("First name: ");
	char *last = enterString("Last name: ");
	char *middle = enterString("Middle name: ");
	int sem = enterInt("Semester: ");

	return  newDescriptor(first, last, middle, sem);
}

Payload enterPayload(const char *message) {
	int data = enterInt(message);
	return newPayload(data);
}

Student * enterStudent(const char *message) {
	printf("%s", message);
	
	StudentDescriptor descriptor = enterDescriptor("Enter student data: \n");
	Payload payload = enterPayload("Enter student payload: ");
	
	return newStudent(descriptor, payload);
}
