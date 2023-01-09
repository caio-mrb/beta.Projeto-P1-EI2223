#include "funcoesDePortateis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoesDeDados.h"
#include "funcoesDeDesign.h"

void searchEqualLaptopId(int *equalIndex, LaptopType laptop[MAX_LAPTOPS],int totalLaptops, int numToComp)
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

void searchEqualDamage(int *equalIndex, DamageType *damageList, int totalDamages, DamageType damageToComp)
{
    int index;
    *equalIndex = -1;
    for (index=0; index<totalDamages; index++)
    {
        if (damageList[index].code == damageToComp.code &&
                damageList[index].type == damageToComp.type &&
                damageList[index].date.day == damageToComp.date.day &&
                damageList[index].date.month == damageToComp.date.month &&
                damageList[index].date.year == damageToComp.date.year)
        {
            *equalIndex = index;

            index = totalDamages;
        }
    }
}

void searchEqualDamageCodeAndHigherDate(int *equalIndex, DamageType *damageList, int totalDamages, DateType dateToComp, int codeToComp)
{
    int index, days, maxDays;
    *equalIndex = -1;
    for (index=0; index<totalDamages; index++)
    {
        if (damageList[index].code == codeToComp)
        {
            numOfDaysBetweenDates(&days,damageList[index].date,dateToComp);

            if (days < 0)
            {
                if (*equalIndex == -1)
                {
                    dateToComp = damageList[index].date;
                    maxDays = days;
                    *equalIndex = index;
                }
                if (days > maxDays)
                {
                    dateToComp = damageList[index].date;
                    maxDays = days;
                    *equalIndex = index;
                }
            }

        }
    }
}

void readLaptopId(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
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

                searchEqualLaptopId(&equalIndex,laptop,totalLaptops,laptop[totalLaptops].id);
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
                        searchEqualLaptopId(&equalIndex,laptop,totalLaptops,laptop[totalLaptops].id + num);
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

void readLaptopName(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
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

void readLaptopProcessor(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
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

void readLaptopRam(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
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

void readLaptopPrice(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
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

void readLaptopLocation(LaptopType laptop[MAX_LAPTOPS],int laptopIndex,int *cancel)
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

void readLaptopPurchaseDate(LaptopType laptop[MAX_LAPTOPS],int totalLaptops,int *cancel)
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

void registerNewLaptop(LaptopType laptop[MAX_LAPTOPS], int totalLaptops, int index, int numOfLaptops, int *cancel)
{
    //Desenha o pedido de informações
    drawLaptopInfoAsk(index,numOfLaptops);

    //Lê o ID do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopId(laptop,totalLaptops,cancel);

    //Lê a designação do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopName(laptop,totalLaptops,cancel);

    //Lê o processador do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopProcessor(laptop,totalLaptops,cancel);

    //Lê a quantidade de memoria RAM do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopRam(laptop,totalLaptops,cancel);

    //Lê o preço do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopPrice(laptop,totalLaptops,cancel);

    //Lê a data de compra do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopPurchaseDate(laptop,totalLaptops,cancel);

    //Executa se o pedido de adição não tiver sido cancelado
    if (*cancel == FALSE_0)
    {
        //Desenha a lista de localizações possíveis para o portatil
        drawLocationsMiniList();
    }

    //Lê a localização do portatil a ser adicionado se o pedido de adição não tiver sido cancelado
    readLaptopLocation(laptop,totalLaptops,cancel);

    //Executa se o pedido de adição não tiver sido cancelado
    if (*cancel == FALSE_0)
    {
        //Define o estado do portatil a ser adicionado como disponível
        laptop[totalLaptops].state = AVAILABLE;
    }

}

void changeLaptopLocation(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *cancel)
{
    int lastLocation;

    //Armazena em uma variavel a localização (int) atual do portatil
    lastLocation = laptop[laptopIndex].location;

    //Desenha a lista de localizações possíveis
    drawLocationsBigList();

    //-----Do{}While-----
    //Executa o conjuto de instruções
    //a seguir enquanto o utilizador
    //pedir para mudar o portatil para
    //a posição em que já se encontra
    //(lastLocation == laptop[laptopIndex].location)
    //e enquanto não pedir para cancelar
    //(cancel == FALSE_0)
    do
    {
        //Lê a localização do portatil e sobrepõe a localização anterior
        readLaptopLocation(laptop,laptopIndex,cancel);

        //Executa se o utilizador mover o portatil para a localização em que já se encontra e se não pedir pra cancelar
        if (lastLocation == laptop[laptopIndex].location && *cancel == FALSE_0)
        {
            //Informa o utilizador que está a tentar mover para o posição que o portatil já está
            printf("        O portatil ja esta nesta localizacao!\n");
        }

        //Executa se o utilizador mover o portatil para uma localização diferente da que já se encontra e se não pedir pra cancelar
        if (lastLocation != laptop[laptopIndex].location && *cancel == FALSE_0)
        {
            //Informa o utilizador que a localização do portatil foi alterada com sucesso
            printf("        Localizacao alterada com sucesso!\n\n");
        }
    }
    while (lastLocation == laptop[laptopIndex].location && *cancel == FALSE_0);
}

void readDamageInfoCode(int index, int numOfDamages, DamageType *damageInfo, DamageType *damageList, int totalDamages, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];
        int index1,counter = 12,permanetDamages[12] = {0}, optionNum[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
        int indexDigits,numOfDamagesDigits;
        getNumOfDigits(&indexDigits,index+1);
        getNumOfDigits(&numOfDamagesDigits,numOfDamages);

        printf("         _________________________________________\n");
        printf("        |_PORTATEIS___________________________(X)_|\n");
        printf("        |                                         |\n");
        printf("        | Estas a registar a avaria %d de %d",index+1,numOfDamages);
        alignMargin(indexDigits+numOfDamagesDigits,9);
        printf("        | Selecione em que sitio foi a avaria:    |\n");

        for (index1=0; index1<totalDamages; index1++)
        {
            if(damageList[index1].type == PERMANET)
            {
                switch(damageList[index1].code)
                {
                case SCREEN:
                    permanetDamages[0] = TRUE_1;
                    removeOneNext(optionNum,13,0);
                    break;
                case KEYBOARD:
                    permanetDamages[1] = TRUE_1;
                    removeOneNext(optionNum,13,1);
                    break;
                case NUMERIC_KEYBOARD:
                    permanetDamages[2] = TRUE_1;
                    removeOneNext(optionNum,13,2);
                    break;
                case BATTERY:
                    permanetDamages[3] = TRUE_1;
                    removeOneNext(optionNum,13,3);
                    break;
                case USB_PORT:
                    permanetDamages[4] = TRUE_1;
                    removeOneNext(optionNum,13,4);
                    break;
                case AUDIO_PORT:
                    permanetDamages[5] = TRUE_1;
                    removeOneNext(optionNum,13,5);
                    break;
                case WIRELESS:
                    permanetDamages[6] = TRUE_1;
                    removeOneNext(optionNum,13,6);
                    break;
                case ETHERNET_PORT:
                    permanetDamages[7] = TRUE_1;
                    removeOneNext(optionNum,13,7);
                    break;
                case MOTHERBOARD:
                    permanetDamages[8] = TRUE_1;
                    removeOneNext(optionNum,13,8);
                    break;
                case GPU:
                    permanetDamages[9] = TRUE_1;
                    removeOneNext(optionNum,13,9);
                    break;
                case CPU:
                    permanetDamages[10] = TRUE_1;
                    removeOneNext(optionNum,13,10);
                    break;
                case RAM:
                    permanetDamages[11] = TRUE_1;
                    removeOneNext(optionNum,13,11);
                    break;
                }
                counter--;
            }
        }
        if(permanetDamages[0] != TRUE_1)
        {
            printf("        | 0%d - Ecra                               |\n",optionNum[0]);
        }
        if(permanetDamages[1] != TRUE_1)
        {
            printf("        | 0%d - Teclado                            |\n",optionNum[1]);
        }
        if(permanetDamages[2] != TRUE_1)
        {
            printf("        | 0%d - Teclado Numerico                   |\n",optionNum[2]);
        }
        if(permanetDamages[3] != TRUE_1)
        {
            printf("        | 0%d - Bateria                            |\n",optionNum[3]);
        }
        if(permanetDamages[4] != TRUE_1)
        {
            printf("        | 0%d - Porta USB                          |\n",optionNum[4]);
        }
        if(permanetDamages[5] != TRUE_1)
        {
            printf("        | 0%d - Entrada de Audio                   |\n",optionNum[5]);
        }
        if(permanetDamages[6] != TRUE_1)
        {
            printf("        | 0%d - Receptor WI-FI                     |\n",optionNum[6]);
        }
        if(permanetDamages[7] != TRUE_1)
        {
            printf("        | 0%d - Porta de Ethernet                  |\n",optionNum[7]);
        }
        if(permanetDamages[8] != TRUE_1)
        {
            printf("        | 0%d - Placa Mae                          |\n",optionNum[8]);
        }
        if(permanetDamages[9] != TRUE_1)
        {
            if(optionNum[9] > 9)
            {
                printf("        | %d - Placa Grafica                      |\n",optionNum[9]);
            }
            else
            {
                printf("        | 0%d - Placa Grafica                      |\n",optionNum[9]);
            }
        }

        if(permanetDamages[10] != TRUE_1)
        {
            if(optionNum[10] > 9)
            {
                printf("        | %d - Processador                        |\n",optionNum[10]);
            }
            else
            {
                printf("        | 0%d - Processador                        |\n",optionNum[10]);
            }
        }

        if(permanetDamages[11] != TRUE_1)
        {
            if(optionNum[11] > 9)
            {
                printf("        | %d - Memoria RAM                        |\n",optionNum[11]);
            }
            else
            {
                printf("        | 0%d - Memoria RAM                        |\n",optionNum[11]);
            }
        }

        if(optionNum[12] > 9)
        {
            printf("        | %d - Cancelar                           |\n",optionNum[12]);
        }
        else
        {
            printf("        | 0%d - Cancelar                           |\n",optionNum[12]);
        }

        printf("        |_________________________________________|\n\n");

        strcpy(message,"Selecione uma opcao");
        readInt(message,&(damageInfo->code),1,optionNum[12]);
        if (damageInfo->code == optionNum[12])
        {
            damageInfo->code = 13;
            *cancel = TRUE_1;
        }
        else
        {
            for(index1=0; index1<12; index1++)
            {
                if(permanetDamages[index1] != TRUE_1)
                {
                    (damageInfo->code)--;
                }
                if(damageInfo->code == 0)
                {
                    damageInfo->code = index1+1;
                    index1 = 12;
                }
            }
        }
    }

}

void readDamageInfoType(int index, int numOfDamages, DamageType *damageInfo, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];

        int indexDigits,numOfDamagesDigits;
        getNumOfDigits(&indexDigits,index+1);
        getNumOfDigits(&numOfDamagesDigits,numOfDamages);

        printf("         ______________________________________________\n");
        printf("        |_PORTATEIS________________________________(X)_|\n");
        printf("        |                                              |\n");
        printf("        | Obs: Um portatil so pode possuir uma avaria  |\n");
        printf("        | permanete por peca e estas sao irreparaveis, |\n");
        printf("        | o que torna o portatil indisponivel por      |\n");
        printf("        | tempo indeterminado.                         |\n");
        printf("        |                                              |\n");
        printf("        | Estas a registar a avaria %d de %d",index+1,numOfDamages);
        alignMargin(indexDigits+numOfDamagesDigits,14);
        printf("        | Avaria:                                      |\n");
        printf("        | 1 - Temporaria                               |\n");
        printf("        | 2 - Permanente                               |\n");
        printf("        | 3 - Cancelar                                 |\n");
        printf("        |______________________________________________|\n\n");

        strcpy(message,"Selecione uma opcao");
        readInt(message,&(damageInfo->type),1,3);

        if (damageInfo->type == 3)
        {
            *cancel = TRUE_1;
        }
    }

}

void readDamageInfoDate(int index, int numOfDamages, DamageType *damageInfo, DateType purchaseDate, DamageType *damageList, int totalDamages, int *cancel)
{
    if (*cancel == FALSE_0)
    {
        char message[MAX_READ_MESSAGE_SIZE];
        int daysResult, equalIndex;
        int indexDigits,numOfDamagesDigits;
        getNumOfDigits(&indexDigits,index+1);
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
        do
        {
            equalIndex = -1;

            readDate(message,&(damageInfo->date));

            if (damageInfo->date.day == 0)
            {
                *cancel = TRUE_1;
            }
            if(*cancel == FALSE_0)
            {
                numOfDaysBetweenDates(&daysResult,purchaseDate,damageInfo->date);

                if (daysResult < 0)
                {
                    drawDamageDateMustBeHigherThanPurchaseDate(purchaseDate);
                }
                if(daysResult >= 0 && damageInfo->type == PERMANET)
                {
                    searchEqualDamageCodeAndHigherDate(&equalIndex,damageList,totalDamages,damageInfo->date,damageInfo->code);

                    if (equalIndex > -1)
                    {
                        drawDamageDateMustBeHigherThanLastDate(damageList[equalIndex].date);
                    }
                }
            }
        }
        while((daysResult < 0 || equalIndex > -1) && *cancel == FALSE_0);
    }
}

int *registerNewRepair(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *damageIndexList, int *sizeDamageIndex, int optRepairMenu)
{
    char message[MAX_NAME_CHAR] = "Digite quantos dias o portatil esteve avariado";

    //Lê e guarda o tempo (int) em dias que demorou até ser reparado
    readInt(message,&laptop[laptopIndex].damagesList[damageIndexList[optRepairMenu-1]].duration,0,MAX_DAMAGE_DAYS);
    //Altera o estado da avaria para concluida
    laptop[laptopIndex].damagesList[damageIndexList[optRepairMenu-1]].state = COMPLETED;
    //Remove 1 a quantidade de avarias ativas
    laptop[laptopIndex].damagesCounterActive--;
    //Executa se nao possuir mais danos ativos
    if(laptop[laptopIndex].damagesCounterActive == 0 && laptop[laptopIndex].state != BROKEN_PERMANENT)
    {
        laptop[laptopIndex].state = AVAILABLE;
    }
    //Remove a avaria acabada de arranjar da lista de avarias temporárias
    damageIndexList = removeTemporaryDamage(damageIndexList,sizeDamageIndex,optRepairMenu-1);

    return damageIndexList;
}

void registerNewDamage(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *index, int numOfDamages, int *cancel)
{
    DamageType damageInfo;
    int damageIndex;

    //Lê o local/código da avaria se o registo de avaria não tiver sido cancelado
    readDamageInfoCode(*index,numOfDamages,&damageInfo,laptop[laptopIndex].damagesList,laptop[laptopIndex].damagesCounterTotal, cancel);

    //Lê o tipo da avaria se o registo de avaria não tiver sido cancelado
    readDamageInfoType(*index,numOfDamages,&damageInfo, cancel);

    //Lê a data da avaria se o registo de avaria não tiver sido cancelado
    readDamageInfoDate(*index,numOfDamages,&damageInfo,laptop[laptopIndex].purchaseDate,laptop[laptopIndex].damagesList,laptop[laptopIndex].damagesCounterTotal, cancel);

    searchEqualDamage(&damageIndex,laptop[laptopIndex].damagesList,laptop[laptopIndex].damagesCounterTotal,damageInfo);

    if (damageIndex == -1)
    {
        //Armazena na lista de avarias do portatil se o registo de avaria não tiver sido cancelado
        laptop[laptopIndex].damagesList = addDamageRepairInfo(damageInfo, laptop, laptopIndex, cancel);
    }
    else
    {
        (*index)--;
        printf("        Este portatil ja possui esta avaria registada!\n");
        enterToContinue("        ");
    }

}

int *searchTemporaryDamagesIndex(int *sizeDamageIndex, LaptopType laptop[MAX_LAPTOPS], int laptopId)
{
    int *damagesIndex = NULL,*backupPointer, index;
    *sizeDamageIndex = 0;

    for (index = 0; index<laptop[laptopId].damagesCounterTotal; index++)
    {
        if (laptop[laptopId].damagesList[index].type == TEMPORARY && laptop[laptopId].damagesList[index].state == ACTIVE)
        {
            damagesIndex = realloc(damagesIndex, (*sizeDamageIndex + 1)*sizeof(int));
            if (damagesIndex != NULL)
            {
            damagesIndex[*sizeDamageIndex] = index;
            (*sizeDamageIndex)++;
            }
            else
            {
                printf("        Erro ao guardar a localizacao da avaria do portatil!\n");
                damagesIndex = backupPointer;
                index = laptop[laptopId].damagesCounterTotal;
            }
        }
        backupPointer = damagesIndex;
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
        drawNameInfoWindow("        ",extraText,laptop[index].name);
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
                if (request[indexRequests].laptopIndex == index)
                {
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
        drawNameInfoWindow("        ",extraText,laptop[index].name);
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
            if (damageRepairInfo.type == PERMANET)
            {
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

int *removeTemporaryDamage(int *damageIndexList,int *sizeDamageIndexList, int indexPosition)
{
    int index, *backupPointer;
    backupPointer = damageIndexList;

    for(index = indexPosition; index<*sizeDamageIndexList; index++)
    {
        damageIndexList[index] = damageIndexList[index + 1];
    }
    (*sizeDamageIndexList)--;
    if (*sizeDamageIndexList > 0)
    {
        damageIndexList = realloc(damageIndexList, (*sizeDamageIndexList)*sizeof(int));
        if (damageIndexList == NULL)
        {
            printf("        Erro ao guardar a reparacao do portatil!\n");
            damageIndexList = backupPointer;
        }
    }
    else
    {
        damageIndexList = NULL;
    }

    return damageIndexList;
}
