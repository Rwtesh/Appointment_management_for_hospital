#include <stdio.h>
#include "library.h"

int compare(char str[],char str2[]){
    int i = 0;
    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] != str2[i]) {
            return 1; 
        }
        i++;
    }
    if (str[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else {
        return 1;
    }
}
int length(char str[]){
    int i=0;
    int c=0;
    while(str[i]!='\0'){
        c+=1;
        i++;
    }
    return c;
}
void conc(char str[],char str2[]){
    int l=length(str);
    int i=0;
    while(str2[i]!='\0'){
        str[l]=str2[i];
        i++;
        l++;
    }
    str[l]='\0';
}
