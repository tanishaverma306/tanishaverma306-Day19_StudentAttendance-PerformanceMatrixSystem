#include <stdio.h>

int main() {
    int Attendance[5][5], Marks[5][5];
    char StName[5][20];
    int i, j, choice;

    for(i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", StName[i]);
    }

    for(i = 0; i < 5; i++) {
        printf("\nEnter attendance and marks for %s:\n", StName[i]);
        for(j = 0; j < 5; j++) {
            printf("  Subject %d - Attendance: ", j + 1);
            scanf("%d", &Attendance[i][j]);
            printf("  Subject %d - Marks: ", j + 1);
            scanf("%d", &Marks[i][j]);
        }
    }

    while(1) {
        printf("\n========= MENU =========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nAttendance Matrix:\n");
                for(i = 0; i < 5; i++) {
                    for(j = 0; j < 5; j++) {
                        printf("%d ", Attendance[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\nMarks Matrix:\n");
                for(i = 0; i < 5; i++) {
                    for(j = 0; j < 5; j++) {
                        printf("%d ", Marks[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                int totalAttended[5];
                int highestIndex = 0, lowestIndex = 0;

                printf("\n===== ATTENDANCE REPORT =====\n");

                for(i = 0; i < 5; i++) {
                    totalAttended[i] = 0;

                    for(j = 0; j < 5; j++)
                        totalAttended[i] += Attendance[i][j];

                    printf("%s - Total Attendance: %d, Total Absences: %d\n",
                           StName[i], totalAttended[i], 150 - totalAttended[i]);
                }

                for(i = 1; i < 5; i++) {
                    if(totalAttended[i] > totalAttended[highestIndex]) highestIndex = i;
                    if(totalAttended[i] < totalAttended[lowestIndex])  lowestIndex = i;
                }

                printf("\nHighest Attendance : %s (%d)\n", StName[highestIndex], totalAttended[highestIndex]);
                printf("Lowest Attendance  : %s (%d)\n", StName[lowestIndex], totalAttended[lowestIndex]);

                break;
            }

            case 4: {
                int totalMarks[5];
                float avgMarks[5];
                int topperIndex = 0, lowIndex = 0;

                printf("\n===== PERFORMANCE REPORT =====\n");

                for(i = 0; i < 5; i++) {
                    totalMarks[i] = 0;

                    for(j = 0; j < 5; j++)
                        totalMarks[i] += Marks[i][j];

                    avgMarks[i] = totalMarks[i] / 5.0;

                    printf("\n---- %s ----\n", StName[i]);
                    printf("Total Marks : %d\n", totalMarks[i]);
                    printf("Average     : %f\n", avgMarks[i]);
                }

                for(i = 1; i < 5; i++) {
                    if(totalMarks[i] > totalMarks[topperIndex]) topperIndex = i;
                    if(totalMarks[i] < totalMarks[lowIndex])    lowIndex = i;
                }

                printf("\nClass Topper      : %s (Total %d)\n",
                       StName[topperIndex], totalMarks[topperIndex]);

                printf("Lowest Performer  : %s (Total %d)\n",
                       StName[lowIndex], totalMarks[lowIndex]);

                break;
            }

            case 5: {
                float avg;
                char grade;

                printf("\n===== GRADE REPORT =====\n");

                for(i = 0; i < 5; i++) {
                    int sum = 0;
                    for(j = 0; j < 5; j++)
                        sum += Marks[i][j];

                    avg = sum / 5.0;

                    if(avg >= 90) grade = 'A';  // for A+   
                    else if(avg >= 80) grade = 'a'; //for A
                    else if(avg >= 70) grade = 'B';
                    else if(avg >= 60) grade = 'C';
                    else if(avg >= 50) grade = 'D';
                    else grade = 'F';

                    printf("\n---- %s ----\n", StName[i]);
                    printf("Average: %f\n", avg);
                    printf("Grade  : %c\n", grade);
                }

                break;
            }

            case 6:
                return 0;

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
