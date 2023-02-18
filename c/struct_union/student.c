#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAMESIZE 32

struct student_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void student_set(struct student_st *p, struct student_st *src){
	*p = *src;
}

void student_show(struct student_st *p){
	printf("student:id=%d name=%s math=%d chinese=%d\n", p->id, p->name, p->math, p->chinese);
}

void student_change(struct student_st *p, const char *name){
	strcpy(p->name, name);
}

void menu(){
	puts("\n");
	printf("Please select an item:\n");
	printf("1 set student\n2 change student\n3 show student\nq for exit\n");
	puts("\n");
}

int main()
{

	struct student_st student, tmp;
	int select,res;
	char newName[NAMESIZE];

	do
	{
		menu();
		res = scanf("%d", &select);
		if(res == 0)
			break;

		switch (select){
			case 1:
				printf("Please enter a student info[id name math chinese]\n");
				scanf("%d%s%d%d", &tmp.id, tmp.name, &tmp.math, &tmp.chinese);
				student_set(&student, &tmp);
				break;
			case 2:
				printf("Please a new name for student[%s]\n", student.name);
				scanf("%s", newName);
				student_change(&student, newName);
				break;
			case 3:
				student_show(&student);
				break;
			default:
				exit(1);

		}
		sleep(1);
	} while(1);

	return 0;
}
