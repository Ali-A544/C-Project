#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_STUDENTS 100
#define MAX_COURSES 10
#define MAX_EXAMS 10
#define MAX_LABS 5
#define MAX_ATTENDANCE_DAYS 30
//Structure to hold student information
struct Student 
{
int studentId;
char name[50];
char program[50];
int semester;
float cgpa;
};
//Structure to hold course information
struct Course 
{
int courseId;
char name[50];
int credits;
};
//Structure to hold exam information
struct Exam 
{
int examId;
char courseName[50];
char date[20];
char time[20];
};
//Structure to hold lab information
struct Lab 
{
int labId;
char courseName[50];
char date[20];
char time[20];
};
//Structure to hold attendance information
struct Attendance 
{
int studentId;
char date[20];
bool isPresent;
};
//Function to initialize students
void initializeStudents(struct Student students[]) 
{
for(int i = 0; i < MAX_STUDENTS; i++) 
	{
    students[i].studentId = -1;
    strcpy(students[i].name, "");
    strcpy(students[i].program, "");
    students[i].semester = 0;
    students[i].cgpa = 0.0;
    }
}
//Function to add a student
void addStudent(struct Student students[], int *numStudents) 
{
if(*numStudents >= MAX_STUDENTS) 
	{
    printf("Cannot add more students. Maximum capacity reached.\n");
    return;
    }
struct Student newStudent;
printf("Enter student ID: ");
scanf("%d", &newStudent.studentId);
for(int i = 0; i < *numStudents; i++) 
	{
    if(students[i].studentId == newStudent.studentId) 
		{
        printf("Student with this ID already exists.\n");
        return;
        }
    }
printf("Enter Student Name: ");
scanf(" %[^\n]s", newStudent.name);
printf("Enter Student Program: ");
scanf(" %[^\n]s", newStudent.program);
printf("Enter Student Semester: ");
scanf("%d", &newStudent.semester);
printf("Enter Student CGPA: ");
scanf("%f", &newStudent.cgpa);
students[*numStudents] = newStudent;
(*numStudents)++;
printf("Student Added Successfully.\n");
}
//Function to display student details
void displayStudents(struct Student students[], int numStudents) 
{
printf("Student Details:\n");
printf("=======================================================\n");
printf("ID\tName\t\tProgram\t\tSemester\tCGPA\n");
printf("=======================================================\n");
for(int i=0; i<numStudents; i++) 
	{
    printf("%d\t%-20s\t%-20s\t%d\t\t%.2f\n", students[i].studentId, students[i].name, students[i].program,
               students[i].semester, students[i].cgpa);
    }
printf("=======================================================\n");
}
//Function to initialize courses
void initializeCourses(struct Course courses[]) 
{
for(int i = 0; i < MAX_COURSES; i++) 
	{
    courses[i].courseId = -1;
    strcpy(courses[i].name, "");
    courses[i].credits = 0;
    }
}
//Function to add a course
void addCourse(struct Course courses[], int *numCourses) 
{
if(*numCourses >= MAX_COURSES) 
	{
    printf("Cannot add more courses. Maximum capacity reached.\n");
    return;
    }
struct Course newCourse;
printf("Enter course ID: ");
scanf("%d", &newCourse.courseId);
for(int i = 0; i < *numCourses; i++) 
	{
    if(courses[i].courseId == newCourse.courseId) 
		{
        printf("Course with this ID already exists.\n");
        return;
        }
    }
printf("Enter course name: ");
scanf(" %[^\n]s", newCourse.name);
printf("Enter course credits: ");
scanf("%d", &newCourse.credits);
courses[*numCourses] = newCourse;
(*numCourses)++;
printf("Course added successfully.\n");
}
//Function to display course details
void displayCourses(struct Course courses[], int numCourses) 
{
printf("Course Details:\n");
printf("============================================\n");
printf("ID\tName\t\tCredits\n");
printf("============================================\n");
for(int i=0; i<numCourses; i++) 
	{
    printf("%d\t%-20s\t%d\n", courses[i].courseId, courses[i].name, courses[i].credits);
    }
printf("============================================\n");
}
//Function to add an exam
void addExam(struct Exam exams[], int *numExams) 
{
if(*numExams >= MAX_EXAMS) 
	{
    printf("Cannot add more exams. Maximum capacity reached.\n");
    return;
    }
struct Exam newExam;
printf("Enter Exam ID: ");
scanf("%d", &newExam.examId);
printf("Enter Course Name: ");
scanf(" %[^\n]s", newExam.courseName);
printf("Enter Exam Date (DD/MM/YYYY): ");
scanf(" %[^\n]s", newExam.date);
printf("Enter Exam Time: ");
scanf(" %[^\n]s", newExam.time);
exams[*numExams] = newExam;
(*numExams)++;
printf("Exam Added Successfully.\n");
}
//Function to display all exams
void displayExams(struct Exam exams[], int numExams) 
{
printf("Exam Details:\n");
printf("===============================================================\n");
printf("ID\tCourse Name\t\tDate\t\tTime\n");
printf("===============================================================\n");
for(int i=0; i<numExams; i++) 
	{
    printf("%d\t%-20s\t%-12s\t%-12s\n", exams[i].examId, exams[i].courseName, exams[i].date, exams[i].time);
    }
printf("===============================================================\n");
}
//Function to add a lab activity
void addLab(struct Lab labs[], int *numLabs) 
{
if (*numLabs >= MAX_LABS) 
	{
    printf("Cannot add more lab activities. Maximum capacity reached.\n");
    return;
    }
struct Lab newLab;
printf("Enter Lab ID: ");
scanf("%d", &newLab.labId);
printf("Enter Course Name: ");
scanf(" %[^\n]s", newLab.courseName);
printf("Enter Lab Date (DD/MM/YYYY): ");
scanf(" %[^\n]s", newLab.date);
printf("Enter Lab Time: ");
scanf(" %[^\n]s", newLab.time);
labs[*numLabs] = newLab;
(*numLabs)++;
printf("Lab Activity Added Successfully.\n");
}
//Function to display all lab activities
void displayLabs(struct Lab labs[], int numLabs) 
{
printf("Lab Activity Details:\n");
printf("===============================================================\n");
printf("ID\tCourse Name\t\tDate\t\tTime\n");
printf("===============================================================\n");
for(int i=0; i<numLabs; i++) 
	{
    printf("%d\t%-20s\t%-12s\t%-12s\n", labs[i].labId, labs[i].courseName, labs[i].date, labs[i].time);
    }
printf("===============================================================\n");
}
//Function to mark attendance
void markAttendance(struct Student students[], int numStudents, struct Attendance attendance[][MAX_ATTENDANCE_DAYS], int *numDays) 
{
int studentId;
printf("Enter Student ID: ");
scanf("%d", &studentId);
int studentIndex = -1;
for(int i = 0; i < numStudents; i++) 
	{
    if(students[i].studentId == studentId) 
		{
        studentIndex = i;
        break;
        }
    }
if(studentIndex == -1) 
	{
    printf("Student with this ID does not exist.\n");
    return;
    }
int present;
char choice;
for(int i = 0; i < *numDays; i++) 
	{
    printf("Is the Student Present on day %d? (1 for yes, 0 for no): ", i + 1);
    scanf("%d", &present);
    if(present == 1) 
		{
        attendance[studentIndex][i].isPresent = true;
        } 
	else if(present == 0) 
		{
            attendance[studentIndex][i].isPresent = false;
        }
	else {
            printf("Invalid choice. Please enter 1 for yes or 0 for no.\n");
            i--;
        }
    }
printf("Attendance Marked Successfully.\n");
}
//Function to display student attendance
void displayAttendance(struct Student students[], int numStudents, struct Attendance attendance[][MAX_ATTENDANCE_DAYS], int numDays) 
{
printf("Student Attendance:\n");
printf("===================================================================\n");
printf("ID\tName\t\t");
for(int i=0; i<numDays; i++) 
	{
    printf("Day %d\t", i + 1);
    }
printf("\n===================================================================\n");
for(int i=0; i<numStudents; i++) 
	{
    printf("%d\t%-20s\t", students[i].studentId, students[i].name);
    for(int j = 0; j < numDays; j++) 
		{
        printf("%s\t", attendance[i][j].isPresent ? "Present" : "Absent");
        }
    printf("\n");
    }
    printf("===================================================================\n");
}
int main() 
{
struct Student students[MAX_STUDENTS];
int numStudents = 0;
struct Course courses[MAX_COURSES];
int numCourses = 0;
struct Exam exams[MAX_EXAMS];
int numExams = 0;
struct Lab labs[MAX_LABS];
int numLabs = 0;
struct Attendance attendance[MAX_STUDENTS][MAX_ATTENDANCE_DAYS];
int numDays = 0;
int choice;
initializeStudents(students);
initializeCourses(courses);
do {
    //Display menu
    printf("\nUniversity Management System\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Add Course\n");
    printf("4. Display All Courses\n");
    printf("5. Add Exam\n");
    printf("6. Display All Exams\n");
    printf("7. Add Lab Activity\n");
    printf("8. Display All Lab Activities\n");
    printf("9. Mark Attendance\n");
    printf("10. Display Student Attendance\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
            		case 1:
                	addStudent(students, &numStudents);
                	break;
            		case 2:
                	displayStudents(students, numStudents);
              		break;
            		case 3:
                	addCourse(courses, &numCourses);
                	break;
            		case 4:
                	displayCourses(courses, numCourses);
                	break;
            		case 5:
                	addExam(exams, &numExams);
            	    break;
            		case 6:
                	displayExams(exams, numExams);
                	break;
            		case 7:
             	   	addLab(labs, &numLabs);
                	break;
            		case 8:
                	displayLabs(labs, numLabs);
                	break;
        	    	case 9:
            	    markAttendance(students, numStudents, attendance, &numDays);
                	numDays++;
                	break;
            		case 10:
              	  	displayAttendance(students, numStudents, attendance, numDays);
                	break;
            		case 11:
               		printf("Exiting University Management System.\n");
                	break;
            		default:
                	printf("Invalid choice. Please try again.\n");
                	break;
        			}
    } while (choice != 11);
return 0;
}