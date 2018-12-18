#include <stdio.h>

#define STUDENT_SIZE			{176,60,78}
#define STUDENT_INFORMATIONS	{"Abdullah","Aydin",25,123456,STUDENT_SIZE}
#define STUDENT                 {STUDENT_INFORMATIONS,{76,45,56,76}}


typedef struct size{
	int height;
	int weight;
}student_size_t;

typedef struct inf{
	char name[10];
	char surname [20];
	int age;
	int number;
	student_size_t size;
}information_t;

typedef struct lesson_point{
	int mat;
	int lang;
	int turk;
	int history;
}lesson_point_t;

typedef struct student{
	information_t student_inf;	
	lesson_point_t student_les;
}student_t;


typedef struct person{
student_t student;
int (*get)(student_t*);
}person_t;

int get_age(student_t* student){
    return student->student_inf.age;
}




int main(void)
{
    person_t person = {STUDENT,&get_age}; 
    printf("%d",person.get(&person.student));
    
	return 0;
}
