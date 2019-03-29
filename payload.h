#ifndef _payload_h
#define _payload_h

#include <stdlib.h>
typedef union {
	struct {
			
	} first;
	Semester second;
	Semester third;
	Semester fourth;
	Semester fifth;
	Semester sixth;
	Semester seventh;
	Semester eighth;
} Payload;

Payload newPayload(int sem, );
void printPayload(Payload payload);

#endif
