/**
 * Design a structure named "Car" to store details like car ID, model, and rental rate per day.
 * Write a C program to input data for three cars,
 * calculate the total rental cost for a specified number of days,
 * and display the results.
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    gets(name);
    char rep = 'love';

    int start, end;
    for(int i=0; i<strlen(name); i++){
        start = i;
        for(int j=i; j<strlen(rep); j++){
            if(name[j] == rep[j-i]){
                end = j;
            }else{
                break;
            }
        }
    }

    printf("%d %d", name[start], name[end]);
    return 0;
}
