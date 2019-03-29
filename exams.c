#include "exams.h"

const char * localizeExam(int examId) {
    switch(examId) {
        case 0:
            return "Math";
        case 1:
            return "Computer Science";
        case 2:
            return "Physics";
        case 3:
            return "Philosophy";
        case 4:
            return "Software engineering";
        case 5:
            return "Political Science";
        default:
            return "[Invalid]";
    }
}

