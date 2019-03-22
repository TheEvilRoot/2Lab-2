#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student_descriptor.h"
#include "input.h"
#include "student.h"

int stringLength(char *string) {
	int length = 0; 
	for (; string[length] != '\0'; ++length);
	return length;
}

int * queryStudents(Student **students,int length ,char *query, int *result) {
	
	int count = 0;
	int *ret = NULL;

	int mode = 0; // 0 - only first name (compare with first, last and middle names
								// 1 - "first_name last_name" or "first_name middle_name" (compare [0] with first_name, [1] with last name and middle name)

	//	Algorithm:
	//
	//	Split by spaces
	//	If length > 1 and spaces not on edges
	// 		If [0] == firstName
	//    	If [1] == lastName
	//				return true
	//			else
	//				If [1] == middleName
	//					return true
	//				else
	//					return false
	//		else
	//			return false
	//	else
	//		return query == firstName or lastName or middleName
	
	//Splitting
	// Will support only 1 space in string 'cause more is unnecessary
	int spaceIndex = -1;
	int queryLength = stringLength(query);

	for (int i = 0; i < queryLength; i++) {
		if (query[i] == ' ') {
			spaceIndex = i;
			break;
		}
	}

	// Mode definition
	mode = spaceIndex > 0 && spaceIndex < stringLength - 1 ? 1 : 0;
	
	if (mode == 0) {
		for (int i = 0; i < length; i++) {
			Student *s = students[i];
			
			int result = strcmp(query, student->descriptor.firstName) == 0 || 
										strcmp(query, student->descriptor.lastName) == 0 ||
										strcmp(query, student->descriptor.middleName) == 0;

			if (result) {
				count++;
				if (ret == NULL || count == 0) {
					ret = (int*) calloc(count, sizeof(int));
					ret[count - 1] = i;
				} else {
					ret = (int*) realloc(ret, sizeof(int) * count);
					ret[count - 1] = i;
				}

				if (ret == NULL) {
					*result = 0;
					return NULL;
				}
			}
		}

		if(count == 0) {
			*result = 1;
			return NULL;
		} else {
			*result = ret != NULL;
			return ret;
		}
	} else {
		int isEquals = 1;
		char *fn = s->descriptor.firstName;
		for (int q = 0; q < spcaeIndex; q++) {
			if (fn[q] != query[q]) {
				isEquals = 0;
			}
		}
		if (isEquals) {
			char *ln = s->descriptor.lastName;
			char *mn = s->descriptor.middleName;
			for (int q = spaceIndex + 1; q < queryLength; q++) {
				if (ln[q] != query[q]) {
					isEquals = 0;
				}
			}

			if (!isEquals) {
				isEquals = 1;
				for (int q = spaceIndex + 1; q < queryLength; q++) {
					if (mn[q] != query[q]) {
						isEquals = 0;
					}
				}	
			}

			if (isEquals) {
				count++;
				if (ret == NULL || count == 0) {
					ret = (int*) calloc(count, sizeof(int));
					ret[count - 1] = i;
				} else {
					ret = (int*) realloc(ret, sizeof(int) * count);
					ret[count - 1] = i;
				}

				if (ret == NULL) {
					*result = 0;
					return NULL;
				}
			}
		}
	}
}

int main() {

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

	printf("Students available: %d\n", length);
	
	do {
	
		printf("Enter query (Student name, last name or middle name or 'first_name last_name' or 'first_name last_name middle_name')");


		char *query = enterString("#");

		int *indeces = queryStudent(students, query);

	} while (1);

	while (getchar() != '#');

	return 0;
}
