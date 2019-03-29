#include <stdlib.h>
#include <stdio.h>

#include "payload.h"
#include "exams.h"
Payload newPayload() {
	Payload payload;

	payload.results = (int*) calloc(6, sizeof(int));
	for (int i = 0; i < 6; i++) {
		payload.results = -1;
	}

	return payload;
}

void addResult(Payload payload, int examId, int result) {
	if (examId > 5) return;

	payload.results[examId] = result;
}

void printPayload(Payload payload) {
	for (int i = 0; i < 6; i++) {
		if (payload.results[i] > 0) {
			printf("%s: %d\n", localizeExam(i), payload.results[i]);
		}
	}
}	
