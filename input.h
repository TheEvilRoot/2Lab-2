#ifndef _input_h
#define _input_h

#include "student_descriptor.h"
#include "student.h"
#include "payload.h"

char * enterString(const char*);
int enterInt(const char*);
StudentDescriptor enterDescriptor(const char *message);
Student * enterStudent(const char *message);
Payload enterPayload(const char *message);

#endif
