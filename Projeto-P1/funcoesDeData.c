#include "funcoesDeData.h"
#include "funcoesDeDados.h"

#include <stdio.h>


void showDate(DateType date){

        int dayDigits, monthDigits;

        getNumOfDigits(&dayDigits,date.day);
        getNumOfDigits(&monthDigits,date.month);

        if (dayDigits == 2 && monthDigits == 2){
            printf("%d/%d/%4d",date.day,date.month,date.year);
        }
        if (dayDigits == 2 && monthDigits != 2){
            printf("%d/0%d/%4d",date.day,date.month,date.year);
        }
        if (dayDigits != 2 && monthDigits == 2){
            printf("0%d/%d/%4d",date.day,date.month,date.year);
        }
        if (dayDigits != 2 && monthDigits != 2){
            printf("0%d/0%d/%4d",date.day,date.month,date.year);
        }
}

