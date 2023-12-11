#include <stdio.h>

#define SIZE 1000

typedef struct COURSES 
{
	int sid[SIZE];
	int studentId[SIZE];
	int courseId[SIZE];
	int totalScore[SIZE];
	int numGrades[SIZE];

} COURSES;

int numFailed(COURSES *course, int numCourses)
{
    int failed = 0;
    double avgScore = 0;

	for (int i = 0; i < numCourses; ++i)
	{
		avgScore = course->totalScore[i] / (double) course->numGrades[i];
		failed = (avgScore < 60.0)? failed + 1: failed;
	}

    return failed;
}

int numStudentCount(COURSES *course, int numCourse)
{
    int num = 0;
    for (int i = 0; i < numCourse; i++)
    {
        scanf("%d %d %d", &course->sid[i], &course->studentId[i], &course->courseId[i]);
        num++;

        for (int j = 0; j < i - 1; j++)
        {
            if (course->studentId[i] == course->studentId[j])
            {
                num--;
                break;
            }
        }
    }

    return num;
}

int main(void)
{
    int numCourses, numScores;
    scanf("%d %d", &numCourses, &numScores);

    COURSES course;
    for (int i = 0; i < SIZE; i++)
    {
        course.totalScore[i] = 0;
        course.numGrades[i] = 0;
    }

   int numStudent = numStudentCount(&course, numCourses);

    int grade, sid;
    for (int i = 0; i < numScores; i++)
    {
        scanf("%d %d",&sid, &grade);

        course.totalScore[sid] += grade;
        course.numGrades[sid]++;
    }

    printf("%d %d", numStudent, numFailed(&course, numCourses));

}
