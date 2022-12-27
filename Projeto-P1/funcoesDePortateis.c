#include "funcoesDePortateis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoesDeDados.h"
#include "funcoesDeDesign.h"



void searchEqualLapId(int *equalIndex, LaptopType laptop[MAX_LAPTOPS],int totalLaptops, int numToComp)
{

    int index;
    *equalIndex = -1;
    for (index=0; index<totalLaptops; index++)
    {
        if (laptop[index].id == numToComp)
        {
            *equalIndex = index;

            index = totalLaptops;
        }
    }

}

void readLapId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {

        int equalIndex, num = 0;
        char message[MAX_READ_MESSAGE_SIZE];

        do
        {
            strcpy(message,"ID do Portatil");
            readInt(message, &laptop[totalLaptops].id,0, MAX_ID);

            if (laptop[totalLaptops].id == 0)
            {
                *cancel = TRUE_1;
            }
            else
            {

                searchEqualLapId(&equalIndex,laptop,totalLaptops,laptop[totalLaptops].id);
                if (equalIndex > -1)
                {
                    printf("        Ja existe um portatil com este ID.\n");
                    do
                    {
                        if (laptop[totalLaptops].id + num == MAX_ID)
                        {
                            num = 0 - laptop[totalLaptops].id;
                        }
                        num++;
                        searchEqualLapId(&equalIndex,laptop,totalLaptops,laptop[totalLaptops].id + num);
                    }
                    while(equalIndex > -1);
                    printf("        Porem o ID %d esta disponivel.\n", laptop[totalLaptops].id + num);
                    equalIndex = 0;
                    num = 0;
                }

            }
        }
        while (equalIndex != -1 && *cancel != TRUE_1);

    }
}

void readLapName(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        strcpy(message,"Nome do Portatil");
        readString(message,laptop[totalLaptops].name,MAX_NAME_CHAR);

        if (laptop[totalLaptops].name[0] == '0')
        {
            *cancel = TRUE_1;
        }
    }
}

void readLapProcessor(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {

        char message[MAX_READ_MESSAGE_SIZE],option[MAX_OPTION_CHAR];
        int validValue;

        strcpy(message,"Processador (0, i3, i5, i7)");

        do
        {
            readString(message,option,MAX_OPTION_CHAR);

            option[0] = toupper(option[0]);


            if (strcmp(option,"I3")==0)
            {

                laptop[totalLaptops].processor = INTEL_I3;

                validValue = TRUE_1;
            }
            if (strcmp(option,"I5")==0)
            {

                laptop[totalLaptops].processor = INTEL_I5;

                validValue = TRUE_1;
            }
            if (strcmp(option,"I7")==0)
            {

                laptop[totalLaptops].processor = INTEL_I7;

                validValue = TRUE_1;
            }

            if (strcmp(option,"0")==0)
            {
                *cancel = TRUE_1;
            }

            if (validValue != TRUE_1 && *cancel != TRUE_1)
            {

                printf("        Escreva como nos parenteses ou digite 0 para cancelar.\n");
            }
        }
        while(validValue != TRUE_1 && *cancel != TRUE_1);

    }
}

void readLapRam(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        strcpy(message,"Memoria RAM");
        readInt(message, &laptop[totalLaptops].ram,0, 512);

        if (laptop[totalLaptops].ram == 0)
        {
            *cancel = TRUE_1;
        }
    }
}

void readLapPrice(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        strcpy(message,"Valor em euros");
        readFloat(message, &laptop[totalLaptops].price,0.0, 99999.0);

        if ((int)(laptop[totalLaptops].price*100) == 0)
        {
            *cancel = TRUE_1;
        }
    }
}

void readLapLocation(LaptopType laptop[MAX_LAPTOPS],int laptopIndex,int *cancel)
{

    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE],option[MAX_OPTION_CHAR];

        int validValue = FALSE_0;


        strcpy(message,"Localizacao");

        do
        {
            readString(message,option,MAX_OPTION_CHAR);

            toupperString(option,option);

            if (strcmp(option,"RE")==0)
            {
                laptop[laptopIndex].location = RESIDENCES;

                validValue = TRUE_1;
            }
            if (strcmp(option,"C1")==0)
            {

                laptop[laptopIndex].location = CAMPUS_1;

                validValue = TRUE_1;
            }
            if (strcmp(option,"C2")==0)
            {

                laptop[laptopIndex].location = CAMPUS_2;

                validValue = TRUE_1;
            }
            if (strcmp(option,"C3")==0)
            {

                laptop[laptopIndex].location = CAMPUS_3;

                validValue = TRUE_1;
            }
            if (strcmp(option,"C5")==0)
            {

                laptop[laptopIndex].location = CAMPUS_5;

                validValue = TRUE_1;
            }

            if (strcmp(option,"0")==0)
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

void readLapPurchaseDate(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        strcpy(message,"Data de compra");
        readDate(message, &laptop[totalLaptops].purchaseDate);

        if (laptop[totalLaptops].purchaseDate.day == 0)
        {
            *cancel = TRUE_1;
        }
    }
}

void readDamageInfoCode(int index, int numOfDamages, DamageType *damageInfo, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];
        int indexDigits,numOfDamagesDigits;
        getNumOfDigits(&indexDigits,index);
        getNumOfDigits(&numOfDamagesDigits,numOfDamages);

        printf("         _________________________________________\n");
        printf("        |_PORTATEIS___________________________(X)_|\n");
        printf("        |                                         |\n");
        printf("        | Estas a registar a avaria %d de %d",index+1,numOfDamages);
        alignMargin(indexDigits+numOfDamagesDigits,9);
        printf("        | Selecione em que sitio foi a avaria:    |\n");
        printf("        | 01 - Ecra                               |\n");
        printf("        | 02 - Teclado                            |\n");
        printf("        | 03 - Teclado Numerico                   |\n");
        printf("        | 04 - Bateria                            |\n");
        printf("        | 05 - Porta USB                          |\n");
        printf("        | 06 - Entrada de Audio                   |\n");
        printf("        | 07 - Receptor WI-FI                     |\n");
        printf("        | 08 - Porta de Ethernet                  |\n");
        printf("        | 09 - Placa Mae                          |\n");
        printf("        | 10 - Placa Grafica                      |\n");
        printf("        | 11 - Processador                        |\n");
        printf("        | 12 - Memoria RAM                        |\n");
        printf("        | 13 - Cancelar                           |\n");
        printf("        |_________________________________________|\n\n");

        strcpy(message,"Selecione uma opcao");
        readInt(message,&(damageInfo->code),1,13);

        if (damageInfo->code == 13)
        {
            *cancel = TRUE_1;
        }
    }
}

void readDamageInfoType(int index, int numOfDamages, DamageType *damageInfo, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        int indexDigits,numOfDamagesDigits;
        getNumOfDigits(&indexDigits,index);
        getNumOfDigits(&numOfDamagesDigits,numOfDamages);

        printf("         ___________________________________________\n");
        printf("        |_PORTATEIS_____________________________(X)_|\n");
        printf("        |                                           |\n");
        printf("        | Obs: Avarias permanentes sao irreparaveis |\n");
        printf("        | o que torna o portatil indisponivel por   |\n");
        printf("        | tempo indeterminado.                      |\n");
        printf("        |                                           |\n");
        printf("        | Estas a registar a avaria %d de %d",index+1,numOfDamages);
        alignMargin(indexDigits+numOfDamagesDigits,11);
        printf("        | Avaria:                                   |\n");
        printf("        | 1 - Temporaria                            |\n");
        printf("        | 2 - Permanente                            |\n");
        printf("        | 3 - Cancelar                              |\n");
        printf("        |___________________________________________|\n\n");

        strcpy(message,"Selecione uma opcao");
        readInt(message,&(damageInfo->type),1,3);

        if (damageInfo->type == 3)
        {
            *cancel = TRUE_1;
        }
    }

}

void readDamageInfoDate(int index, int numOfDamages, DamageType *damageInfo, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        int indexDigits,numOfDamagesDigits;
        getNumOfDigits(&indexDigits,index);
        getNumOfDigits(&numOfDamagesDigits,numOfDamages);

        printf("         ______________________________\n");
        printf("        |_PORTATEIS________________(X)_|\n");
        printf("        |                              |\n");
        printf("        | Estas a registar a avaria    |\n");
        printf("        | %d de %d",index+1,numOfDamages);
        alignMargin(indexDigits+numOfDamagesDigits,24);
        printf("        | Em que dia ocorreu a avaria? |\n");
        printf("        | Digite 0 para cancelar.      |\n");
        printf("        |______________________________|\n\n");
        strcpy(message,"Data");
        readDate(message,&(damageInfo->date));

        if (damageInfo->date.day == 0)
        {
            *cancel = TRUE_1;
        }
    }

}

int *searchTemporaryDamagesIndex(int *sizeDamageIndex, LaptopType laptop[MAX_LAPTOPS], int laptopId)
{

    int *damagesIndex = NULL, index;
    *sizeDamageIndex = 0;


    for (index = 0; index<laptop[laptopId].damagesCounterTotal; index++)
    {

        if (laptop[laptopId].damagesList[index].type == TEMPORARY && laptop[laptopId].damagesList[index].state == ACTIVE)
        {
            damagesIndex = realloc(damagesIndex, (*sizeDamageIndex + 1)*sizeof(int));
            damagesIndex[*sizeDamageIndex] = index;
            (*sizeDamageIndex)++;
        }
    }
    return damagesIndex;
}

void showLaptopInfo(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,RequestType *request,int totalRequests)
{

    //A caixa de informações tem um tamanho fixo de 34
    //Composto por:
    //               2 -> |
    //               2 -> ' '
    //              30 -> Espaços para conteudo em si

    //Exemplo de linha:  _________PORTATIL ID#1__________
    //Exemplo de linha: | [--conteudo aqui 30 espaços--] |
    //Exemplo de linha: | Processador: Intel Core i7     |
    //Exemplo de linha: | Valor de Compra: 540.00        |

    int index, indexRequests;
    char extraText[19] = "Nome do Portatil: ";

    for (index = 0; index<totalLaptops; index++)
    {
        printf("         ________________________________\n");
        drawLaptopIdInfoWindow(laptop[index].id);
        printf("        |                                |\n");
        drawNameInfoWindow(extraText,laptop[index].name);
        printf("        |                                |\n");
        drawLaptopStateInfoWindow(laptop[index].state);
        drawLaptopLocationInfoWindow(laptop[index].location);
        drawLaptopTotalDamagesInfoWindow(laptop[index].damagesCounterTotal);
        drawLaptopTotalRequestsInfoWindow(laptop[index].requestsCounter);
        printf("        |                                |\n");
        printf("        | --------Especificacoes-------- |\n");
        drawLaptopProcessorInfoWindow(laptop[index].processor);
        drawLaptopRamInfoWindow(laptop[index].ram);
        printf("        | ------------------------------ |\n");
        drawLaptopPriceInfoWindow(laptop[index].price);
        drawLaptopPurchaseDateInfoWindow(laptop[index].purchaseDate);
        printf("        |                                |\n");
        printf("        | -->Historico de Requisicoes<-- |\n");
        if (laptop[index].requestsCounter > 0)
        {
            for (indexRequests=totalRequests-1; indexRequests>=0; indexRequests--)
            {
                if (request[indexRequests].laptopIndex == index){
                  printf("        |                                |\n");
                  drawRequestApplicantTypeInfoWindow(request[indexRequests].applicantType);
                  drawRequestDurationInfoWindow(request[indexRequests].duration);
                }
            }
        }
        else
        {
            printf("        |                                |\n");
            printf("        | O portatil nao possui          |\n");
            printf("        | requisicoes registadas ainda.  |\n");
        }
        printf("        |________________________________|\n\n");

    }
}

void showDamageHistoric(LaptopType laptop[MAX_LAPTOPS],int totalLaptops)
{

    int index, indexDamages;
    char extraText[19] = "Nome do Portatil: ";

    for (index = 0; index<totalLaptops; index++)
    {
        printf("         ________________________________\n");
        drawLaptopIdInfoWindow(laptop[index].id);
        printf("        |                                |\n");
        drawNameInfoWindow(extraText,laptop[index].name);
        printf("        |                                |\n");
        drawLaptopStateInfoWindow(laptop[index].state);
        drawLaptopLocationInfoWindow(laptop[index].location);
        drawLaptopTotalDamagesInfoWindow(laptop[index].damagesCounterTotal);
        drawLaptopTotalRequestsInfoWindow(laptop[index].requestsCounter);
        printf("        |                                |\n");
        printf("        | --------Especificacoes-------- |\n");
        drawLaptopProcessorInfoWindow(laptop[index].processor);
        drawLaptopRamInfoWindow(laptop[index].ram);
        printf("        | ------------------------------ |\n");
        drawLaptopPriceInfoWindow(laptop[index].price);
        drawLaptopPurchaseDateInfoWindow(laptop[index].purchaseDate);
        printf("        |                                |\n");
        printf("        | ---> Historico de Avarias <--- |\n");

        if (laptop[index].damagesCounterTotal > 0)
        {
            for (indexDamages=laptop[index].damagesCounterTotal - 1; indexDamages>=0; indexDamages--)
            {
                printf("        |                                |\n");
                printf("        | [");
                showDate(laptop[index].damagesList[indexDamages].date);
                printf("] ");

                writeDamageCode(laptop[index].damagesList[indexDamages].code,MAX_SPACES_INFO_WINDOW);

                drawLaptopDamageTypeInfoWindow(laptop[index].damagesList[indexDamages].type);

                drawLaptopDamageDescInfoWindow(laptop[index].damagesList, indexDamages);
            }
        }
        else
        {
          printf("        |                                |\n");
          printf("        | O portatil nao possui avarias  |\n");
          printf("        | registadas ainda.              |\n");
        }

          printf("        |________________________________|\n\n");

    }

}

void writeDamageCode(int code, int windowSize)
{

    switch(code)
    {
    case SCREEN:
        printf("Ecra");
        alignMargin(0,windowSize-17);
        break;
    case KEYBOARD:
        printf("Teclado");
        alignMargin(0,windowSize-20);
        break;
    case NUMERIC_KEYBOARD:
        printf("Teclado numerico");
        alignMargin(0,windowSize-29);
        break;
    case BATTERY:
        printf("Bateria");
        alignMargin(0,windowSize-20);
        break;
    case USB_PORT:
        printf("Porta USB");
        alignMargin(0,windowSize-22);
        break;
    case AUDIO_PORT:
        printf("Porta de Audio");
        alignMargin(0,windowSize-27);
        break;
    case WIRELESS:
        printf("Internet sem Fio");
        alignMargin(0,windowSize-29);
        break;
    case ETHERNET_PORT:
        printf("Internet a Cabo");
        alignMargin(0,windowSize-28);
        break;
    case MOTHERBOARD:
        printf("Placa Mae");
        alignMargin(0,windowSize-22);
        break;
    case GPU:
        printf("Placa Grafica");
        alignMargin(0,windowSize-26);
        break;
    case CPU:
        printf("Processador");
        alignMargin(0,windowSize-24);
        break;
    case RAM:
        printf("Memoria RAM");
        alignMargin(0,windowSize-24);
        break;
    }
}

DamageType *addDamageRepairInfo(DamageType damageRepairInfo, LaptopType laptop[MAX_LAPTOPS],int laptopIndex, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        DamageType *backupPointer;

        backupPointer = laptop[laptopIndex].damagesList;

        laptop[laptopIndex].damagesList = realloc(laptop[laptopIndex].damagesList, (laptop[laptopIndex].damagesCounterTotal + 1) * sizeof(DamageType));

        if (laptop[laptopIndex].damagesList == NULL)
        {

            printf("        Nao e possivel registar mais avarias/reparacoes deste portatil.\n");

            laptop[laptopIndex].damagesList = backupPointer;
            *cancel = TRUE_1;
        }
        else
        {
            if (damageRepairInfo.type == PERMANET){
                laptop[laptopIndex].state = BROKEN_PERMANENT;
            }
            if (damageRepairInfo.type == TEMPORARY)
            {
                laptop[laptopIndex].damagesCounterActive++;
                damageRepairInfo.state = ACTIVE;
                if (laptop[laptopIndex].state != BROKEN_PERMANENT)
                {
                    laptop[laptopIndex].state = BROKEN_TEMPORARY;
                }

            }
            laptop[laptopIndex].damagesList[laptop[laptopIndex].damagesCounterTotal] = damageRepairInfo;
            (laptop[laptopIndex].damagesCounterTotal)++;
        }
    }

    return laptop[laptopIndex].damagesList;
}

int *removeTemporaryDamage(int *damageIndexList,int sizeDamageIndexList, int indexPosition)
{
    int index;

    for(index = indexPosition; index<sizeDamageIndexList; index++)
    {
        damageIndexList[index] = damageIndexList[index + 1];
    }
    sizeDamageIndexList--;
    if (sizeDamageIndexList > 0)
    {
        damageIndexList = realloc(damageIndexList, (sizeDamageIndexList)*sizeof(int));
    }
    else
    {
        damageIndexList = NULL;
    }

    return damageIndexList;
}


