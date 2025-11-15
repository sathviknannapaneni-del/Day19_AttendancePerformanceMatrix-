#include <stdio.h>

int main() {

    char names[5][20];
    int attendance[5][5];
    int marks[5][5];

    int totalAttendance[5], totalAbsence[5];
    int totalMarks[5];
    float avg[5];
    char grade[5];

    int i, j;

    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\nEnter Attendance Matrix (5x5) - 1 for Present, 0 for Absent:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nEnter Marks Matrix (5x5):\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    int highestAtt = -1, lowestAtt = 9999;
    int highIndex = 0, lowIndex = 0;

    for(i = 0; i < 5; i++) {
        totalAttendance[i] = 0;
        totalAbsence[i] = 0;

        for(j = 0; j < 5; j++) {
            if(attendance[i][j] == 1)
                totalAttendance[i]++;
            else
                totalAbsence[i]++;
        }

        if(totalAttendance[i] > highestAtt) {
            highestAtt = totalAttendance[i];
            highIndex = i;
        }

        if(totalAttendance[i] < lowestAtt) {
            lowestAtt = totalAttendance[i];
            lowIndex = i;
        }
    }

    int highestMarks = -1, lowestMarks = 9999;
    int topperIndex = 0, lowPerfIndex = 0;

    for(i = 0; i < 5; i++) {
        totalMarks[i] = 0;

        for(j = 0; j < 5; j++) {
            totalMarks[i] += marks[i][j];
        }

        avg[i] = totalMarks[i] / 5.0;

        if(totalMarks[i] > highestMarks) {
            highestMarks = totalMarks[i];
            topperIndex = i;
        }

        if(totalMarks[i] < lowestMarks) {
            lowestMarks = totalMarks[i];
            lowPerfIndex = i;
        }

        if(avg[i] >= 90)
            grade[i] = '1'; // A+
        else if(avg[i] >= 80)
            grade[i] = '2'; // A
        else if(avg[i] >= 70)
            grade[i] = '3'; // B
        else if(avg[i] >= 60)
            grade[i] = '4'; // C
        else if(avg[i] >= 50)
            grade[i] = '5'; // D
        else
            grade[i] = '6'; // F
    }


    int choice;

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
                printf("\n--- Attendance Matrix ---\n");
                for(i = 0; i < 5; i++) {
                    for(j = 0; j < 5; j++) {
                        printf("%d ", attendance[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\n--- Marks Matrix ---\n");
                for(i = 0; i < 5; i++) {
                    for(j = 0; j < 5; j++) {
                        printf("%d ", marks[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\n--- Attendance Report ---\n");
                for(i = 0; i < 5; i++) {
                    printf("%s : Present = %d, Absent = %d\n", names[i], totalAttendance[i], totalAbsence[i]);
                }
                printf("Highest Attendance : %s (%d)\n", names[highIndex], highestAtt);
                printf("Lowest Attendance  : %s (%d)\n", names[lowIndex], lowestAtt);
                break;

            case 4:
                printf("\n--- Performance Report ---\n");
                for(i = 0; i < 5; i++) {
                    printf("%s : Total = %d, Average = %.2f\n", names[i], totalMarks[i], avg[i]);
                }
                printf("Class Topper       : %s (%d)\n", names[topperIndex], highestMarks);
                printf("Lowest Performer   : %s (%d)\n", names[lowPerfIndex], lowestMarks);
                break;

            case 5:
                printf("\n--- Grade Report ---\n");
                for(i = 0; i < 5; i++) {
                    printf("%s : ", names[i]);

                    if(grade[i] == '1') printf("A+\n");
                    else if(grade[i] == '2') printf("A\n");
                    else if(grade[i] == '3') printf("B\n");
                    else if(grade[i] == '4') printf("C\n");
                    else if(grade[i] == '5') printf("D\n");
                    else printf("F\n");
                }
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
