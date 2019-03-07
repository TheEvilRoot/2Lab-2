#include <stdlib.h>
#include <stdio.h>

#include "payload.h"

Payload newPayload(int data) {
	Payload payload;

	payload.data = data;

	return payload;
}

void printPayload(Payload payload) {
	printf("Payload:\t%d\n", payload.data);
}	
