#include <stdio.h>

int main()
{
    // user input
    int userScore;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &userScore);
    // checks for valid score
    if (userScore <= 1) {
        printf("terminating program...");
        return 0;
    } 
    else if (userScore >= 2) {
        int tdPlus2pt = 0;
        // nested recursive loop to count every possible score
        while ( tdPlus2pt <= 2 + (userScore/8) ) {
            int tdPlusFG = 0;
            while ( tdPlusFG <= 2 + (userScore/7) ) {
                int touchdown = 0;
                while ( touchdown <= 2 + (userScore/6) ) {
                    int feildGoal = 0;
                    while ( feildGoal <= 2 + (userScore/3) ) {
                        int safety = 0;
                        while ( safety <= 2 + (userScore/2) ) {
                            // check if user score has been reached
                            if ( (tdPlus2pt * 8) + (tdPlusFG * 7) + (touchdown * 6) + 
                            (feildGoal * 3) + (safety * 2 ) == userScore ) {
                                // outputs possible score frequencies 
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                tdPlus2pt, tdPlusFG, touchdown, feildGoal, safety);
                            }
                            safety++;
                        }
                        feildGoal++;
                    }
                    touchdown++;
                }
                tdPlusFG++;
            }
            tdPlus2pt++;
        }
    }
    return 0;
}