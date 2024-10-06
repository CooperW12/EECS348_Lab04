#include <stdio.h>

int main() {

int userIn = 2; //make sure the loop doesn't end right away
while (userIn > 1){
printf("enter 0 or 1 to STOP \n");
printf("enter football score:");
scanf("%d", &userIn);

int score = userIn; //set score to user input score

for (int touchdownTPCs = 0 ; touchdownTPCs <= score/8 ; touchdownTPCs++){ //loop touchdowns + 2 point conversion
    for (int touchdownEPs = 0 ; touchdownEPs <= score/7 ; touchdownEPs++){ //loop touchdowns + 1 extra point
        for (int touchdowns = 0 ; touchdowns <= score/6 ; touchdowns++){ //loop touchdowns 
            for (int fieldgoals = 0 ; fieldgoals <= score/3 ; fieldgoals++){ //loop fieldgoals
                for (int safetys = 0 ; safetys <= score/2 ; safetys++){ //loop safeties
                    int loopScore = (touchdownTPCs * 8) + (touchdownEPs * 7) + (touchdowns * 6) + (fieldgoals * 3) + (safetys * 2); //add up the loop score
                    if (loopScore == score) { //if the loop score is the score we want print it out
                        printf("TDTPCs: %d, TDEPs: %d, TDs: %d, FGs: %d, Safeties: %d\n", touchdownTPCs, touchdownEPs, touchdowns, fieldgoals, safetys);
                    }
                }
            }
        }
    }
}
}

return 0;
}