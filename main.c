//
//  main.c
//  2Lab-2
//
//  Created by Доктор Кларик on 11.04.19.
//  Copyright © 2019 Доктор Кларик. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#define scanf scanf_s
#endif

#define boolean unsigned int
#define true 1
#define false 0

#define EXAM_COUNT 10

const char *EXAMS[EXAM_COUNT] = {
  "Physics",
  "Algebra",
  "Computer Science",
  "Software Engineering",
  "English",
  "History",
  "Philosophy",
  "Discrete Math",
  "Circuitry",
  "Radionics"
};

typedef char* string;

struct _student_id {
  string firstName;
  string lastName;
  string middleName;
  
  int semester;
};

struct _exam {
  int id;
  int result;
};

union _student_result {
  struct {
    struct _exam firstExam;
    struct _exam secondExam;
    struct _exam thirdExam;
  } firstSem;
  
  struct {
    struct _exam firstExam;
    struct _exam secondExam;
    struct _exam thirdExam;
    struct _exam fourthExam;
    struct _exam fifthExam;
  } secondSem;
};

struct _student {
  struct _student_id id;
  union _student_result results;
};

typedef struct _student Student;
typedef struct _exam Exam;

const char * localizeExam(int index) {
  if (index >= EXAM_COUNT) return "Not Found";
  
  return EXAMS[index];
}

int stringLength(string str) {
  int length = 0;
  for (; str[length] != '\0'; ++length);
  return length;
}

int parseInt(string str) {
  int number = 0;
  int length = stringLength(str);
  
  for (int i = length - 1; i >= 0; i--) {
    if (str[i] >= '0' && str[i] <= '9') {
      number *= 10;
      number += str[i] - '0';
    } else {
      break;
    }
  }
  return number;
}

boolean isValidSemester(int num) {
  return num > 0 && num < 3;
}

// Should check existence of semester number in argv
// Will recognize the last valid number in [argv] array as semester then break the loop.
// Example:
// argv =	[123, 1, 22, 5]	-> 1
// argv =	[2, 1, 2, 1, 2]	-> 2
// argv =	[asd, 1, 2, a]	-> 2
// argv =	[]              -> 0
// argv =	[a, b, c, 1234]	-> 0
int parseArguments(const int argc, char *argv[]) {
  int semester = 0;
  for (int i = argc - 1; i >= 1; i--) {
    int num = parseInt(argv[i]);
    
    if (isValidSemester(num)) {
      semester = num;
      break;
    }
  }
  return semester;
}

// @Nullable
string enterString(const string message) {
  string str = (string) calloc(1,  sizeof(char)); // Checked
  if (str == NULL) {
    return NULL;
  }
  
  int i = 0;
  char c;
  
  printf("%s", message);
  
  fflush(stdin);
  fseek(stdin, 0, SEEK_END);
  while ((c = getchar()) != -1) {
    str[i++] = c;
    
    if (c == '\n') {
      str[i - 1] = '\0';
      break;
    }
    
    if (!(str = (string) realloc(str, sizeof(char) * (i + 1)))) {
      str[i - 1] = '\0';
      break;
    }
  }
  
  return str;
}

int enterInt(const string message) {
  int ret = 0;
  
  do {
    printf("%s", message);
    fflush(stdin);
    fseek(stdin, 0, SEEK_END);
  } while (!scanf("%d", &ret));
  
  return ret;
}

char enterChar(const string message) {
  printf("%s", message);
  fflush(stdin);
  fseek(stdin, 0, SEEK_END);
  return getchar();
}


void enterExam(const char *message, int *id, int *res) {
  printf("%s", message);
  printf("Available exams: \n");
  for (int i = 0; i < EXAM_COUNT; i++) {
    printf("[%d]: %s\n", i, localizeExam(i));
  }
  int choice;
  do {
    choice = enterInt("Enter exam ID: ");
  } while (choice < 0 || choice >= EXAM_COUNT);
  
  int result;
  do {
    result = enterInt("Enter result for this exam: ");
  } while (result < 0 || result > 10);
  
  *id = choice;
  *res = result;
}

// @NullWarning 
boolean copyString(char *original, char **dist) {
	
	if (original == NULL || dist == NULL) {
		return false;
	}

	int length = stringLength(original);
	(*dist) = (string) calloc(length + 1, sizeof(char)); // Checked
	if (*dist == NULL) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		(*dist)[i] = original[i];
	}
	(*dist)[length] = '\0';
	return true;
}

// @Nullable
Student * enterStudent(const string message) {
  printf("%s", message);
  
  Student *student = (Student*) calloc(1, sizeof(Student)); // Checked
  
  if (student == NULL) {
    return NULL;
  }
  
  // [ ] Enter student's id
  
  string firstName = enterString("Enter student's first name: "); // Checked
  string lastName = enterString("Enter student's last name: "); // Checked
  string middleName = enterString("Enter student's middle name: "); // Checked
  int semester = 0;
  do {
    semester = enterInt("Enter semester: ");
  } while(!isValidSemester(semester));

  if (firstName == NULL || lastName == NULL || middleName == NULL) {
    return NULL;
  }
  
  // [ ] Copy first name
  
  if (!copyString(firstName, &student->id.firstName)) {
	  return NULL;
  }

  // [ ] Copy last name
 
  if (!copyString(lastName, &student->id.lastName)) {
	  return NULL;
  }
  
  // [ ] Copy middle name
  
  if (!copyString(middleName, &student->id.middleName)) {
	  return NULL;
  }
  
  // [ ] Set semester
  
  student->id.semester = semester;
  
  // [ ] Enter exams
  
  if (semester == 1) {
    enterExam("Enter first exam: \n", &student->results.firstSem.firstExam.id, &student->results.firstSem.firstExam.result);
    enterExam("Enter second exam: \n", &student->results.firstSem.secondExam.id, &student->results.firstSem.secondExam.result);
    enterExam("Enter third exam: \n", &student->results.firstSem.thirdExam.id, &student->results.firstSem.thirdExam.result);
  } else if (semester == 2) {
    enterExam("Enter first exam: \n", &student->results.secondSem.firstExam.id, &student->results.secondSem.firstExam.result);
    enterExam("Enter second exam: \n", &student->results.secondSem.secondExam.id, &student->results.secondSem.secondExam.result);
    enterExam("Enter third exam: \n", &student->results.secondSem.thirdExam.id, &student->results.secondSem.thirdExam.result);
    enterExam("Enter fourth exam: \n", &student->results.secondSem.fourthExam.id, &student->results.secondSem.fourthExam.result);
    enterExam("Enter fifth exam: \n", &student->results.secondSem.fifthExam.id, &student->results.secondSem.fifthExam.result);
  }
  
  return student;
}

// @Nullable
Student ** initStudents(int *lengthPtr) {
  Student **students = (Student**) calloc(1, sizeof(Student*)); // Checked
  int index = 0;
  
  do {
    if (students == NULL) {
      return NULL;
    }
    
    students[index++] = enterStudent("Enter new student: \n");
    if (students[index - 1] == NULL) {
      printf("An unknown error occurred while student creating... Stopping input\n");
      break;
    }
    
    char *confirm = enterString("Do you want to enter another student?\n'y' to continue, anything else to stop\n#");
    if (confirm == NULL || stringLength(confirm) == 0 || (confirm[0] != 'Y' && confirm[0] != 'y')) {
      break;
    }
    
    students = (Student**) realloc(students, sizeof(Student*) * (index + 1));
    if (students == NULL) {
      break;
    }
  } while (true);
  
  *lengthPtr = index;
  return students;
}

void printStudent(Student *student) {
  if (student == NULL ||
      student->id.firstName == NULL ||
      student->id.lastName == NULL ||
      student->id.middleName == NULL) {
    return;
  }
  
  printf("\nStudent %s %s %s\n", student->id.firstName, student->id.lastName, student->id.middleName);
  printf("Semester: %d\n", student->id.semester);
  printf("Exams: \n");
  if (student->id.semester == 1) {
    printf("%s: %d\n", localizeExam(student->results.firstSem.firstExam.id), student->results.firstSem.firstExam.result);
    printf("%s: %d\n", localizeExam(student->results.firstSem.secondExam.id), student->results.firstSem.secondExam.result);
    printf("%s: %d\n", localizeExam(student->results.firstSem.thirdExam.id), student->results.firstSem.thirdExam.result);
  } else if (student->id.semester == 2) {
    printf("%s: %d\n", localizeExam(student->results.secondSem.firstExam.id), student->results.secondSem.firstExam.result);
    printf("%s: %d\n", localizeExam(student->results.secondSem.secondExam.id), student->results.secondSem.secondExam.result);
    printf("%s: %d\n", localizeExam(student->results.secondSem.thirdExam.id), student->results.secondSem.thirdExam.result);
    printf("%s: %d\n", localizeExam(student->results.secondSem.fourthExam.id), student->results.secondSem.fourthExam.result);
    printf("%s: %d\n", localizeExam(student->results.secondSem.fifthExam.id), student->results.secondSem.fifthExam.result);
  }
}

int main(const int argc, char *argv[]) {
  
  // [ ] Arguments check
  
  int semesterToFind = parseArguments(argc, argv);
  if (!isValidSemester(semesterToFind)) {
	  enterChar("I'm a potato. Your arguments is invalid\n");
    return 1;
  }
  
  // [ ] Students input

  int studentCount = 0;
  Student **students = initStudents(&studentCount);
  if (students == NULL) {
    if (studentCount == 0) { // User not entered any students (How did you do it?)
      printf("You not entered any students. Nothing to do here...\n");
      return 0;
    } else {
      printf("A memory error occurred while student entering. Sorry for inconvenience.\n");
      return 1;
    }
  }
  
  // [ ] Output according argument input
  
  boolean anyPrinted = false;
  for (int i = 0; i < studentCount; i++) {
    if (students[i]->id.semester != semesterToFind) continue;
  
    // [ ] Here all students have necessary semester, let's print them
    anyPrinted = true;
    printStudent(students[i]);
  }

  if (!anyPrinted) {
	  printf("There's no students with %d semester.\n", semesterToFind);
  }

  enterChar("Press any key to exit the program...\n");
  return 0;
}
