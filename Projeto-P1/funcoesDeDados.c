#include "funcoesDeDados.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>



void flushStdin(void)
{
    char trash;

    do
    {
        trash = getchar();
    }
    while (trash!='\n' && trash!=EOF);
}


void readInt(char *message, int *num,int numMin, int numMax)
{

    int control;

    do
    {
        printf("        %s (%d-%d): ",message,numMin,numMax);

        control = scanf("%d",num);
        flushStdin();

        if (*num < numMin || *num > numMax || control == 0)
        {
            printf("        Valor invalido!\n");
        }

    }
    while(*num < numMin || *num > numMax || control == 0);


}

void readFloat(char *message, float *num, float numMin, float numMax)
{

    int control;

    do
    {
        printf("        %s (%.2f-%.2f): ",message,numMin,numMax);

        control = scanf("%f",num);
        flushStdin();

        if (*num<numMin || *num > numMax || control == 0)
        {
            printf("        Valor invalido!\n");
        }

    }
    while(*num<numMin || *num > numMax || control == 0);

}

void readDate(char *message, DateType *date)
{

    int control,validValue = FALSE_0;
    int day, month, year;

    do
    {
        printf("        %s (dd/mm/yyyy): ", message);
        control = scanf("%d/%d/%d",&day,&month,&year);
        flushStdin();

        if (day != 0)
        {
            if (year >= 1900 && year <= 3500)
            {

                if (month>=1 && month<=12)
                {

                    if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                    {
                        validValue = TRUE_1;
                    }
                    else
                    {

                        if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                        {

                            validValue = TRUE_1;
                        }
                        else
                        {

                            if(day>=1 && day<=28 && month==2)
                            {

                                validValue = TRUE_1;
                            }
                            else
                            {

                                if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                                {

                                    validValue = TRUE_1;
                                }
                                else
                                {

                                    printf("        Dia invalido!\n");

                                }

                            }

                        }

                    }

                }
                if ((month<1 || month>12) && control == 3)
                {
                    printf("        Mes invalido, valido (1-12)!\n");
                }

            }
            if ((year < 1900 || year > 3500) && control == 3)
            {
                printf("        Ano invalido, valido (1900-3500)\n");
            }

        }
        if (day == 0)
        {
            validValue = TRUE_1;
        }
        if (validValue == FALSE_0 && control < 3)
        {
            printf("        Valor invalido!\n");
        }

    }
    while(validValue == FALSE_0);

    date->day = day;

    if (day != 0)
    {
        date->month = month;
        date->year = year;
    }

}


void readString(char *message,char *string, int maxStringSize)
{
    int stringSize,index, invalidChar;
    char checker;
    do
    {
        invalidChar = FALSE_0;
        printf("        %s (letras e numeros): ",message);
        fgets(string, maxStringSize, stdin);
        removeSpecificChar(string,' ');
        stringSize = strlen(string);
        if (stringSize == 1)
        {
            printf("        O campo não pode ficar vazio!\n");
        }
        else
        {
            for (index=0; index<stringSize; index++)
            {
                checker = string[index];
                if (checker != '\n' && checker != ' ' && (checker < '0' || checker > '9') && (checker < 65/*A*/ || checker > 90/*Z*/) && (checker < 97/*a*/ || checker > 122/*z*/))
                {
                    invalidChar = TRUE_1;
                }
            }
            if (invalidChar == TRUE_1)
            {
                printf("        So sao permitidos caracteres simples (a-z), \n");
                printf("        (A-Z), Espacos e numeros (0-9).\n");
            }
        }
    }
    while (stringSize == 1 || invalidChar == TRUE_1);
    if (string[stringSize-1] != '\n')
    {
        flushStdin();
    }
    else
    {
        string[stringSize-1] ='\0';
    }
}

void readStringOnlyLetters(char *message,char *string, int maxStringSize)
{
    int stringSize,index, invalidChar;
    char checker;
    do
    {
        invalidChar = FALSE_0;
        printf("        %s (apenas letras): ",message);
        fgets(string, maxStringSize, stdin);
        removeSpecificChar(string,' ');
        if(strcmp(string,"0")!=0)
        {
            removeSpecificChar(string,'0');
        }
        stringSize = strlen(string);
        if (stringSize == 1)
        {
            printf("        O campo nao pode ficar vazio!\n");
        }
        else
        {
            for (index=0; index<stringSize; index++)
            {
                checker = string[index];
                if (checker != '\n' && checker != ' ' && checker != '0' && (checker < 65 /*A*/ || checker > 90 /*Z*/) && (checker < 97 /*a*/ || checker > 122 /*z*/))
                {
                    invalidChar = TRUE_1;
                }
            }
            if (invalidChar == TRUE_1)
            {
                printf("        So sao permitidos caracteres simples (a-z),\n");
                printf("        (A-Z), Espacos e 0 para cancelar.\n");
            }
        }
    }
    while (stringSize == 1 || invalidChar == TRUE_1);
    if (string[stringSize-1] != '\n')
    {
        flushStdin();
    }
    else
    {
        string[stringSize-1] ='\0';
    }


}

void removeSpecificChar(char *stringToEdit,char charToRemove)
{

    int index, stringSize, stringOffset = 0;

    stringSize = strlen(stringToEdit);

    for (index=0; index<stringSize; index++)
    {

        if (stringToEdit[index] != charToRemove && stringToEdit[index + 1] != ' ')
        {

            stringToEdit[index-stringOffset] = stringToEdit[index];

            stringOffset--;
        }

        if (stringToEdit[index] != charToRemove && (stringToEdit[index + 1] == ' ' || stringToEdit[index + 1] == '\0'))
        {
            stringToEdit[index-stringOffset] = stringToEdit[index];
            index++;
            stringToEdit[index-stringOffset] = stringToEdit[index];
            stringOffset--;
        }
        stringOffset++;
    }
    stringToEdit[stringSize - stringOffset - 1] = '\0';
    if (stringToEdit[stringSize - stringOffset - 3] == ' ')
    {
        stringToEdit[stringSize - stringOffset - 2] = '\0';
        stringToEdit[stringSize - stringOffset - 3] = '\n';
    }

}

void numAvailableLaptops(int *result, LaptopType laptop[MAX_LAPTOPS],int totalLaptos)
{

    int index;
    *result = 0;

    for (index=0; index<totalLaptos; index++)
    {
        if (laptop[index].state == AVAILABLE)
        {
            (*result)++;
        }
    }

}

void numActiveRequests(int *result, RequestType *request,int totalRequests)
{

    int index;
    *result = 0;

    for (index=0; index<totalRequests; index++)
    {
        if (request[index].state == ACTIVE)
        {
            (*result)++;
        }
    }
}

void numCompletedRequests(int *result, RequestType *request,int totalRequests)
{

    int index;
    *result = 0;

    for (index=0; index<totalRequests; index++)
    {
        if (request[index].state == COMPLETED)
        {
            (*result)++;
        }
    }
}

void splitString(int splitPoint, char *enterStr, char firstReturnStr[MAX_SPLIT_STRING], char secondReturnStr[MAX_SPLIT_STRING])
{

    int sizeEnterStr, index, spacePos = 0;

    sizeEnterStr = strlen(enterStr);

    for (index = 0; index<sizeEnterStr; index++)
    {
        if (enterStr[index] == ' ' && index >= splitPoint - 2 && index <= splitPoint)
        {
            spacePos = index;
            index = sizeEnterStr;
        }
    }

    if (spacePos == 0)
    {
        for (index = 0; index<splitPoint; index++)
        {
            firstReturnStr[index] = enterStr[index];
        }
        for (index = splitPoint; index<sizeEnterStr; index++)
        {
            secondReturnStr[index - splitPoint] = enterStr[index];
        }
        firstReturnStr[splitPoint] = '\0';
        secondReturnStr[index - splitPoint] = '\0';
    }
    else
    {

        for (index = 0; index<spacePos; index++)
        {
            firstReturnStr[index] = enterStr[index];
        }
        spacePos++;
        for (index = spacePos; index<sizeEnterStr; index++)
        {
            secondReturnStr[index - spacePos] = enterStr[index];
        }
        secondReturnStr[index - spacePos] = '\0';
        spacePos--;
        firstReturnStr[spacePos] = '\0';

    }

}

void getNumOfDigits(int *result, int numToCountDigits)
{

    float index;
    *result = 0;

    do
    {
        index = numToCountDigits/10.0;
        numToCountDigits = numToCountDigits/10;
        (*result)++;
    }
    while((int)index > 0);
}

void toupperString(char *result, char *stringToUp)
{
    int index, stringSize;
    stringSize = strlen(stringToUp);
    for(index = 0; index<stringSize; index++)
    {
        result[index] = toupper(stringToUp[index]);
    }
}

void showStatistics(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,RequestType *request,int totalRequests)
{
    char tittle[14];

    strcpy(tittle,"MULTAS");

    printf("                ________________________________________\n");
    printf("               ");
    centerTittle(tittle,"\0",38);
    printf("               |                                        |\n");
    if(totalRequests > 0)
    {
        float avarageDelayFees;
        avarageFees(&avarageDelayFees,request,totalRequests);
        if((int)avarageDelayFees>0)
        {
            int higherDelayFee, lowerDelayFee;
            higherFee(&higherDelayFee,request,totalRequests);
            lowerFee(&lowerDelayFee,request,totalRequests);

            int lowerDigits, higherDigits, avarageDigits;
            getNumOfDigits(&lowerDigits,lowerDelayFee);
            getNumOfDigits(&higherDigits,higherDelayFee);
            getNumOfDigits(&avarageDigits,(int)avarageDelayFees);

            printf("               | O custo medio de cada multa paga       |\n");
            printf("               | foi %.2f euros.",avarageDelayFees);
            alignMargin(avarageDigits,24);
            printf("               | A maior multa foi de %d euros.",higherDelayFee);
            alignMargin(higherDigits,10);
            printf("               | A menor multa foi de %d euros.",lowerDelayFee);
            alignMargin(lowerDigits,10);
        }
        else
        {
            printf("               |       Ainda nao existem multas.        |\n");
        }
    }
    else
    {
        printf("               |     Ainda nao existem requisicoes.     |\n");
    }

    printf("               |________________________________________|\n\n");


    float percentageI3, percentageI5, percentageI7;
    percentageProcessor(&percentageI3,laptop,totalLaptops,INTEL_I3);
    percentageProcessor(&percentageI5,laptop,totalLaptops,INTEL_I5);
    percentageProcessor(&percentageI7,laptop,totalLaptops,INTEL_I7);

    int i3Digits, i5Digits, i7Digits;
    getNumOfDigits(&i3Digits,(int)percentageI3);
    getNumOfDigits(&i5Digits,(int)percentageI5);
    getNumOfDigits(&i7Digits,(int)percentageI7);

    strcpy(tittle,"PROCESSADORES");

    printf("             ______________________________________________\n");
    printf("            ");
    centerTittle(tittle,"\0",44);
    printf("            |                                              |\n");
    printf("            | Percentagem de processadores por portatil.   |\n");
    printf("            | ");
    drawPercentageBar(percentageI3);
    printf(" Intel Core i3");
    alignMargin(i3Digits,3);
    printf("            | ");
    drawPercentageBar(percentageI5);
    printf(" Intel Core i5");
    alignMargin(i5Digits,3);
    printf("            | ");
    drawPercentageBar(percentageI7);
    printf(" Intel Core i7");
    alignMargin(i7Digits,3);
    printf("            |______________________________________________|\n\n");


    strcpy(tittle,"UTENTES");
    printf("         _______________________________________________________\n");
    printf("        ");
    centerTittle(tittle,"\0",53);
    printf("        |                                                       |\n");
    if(totalRequests > 0)
    {
        float percentageStudent, percentageTeacher, percentageAdminTech;
        percentageApplicant(&percentageStudent,request,totalRequests,STUDENT);
        percentageApplicant(&percentageTeacher,request,totalRequests,TEACHER);
        percentageApplicant(&percentageAdminTech,request,totalRequests,ADMIN_TECH);

        int studentDigits, teacherDigits, adminTechDigits;
        getNumOfDigits(&studentDigits,(int)percentageStudent);
        getNumOfDigits(&teacherDigits,(int)percentageTeacher);
        getNumOfDigits(&adminTechDigits,(int)percentageAdminTech);

        int numOfSpaces = 0;

        printf("        | Percentagem de requisicoes por tipo de utente.        |\n");
        printf("        | ");
        drawPercentageBar(percentageStudent);
        printf(" Estudante");
        alignMargin(studentDigits,16);
        printf("        | ");
        drawPercentageBar(percentageTeacher);
        printf(" Docente");
        alignMargin(teacherDigits,18);
        printf("        | ");
        drawPercentageBar(percentageAdminTech);
        printf(" Tecnico Administrativo");
        alignMargin(adminTechDigits,3);

        printf("        |                                                       |\n");
        printf("        | Utente(s) com a menor quantidade de requisicoes:      |\n");
        printf("        | ");
        if((int)percentageStudent <= (int)percentageTeacher && (int)percentageStudent <= (int)percentageAdminTech)
        {
            printf("->Estudante ");
            numOfSpaces += 12;
        }
        if((int)percentageTeacher <= (int)percentageStudent && (int)percentageTeacher <= (int)percentageAdminTech)
        {
            printf("->Docente ");
            numOfSpaces += 10;
        }
        if((int)percentageAdminTech <= (int)percentageTeacher && (int)percentageAdminTech <= (int)percentageStudent)
        {
            printf("->Tecnico Administrativo ");
            numOfSpaces += 25;
        }
        alignMargin(numOfSpaces,53);
    }
    else
    {
        printf("        |            Ainda nao existem requisicoes.             |\n");
    }

    printf("        |_______________________________________________________|\n\n");

    strcpy(tittle,"DEVOLUCOES");

    printf("         ________________________________\n");
    printf("        ");
    centerTittle(tittle,"\0",30);
    printf("        |                                |\n");
    if(totalRequests > 0)
    {
        int completedRequests;
        numCompletedRequests(&completedRequests,request,totalRequests);
        if (completedRequests > 0)
        {


            if(completedRequests > 3)
            {
                completedRequests = 3;
            }


            if (completedRequests == 1)
            {
                printf("        | Devolucao mais recente:        |\n");
            }
            else
            {
                printf("        | Devolucoes mais recentes:      |\n");
            }

            printf("        | (mais recente primeiro)        |\n");
            showRecentCompletedRequests(completedRequests,request,totalRequests);
        }
        else
        {
            printf("        | Ainda nao existem devolucoes.  |\n");
        }
    }
    else
    {
        printf("        | Ainda nao existem requisicoes. |\n");
    }
    printf("        |________________________________|\n\n");
}

void showRecentCompletedRequests(int numOfRequests,RequestType *request, int totalRequests)
{
    int index;
    char extraNameText[23];
    for(index=totalRequests-1; index>=0; index--)
    {
        if(request[index].state==COMPLETED)
        {
            printf("        |                                |\n");
            printf("        | --------------[%d]------------- |\n",4-numOfRequests);
            strcpy(extraNameText,"Codigo da Requisicao: ");
            drawNameInfoWindow(extraNameText,request[index].code);
            strcpy(extraNameText,"Nome do Utente: ");
            drawNameInfoWindow(extraNameText,request[index].applicantName);
            drawRequestDurationInfoWindow(request[index].duration);
            drawRequestTotalDurationInfoWindow(request[index].durationTotal);
            numOfRequests--;
        }
        if(numOfRequests == 0)
        {
            index = -1;
        }
    }
}

void lowerFee(int *lower, RequestType *request,int totalRequests)
{
    int index;

    *lower = request[0].delayFee;

    for (index=0; index<totalRequests; index++)
    {
        if(request[index].delayFee < *lower && request[index].delayFee > 0 && request[index].state == COMPLETED)
        {
            *lower = request[index].delayFee;
        }
    }
}

void higherFee(int *higher, RequestType *request,int totalRequests)
{
    int index;

    *higher = request[0].delayFee;

    for (index=0; index<totalRequests; index++)
    {
        if(request[index].delayFee > *higher && request[index].state == COMPLETED)
        {
            *higher = request[index].delayFee;
        }
    }
}

void avarageFees(float *avarage,RequestType *request,int totalRequests)
{
    int index, feeCounter = 0, totalFee = 0;
    *avarage = 0;
    for (index=0; index<totalRequests; index++)
    {
        if(request[index].delayFee > 0 && request[index].state == COMPLETED)
        {
            feeCounter++;
            totalFee += request[index].delayFee;
        }
    }
    if(feeCounter != 0)
    {
        *avarage = (float)totalFee/feeCounter;
    }
}

void percentageApplicant(float *percentage,RequestType *request, int totalRequests,int applicantType)
{
    int index;
    *percentage = 0;
    for(index=0; index<totalRequests; index++)
    {
        if(request[index].applicantType == applicantType)
        {
            (*percentage)++;
        }
    }
    if(totalRequests != 0)
    {
        *percentage = (*percentage)*100/totalRequests;
    }
}

void percentageProcessor(float *percentage,LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int processor)
{
    int index;
    *percentage = 0;
    for(index=0; index<totalLaptops; index++)
    {
        if(laptop[index].processor == processor)
        {
            (*percentage)++;
        }
    }
    *percentage = (*percentage)*100/totalLaptops;
}

void storeInfoToFile(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests)
{
    if (totalLaptops == 0 && totalRequests == 0)
    {
        printf("         _________________________\n");
        printf("        |                         |\n");
        printf("        | Nao ha informacoes para |\n");
        printf("        | serem escritas.         |\n");
        printf("        |_________________________|\n\n");
    }
    else
    {
        FILE *infofile;
        int result, index;
        infofile = fopen("info.dat","wb");
        if (infofile == NULL)
        {
            printf("         _____________________\n");
            printf("        |                     |\n");
            printf("        | Erro ao abrir o     |\n");
            printf("        | ficheiro \"info.dat\" |\n");
            printf("        |_____________________|\n\n");
        }
        else
        {
            result = fwrite(&totalLaptops,sizeof(int),1,infofile);
            if (result !=0)
            {
                result = fwrite(laptop,sizeof(LaptopType),totalLaptops,infofile);
                if (result != 0)
                {

                    for (index = 0; index<totalLaptops; index++)
                    {
                        if(laptop[index].damagesCounterTotal > 0)
                        {
                            result = fwrite(laptop[index].damagesList,sizeof(DamageType),laptop[index].damagesCounterTotal,infofile);
                            if (result == 0)
                            {
                                index = totalLaptops;
                            }
                        }
                    }
                    if (result != 0)
                    {

                        result = fwrite(&totalRequests,sizeof(int),1,infofile);
                        if(result != 0)
                        {

                            result = fwrite(request,sizeof(RequestType),totalRequests,infofile);
                            if (result != 0 || totalRequests == 0)
                            {

                                printf("         _______________________\n");
                                printf("        |                       |\n");
                                printf("        | Todas as informacoes  |\n");
                                printf("        | foram escritas no     |\n");
                                printf("        | ficheiro com sucesso! |\n");
                                printf("        |_______________________|\n\n");

                            }
                            else
                            {
                                printf("         _______________________________\n");
                                printf("        |                               |\n");
                                printf("        | Erro ao escrever a informacao |\n");
                                printf("        | das requisicoes!              |\n");
                                printf("        |_______________________________|\n\n");

                            }


                        }
                        else
                        {
                            printf("         __________________________\n");
                            printf("        |                          |\n");
                            printf("        | Erro ao escrever o total |\n");
                            printf("        | de requisicoes!          |\n");
                            printf("        |__________________________|\n\n");

                        }

                    }
                    else
                    {
                        printf("         ______________________________\n");
                        printf("        |                              |\n");
                        printf("        | Erro ao escrever o historico |\n");
                        printf("        | de avaria(s) de algum(uns)   |\n");
                        printf("        | portatil(eis)!               |\n");
                        printf("        |______________________________|\n\n");


                    }

                }
                else
                {
                    printf("         _______________________________\n");
                    printf("        |                               |\n");
                    printf("        | Erro ao escrever a informacao |\n");
                    printf("        |  dos portateis!               |\n");
                    printf("        |_______________________________|\n");

                }

            }
            else
            {
                printf("         _____________________\n");
                printf("        |                     |\n");
                printf("        | Erro ao escrever o  |\n");
                printf("        | total de portateis! |\n");
                printf("        |_____________________|\n");

            }
            fclose(infofile);
        }

    }



}


RequestType *loadFileToInfo(LaptopType laptop[MAX_LAPTOPS],int *totalLaptops, RequestType *request, int *totalRequests)
{

    FILE *infofile;
    int result, index;

    printf(" __________________________________\n");
    printf("|                                  |\n");

    infofile = fopen("info.dat","rb");
    if (infofile == NULL)
    {
        printf("| Erro ao abrir o ficheiro         |\n");
        printf("| \"info.dat\"                       |\n");
        laptop = NULL;
        request = NULL;
    }
    else
    {
        result = fread(totalLaptops,sizeof(int),1,infofile);

        if (result !=0)
        {

            result = fread(laptop,sizeof(LaptopType),*totalLaptops,infofile);

            if (result != 0)
            {

                for (index = 0; index<*totalLaptops; index++)
                {
                    if(laptop[index].damagesCounterTotal > 0)
                    {
                        laptop[index].damagesList = malloc(laptop[index].damagesCounterTotal * sizeof(DamageType));
                        result = fread(laptop[index].damagesList,sizeof(DamageType),laptop[index].damagesCounterTotal,infofile);
                        if (result == 0)
                        {
                            index = *totalLaptops;
                        }
                    }
                }

                if (result != 0)
                {

                    result = fread(totalRequests,sizeof(int),1,infofile);

                    if (result != 0)
                    {

                        request = malloc((*totalRequests)*sizeof(RequestType));
                        if (request != NULL)
                        {
                            result = fread(request,sizeof(RequestType),*totalRequests,infofile);
                            if (result != 0 || *totalRequests == 0)
                            {
                                printf("| Todas as informacoes foram lidas |\n");
                                printf("| do ficheiro com sucesso!         |\n");
                            }
                            else
                            {
                                printf("| Erro ao ler a informacao das     |\n");
                                printf("| requisicoes!                     |\n");

                            }
                        }
                        else
                        {
                            printf("| Erro ao alocar memória para o    |\n");
                            printf("| vetor de requisicoes!            |\n");


                        }

                    }
                    else
                    {
                        printf("| Erro ao ler o total de           |\n");
                        printf("| requisicoes!                     |\n");

                    }

                }
                else
                {
                    printf("| Erro ao ler o historico de       |\n");
                    printf("| avaria(s) de algum(uns)          |\n");
                    printf("| portatil(eis)                    |\n");

                }



            }
            else
            {
                printf("| Erro ao ler a informacao dos     |\n");
                printf("| portateis!                       |\n");

            }


        }
        else
        {
            printf("| Erro ao ler o total de           |\n");
            printf("| portateis!                       |\n");

        }

        fclose(infofile);
    }

    printf("|__________________________________|\n\n");



    return request;
}


void writeApplicantTypeToFile(int numApplicantType, FILE *infofile)
{
    switch(numApplicantType)
    {
    case STUDENT:
        fprintf(infofile,"Estudante");
        break;
    case TEACHER:
        fprintf(infofile,"Docente");
        break;
    case ADMIN_TECH:
        fprintf(infofile,"Técnico Administrativo");
        break;
    }
}

void writeLocationToFile(int numLocation, FILE *infofile)
{
    switch(numLocation)
    {
    case RESIDENCES:
        fprintf(infofile,"Residências");
        break;
    case CAMPUS_1:
        fprintf(infofile,"Campus1");
        break;
    case CAMPUS_2:
        fprintf(infofile,"Campus2");
        break;
    case CAMPUS_3:
        fprintf(infofile,"Campus3");
        break;
    case CAMPUS_5:
        fprintf(infofile,"Campus5");
        break;
    }
}

//Log DATA

void storeLogData(LaptopType laptop[MAX_LAPTOPS], RequestType *request, int requestIndex)
{
    FILE *logfile;
    logfile = fopen("log.txt","a");
    if (logfile == NULL)
    {
        printf("         ____________________\n");
        printf("        |                    |\n");
        printf("        | Erro ao abrir o    |\n");
        printf("        | ficheiro \"log.txt\" |\n");
        printf("        |____________________|\n\n");
    }
    else
    {
        fprintf(logfile,"Código da Requisição: %s, ",request[requestIndex].code);

        fprintf(logfile,"Data da Requisicao: ");
        writeDateToFile(request[requestIndex].requestDate,logfile);
        fprintf(logfile,", ");

        fprintf(logfile,"Data da Devolução: ");
        writeDateToFile(request[requestIndex].returnDate,logfile);
        fprintf(logfile,", ");

        fprintf(logfile,"Utente: %s, ",request[requestIndex].applicantName);

        fprintf(logfile,"Tipo: ");
        writeApplicantTypeToFile(request[requestIndex].applicantType,logfile);
        fprintf(logfile,", ");

        fprintf(logfile,"Local de Devolução: ");
        writeLocationToFile(request[requestIndex].returnLocation,logfile);
        fprintf(logfile,", ");

        fprintf(logfile,"Prazo da Requisição: %d dia(s), ",request[requestIndex].duration);

        fprintf(logfile,"Tempo da Requisição: %d dia(s), ",request[requestIndex].durationTotal);

        if (request[requestIndex].delayFee > 0)
        {
            fprintf(logfile,"Multa: %d euro(s), ",request[requestIndex].delayFee);
        }
        else
        {
            fprintf(logfile,"Multa: Não houve multa pois foi entregue dentro do prazo, ");
        }

        fprintf(logfile,"Laptod ID#%d, ",laptop[request[requestIndex].laptopIndex].id);

        fprintf(logfile,"CPU: Intel Core i%d, ",laptop[request[requestIndex].laptopIndex].processor);

        fprintf(logfile,"RAM: %d GB.\n",laptop[request[requestIndex].laptopIndex].ram);
    }
    fclose(logfile);
}





