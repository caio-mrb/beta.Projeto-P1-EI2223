#include "funcoesDeData.h"
#include "funcoesDeDados.h"


void showDate(DateType date)
{
    int dayDigits, monthDigits;

    getNumOfDigits(&dayDigits,date.day);
    getNumOfDigits(&monthDigits,date.month);

    if (dayDigits == 2 && monthDigits == 2)
    {
        printf("%d/%d/%d",date.day,date.month,date.year);
    }
    if (dayDigits == 2 && monthDigits != 2)
    {
        printf("%d/0%d/%d",date.day,date.month,date.year);
    }
    if (dayDigits != 2 && monthDigits == 2)
    {
        printf("0%d/%d/%d",date.day,date.month,date.year);
    }
    if (dayDigits != 2 && monthDigits != 2)
    {
        printf("0%d/0%d/%d",date.day,date.month,date.year);
    }
}

void writeDateToFile(DateType date, FILE *infoFile)
{
    int dayDigits, monthDigits;

    getNumOfDigits(&dayDigits,date.day);
    getNumOfDigits(&monthDigits,date.month);

    if (dayDigits == 2 && monthDigits == 2)
    {
        fprintf(infoFile,"%d/%d/%d",date.day,date.month,date.year);
    }
    if (dayDigits == 2 && monthDigits != 2)
    {
        fprintf(infoFile,"%d/0%d/%d",date.day,date.month,date.year);
    }
    if (dayDigits != 2 && monthDigits == 2)
    {
        fprintf(infoFile,"0%d/%d/%d",date.day,date.month,date.year);
    }
    if (dayDigits != 2 && monthDigits != 2)
    {
        fprintf(infoFile,"0%d/0%d/%d",date.day,date.month,date.year);
    }
}

void numOfDaysBetweenDates(int *result,DateType lowerDate, DateType higherDate)
{

    int index;
    DateType dateAux = {0};

    *result = 0;

    if (higherDate.year < lowerDate.year)
    {
        dateAux = higherDate;
        higherDate = lowerDate;
        lowerDate = dateAux;

    }


        for (index=lowerDate.year; index<higherDate.year-1; index++)
        {

            if(index%400==0 ||(index%4==0 && index%100!=0))
            {
                (*result) +=366;
            }
            else
            {
                (*result) +=365;
            }
        }

        for (index=lowerDate.month; index<=12; index++)
        {
            switch(index)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                *result += 30;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                *result += 31;
                break;
            case 2:
                if(lowerDate.year%400==0 ||(lowerDate.year%4==0 && lowerDate.year%100!=0))
                {
                    *result += 29;
                }
                else
                {
                    *result += 28;
                }
                break;
            }
        }

        for (index=1; index<higherDate.month; index++)
        {
            switch(index)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                *result += 30;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                *result += 31;
                break;
            case 2:
                if(higherDate.year%400==0 ||(higherDate.year%4==0 && higherDate.year%100!=0))
                {
                    *result += 29;
                }
                else
                {
                    *result += 28;
                }
                break;
            }
        }

        if (higherDate.year == lowerDate.year){
            if(higherDate.year%400==0 ||(higherDate.year%4==0 && higherDate.year%100!=0))
            {
                (*result) -=366;
            }
            else
            {
                (*result) -=365;
            }
        }

        *result += (higherDate.day - lowerDate.day);

        if (dateAux.day != 0) {

            *result = (*result) * -1;
        }

}
