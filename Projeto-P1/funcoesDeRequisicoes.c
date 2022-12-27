#include "funcoesDeRequisicoes.h"

#include "funcoesDeDados.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchEqualReqCode(int *equalIndex, RequestType *request,int totalRequests, char *codeToComp)
{

    int index;
    char stringUppercase[MAX_CODE_CHAR] = {'\0'}, codeUppercase[MAX_CODE_CHAR] = {'\0'};
    *equalIndex = -1;
    for (index=0; index<totalRequests; index++)
    {
        toupperString(stringUppercase,request[index].code);
        toupperString(codeUppercase,codeToComp);
        if (strcmp(stringUppercase,codeUppercase) == 0)
        {
            *equalIndex = index;

            index = totalRequests;
        }
    }
}

void searchRequestIndex(int *equalIndex, RequestType *request,int totalRequests, int laptopIndex)
{
    int index;
    *equalIndex = -1;
    for (index=totalRequests-1; index>=0; index--)
    {
        if (request[index].laptopIndex == laptopIndex)
        {

            *equalIndex = index;

            index = 0;
        }
    }
}

void showRequestInfo(LaptopType laptop[MAX_LAPTOPS], RequestType *request, int requestIndex)
{
    char extraTittleText[9] = "Codigo: ",extraRequestNameText[17] = "Nome do Utente: ", extraLaptopNameText[19] = "Nome do Portatil: ";

    printf("         ________________________________\n");
    printf("        ");
    centerTittle(extraTittleText,request[requestIndex].code,MAX_SPACES_INFO_WINDOW);
    printf("        |                                |\n");
    drawNameInfoWindow(extraRequestNameText,request[requestIndex].applicantName);
    drawRequestApplicantTypeInfoWindow(request[requestIndex].applicantType);
    printf("        |                                |\n");
    drawRequestStateInfoWindow(request[requestIndex].state);
    if (request[requestIndex].state != ACTIVE)
    {
        drawRequestLocationInfoWindow(request[requestIndex].returnLocation);
        drawRequestDurationInfoWindow(request[requestIndex].duration);
        drawRequestTotalDurationInfoWindow(request[requestIndex].durationTotal);
        drawRequestDelayFeeInfoWindow(request[requestIndex].delayFee);
    }
    printf("        |                                |\n");
    printf("        | ---->Portatil Requisitado<---- |\n");
    drawRequestLaptopIdInfoWindow(laptop[request[requestIndex].laptopIndex].id);
    drawNameInfoWindow(extraLaptopNameText,laptop[request[requestIndex].laptopIndex].name);
    drawLaptopStateInfoWindow(laptop[request[requestIndex].laptopIndex].state);
    drawLaptopDaysRequested(laptop[request[requestIndex].laptopIndex].daysRequestedCounter);
    printf("        |________________________________|\n\n");


}

void registerRenewByLaptopId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfRenews, int *cancel)
{
    int renewDays, laptopIndex, requestIndex;
    char message[MAX_READ_MESSAGE_SIZE] = "Dias para extender a requisicao";

    drawRenewInfoAsk(index,numOfRenews);

    readReturnLaptopId(&laptopIndex, laptop, totalLaptops, cancel);

    if (*cancel == FALSE_0)
    {
        searchRequestIndex(&requestIndex,request,totalRequests,laptopIndex);
        readInt(message,&renewDays,0,7);
    }
    if (renewDays == 0)
    {
        *cancel = TRUE_1;
    }
    else
    {
        request[requestIndex].duration += renewDays;
        laptop[laptopIndex].daysRequestedCounter += renewDays;
    }
    if (*cancel == FALSE_0)
    {
        storeInfoToFile(laptop, totalLaptops,request,totalRequests);
    }
}

void registerRenewByRequestCode(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfRenews, int *cancel)
{
    int renewDays, requestIndex;
    char message[MAX_READ_MESSAGE_SIZE] = "Dias para extender a requisicao";

    drawRenewInfoAsk(index,numOfRenews);

    readReturnRequestCode(&requestIndex,request, totalRequests, cancel);

    if (*cancel == FALSE_0)
    {
        readInt(message,&renewDays,0,7);
    }
    if (renewDays == 0)
    {
        *cancel = TRUE_1;
    }
    else
    {
        request[requestIndex].duration += renewDays;
        laptop[request[requestIndex].laptopIndex].daysRequestedCounter += renewDays;
    }
    if (*cancel == FALSE_0)
    {
        storeInfoToFile(laptop, totalLaptops,request,totalRequests);
    }
}

void registerReturnByDamageMenu(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests, int laptopIndex, int *cancel)
{
    int requestIndex;

    searchRequestIndex(&requestIndex,request,totalRequests,laptopIndex);
    if (*cancel == FALSE_0)
    {
        drawLocationsMiniList();
    }
    readLapLocation(laptop,laptopIndex,cancel);
    if (*cancel == FALSE_0)
    {
        request[requestIndex].returnLocation = laptop[laptopIndex].location;
    }
    readReturnDate(&request[requestIndex].durationTotal,request,requestIndex, cancel);
    if (*cancel == FALSE_0)
    {
        if (request[requestIndex].durationTotal > request[requestIndex].duration)
        {
            request[requestIndex].delayFee = (request[requestIndex].durationTotal - request[requestIndex].duration) * 10;
            drawReturnDelayFeeAlert(request[requestIndex].delayFee);
            //Desenha a margem a esquerda
            printf("        ");
            //Aguarda o input do utilizador para dar seguimento ao programa
            enterToContinue();
        }
        else
        {
            request[requestIndex].delayFee = 0;
        }
        request[requestIndex].state = COMPLETED;
        laptop[laptopIndex].state = AVAILABLE;
        laptop[laptopIndex].daysRequestedCounter += (request[requestIndex].durationTotal - request[requestIndex].duration);
        storeLogData(laptop,request,requestIndex);
        storeInfoToFile(laptop, totalLaptops,request,totalRequests);
    }
}

void registerReturnByRequestCode(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfReturns, int *cancel)
{
    int requestIndex;

    drawReturnInfoAsk(index, numOfReturns);

    readReturnRequestCode(&requestIndex,request, totalRequests, cancel);
    if (*cancel == FALSE_0)
    {
        drawLocationsMiniList();
    }
    readLapLocation(laptop,request[requestIndex].laptopIndex,cancel);
    if (*cancel == FALSE_0)
    {
        request[requestIndex].returnLocation = laptop[request[requestIndex].laptopIndex].location;
    }
    readReturnDate(&request[requestIndex].durationTotal,request,requestIndex, cancel);
    if (*cancel == FALSE_0)
    {
        if (request[requestIndex].durationTotal > request[requestIndex].duration)
        {
            request[requestIndex].delayFee = (request[requestIndex].durationTotal - request[requestIndex].duration) * 10;
            drawReturnDelayFeeAlert(request[requestIndex].delayFee);
            //Desenha a margem a esquerda
            printf("        ");
            //Aguarda o input do utilizador para dar seguimento ao programa
            enterToContinue();
        }
        else
        {
            request[requestIndex].delayFee = 0;
        }
        request[requestIndex].state = COMPLETED;
        laptop[request[requestIndex].laptopIndex].state = AVAILABLE;
        laptop[request[requestIndex].laptopIndex].daysRequestedCounter += (request[requestIndex].durationTotal - request[requestIndex].duration);
        storeLogData(laptop,request,requestIndex);
        storeInfoToFile(laptop,totalLaptops,request,totalRequests);
    }

}

void registerReturnByLaptopId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops, RequestType *request, int totalRequests,int index,int numOfReturns, int *cancel)
{
    int laptopIndex, requestIndex;

    drawReturnInfoAsk(index,numOfReturns);

    readReturnLaptopId(&laptopIndex, laptop, totalLaptops, cancel);

    if (*cancel == FALSE_0)
    {
        searchRequestIndex(&requestIndex,request,totalRequests,laptopIndex);
        drawLocationsMiniList();
    }
    readLapLocation(laptop,laptopIndex,cancel);
    if (*cancel == FALSE_0)
    {
        request[requestIndex].returnLocation = laptop[laptopIndex].location;
    }
    readReturnDate(&request[requestIndex].durationTotal,request,requestIndex,cancel);
    if (*cancel == FALSE_0)
    {
        if (request[requestIndex].durationTotal > request[requestIndex].duration)
        {
            request[requestIndex].delayFee = (request[requestIndex].durationTotal - request[requestIndex].duration) * 10;
            drawReturnDelayFeeAlert(request[requestIndex].delayFee);
            //Desenha a margem a esquerda
            printf("        ");
            //Aguarda o input do utilizador para dar seguimento ao programa
            enterToContinue();
        }
        else
        {
            request[requestIndex].delayFee = 0;
        }
        request[requestIndex].state = COMPLETED;
        laptop[laptopIndex].state = AVAILABLE;
        laptop[laptopIndex].daysRequestedCounter += (request[requestIndex].durationTotal - request[requestIndex].duration);

        storeLogData(laptop,request,requestIndex);
        storeInfoToFile(laptop, totalLaptops,request,totalRequests);
    }
}

void readReturnDate(int *returnDays,RequestType *request, int requestIndex, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Data da devolucao";
        do
        {
            readDate(message,&request[requestIndex].returnDate);
            if (request[requestIndex].returnDate.day == 0)
            {
                *cancel = TRUE_1;
            }
            else
            {
                numOfDaysBetweenDates(returnDays,request[requestIndex].requestDate,request[requestIndex].returnDate);

                if (*returnDays < 0)
                {
                    printf("         __________________________________________\n");
                    printf("        | A data de devolucao nao pode ser         |\n");
                    printf("        | inferior a data de requisicao.           |\n");
                    printf("        | Este portatil foi requisitado            |\n");
                    printf("        |_no dia ");
                    showDate(request[requestIndex].requestDate);
                    printf("________________________|\n\n");
                }
            }

        }
        while (*returnDays < 0 && *cancel == FALSE_0);
    }

}

void readReturnRequestCode(int *requestIndex,RequestType *request, int totalRequests,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char requestCode[MAX_CODE_CHAR],message[MAX_READ_MESSAGE_SIZE] = "Codigo da requisicao";
        do
        {
            readString(message,requestCode,MAX_CODE_CHAR);
            if(strcmp(requestCode,"0")!=0)
            {
                searchEqualReqCode(requestIndex,request,totalRequests,requestCode);
                if (*requestIndex > -1)
                {
                    if(request[*requestIndex].state != ACTIVE)
                    {
                        printf("        A requisicao ja foi concluida!\n");
                        *requestIndex = -1;
                    }
                }
                else
                {
                    printf("        Nao existe am requisicao com este codigo!\n");
                }
            }
            else
            {
                *cancel = TRUE_1;
            }
        }
        while(*requestIndex == -1 && *cancel == FALSE_0);
    }
}

void readReturnLaptopId(int *laptopIndex, LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{

    if(*cancel == FALSE_0)
    {
        int laptopId, laptopState = AVAILABLE;
        char message[MAX_READ_MESSAGE_SIZE] = "Id do portatil";

        do
        {
            readInt(message,&laptopId,0,MAX_ID);
            if (laptopId > 0)
            {
                searchEqualLapId(laptopIndex,laptop,totalLaptops,laptopId);
                if (*laptopIndex > -1)
                {
                    if (laptop[*laptopIndex].state != REQUESTED)
                    {
                        printf("        Este portatil nao esta requisitado!\n");
                    }
                    else
                    {
                        laptopState = laptop[*laptopIndex].state;
                    }
                }
                else
                {
                    printf("        Nao existe um portatil com este ID!\n");
                }

            }
            else
            {
                *cancel = TRUE_1;
            }
        }
        while((*laptopIndex == -1 || laptopState != REQUESTED) && *cancel == FALSE_0);
    }

}



RequestType *registerNewRequest(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,RequestType *request, int *totalRequests,int index,int numOfRequests, int *cancel)
{
    RequestType *backupPointer, requestInfo;

    backupPointer = request;

    request = realloc(request, ((*totalRequests) + 1)*sizeof(RequestType));
    if (request == NULL)
    {
        printf("         ______________________________________________\n");
        printf("        |_REQUISICOES/DEVOLUCOES___________________(X)_|\n");
        printf("        |                                              |\n");
        printf("        | Nao sera possivel registar novas requisicoes |\n");
        printf("        |______________________________________________|\n\n");
        request = backupPointer;
        *cancel = TRUE_1;
    }
    else
    {
        drawRequestInfoAsk(index,numOfRequests);
        readRequestCode(&requestInfo,request,*totalRequests,cancel);
        readRequestLaptopId(&requestInfo,laptop,totalLaptops,cancel);
        drawLaptopSelectedInfo(requestInfo.laptopIndex,laptop);
        readRequestApplicantName(&requestInfo,cancel);
        readRequestApplicantType(&requestInfo,cancel);
        readRequestDate(&requestInfo,laptop,cancel);
        readRequestRequestDuration(&requestInfo,cancel);

        if (*cancel == FALSE_0)
        {
            requestInfo.state = ACTIVE;
            laptop[requestInfo.laptopIndex].state = REQUESTED;
            laptop[requestInfo.laptopIndex].requestsCounter++;
            laptop[requestInfo.laptopIndex].daysRequestedCounter += requestInfo.duration;

            request[*totalRequests] = requestInfo;
            (*totalRequests)++;
            storeInfoToFile(laptop,totalLaptops,request,*totalRequests);
        }
    }
    return request;
}

void readRequestDate(RequestType *newRequestInfo,LaptopType laptop[MAX_LAPTOPS],int *cancel)
{
    int daysBetweenRequestAndPurchaseDate;

    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Data da requisicao";
        do
        {
            readDate(message,&newRequestInfo->requestDate);
            if (newRequestInfo->requestDate.day == 0)
            {
                *cancel = TRUE_1;
            }
            else
            {
                numOfDaysBetweenDates(&daysBetweenRequestAndPurchaseDate,laptop[newRequestInfo->laptopIndex].purchaseDate,newRequestInfo->requestDate);
                if (daysBetweenRequestAndPurchaseDate < 0)
                {
                    printf("         ___________________________\n");
                    printf("        | A data da requisicao nao  |\n");
                    printf("        | pode ser inferior a data  |\n");
                    printf("        | de compra po portatil.    |\n");
                    printf("        | O portatil em questao foi |\n");
                    printf("        | comprado dia ");
                    showDate(laptop[newRequestInfo->laptopIndex].purchaseDate);
                    printf("___|\n\n");
                }
            }
        }
        while(daysBetweenRequestAndPurchaseDate < 0 && *cancel == FALSE_0);
    }
}

void readRequestCode(RequestType *newRequestInfo,RequestType *request,int totalRequests,int *cancel)
{

    if(*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Codigo da requisicao";
        int equalIndex;
        do
        {
            readString(message,newRequestInfo->code,MAX_CODE_CHAR);

            if(strcmp(request[totalRequests].code,"0") == 0)
            {
                *cancel = TRUE_1;
            }
            else
            {
                searchEqualReqCode(&equalIndex,request,totalRequests,newRequestInfo->code);
                if(equalIndex != -1)
                {
                    printf("        Ja existe uma requisicao com este codigo!\n");
                }
            }
        }
        while(equalIndex != -1 && *cancel == FALSE_0);
    }
}

void readRequestCodeShowInfo(int *requestIndex,RequestType *request,int totalRequests, int *cancel)
{
    char code[MAX_CODE_CHAR],message[MAX_READ_MESSAGE_SIZE] = "Codigo da requisicao";
    do
    {
        readString(message,code,MAX_CODE_CHAR);
        if(strcmp(code,"0")==0)
        {
            *cancel = TRUE_1;
        }
        else
        {
            searchEqualReqCode(requestIndex,request,totalRequests,code);
            if(*requestIndex == -1)
            {
                printf("        Nao existe uma requisicao com este codigo!\n");
            }
        }
    }
    while(*requestIndex == -1 && *cancel == FALSE_0);
}


void readRequestLaptopId(RequestType *newRequestInfo,LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Id do portatil a requisitar";
        int equalLaptopIndex, laptopId, laptopState = REQUESTED;

        do
        {
            readInt(message,&laptopId,0,MAX_ID);
            if(laptopId == 0)
            {
                *cancel = TRUE_1;
            }
            else
            {
                searchEqualLapId(&equalLaptopIndex,laptop,totalLaptops,laptopId);
                if(equalLaptopIndex == -1)
                {
                    printf("        Nao existe um portatil com este ID!\n");
                }
                else
                {
                    switch(laptop[equalLaptopIndex].state)
                    {
                    case AVAILABLE:
                        laptopState = laptop[equalLaptopIndex].state;
                        newRequestInfo->laptopIndex = equalLaptopIndex;
                        break;
                    case REQUESTED:
                        printf("        Este portatil ja esta requisitado!\n");
                        break;
                    case BROKEN_PERMANENT:
                    case BROKEN_TEMPORARY:
                        printf("        Este portatil esta avariado!\n");
                        break;
                    }
                }
            }
        }
        while((equalLaptopIndex == -1 || laptopState == REQUESTED) && *cancel == FALSE_0);
    }
}

void readRequestApplicantName(RequestType *newRequestInfo,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Nome do utente";

        readStringOnlyLetters(message,newRequestInfo->applicantName,MAX_NAME_CHAR);
        if (strcmp(newRequestInfo->applicantName,"0") == 0)
        {
            *cancel = TRUE_1;
        }
    }
}

void readRequestApplicantType(RequestType *newRequestInfo,int *cancel)
{

    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Tipo do utente",option[MAX_OPTION_CHAR];
        int validValue = FALSE_0;

        printf("         _____________________________\n");
        printf("        | ES - Estudante              |\n");
        printf("        | DO - Docente                |\n");
        printf("        |_TA - Tecnico Administatrivo_|\n\n");

        do
        {
            readStringOnlyLetters(message,option,MAX_OPTION_CHAR);

            toupperString(option,option);

            if (strcmp(option,"ES") == 0)
            {
                newRequestInfo->applicantType = STUDENT;

                validValue = TRUE_1;
            }
            if (strcmp(option,"DO") == 0)
            {

                newRequestInfo->applicantType = TEACHER;

                validValue = TRUE_1;
            }
            if (strcmp(option,"TA") == 0)
            {

                newRequestInfo->applicantType = ADMIN_TECH;

                validValue = TRUE_1;
            }

            if (strcmp(option,"0") == 0)
            {
                *cancel = TRUE_1;
            }

            if (validValue != TRUE_1 && *cancel != TRUE_1)
            {

                printf("        Selecione uma das opcoes acima ou digite 0 para cancelar.\n");
            }

        }
        while(validValue != TRUE_1 && *cancel != TRUE_1);
    }
}

void readRequestRequestDuration(RequestType *newRequestInfo,int *cancel)
{

    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE] = "Duracao da requisicao em dias";

        readInt(message,&newRequestInfo->duration,0,30);
        if (newRequestInfo->duration == 0)
        {
            *cancel = TRUE_1;
        }
    }
}
