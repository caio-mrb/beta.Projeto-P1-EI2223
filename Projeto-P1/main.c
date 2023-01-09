#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "funcoesDePortateis.h"
#include "funcoesDeRequisicoes.h"
#include "funcoesDeDados.h"
#include "funcoesDeDesign.h"
#include "constantes.h"


int main()
{
    //Cria e inicializa a 0 um vetor estatico com MAX_LAPTOPS posi��es
    //Constante MAX_LAPTOPS = 30
    LaptopType laptop[MAX_LAPTOPS] = {0};

    //Cria um vetor dinamico
    RequestType *request = NULL;

    //Cria e inicializa a 0 quatro variaveis.
    //totalLaptops: Representa todos os portateis inseridos no sistema
    //availableLaptops: Representa todos os portateis dispon�veis para serem requisitados
    //totalRequests: Representa todas as requisi��es efetuadas no sistema
    //activeRequests: Representa todas as requisi��es ativas
    int totalLaptops = 0, availableLaptops = 0, totalRequests = 0, activeRequests = 0;

    //Desenha o titulo do projeto
    drawTittle();

    //Cria um ficheiro para verificar se o programa j� foi executado alguma vez no computador do utilizador
    FILE *check;

    //Verifica se consegue abrir o ficheiro "info.dat"
    check = fopen("info.dat","rb");

    //Se n�o conseguir conclui que � a primeira vez que o utilizador abre o programa
    if (check == NULL)
    {
        //Desenha a mensagem de bem-vindo
        drawWelcome();
    }
    //Se conseguir conclui que n�o � a primeira vez que o utilizador abre o programa
    else
    {

        //Desenha a mensagem de bem-vindo de volta
        drawWelcomeBack();

        //Carrega a informa��o do ficheiro para os respetivos ficheiros
        request = loadFileToInfo(laptop,&totalLaptops,request,&totalRequests);

        //Fecha o arquivo que foi previamente aberto
        fclose(check);
    }

    //Aguarda o input do utilizador para dar seguimento ao programa
    enterToContinue("\0");

    int optMainMenu,optLapMenu,optReqMenu,optExtMenu,optDamageMenu,optRepairMenu,optInfoMenu,optReturnMenu,optRenewMenu,optReqInfoMenu;

    int index,equalIndex,readedID=0,numOfLaptops,numOfRequests,numOfDamages,numOfReturns,numOfRenews;

    int *damagesIndex, totalPermanentDamages, sizeDamageIndex = 0, cancelOption;

    int cancel = FALSE_0;

    char message[MAX_READ_MESSAGE_SIZE] = "Selecione uma opcao";

    do
    {
        numAvailableLaptops(&availableLaptops,laptop,totalLaptops);
        numActiveRequests(&activeRequests,request,totalRequests);
        //Limpa a tela
        clearScreen();

        //Desenha o menu principal
        drawMainMenu(totalLaptops,availableLaptops,totalRequests,activeRequests);

        //Pede uma op��o (int) ao utilizador
        strcpy(message,"Selecione uma opcao");
        readInt(message,&optMainMenu,1,4);

        //Executa alguma a��o de acordo com a escolha do utilizador
        //Op��o 1: Menu dos portateis com 4 op��es
        //Op��o 2: Menu das requisi��es/devolu��es com 4 op��es
        //Op��o 3: Mostra as estat�sticas
        //Op��o 4: Menu para confirmar a escolha de sair

        ///----------------------------------------------COME�O MENU PRINCIPAL----------------------------------------------
        switch (optMainMenu)
        {
        case 1:
            /************************************************COME�O OP��O PORTATEIS******************************************************/
            do
            {
                //Limpa a tela
                clearScreen();

                //Desenha o menu dos portateis
                drawLaptopMenu();

                //Altera o texto da mensagem para fazer sentido ao utilizador
                strcpy(message,"Selecione uma opcao");
                //Pede uma op��o (int) ao utilizador
                readInt(message,&optLapMenu,1,5);

                //Executa alguma a��o de acordo com a escolha do utilizador
                //Op��o 1: Adicionar portateis
                //Op��o 2: Listar informa��es dos portateis
                //Op��o 3: Menu das estat�sticas com X submenus

                ///----------------------------------------------COME�O MENU DE PORTATEIS----------------------------------------------
                switch (optLapMenu)
                {
                case 1:
                    /*************************************COME�O OP��O ADICIONAR PORTATEIS**************************************************/

                    /** Nesta op��o o utilizador pode:                   **
                      * ->Escolher a quantidade de portateis a adicionar *
                      * ->Cancelar a adi��o durante o processo           *
                      *                                                  *
                      * Nesta op��o o utilizador n�o pode:               *
                      * ->Adicionar mais que MAX_LAPTOPS portateis       *
                      * Constante MAX_LAPTOPS = 30                       **/

                    //Limpa a tela
                    clearScreen();

                    //Verifica se j� foi atingido o limite de portateis existentes
                    if (totalLaptops == MAX_LAPTOPS)
                    {
                        //Desenha o alerta de limite de portateis atingido
                        drawMaxLaptopsReachAlert();
                        enterToContinue("        ");
                    }
                    //Executa se for poss�vel adicionar um novo portatil
                    else
                    {
                        //Limpa a tela
                        clearScreen();

                        //Desenha a mensagem de adi��o de portatil
                        /*Mais informa��es em "fun��esDeDesign.h"*/
                        drawAddLaptop(totalLaptops);

                        //Altera a mensagem da string para fazer sentido ao utilizador
                        strcpy(message,"Digite quantos portateis deseja adicionar");

                        //Le um numero (int) introduzido pelo utilizador e armazena no segundo parametro
                        /*Mais informa��es em "fun��esDeDados.h"*/
                        readInt(message,&numOfLaptops,0,(MAX_LAPTOPS - totalLaptops));

                        //Verifica se o ID introduzido pelo utilizador � maior que 0
                        if (numOfLaptops > 0)
                        {
                            //Define a variavel como falso
                            cancel = FALSE_0;

                            //Repete o ciclo o numero de vezes que o utilizador inseriu
                            for (index = 0; index<numOfLaptops; index++)
                            {
                                clearScreen();

                                //Pede todas as informa��es ao utilizador para a adi��o de um novo port�til
                                registerNewLaptop(laptop,totalLaptops,index,numOfLaptops,&cancel);

                                if (cancel == FALSE_0)
                                {
                                    //Acrescenta um aos portateis disponiveis
                                    availableLaptops++;
                                    //Acrescenta um ao total de portateis
                                    totalLaptops++;
                                    //Guarda a informa��o do portatil adicionado no ficheiro "info.dat"
                                    storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                }
                                //Executa se o pedido de adi��o tiver sido cancelado
                                else
                                {
                                    //Iguala o n�mero de portateis ao �ndice para quebrar o ciclo e cancelar a adi��o de novos portateis
                                    numOfLaptops = index;
                                }
                            }

                            //Executa se o pedido de adi��o tiver sido cancelado e o numero
                            //de portateis a serem adicionados for maior que 0
                            if (cancel == TRUE_1 && numOfLaptops > 0)
                            {
                                clearScreen();
                                //Desenha o aviso que apenas alguns portateis foram adicionados
                                drawAddLaptopCancel(numOfLaptops);
                                //Aguarda o input do utilizador para dar seguimento ao programa
                                enterToContinue("        ");
                            }
                        }
                    }
                    /*******************************************FIM OP��O ADICIONAR PORTATEIS*****************************************/
                    break;
                case 2:
                    /**********************************COME�O OP��O LISTAR INFORMA��O DOS PORTATEIS***********************************/

                    /** Nesta op��o o utilizador pode:                         *
                      * ->Listar a informa��o de todos os portateis existentes **/

                    if (totalLaptops > 0)
                    {
                        do
                        {
                            clearScreen();

                            drawInfoMenu();

                            strcpy(message,"Selecione uma opcao");

                            readInt(message,&optInfoMenu,1,3);

                            switch(optInfoMenu)
                            {
                            case 1:
                                clearScreen();
                                //Mostra a informa��o base de todos os portateis existentes
                                showLaptopInfo(laptop,totalLaptops,request,totalRequests);
                                //Aguarda o input do utilizador para dar seguimento ao programa
                                enterToContinue("        ");
                                break;
                            case 2:
                                clearScreen();
                                //Mostra o historico de avarias de todos os portateis existentes
                                showDamageHistoric(laptop,totalLaptops);
                                //Aguarda o input do utilizador para dar seguimento ao programa
                                enterToContinue("        ");
                                break;
                            }

                        }
                        while (optInfoMenu != 3);
                    }
                    else
                    {
                        clearScreen();
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue("        ");
                    }
                    /**********************************FIM OP��O LISTAR INFORMA��O DOS PORTATEIS***************************************/
                    break;
                case 3:
                    /*********************************COME�O OP��O ALTERAR LOCALIZA��O DO PORTATIL*************************************/

                    /** Nesta op��o o utilizador pode:                              *
                      * ->Alterar a localiza��o de um portatil existente            *
                      *                                                             *
                      * Nesta op��o o utilizador n�o pode:                          *
                      * ->Mover o portatil para a localiza��o em que j� se encontra **/

                    //Limpa a tela
                    clearScreen();

                    //Executa se existirem portateis no sistema
                    if (totalLaptops > 0)
                    {
                        //Desenha a mensagem de pedir um id para mover o portatil
                        drawLaptopIdToMove();

                        //Muda o texto da mensagem para fazer sentido ao utilizador
                        strcpy(message,"ID do Portatil");

                        //-----Do{}While-----
                        //Executa o conjuto de instru��es
                        //a seguir enquanto o utilizador
                        //inserir um ID inexistente
                        //(equalIndex == -1) e enquanto
                        //n�o pedir para cancelar
                        //(readedID != 0)
                        do
                        {
                            //Redefine a variavel para falso
                            cancel = FALSE_0;

                            //L� um inteiro inserido pelo utilizador at� MAX_ID
                            //Constante MAX_ID = 9999
                            readInt(message,&readedID,0,MAX_ID);

                            //Executa se o utilizador n�o cancelar a a��o
                            if(readedID > 0)
                            {
                                //Procura um portatil com um id igual ao pedido pelo utilizador e guarda no primeiro par�metro, caso contr�rio devolve -1
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                searchEqualLaptopId(&equalIndex,laptop,totalLaptops,readedID);

                                //Executa se encontrar um portatil com o ID inserido pelo utliziador
                                if (equalIndex > -1)
                                {
                                    //Limpa a tela
                                    clearScreen();

                                    changeLaptopLocation(laptop,equalIndex,&cancel);
                                    //Armazena a informa��o alterada no ficheiro "info.dat"
                                    /*Mais informa��es em "funcoesDeDados.h"*/
                                    storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                    //Aguarda o input do utilizador para dar seguimento ao programa
                                    enterToContinue("        ");
                                }
                            }
                            //Executa se n�o encontrar um portatil com o ID inserido pelo utilizador
                            if (equalIndex == -1)
                            {
                                //Informa o utilizador que n�o foi encontrado um portatil com o ID inserido
                                printf("        Nao existe um portatil com este ID!\n");
                            }

                        }
                        while(equalIndex == -1 && readedID != 0);
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue("        ");
                    }
                    /********************************FIM OP��O ALTERAR LOCALIZA��O DO PORTATIL****************************************/
                    break;
                case 4:
                    /***************************COME�O OP��O REGISTAR AVARIA/REPARA��O DO PORTATIL************************************/
                    /** Nesta op��o o utilizador pode:                                                       *
                      * ->Registar X avarias de um portatil                                                  *
                      * ->Registar o reparo de todas as avarias temporarias ainda por reparar de um portatil *
                      *                                                                                      *
                      * Nesta op��o o utilizador n�o pode:                                                   *
                      * ->Escolher reparar um portatil se n�o possuir avarias por reparar                    **/

                    //Limpa a tela
                    clearScreen();

                    //Executa se houverem portateis no sistema
                    if (totalLaptops > 0)
                    {
                        //Desenha o pedido de ID ao utilizador referente ao portatil para registar avaria/repara��o
                        drawLaptopIdDamageAsk();

                        //Muda o texto da mensagem para fazer sentido ao utilizador
                        strcpy(message,"ID do Portatil");

                        //-----Do{}While-----
                        //Executa o conjunto de instru��es
                        //a seguir enquanto o utilizador n�o
                        //pedir para cancelar (readedID != 0)
                        do
                        {
                            //Redefine o valor da variavel para falso
                            cancel = FALSE_0;

                            //L� um inteiro inserido pelo utilizador at� MAX_ID
                            //Constante MAX_ID = 9999
                            readInt(message,&readedID,0,MAX_ID);

                            //Executa se o utilizador n�o pedir para cancelar
                            if(readedID > 0)
                            {

                                //Procura um portatil com um id igual ao pedido pelo utilizador e guarda no primeiro par�metro, caso contr�rio devolve -1
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                searchEqualLaptopId(&equalIndex,laptop,totalLaptops,readedID);

                                //Executa se encontrar um portatil com o id inserido pelo utilizador
                                if (equalIndex > -1)
                                {

                                    //Executa se o portatil n�o possuir avarias registadas
                                    if(laptop[equalIndex].damagesCounterTotal == 0)
                                    {
                                        //Inicializa o vetor dinamico da lista de avarias do respetivo portatil a NULL
                                        laptop[equalIndex].damagesList = NULL;
                                    }

                                    numPermanentDamages(&totalPermanentDamages,laptop[equalIndex].damagesList,laptop[equalIndex].damagesCounterTotal);

                                    if(totalPermanentDamages < 12 || laptop[equalIndex].damagesCounterActive !=0)
                                    {

                                        //-----Do{}While-----
                                        //Executa o conjunto de instru��es
                                        //a seguir enquanto o utilizador n�o
                                        //pedir para cancelar (readedID != 0)

                                        do
                                        {
                                            //Executa se o portatil selecionado pelo utilizador possuir avarias ativas
                                            if (laptop[equalIndex].damagesCounterActive != 0)
                                            {
                                                if (totalPermanentDamages < 12)
                                                {
                                                    //Limpa a tela
                                                    clearScreen();

                                                    //Desenha o menu de avarias/repara��es
                                                    drawLaptopDamagesSubMenu(laptop[equalIndex].id);

                                                    //Altera o texto da mensagem para fazer sentido ao utilizador
                                                    strcpy(message,"Selecione uma opcao");
                                                    //L� uma op��o (int) do menu de avarias/repara��es
                                                    readInt(message,&optDamageMenu,1,3);
                                                }
                                                else
                                                {
                                                    //Limpa a tela
                                                    clearScreen();

                                                    //Desenha o alerta que o portatil selecionado pelo utilizador j� possui o m�ximo
                                                    //de avarias poss�vel e s� � poss�vel registar a repara��o das avarias pendentes
                                                    drawDamagesMaxPermanent();

                                                    //Redefine o valor da variavel para falso
                                                    enterToContinue("        ");

                                                    optDamageMenu = 2;
                                                }

                                            }
                                            //Executa se o portatil selecionado pelo utilizador n�o possuir avarias ativas o que implica s� poder registar avarias
                                            //e n�o repara��es, ou seja, sem avarias ativas � imposs�vel registar repara��es.
                                            else
                                            {
                                                //Define a variavel como 1 (Registar Avaria)
                                                optDamageMenu = 1;
                                            }

                                            ///--------------------------------------COME�O SUBMENU DE AVARIAS/REPARA��ES------------------------------------------
                                            switch(optDamageMenu)
                                            {
                                            case 1:
                                                /*******************************************COME�O OP��O 1************************************************/
                                                /** Nesta op��o o utilizador pode:      *
                                                  * ->Registar X avarias de um portatil *
                                                  *                                     *
                                                  * Nesta op��o o utilizador n�o pode:  *
                                                  * ->Alterar o poratil j� selecionado  **/
                                                if(laptop[equalIndex].state == REQUESTED)
                                                {
                                                    cancel = FALSE_0;

                                                    drawReturnSubMenuInDamageMenu();
                                                    //Altera o texto da mensagem para fazer sentido ao utilizador
                                                    strcpy(message,"Selecione uma opcao");
                                                    //L� uma op��o (int) do menu de avarias/repara��es
                                                    readInt(message,&optReturnMenu,1,2);
                                                    if(optReturnMenu == 2)
                                                    {
                                                        cancel = TRUE_1;
                                                    }
                                                    else
                                                    {
                                                        registerReturnByDamageMenu(laptop, totalLaptops, request, totalRequests, equalIndex, &cancel);
                                                    }
                                                }
                                                if(cancel == FALSE_0)
                                                {
                                                    //Executa se o portatil n�o possuir avarias por arranjar
                                                    if(laptop[equalIndex].damagesCounterActive == 0)
                                                    {
                                                        //Limpa a tela
                                                        clearScreen();

                                                        //Desenha o alerta que o portatil selecionado pelo utilizador n�o possui avarias por arranjar
                                                        //e s� � possivel registar novas avarias
                                                        drawDamagensNoneActive(laptop[equalIndex].id);

                                                        //Redefine o valor da variavel para falso
                                                        cancel = FALSE_0;
                                                    }

                                                    //Altera o texto da mensagem para fazer sentido ao utilizador
                                                    strcpy(message,"Digite quantas avarias desejas registar");

                                                    //L� a quantidade de avarias (int) que o utilizador deseja registar
                                                    readInt(message,&numOfDamages,0,9999);

                                                    //Executa se o utilizador n�o pedir para cancelar
                                                    if (numOfDamages > 0)
                                                    {
                                                        //Repete o ciclo o numero de vezes que o utilizador inseriu
                                                        for (index = 0; index<numOfDamages; index++)
                                                        {
                                                            //Limpa a tela
                                                            clearScreen();

                                                            registerNewDamage(laptop,equalIndex,&index,numOfDamages,&cancel);

                                                            //Executa se o registo de avaria n�o tiver sido cancelado
                                                            if(cancel == FALSE_0)
                                                            {
                                                                if(laptop[equalIndex].damagesList[laptop[equalIndex].damagesCounterTotal-1].type == PERMANET)
                                                                {
                                                                    totalPermanentDamages++;
                                                                }
                                                                //Armazena no ficheiro as atualiza��es do portatil
                                                                storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                                            }

                                                            ////Executa se o registo de avaria tiver sido cancelado
                                                            if (cancel == TRUE_1 || totalPermanentDamages == 12)
                                                            {
                                                                //Iguala o n�mero de avarias ao �ndice para quebrar o ciclo e cancelar o registo de novas avarias
                                                                numOfDamages = index;
                                                            }
                                                        }

                                                        //Executa se o pedido de registo de avaria tiver sido cancelado
                                                        //e o numero de avarias a serem registadas for maior que 0
                                                        if (cancel == TRUE_1 && numOfDamages > 0)
                                                        {
                                                            clearScreen();

                                                            //Desenha o aviso que apenas algumas avarias foram registadas
                                                            drawDamageCancel(numOfDamages);

                                                            //Aguarda o input do utilizador para dar seguimento ao programa
                                                            enterToContinue("        ");
                                                        }
                                                        if(totalPermanentDamages == 12)
                                                        {
                                                            clearScreen();

                                                            //Desenha o aviso que o maximo de avarias foi atingido
                                                            drawDamageCancelMaxPermanent();

                                                            //Aguarda o input do utilizador para dar seguimento ao programa
                                                            enterToContinue("        ");
                                                        }

                                                    }
                                                    //Executa se o utilizador pedir para cancelar
                                                    else
                                                    {
                                                        //Redefine o valor da variavel para verdadeiro
                                                        cancel = TRUE_1;
                                                    }
                                                }
                                                /********************************************FIM OP��O 1************************************************/
                                                break;
                                            case 2:
                                                /*******************************************COME�O OP��O 2***********************************************/
                                                /** Nesta op��o o utilizador pode:                       *
                                                  * ->Registar o reparo de todas as avarias por arranjar *
                                                  *                                                      *
                                                  * Nesta op��o o utilizador n�o pode:                   *
                                                  * ->Alterar qual � o poratil selecionado               **/
                                                //Encontra e armazena no vetor dinamico o indice de cada avaria
                                                //temporaria pertencente a lista de avarias do respetivo portatil.
                                                /*Mais informa��es em "funcoesDePortateis.c*/
                                                damagesIndex = searchTemporaryDamagesIndex(&sizeDamageIndex,laptop,equalIndex);
                                                do
                                                {
                                                    //Executa se encontrar avarias tempor�rias por arranjar
                                                    if (sizeDamageIndex>0)
                                                    {
                                                        cancelOption = sizeDamageIndex+1;
                                                        //Desenha a lista de avarias do respetivo portatil
                                                        drawRepairList(laptop,equalIndex,damagesIndex,sizeDamageIndex);
                                                        //Altera o texto da mensagem para fazer sentido ao utilizador
                                                        strcpy(message,"Selecione uma opcao");
                                                        //L� a op��o (int) da avaria para registar o arranjo
                                                        readInt(message,&optRepairMenu,1,cancelOption);

                                                        //Executa se o utilizador n�o pedir para cancelar
                                                        if (optRepairMenu != cancelOption)
                                                        {
                                                            damagesIndex = registerNewRepair(laptop,equalIndex,damagesIndex,&sizeDamageIndex,optRepairMenu);

                                                            //Armazena no ficheiro as atualiza��es do portatil
                                                            storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        clearScreen();

                                                        drawAllRepairSucessful();
                                                        //Aguarda o input do utilizador para dar seguimento ao programa
                                                        enterToContinue("        ");
                                                        //Iguala a op��o do menu de repara��o ao n�mero que cancela no menu para quebrar o ciclo
                                                        optRepairMenu = cancelOption;
                                                        //Redefine a variavel para verdadeiro para quebrar o outro ciclo e voltar ao menu dos portateis
                                                        cancel = TRUE_1;
                                                    }
                                                }
                                                while(optRepairMenu != cancelOption);


                                                /********************************************FIM OP��O 2************************************************/
                                                break;
                                            case 3:
                                                /*******************************************COME�O OP��O 3**********************************************/
                                                cancel = TRUE_1;
                                                /********************************************FIM OP��O 3************************************************/
                                                break;
                                            }
                                        }
                                        while (cancel == FALSE_0);
                                    }
                                    else
                                    {
                                        printf("        Este portatil ja possui o maximo de avarias possivel!\n");
                                    }
                                }
                                //Executa se n�o encontrar um portatil com o ID inserido pelo utilizador
                                if (equalIndex == -1)
                                {
                                    printf("        Nao existe um portatil com este ID!\n");
                                }
                            }
                            ///--------------------------------------------FIM SUBMENU DE AVARIAS/REPARA��ES------------------------------------------
                        }
                        while (readedID != 0 && cancel == FALSE_0);

                        /******************************FIM OP��O REGISTAR AVARIA/REPARA��O DO PORTATIL********************************/
                        break;
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue("        ");

                    }
                }
                ///---------------------------------------------------FIM MENU DE PORTATEIS----------------------------------------------
            }
            while (optLapMenu != 5);
            /************************************************FIM OP��O PORTATEIS******************************************************/
            break;
        case 2:
            /****************************************COME�O OP��O REQUISI��ES/DEVOLU��ES**********************************************/
            if (totalLaptops > 0)
            {
                do
                {

                    clearScreen();
                    cancel = FALSE_0;
                    drawRequestMenu();
                    strcpy(message,"Selecione uma opcao");
                    readInt(message,&optReqMenu,1,5);

                    switch (optReqMenu)
                    {
                    case 1:
                        if (availableLaptops > 0)
                        {
                            if (availableLaptops > 1)
                            {
                                strcpy(message,"Digite quantas requisicoes pretendes registar");
                                readInt(message,&numOfRequests,0,availableLaptops);
                            }
                            else
                            {
                                numOfRequests = 1;
                            }
                            for (index = 0; index<numOfRequests; index++)
                            {
                                clearScreen();

                                request = registerNewRequest(laptop, totalLaptops, request, &totalRequests, index, numOfRequests, &cancel);

                                if (cancel == TRUE_1)
                                {
                                    numOfRequests = index;
                                }
                                else
                                {
                                    availableLaptops--;
                                    activeRequests++;
                                }
                            }

                            if (cancel == TRUE_1 && numOfRequests > 0)
                            {
                                clearScreen();
                                //Desenha o aviso que apenas algumas requisi��es foram registadas
                                drawRequestCancel(numOfRequests);
                                //Aguarda o input do utilizador para dar seguimento ao programa
                                enterToContinue("        ");
                            }
                        }
                        else
                        {
                            clearScreen();
                            //Desenha o alerta de 0 portateis disponiveis no sistema
                            drawLaptopsUnavailable();
                            //Aguarda o input do utilizador para dar seguimento ao programa
                            enterToContinue("        ");

                        }
                        break;
                    case 2:
                        if (activeRequests > 0)
                        {
                            do
                            {
                                clearScreen();
                                cancel = FALSE_0;
                                drawRequestReturnSubMenu();
                                strcpy(message,"Selecione uma opcao");
                                readInt(message,&optReturnMenu,1,3);
                                if (optReturnMenu != 3)
                                {
                                    if(activeRequests > 1)
                                    {
                                        strcpy(message,"Selecione quantas devolucoes pretendes registar");
                                        readInt(message,&numOfReturns,0,activeRequests);
                                        if (numOfReturns == 0)
                                        {
                                            cancel = TRUE_1;
                                        }
                                    }
                                    else
                                    {
                                        numOfReturns = 1;
                                    }
                                }
                                else
                                {
                                    cancel = TRUE_1;
                                }
                                if(cancel == FALSE_0)
                                {
                                    switch(optReturnMenu)
                                    {
                                    case 1:
                                        for (index = 0; index<numOfReturns; index++)
                                        {
                                            clearScreen();

                                            registerReturnByLaptopId(laptop,totalLaptops,request,totalRequests,index,numOfReturns,&cancel);

                                            if (cancel == TRUE_1)
                                            {
                                                numOfReturns = index;
                                            }
                                        }
                                        break;
                                    case 2:
                                        for (index = 0; index<numOfReturns; index++)
                                        {
                                            clearScreen();

                                            registerReturnByRequestCode(laptop,totalLaptops,request,totalRequests,index,numOfReturns,&cancel);

                                            if (cancel == TRUE_1)
                                            {
                                                numOfReturns = index;
                                            }
                                        }
                                        break;
                                    }
                                    activeRequests -= numOfReturns;
                                    availableLaptops += numOfReturns;

                                    if(cancel == TRUE_1 && numOfReturns > 0)
                                    {
                                        clearScreen();
                                        //Desenha o aviso que apenas algumas devolu��es foram registadas
                                        drawReturnCancel(numOfReturns);
                                        //Aguarda o input do utilizador para dar seguimento ao programa
                                        enterToContinue("        ");
                                        optReturnMenu = 3;
                                    }

                                    if (activeRequests == 0 && numOfReturns > 0)
                                    {
                                        clearScreen();
                                        //Desenha o alerta de que todas as devolucoes foram registadas no sistema com sucesso
                                        drawAllReturnSucessful();
                                        //Aguarda o input do utilizador para dar seguimento ao programa
                                        enterToContinue("        ");
                                        optReturnMenu = 3;
                                    }
                                }
                            }
                            while(optReturnMenu != 3);
                        }
                        else
                        {
                            clearScreen();
                            //Desenha o alerta de 0 requisicoes ativas no sistema
                            drawActiveRequestsNotFound();
                            //Aguarda o input do utilizador para dar seguimento ao programa
                            enterToContinue("        ");
                        }
                        break;
                    case 3:
                        if (activeRequests > 0)
                        {
                            do
                            {
                                clearScreen();
                                cancel = FALSE_0;
                                drawRequestRenewSubMenu();
                                strcpy(message,"Selecione uma opcao");
                                readInt(message,&optRenewMenu,1,3);
                                if (optRenewMenu != 3)
                                {
                                    strcpy(message,"Selecione quantas renovacoes pretendes registar");
                                    readInt(message,&numOfRenews,0,999);
                                    if (numOfRenews == 0)
                                    {
                                        cancel = TRUE_1;
                                    }
                                }
                                else
                                {
                                    cancel = TRUE_1;
                                }
                                if(cancel == FALSE_0)
                                {
                                    switch(optRenewMenu)
                                    {
                                    case 1:
                                        for (index = 0; index<numOfRenews; index++)
                                        {
                                            clearScreen();

                                            registerRenewByLaptopId(laptop,totalLaptops,request,totalRequests,index,numOfRenews,&cancel);

                                            if (cancel == TRUE_1)
                                            {
                                                numOfRenews = index;
                                            }
                                        }
                                        break;
                                    case 2:
                                        for (index = 0; index<numOfRenews; index++)
                                        {
                                            clearScreen();

                                            registerRenewByRequestCode(laptop,totalLaptops,request,totalRequests,index,numOfRenews,&cancel);

                                            if (cancel == TRUE_1)
                                            {
                                                numOfRenews = index;
                                            }
                                        }
                                        break;
                                    }

                                    if(cancel == TRUE_1 && numOfRenews > 0)
                                    {
                                        clearScreen();
                                        //Desenha o aviso que apenas algumas devolu��es foram registadas
                                        drawRenewCancel(numOfRenews);
                                        //Aguarda o input do utilizador para dar seguimento ao programa
                                        enterToContinue("        ");
                                        optReturnMenu = 3;
                                    }
                                }
                            }
                            while(optRenewMenu != 3);
                        }
                        else
                        {
                            clearScreen();
                            //Desenha o alerta de 0 requisicoes ativas no sistema
                            drawActiveRequestsNotFound();
                            //Aguarda o input do utilizador para dar seguimento ao programa
                            enterToContinue("        ");
                        }
                        break;
                    case 4:
                        if(totalRequests > 0)
                        {
                            do
                            {
                                clearScreen();
                                cancel = FALSE_0;
                                drawRequestShowInfoSubMenu();
                                strcpy(message,"Selecione uma opcao");
                                readInt(message,&optReqInfoMenu,1,3);

                                switch(optReqInfoMenu)
                                {
                                case 1:
                                    clearScreen();
                                    drawRequestCodeToShowInfoAsk();

                                    readRequestCodeToShowInfo(&index,request,totalRequests,&cancel);
                                    if(cancel == FALSE_0)
                                    {
                                        clearScreen();
                                        showRequestInfo(laptop,request,index);
                                        //Aguarda o input do utilizador para dar seguimento ao programa
                                        enterToContinue("        ");
                                    }
                                    break;
                                case 2:
                                    clearScreen();
                                    for (index = 0; index<totalRequests; index++)
                                    {
                                        showRequestInfo(laptop,request,index);
                                    }
                                    //Aguarda o input do utilizador para dar seguimento ao programa
                                    enterToContinue("        ");
                                    break;
                                }

                            }
                            while(optReqInfoMenu != 3);
                        }
                        else
                        {
                            clearScreen();
                            //Desenha o alerta de 0 requisicoes no sistema
                            drawRequestsNotFound();
                            //Aguarda o input do utilizador para dar seguimento ao programa
                            enterToContinue("        ");
                        }
                        break;
                    }

                }
                while(optReqMenu != 5);
            }
            else
            {
                clearScreen();
                //Desenha o alerta de 0 portateis no sistema
                drawLaptopsNotFound();
                //Aguarda o input do utilizador para dar seguimento ao programa
                enterToContinue("        ");
            }
            /******************************************FIM OP��O REQUISI��ES/DEVOLU��ES***********************************************/
            break;
        case 3:
            /*********************************************COME�O OP��O ESTATISTICAS***************************************************/
            clearScreen();
            if (totalLaptops > 0)
            {
                showStatistics(laptop,totalLaptops,request,totalRequests);
            }
            else
            {
                //Desenha o alerta de 0 portateis no sistema
                drawLaptopsNotFound();
            }

            //Aguarda o input do utilizador para dar seguimento ao programa
            enterToContinue("        ");

            /***********************************************FIM OP��O ESTATISTICAS****************************************************/
            //infoLaptop();
            break;
        case 4:
            /*********************************************COME�O CONFIRMA��O DE SAIDA*************************************************/
            //Limpa a tela
            clearScreen();

            //Desenha o alerta de confirma��o de sa�da
            drawConfirmExit();

            //Altera o texto da mensagem para fazer sentido ao utilizador
            strcpy(message,"Selecione uma opcao");
            //L� uma op��o (int) inserida pelo utilizador
            readInt(message,&optExtMenu,1,2);
            /***********************************************FIM CONFIRMA��O DE SAIDA***************************************************/
            break;
        }
        ///--------------------------------------------------FIM MENU PRINCIPAL----------------------------------------------
    }
    while(optExtMenu != 2);
    //Liberta a mem�ria do vertor dinamico
    free(request);
    return 0;
}


