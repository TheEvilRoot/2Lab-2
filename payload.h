#ifndef _payload_h
#define _payload_h

#include <stdlib.h>

typedef union {
	int data;
} Payload;

Payload newPayload(int data);
void printPayload(Payload payload);

#endif
