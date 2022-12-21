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
        readStringOnlyLetters(message,laptop[totalLaptops].name,MAX_NAME_CHAR);

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

        char message[MAX_READ_MESSAGE_SIZE],option[MAX_NAME_CHAR];
        int validValue;

        strcpy(message,"Processador (0, i3, i5, i7)");

        do
        {
            readString(message,option,MAX_NAME_CHAR);

            option[0] = toupper(option[0]);


            if (option[0] == 'I' && option[1] == '3')
            {

                laptop[totalLaptops].processor = INTEL_I3;

                validValue = TRUE_1;
            }
            if (option[0] == 'I' && option[1] == '5')
            {

                laptop[totalLaptops].processor = INTEL_I5;

                validValue = TRUE_1;
            }
            if (option[0] == 'I' && option[1] == '7')
            {

                laptop[totalLaptops].processor = INTEL_I7;

                validValue = TRUE_1;
            }

            if (option[0] == '0')
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


void readLapLocation(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
{

    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE],option[MAX_NAME_CHAR];

        int validValue = FALSE_0;


        strcpy(message,"Localizacao");

        do
        {
            readString(message,option,MAX_NAME_CHAR);

            option[0] = toupper(option[0]);
            option[1] = toupper(option[1]);

            if (option[0] == 'R' && option[1] == 'E')
            {
                laptop[totalLaptops].location = RESIDENCES;

                validValue = TRUE_1;
            }
            if (option[0] == 'C' && option[1] == '1')
            {

                laptop[totalLaptops].location = CAMPUS_1;

                validValue = TRUE_1;
            }
            if (option[0] == 'C' && option[1] == '2')
            {

                laptop[totalLaptops].location = CAMPUS_2;

                validValue = TRUE_1;
            }
            if (option[0] == 'C' && option[1] == '3')
            {

                laptop[totalLaptops].location = CAMPUS_3;

                validValue = TRUE_1;
            }
            if (option[0] == 'C' && option[1] == '5')
            {

                laptop[totalLaptops].location = CAMPUS_5;

                validValue = TRUE_1;
            }

            if (option[0] == '0')
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



void showLaptopInfo(LaptopType laptop[MAX_LAPTOPS],int totalLaptops)
{

    //A caixa de informa��es tem um tamanho fixo de 34
    //Composto por:
    //               2 -> |
    //               2 -> ' '
    //              30 -> Espa�os para conteudo em si

    //Exemplo de linha:  _________PORTATIL ID#1__________
    //Exemplo de linha: | [--conteudo aqui 26 espa�os--] |
    //Exemplo de linha: | Processador: Intel Core i7     |
    //Exemplo de linha: | Valor de Compra: 540.00        |

    int index, indexDamages, idDigits, priceDigitis, dayDigits, monthDigits, ramDigits, damagesDigits;
    char firstSplitedStr[MAX_SPLIT_STRING] = {'\0'}, secondSplitedStr[MAX_SPLIT_STRING] = {'\0'}, thirdSplitedStr[MAX_SPLIT_STRING] = {'\0'};

    for (index = 0; index<totalLaptops; index++)
    {

        getNumOfDigits(&priceDigitis,   (int)laptop[index].price);
        getNumOfDigits(&idDigits,   laptop[index].id);
        getNumOfDigits(&ramDigits,  laptop[index].ram);
        getNumOfDigits(&damagesDigits, laptop[index].damagesCounterTotal);


        getNumOfDigits(&dayDigits,  laptop[index].purchaseDate.day);
        getNumOfDigits(&monthDigits,    laptop[index].purchaseDate.month);

        printf("         ________________________________\n");
        switch (idDigits)
        {

        case 1:
            printf("        (_________PORTATIL ID#%d__________)\n",laptop[index].id);
            break;
        case 2:
            printf("        (_________PORTATIL ID#%d_________)\n",laptop[index].id);
            break;
        case 3:
            printf("        (________PORTATIL ID#%d_________)\n",laptop[index].id);
            break;
        case 4:
            printf("        (________PORTATIL ID#%d________)\n",laptop[index].id);
            break;
        }
        printf("        |                                |\n");

        if (strlen(laptop[index].name) < 13)
        {
            printf("        | Nome do portatil: %s",laptop[index].name);
            alignMargin(strlen(laptop[index].name),12);
        }

        if (strlen(laptop[index].name) < 43 && strlen(laptop[index].name) >= 13)
        {
            splitString(12,laptop[index].name,firstSplitedStr,secondSplitedStr);

            printf("        | Nome do portatil: %s",firstSplitedStr);
            alignMargin(strlen(firstSplitedStr),12);

            printf("        | %s",secondSplitedStr);
            alignMargin(strlen(secondSplitedStr),MAX_SPACES_INFO_WINDOW);

        }

        if (strlen(laptop[index].name) < 51 && strlen(laptop[index].name) >= 43)
        {
            splitString(12,laptop[index].name,firstSplitedStr,secondSplitedStr);
            splitString(MAX_SPACES_INFO_WINDOW,secondSplitedStr,secondSplitedStr,thirdSplitedStr);


            printf("        | Nome do portatil: %s",firstSplitedStr);
            alignMargin(strlen(firstSplitedStr),12);

            printf("        | %s",secondSplitedStr);
            alignMargin(strlen(secondSplitedStr),MAX_SPACES_INFO_WINDOW);

            printf("        | %s",thirdSplitedStr);
            alignMargin(strlen(thirdSplitedStr),MAX_SPACES_INFO_WINDOW);

        }

        printf("        |                                |\n");

        if (laptop[index].state == AVAILABLE)
        {
            printf("        | Estado: Disponivel");
            alignMargin(0,MAX_SPACES_INFO_WINDOW-18);
        }
        else
        {
            printf("        | Estado: Indisponivel");
            alignMargin(0,MAX_SPACES_INFO_WINDOW-20);

        }
        switch(laptop[index].location)
        {
        case RESIDENCES:
            printf("        | Localizacao Atual: Residencias |\n");
            break;
        case CAMPUS_1:
            printf("        | Localizacao Atual: Campus1");
            alignMargin(0,MAX_SPACES_INFO_WINDOW-26);
            break;
        case CAMPUS_2:
            printf("        | Localizacao Atual: Campus2");
            alignMargin(0,MAX_SPACES_INFO_WINDOW-26);
            break;
        case CAMPUS_3:
            printf("        | Localizacao Atual: Campus3");
            alignMargin(0,MAX_SPACES_INFO_WINDOW-26);
            break;
        case CAMPUS_5:
            printf("        | Localizacao Atual: Campus5");
            alignMargin(0,MAX_SPACES_INFO_WINDOW-26);
            break;

        }

        printf("        | Quantidade de avarias: %d", laptop[index].damagesCounterTotal);
        alignMargin(damagesDigits,MAX_SPACES_INFO_WINDOW-23);
        printf("        |                                |\n");

        printf("        | --------Especificacoes-------- |\n");
        printf("        | Processador: Intel Core i%d     |\n",laptop[index].processor);

        printf("        | Memoria RAM: %d GB",laptop[index].ram);
        alignMargin(ramDigits,MAX_SPACES_INFO_WINDOW-16);
        printf("        | ------------------------------ |\n");

        printf("        | Valor de Compra: %.2f euros",laptop[index].price);
        alignMargin(priceDigitis,MAX_SPACES_INFO_WINDOW-26);

        printf("        | Data de Compra: ");
        showDate(laptop[index].purchaseDate);
        alignMargin(0,MAX_SPACES_INFO_WINDOW-26);

        if (laptop[index].damagesCounterTotal > 0)
        {
            printf("        |                                |\n");
            printf("        | ---> Historico de Avarias <--- |\n");
            for (indexDamages=laptop[index].damagesCounterTotal - 1; indexDamages>=0; indexDamages--)
            {

                printf("        |                                |\n");
                getNumOfDigits(&dayDigits,  laptop[index].damagesList[indexDamages].date.day);
                getNumOfDigits(&monthDigits,    laptop[index].damagesList[indexDamages].date.month);
                printf("        | [");
                showDate(laptop[index].damagesList[indexDamages].date);
                printf("] ");

                writeDamageCode(laptop[index].damagesList[indexDamages].code,MAX_SPACES_INFO_WINDOW);


                if (laptop[index].damagesList[indexDamages].type == TEMPORARY && laptop[index].damagesList[indexDamages].state == ACTIVE)
                {
                    printf("        | ->Avaria Temporaria<-");
                    alignMargin(0,MAX_SPACES_INFO_WINDOW-21);
                }
                if (laptop[index].damagesList[indexDamages].type == TEMPORARY && laptop[index].damagesList[indexDamages].state == COMPLETED)
                {
                    printf("        | ->Avaria Arranjada<-");
                    alignMargin(0,MAX_SPACES_INFO_WINDOW-20);
                }
                if (laptop[index].damagesList[indexDamages].type == PERMANET)
                {
                    printf("        | ->Avaria Permanente<-");
                    alignMargin(0,MAX_SPACES_INFO_WINDOW-21);
                }




                getNumOfDigits(&dayDigits,laptop[index].damagesList[indexDamages].duration);

                if (laptop[index].damagesList[indexDamages].state == COMPLETED)
                {
                    printf("        | Avariado por %d dias",laptop[index].damagesList[indexDamages].duration);
                    alignMargin(dayDigits,MAX_SPACES_INFO_WINDOW-18);
                }
                if (laptop[index].damagesList[indexDamages].state == ACTIVE && laptop[index].damagesList[indexDamages].type == TEMPORARY)
                {
                    printf("        | Avaria ainda por arranjar...");
                    alignMargin(0,MAX_SPACES_INFO_WINDOW-28);
                }
                if (laptop[index].damagesList[indexDamages].type == PERMANET)
                {
                    printf("        | Avaria impossivel de arranjar");
                    alignMargin(0,MAX_SPACES_INFO_WINDOW-29);
                }


            }

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
            if (damageRepairInfo.type == TEMPORARY)
            {
                laptop[laptopIndex].damagesCounterActive++;
                damageRepairInfo.state = ACTIVE;
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
    if (sizeDamageIndexList > 0){
        damageIndexList = realloc(damageIndexList, (sizeDamageIndexList)*sizeof(int));
    }else{
        damageIndexList = NULL;
    }

    return damageIndexList;
}


