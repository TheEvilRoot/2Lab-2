
#ifndef _student_h
#define _student_h

#include <stdlib.h>

#include "student_descriptor.h"
#include "payload.h"

typedef struct {
	StudentDescriptor descriptor;
	Payload payload; // TODO: Will be replaced to weird union (I'm not completely sure how to implement this one)
	
} Student;

Student * newStudent(StudentDescriptor descriptor, Payload payload);

void printStudent(Student *student);

#endif
