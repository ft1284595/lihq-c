#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

//定义结构体
struct student_st{
	int id;
	char name[NAMESIZE];
	struct birthday_st {
		int year;
		int month;
		int day;
	} birth;
	int math;
	int chinese;
};

int main()
{

#if 0
	//初始化结构体
	struct student_st stu = {10001, "zhangsan", {2011,1,5}, 99, 98};

	//printf("%p %p\n", stu, &stu); //为什么&stu是nil
	//部分初始化结构体
	//struct student_st stu = {.math=100, .chinese=95};

	//printf("%d %s %d-%d-%d %d %d\n", stu.id, stu.name, stu.birth.year, stu.birth.month, stu.birth.day, stu.math, stu.chinese);
	//使用指针访问结构体成员
	
	struct student_st *p = &stu;
	printf("%p\n", p);
	printf("%d %s %d-%d-%d %d %d\n", p->id, p->name, p->birth.year, p->birth.month, p->birth.day, p->math, p->chinese);

#endif
	struct student_st stu[2] = {{10001, "lisi",{1999,2,5},87,89},{10002, "wangwu",{1998,5,30},75,80}};

	//struct student_st *p = stu;
	struct student_st *p = &stu[0];
	//struct student_st *p = &stu;	//warning 类型不同,&stu是struct student_st(*)[2]
	int i;

	for(i=0; i<2; i++, p++)
	{
		printf("%d %s %d-%d-%d %d %d\n", p->id, p->name, p->birth.year, p->birth.month, p->birth.day, p->math, p->chinese);
	}
/*
	for(i=0; i<2; i++)
	{
		printf("%d %s %d-%d-%d %d %d\n", (p+i)->id, (p+i)->name, (p+i)->birth.year, (p+i)->birth.month, (p+i)->birth.day, (p+i)->math, (p+i)->chinese);
		printf("%d %s %d-%d-%d %d %d\n", p[i].id, p[i].name, p[i].birth.year, p[i].birth.month, p[i].birth.day, p[i].math, p[i].chinese);
	}
*/



	return 0;
}
