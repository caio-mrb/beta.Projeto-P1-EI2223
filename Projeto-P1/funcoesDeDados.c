#include "funcoesDeDados.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



void flushStdin(void)
{
    char trash;

    do
    {
        trash = getchar();
    }
    while (trash!='\n' && trash!=EOF);
}





void plusIfNegative(int numCompared, int *result)
{
    if (numCompared < 0)
    {
        (*result)++;
    }

}

void plusIfEqualZero(int numCompared, int *result)
{
    if (numCompared == 0)
    {
        (*result)++;
    }

}

void plusIfNULL(int *numCompared, int *result)
{
    if (numCompared == NULL)
    {
        (*result)++;
    }

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
            if (year >= 1000 && year <= 9999)
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
                    printf("        Mes invalido!\n");
                }

            }
            if ((year < 1900 || year > 3500) && control == 3)
            {
                printf("        Ano invalido!\n");
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
        printf("        %s: ",message);
        fgets(string, maxStringSize, stdin);
        removeExtraSpaces(string);
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
    if (string[stringSize-1] != '\n') // não foram armazenados no vetor todos os caracteres
    {
        flushStdin(); // elimina caracteres que ficaram no buffer stdin
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
        printf("        %s: ",message);
        fgets(string, maxStringSize, stdin);
        if(string[0] != '0')
        {
            removeExtraSpacesAndZeros(string);
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
    if (string[stringSize-1] != '\n') // não foram armazenados no vetor todos os caracteres
    {
        flushStdin(); // elimina caracteres que ficaram no buffer stdin
    }
    else
    {
        string[stringSize-1] ='\0';
    }


}

/*void removeExtraSpacesAndZeros(char string[MAX_NAME_CHAR], int stringSize)
{
    int index = 0, index2 = 0, wordsCounter = 0, *firstChar = NULL,fCharIndex=-1, *lastChar = NULL, lCharIndex=-1, posInString = 0;

    for (index = 0; index<stringSize; index++)
    {

        if ((string[index] != ' ' && string[index] != '0' && string[index] != '\0') && (index == 0 || (index > 0 && (string[index - 1] == ' ' || string[index - 1] == '0'))))  //first char
        {
            fCharIndex++;
            firstChar = realloc(firstChar,(fCharIndex + 1)*sizeof(int));
            firstChar[fCharIndex] = index;

        }

        if (string[index] != ' ' && string[index] != '0' && (string[index + 1] == ' ' || string[index + 1] == '0' || string[index + 1] == '\0') && index<stringSize-1)  //lastchar
        {
            lCharIndex++;
            lastChar = realloc(lastChar,(lCharIndex + 1)*sizeof(int));
            lastChar[lCharIndex] = index;
        }
    }

    for (index = 0; index<=fCharIndex;index++){

        for (index2 = 0; index2<(lastChar[index]-firstChar[index]+1);index2++){
            string[index2 + posInString] = string[index2+firstChar[index]];
        }
        string[index2 + posInString] = '@';
        posInString += index2 + 1;
    }
    stringSize = 0;

    for (index = 0; index<=fCharIndex;index++){
        stringSize += lastChar[index]-firstChar[index]+1;
    }
    stringSize += fCharIndex+1;
    string[stringSize - 1] = '\0';

    free(firstChar);
    free(lastChar);
}*/

void removeExtraSpaces(char *string)
{

    int index, stringSize, stringOffset = 0;

    stringSize = strlen(string) + 1;

    for (index=0; index<stringSize; index++)
    {

        if (string[index] != ' ' && string[index + 1] != ' ')
        {

            string[index-stringOffset] = string[index];

            stringOffset--;
        }

        if (string[index] != ' ' && (string[index + 1] == ' ' || string[index + 1] == '\0'))
        {

            string[index-stringOffset] = string[index];
            index++;
            string[index-stringOffset] = string[index];
            stringOffset--;

        }

        stringOffset++;
    }

    string[stringSize - stringOffset - 2] = '\0';
    stringSize = strlen(string) + 1;

}


void removeExtraSpacesAndZeros(char *string)
{

    int index, stringSize, stringOffset = 0;

    stringSize = strlen(string) + 1;

    for (index=0; index<stringSize; index++)
    {

        if (string[index] != ' ' && string[index] != '0' && string[index + 1] != ' ')
        {

            string[index-stringOffset] = string[index];

            stringOffset--;
        }

        if (string[index] != ' ' && string[index] != '0' && (string[index + 1] == ' ' || string[index + 1] == '\0'))
        {

            string[index-stringOffset] = string[index];
            index++;
            string[index-stringOffset] = string[index];
            stringOffset--;

        }

        stringOffset++;
    }

    string[stringSize - stringOffset - 2] = '\0';
    stringSize = strlen(string) + 1;

}



void getApplicantTypeName(int typeNum, char stringApplicantType[MAX_NAME_APPLICANT_TYPE])
{

    if (typeNum == STUDENT)
    {
        strcpy(stringApplicantType,"Estudante");
    }
    if (typeNum == TEACHER)
    {
        strcpy(stringApplicantType,"Docente");
    }
    if (typeNum == ADMIN_TECH)
    {
        strcpy(stringApplicantType,"Técnico Administrativo");
    }

}

void getLocationName(int locationNum, char stringLocation[MAX_NAME_LOCATION])
{
    if (locationNum == RESIDENCES)
    {
        strcpy(stringLocation,"Residencias");
    }
    if (locationNum == CAMPUS_1)
    {
        strcpy(stringLocation,"Campus1");
    }
    if (locationNum == CAMPUS_2)
    {
        strcpy(stringLocation,"Campus2");
    }
    if (locationNum == CAMPUS_3)
    {
        strcpy(stringLocation,"Campus3");
    }
    if (locationNum == CAMPUS_5)
    {
        strcpy(stringLocation,"Campus5");
    }

}

void getRequestStateName(int stateNum, char stringRequestState[MAX_NAME_REQUEST_STATE])
{

    if (stateNum == ACTIVE)
    {
        strcpy(stringRequestState,"Ativa");
    }
    if (stateNum == COMPLETED)
    {
        strcpy(stringRequestState,"Concluída");
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
        if (request[index].state == AVAILABLE)
        {
            (*result)++;
        }
    }

}

void splitString(int splitPoint, char *enterStr, char firstReturnStr[MAX_SPLIT_STRING], char secondReturnStr[MAX_SPLIT_STRING])
{

    int sizeEnterStr, index, spacePos = 0;

    sizeEnterStr = strlen(enterStr);

    //printf("\nSize: %d\n\n",sizeEnterStr);

    for (index = 0; index<sizeEnterStr; index++)
    {
        if (enterStr[index] == ' ' && index >= splitPoint - 4)
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
            printf("         __________________\n");
            printf("        |                  |\n");
            printf("        | Erro ao abrir o  |\n");
            printf("        | ficheiro!        |\n");
            printf("        |__________________|\n\n");
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
                            if (result != 0)
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
                            if (result != 0)
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





//Log DATA

/*void storeLogData(LogType *log,int totalLogs,int wroteCorrect[MAX_LOAD_INFO])
{
    int index, checkLine, checkTotal;
    char stringApplicantType[MAX_NAME_APPLICANT_TYPE], stringRequestState[MAX_NAME_REQUEST_STATE];
    FILE *logfile;
    logfile = fopen("log.txt","a");
    if (logfile == NULL)
    {
        wroteCorrect[0] = 0; //Coloca 0 em wroteCorrect[0] caso não tenha conseguido abrir o ficheiro
    }
    else
    {
        wroteCorrect[0] = 1; //Coloca 1 em wroteCorrect[0] caso tenha conseguido abrir o ficheiro

        wroteCorrect[1] = fprintf(logfile,"%d\n", totalLogs); //Coloca em wroteCorrect[1] o número de inteiros escritos com sucesso

        for (index=0; index<totalLogs; index++)
        {
            checkLine = 0;
            checkTotal = 0;

            checkLine = fprintf(logfile,"[%d/%d/%d]",log->todayDate.day,log->todayDate.month,log->todayDate.year);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Código de Requisição: %s, ",log->request.code); //Coloca um valor negativo em checkLine se não conseguir escrever com sucesso
            plusIfNegative(checkLine,&checkTotal); //Se checkLine < 0 então adiciona um em checkTotal

            checkLine = fprintf(logfile,"Requerente: %s, ",log->request.applicantName);
            plusIfNegative(checkLine,&checkTotal);

            getApplicantTypeName(log->request.applicantType,stringApplicantType);

            checkLine = fprintf(logfile,"Tipo: %s, ",stringApplicantType);
            plusIfNegative(checkLine,&checkTotal);

            getRequestStateName(log->request.state,stringRequestState);

            checkLine = fprintf(logfile,"Estado da Requisição: %s, ",stringRequestState);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Laptod ID#%d, ",log->request.laptop.id);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"CPU: %d, ",log->request.laptop.processor);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"RAM: %d, ",log->request.laptop.ram);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Preço: %.2f, ",log->request.laptop.price);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Data da Requisição: %d/%d/%d, ",log->request.requestDate.day,log->request.requestDate.month,log->request.requestDate.year);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Local da Requisição: %d, ",log->request.renewLocation);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Tempo de Requisição: %d dias, ",log->request.requestPeriod);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Data da Devolução: %d/%d/%d, ",log->request.renewDate.day,log->request.renewDate.month,log->request.renewDate.year);
            plusIfNegative(checkLine,&checkTotal);

            checkLine = fprintf(logfile,"Taxa de Atraso: %d\n",log->request.delayFee);
            plusIfNegative(checkLine,&checkTotal);


            if (checkTotal == 0)
            {
                wroteCorrect[2]++; //Se houver algum erro na escrita, então não adciona um em wroteCorrect[2] para verficar quantos RequestType's foram escritos com sucesso
            }
        }
        wroteCorrect[3] = fclose(logfile);  //Coloca 0 em wroteCorrect[3] se conseguir fechar o ficheiro
        wroteCorrect[3]++; //Adiciona 1 ao valor em wroteCorrect[3] para ser diferente do valor de inicialização e poder ser feita a verificação futuramente
    }
}*/





