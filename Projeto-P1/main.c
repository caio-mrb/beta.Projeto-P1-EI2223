#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "funcoesDePortateis.h"
#include "funcoesDeRequisicoes.h"
#include "funcoesDeDados.h"
#include "constantes.h"

void enterToContinue(void);


int main()
{


    LaptopType laptop[MAX_LAPTOPS] = {0};
    RequestType *request = NULL;
    int totalLaptops = 0, totalRequests = 10, availableLaptops = 0, activeRequests = 0;

    FILE *check;

    request = malloc(totalRequests*sizeof(RequestType));


    printf(" _               _____ _______ ____  _____    _____  ______ ____  _    _ ______  _____ _______\n");
    printf("| |        /\\   |  __ \\__   __/ __ \\|  __ \\  |  __ \\|  ____/ __ \\| |  | |  ____|/ ____|__   __|  TM\n");
    printf("| |       /  \\  | |__) | | | | |  | | |__) | | |__) | |__ | |  | | |  | | |__  | (___    | |\n");
    printf("| |      / /\\ \\ |  ___/  | | | |  | |  ___/  |  _  /|  __|| |  | | |  | |  __|  \\___ \\   | |\n");
    printf("| |____ / ____ \\| |      | | | |__| | |      | | \\ \\| |___| |__| | |__| | |____ ____) |  | |\n");
    printf("|______/_/    \\_\\_|      |_|  \\____/|_|      |_|  \\_\\______\\___\\_\\\\____/|______|_____/   |_|\n\n");
    printf("Criado por: Andre Rosa e Caio Barbosa.\n");

    check = fopen("info.dat","rb");

    if (check == NULL)
    {
        printf(" ________________________\n");
        printf("|                        |\n");
        printf("| Bem-Vindo ao Programa! |\n");
        printf("|________________________|\n\n");

    }
    else
    {
        printf(" ____________________\n");
        printf("|                    |\n");
        printf("| Bem-Vindo de volta |\n");
        printf("| ao Programa!       |\n");
        printf("|____________________|\n");

        request = loadFileToInfo(laptop,&totalLaptops,request,&totalRequests);

        fclose(check);

    }



    //storeInfoToFile(laptop,totalLaptops,request,totalRequests);

    enterToContinue();


    int optMainMenu,optLapMenu,optLapSubMenu,numOfLaptops,optReqMenu,optStatsMenu,optExtMenu,index,equalIndex,lastLocation,readedID = 0, numOfDamages, optDamageMenu, damagesDigits, idDigits;

    int cancel = 0;

    char message[MAX_READ_MESSAGE_SIZE] = "Selecione uma opcao";

    numAvailableLaptops(&availableLaptops,laptop,totalLaptops);
    numActiveRequests(&activeRequests,request,totalRequests);

    do
    {
        clrScr();

        printf("                    _____ ___ ___ _ _\n");
        printf("                   |     | -_|   | | |\n");
        printf("                   |_|_|_|___|_|_|___|\n\n");
        printf("         ________________________________________\n");
        printf("        |                                        |\n");
        printf("        | Portateis existentes: %2d               |\n",totalLaptops);
        printf("        | Portateis disponiveis: %2d              |\n",availableLaptops);
        printf("        |                                        |\n");
        printf("        | Quantidade de requisicoes ativas: %4d |\n",activeRequests);
        printf("        | Quantidade total de requisicoes: %4d  |\n",totalRequests);
        printf("        |________________________________________|\n\n");

        printf("         ________________________________________\n");
        printf("        |                                        |\n");
        printf("        | Selecione uma opcao para aceder ao     |\n");
        printf("        | respetivo submenu:                     |\n");
        printf("        | 1 - Portateis                          |\n");
        printf("        | 2 - Requisicoes/Devolucoes             |\n");
        printf("        | 3 - Estatisticas                       |\n");
        printf("        | 4 - Sair                               |\n");
        printf("        |________________________________________|\n\n");

        readInt(message,&optMainMenu,1,4);

        switch (optMainMenu)
        {
        case 1:
            do
            {
                clrScr();

                printf("         ____________________________________________\n");
                printf("        |_PORTATEIS______________________________(X)_|\n");
                printf("        |                                            |\n");
                printf("        | Selecione a opcao pretendida:              |\n");
                printf("        | 1 - Adicionar portatil(eis)                |\n");
                printf("        | 2 - Listar informacoes do(s) portatil(eis) |\n");
                printf("        | 3 - Alterar localizacao do portatil        |\n");
                printf("        | 4 - Registar avaria/reparacao do portatil  |\n");
                printf("        | 5 - Voltar                                 |\n");
                printf("        |____________________________________________|\n\n");


                strcpy(message,"Selecione uma opcao");
                readInt(message,&optLapMenu,1,5);

                switch (optLapMenu)
                {
                case 1:
                    clrScr();

                    if (totalLaptops == MAX_LAPTOPS)
                    {
                        printf("         ____________________________________\n");
                        printf("        |_PORTATEIS______________________(X)_|\n");
                        printf("        |                                    |\n");
                        printf("        | Ja foi atingido o limite maximo de |\n");
                        printf("        | portateis existentes.              |\n");
                        printf("        |____________________________________|\n\n");

                        printf("         ");
                        enterToContinue();

                    }
                    else
                    {
                        clrScr();

                        printf("         ___________________________________\n");
                        printf("        |_PORTATEIS_____________________(X)_|\n");
                        printf("        |                                   |\n");
                        if (totalLaptops > 0)
                        {
                            printf("        | Ja existe(m) %2d portatil(eis).    |\n", totalLaptops);
                        }
                        else
                        {
                            printf("        | Nao existem portateis ainda.      |\n");
                        }
                        printf("        | Podes adicionar %2d portatil(eis). |\n",MAX_LAPTOPS - totalLaptops);
                        printf("        | Digite 0 para cancelar.           |\n");
                        printf("        |___________________________________|\n\n");

                        strcpy(message,"Digite quantos portateis deseja adicionar");

                        readInt(message,&numOfLaptops,0,(MAX_LAPTOPS - totalLaptops));

                        if (numOfLaptops > 0)
                        {
                            cancel = FALSE_0;

                            for (index = 0; index<numOfLaptops; index++)
                            {
                                clrScr();


                                printf("         ____________________________________________\n");
                                printf("        |_PORTATEIS______________________________(X)_|\n");
                                printf("        |                                            |\n");
                                printf("        | Preencha os campos de acordo com o que e   |\n");
                                printf("        | pedido.                                    |\n");
                                printf("        | Estas a adicionar o portatil %2d de %2d.     |\n", index+1, numOfLaptops);
                                printf("        | Digite 0 em qualquer campo para cancelar.  |\n");
                                printf("        |____________________________________________|\n\n");

                                //enterToContinue();



                                readLapId(laptop,totalLaptops,&cancel);
                                readLapName(laptop,totalLaptops,&cancel);
                                readLapProcessor(laptop,totalLaptops,&cancel);
                                readLapRam(laptop,totalLaptops,&cancel);
                                readLapPrice(laptop,totalLaptops,&cancel);
                                readLapPurchaseDate(laptop,totalLaptops,&cancel);

                                if (cancel == FALSE_0)
                                {
                                    printf("         __________________\n");
                                    printf("        | RE - Residencias |\n");
                                    printf("        | C1 - Campus1     |\n");
                                    printf("        | C2 - Campus2     |\n");
                                    printf("        | C3 - Campus3     |\n");
                                    printf("        |_C5 - Campus5_____|\n");
                                }
                                readLapLocation(laptop,totalLaptops,&cancel);


                                if (cancel == FALSE_0)
                                {
                                    laptop[totalLaptops].state = AVAILABLE;
                                    availableLaptops++;
                                    totalLaptops++;
                                    storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                }

                                if (cancel == TRUE_1)
                                {
                                    numOfLaptops = index;
                                }
                            }

                            if (cancel == TRUE_1 && numOfLaptops > 0)
                            {

                                printf("         _________________________________________________\n");
                                printf("        |_PORTATEIS___________________________________(X)_|\n");
                                printf("        |                                                 |\n");
                                printf("        | Foi(ram) adicionado(s) apenas %2d portatil(eis). |\n",numOfLaptops);
                                printf("        |_________________________________________________|\n\n");

                                printf("        ");
                                enterToContinue();

                            }

                        }
                    }

                    break;
                case 2:
                    clrScr();
                    if (totalLaptops > 0){
                        showLaptopInfo(laptop,totalLaptops);
                        printf("        ");
                        enterToContinue();
                    }else{
                    printf("         __________________________________\n");
                    printf("        |_PORTATEIS____________________(X)_|\n");
                    printf("        |                                  |\n");
                    printf("        | Nao existem portateis no sistema |\n");
                    printf("        |__________________________________|\n\n");
                    printf("        ");
                    enterToContinue();

                    }

                    break;
                case 3:
                    cancel = FALSE_0;
                    clrScr();
                    if (totalLaptops > 0){
                    printf("         _____________________________\n");
                    printf("        |_PORTATEIS_______________(X)_|\n");
                    printf("        |                             |\n");
                    printf("        | Digite o id do portatil que |\n");
                    printf("        | pretendes mover.            |\n");
                    printf("        | Digite 0 para cancelar      |\n");
                    printf("        |_____________________________|\n\n");

                    strcpy(message,"ID do Portatil");

                    do
                    {

                        readInt(message,&readedID,0,MAX_ID);

                        if(readedID > 0)
                        {
                            searchEqualLapId(&equalIndex,laptop,totalLaptops,readedID);

                            if (equalIndex > -1)
                            {
                                lastLocation = laptop[equalIndex].location;

                                printf("         ____________________________\n");
                                printf("        |_PORTATEIS______________(X)_|\n");
                                printf("        |                            |\n");
                                printf("        | Selecione para onde deseja |\n");
                                printf("        | mover o portatil:          |\n");
                                printf("        | RE - Residencias           |\n");
                                printf("        | C1 - Campus1               |\n");
                                printf("        | C2 - Campus2               |\n");
                                printf("        | C3 - Campus3               |\n");
                                printf("        | C5 - Campus5               |\n");
                                printf("        |  0 - Cancelar              |\n");
                                printf("        |____________________________|\n\n");

                                do
                                {
                                    readLapLocation(laptop,equalIndex,&cancel);

                                    if (lastLocation == laptop[equalIndex].location && cancel == FALSE_0)
                                    {
                                        printf("        O portatil ja esta nesta localizacao!\n");
                                    }
                                    if (lastLocation != laptop[equalIndex].location && cancel == FALSE_0)
                                    {
                                        printf("        Localizacao alterada com sucesso!\n\n");
                                        storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                        printf("        ");
                                        enterToContinue();
                                    }
                                }
                                while (lastLocation == laptop[equalIndex].location && cancel == FALSE_0);


                            }
                        }
                        if (equalIndex == -1)
                        {
                            printf("        Nao existe um portatil com este ID!\n");
                        }

                    }
                    while(equalIndex == -1 && readedID != 0);
                    }else{
                    printf("         ____________________________\n");
                    printf("        |_PORTATEIS______________(X)_|\n");
                    printf("        |                            |\n");
                    printf("        | Nao existem portateis para |\n");
                    printf("        | serem movidos.             |\n");
                    printf("        |____________________________|\n\n");
                    printf("        ");
                    enterToContinue();
                    }

                    break;
                case 4:
                    cancel = FALSE_0;
                    clrScr();

                    printf("         _______________________________________\n");
                    printf("        |_PORTATEIS_________________________(X)_|\n");
                    printf("        |                                       |\n");
                    printf("        | Digite o id do portatil que pretendes |\n");
                    printf("        | registar a avaria/reparacao.          |\n");
                    printf("        | Digite 0 para cancelar.               |\n");
                    printf("        |_______________________________________|\n\n");

                    strcpy(message,"ID do Portatil");

                    do{

                    readInt(message,&readedID,0,MAX_ID);

                    if(readedID > 0)
                    {
                        searchEqualLapId(&equalIndex,laptop,totalLaptops,readedID);

                        if (equalIndex > -1)
                        {
                            do{

                            if (laptop[equalIndex].damagesCounterActive != 0)
                            {
                                clrScr();
                                getNumOfDigits(&idDigits,laptop[equalIndex].id)
                                printf("         ____________________\n");
                                printf("        |_PORTATEIS______(X)_|\n");
                                printf("        |                    |\n");
                                printf("        | Selecionado:       |\n");
                                printf("        | ->Portatil ID#%d",laptop[equalIndex].id);
                                alignMargin(idDigits,4);
                                printf("        |                    |\n");
                                printf("        | Pretende registar: |\n");
                                printf("        | 1 - Avaria         |\n");
                                printf("        | 2 - Reparacao      |\n");
                                printf("        | 3 - Cancelar       |\n");
                                printf("        |____________________|\n\n");
                            }

                            if (laptop[equalIndex].damagesCounterActive != 0)
                            {
                                strcpy(message,"Selecione uma opcao");
                                readInt(message,&optLapSubMenu,1,3);

                            }
                            else
                            {
                                optLapSubMenu = 1;
                            }


                            switch(optLapSubMenu)
                            {
                            case 1:
                                if(laptop[equalIndex].damagesCounterActive == 0)
                                {

                                    printf("         _________________________________________\n");
                                    printf("        |_PORTATEIS___________________________(X)_|\n");
                                    printf("        |                                         |\n");
                                    printf("        | O portatil nao tem avarias por reparar, |\n");
                                    printf("        | so e possivel registar avarias.         |\n");
                                    printf("        |_________________________________________|\n\n");
                                }

                                strcpy(message,"Digite quantas avarias desejas\n        registar para este portatil");
                                readInt(message,&numOfDamages,1,9999);

                                for (index = 0; index<numOfDamages; index++){

                                    //Adicionar espaço ao vetor dinamico damagesList
                                    printf("         _________________________________________\n");
                                    printf("        |_PORTATEIS___________________________(X)_|\n");
                                    printf("        |                                         |\n");
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
                                    readInt(message,&optDamageMenu,1,13);

                                    switch(optDamageMenu){
                                case 1:
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    break;
                                case 6:
                                    break;
                                case 7:
                                    break;
                                case 8:
                                    break;
                                case 9:
                                    break;
                                case 10:
                                    break;
                                case 11:
                                    break;
                                case 12:
                                    break;


                                    }

                                    if (optDamageMenu == 13){
                                        cancel = TRUE_1;
                                        readedID = 0;
                                        numOfDamages = index;
                                    }


                                //enterToContinue();
                                }
                                    if (cancel == TRUE_1){
                                        getNumOfDigits(&damagesDigits,numOfDamages);
                                        printf("         _________________________________________________\n");
                                        printf("        |_PORTATEIS___________________________________(X)_|\n");
                                        printf("        |                                                 |\n");
                                        printf("        | Foi(ram) registada(s) apenas %d avaria(s).",numOfDamages);
                                        alignMargin(damagesDigits,7);
                                        printf("        |_________________________________________________|\n\n");

                                        printf("        ");
                                        enterToContinue();
                                    }


                                break;
                            case 2:
                                break;
                            case 3:
                                cancel = TRUE_1;
                                readedID = 0;
                                break;

                            }

                        }while (cancel != TRUE_1);

                        }
                        if (equalIndex == -1)
                        {
                            printf("        Nao existe um portatil com este ID!\n");

                        }
                    }

                    }while (readedID != 0);
                    break;
                }


        }
        while (optLapMenu != 5);
        break;
    case 2:
        printf("Caso 2\n");
        break;
    case 3:
        printf("Caso 3\n");
        //infoLaptop();
        break;
    case 4:
        clrScr();

        optExtMenu = 0;

        printf("         _______________________________\n");
        printf("        |_SAIR______________________(X)_|\n");
        printf("        |                               |\n");
        printf("        | Tem certeza que deseja sair?  |\n");
        printf("        | 1 - Nao                       |\n");
        printf("        | 2 - Sim                       |\n");
        printf("        |_______________________________|\n\n");

        strcpy(message,"Selecione uma opcao");
        readInt(message,&optExtMenu,1,2);

        break;
    }
}
while(optExtMenu != 2);

free(request);
return 0;
}

void enterToContinue(void)
{
    printf("Pressione ENTER para continuar...");

    if (getchar() != '\n') //Impede que comece o menu com um erro de "Valor Inválido!"
    {
        flushStdin();
    }

}
