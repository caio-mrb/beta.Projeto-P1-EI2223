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

    //Cria e inicializa a NULL um vetor dinamico
    RequestType *request = NULL;

    //Cria e inicializa a 0 quatro variaveis.
    //totalLaptops: Representa todos os portateis inseridos no sistema
    //availableLaptops: Representa todos os portateis dispon�veis para serem requisitados
    //totalRequests: Representa todas as requisi��es efetuadas no sistema
    //activeRequests: Representa todas as requisi��es ativas
    int totalLaptops = 0, availableLaptops, totalRequests = 10, activeRequests = 0;

    //Aloca na memoria memoria no vetor dinamico
    request = malloc(totalRequests*sizeof(RequestType));

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
    enterToContinue();


    int optMainMenu,optLapMenu, optDamageMenu,numOfLaptops,optReqMenu,optStatsMenu,optExtMenu,index,equalIndex,lastLocation,readedID = 0, optRepairMenu, idDigits;

    DamageType damageInfo;

    int *damagesIndex, numOfDamages, sizeDamageIndex = 0;

    int cancel = FALSE_0;

    char message[MAX_READ_MESSAGE_SIZE] = "Selecione uma opcao";

    numAvailableLaptops(&availableLaptops,laptop,totalLaptops);
    numActiveRequests(&activeRequests,request,totalRequests);

    do
    {
        //Limpa a tela
        clearScreen();

        //Desenha o menu principal
        drawMainMenu(totalLaptops,availableLaptops,totalRequests,activeRequests);

        //Pede uma op��o (int) ao utilizador
        strcpy(message,"Selecione uma opcao");
        readInt(message,&optMainMenu,1,4);

        //Executa alguma a��o de acordo com a escolha do utilizador
        //Op��o 1: Menu dos portateis com 4 submenus
        //Op��o 2: Menu das requisi��es/devolu��es com X submenus
        //Op��o 3: Menu das estat�sticas com X submenus
        //Op��o 4: Menu para confirmar a escolha de sair

        //----------------------------------------------COME�O MENU PRINCIPAL----------------------------------------------
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


                //----------------------------------------------COME�O MENU DE PORTATEIS----------------------------------------------
                switch (optLapMenu)
                {
                case 1:
                    /************************************************COME�O OP��O 1******************************************************/

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

                        printf("         ");
                        enterToContinue();
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
                                //Limpa a tela
                                clearScreen();

                                //Desenha o pedido de informa��es
                                drawLaptopInfoAsk(index,numOfLaptops);

                                //L� o ID do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapId(laptop,totalLaptops,&cancel);

                                //L� a designa��o do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapName(laptop,totalLaptops,&cancel);

                                //L� o processador do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapProcessor(laptop,totalLaptops,&cancel);

                                //L� a quantidade de memoria RAM do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapRam(laptop,totalLaptops,&cancel);

                                //L� o pre�o do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapPrice(laptop,totalLaptops,&cancel);

                                //L� a data de compra do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapPurchaseDate(laptop,totalLaptops,&cancel);

                                //Executa se o pedido de adi��o n�o tiver sido cancelado
                                if (cancel == FALSE_0)
                                {
                                    //Desenha a lista de localiza��es poss�veis para o portatil
                                    drawLocationsMiniList();
                                }

                                //L� a localiza��o do portatil a ser adicionado se o pedido de adi��o n�o tiver sido cancelado
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                readLapLocation(laptop,totalLaptops,&cancel);

                                //Executa se o pedido de adi��o n�o tiver sido cancelado
                                if (cancel == FALSE_0)
                                {
                                    //Define o estado do portatil a ser adicionado como dispon�vel
                                    laptop[totalLaptops].state = AVAILABLE;
                                    //Acrescenta um aos portateis disponiveis
                                    availableLaptops++;
                                    //Acrescenta um ao total de portateis
                                    totalLaptops++;
                                    //Guarda a informa��o do portatil adicionado no ficheiro "info.dat"
                                    storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                }

                                //Executa se o pedido de adi��o tiver sido cancelado
                                if (cancel == TRUE_1)
                                {
                                    //Iguala o n�mero de portateis ao �ndice para quebrar o ciclo e cancelar a adi��o de novos portateis
                                    numOfLaptops = index;
                                }
                            }

                            //Executa se o pedido de adi��o tiver sido cancelado e o numero
                            //de portateis a serem adicionados for maior que 0
                            if (cancel == TRUE_1 && numOfLaptops > 0)
                            {
                                //Desenha o aviso que apenas alguns portateis foram adicionados
                                drawAddLaptopCancel(numOfLaptops);

                                //Desenha a margem a esquerda
                                printf("        ");

                                //Aguarda o input do utilizador para dar seguimento ao programa
                                enterToContinue();
                            }
                        }
                    }
                    /************************************************FIM OP��O 1******************************************************/
                    break;
                case 2:
                    /**********************************************COME�O OP��O 2*****************************************************/

                    /** Nesta op��o o utilizador pode:                         *
                      * ->Listar a informa��o de todos os portateis existentes **/


                    clearScreen();
                    if (totalLaptops > 0)
                    {
                        //Mostra a informa��o de todos os portateis existentes
                        showLaptopInfo(laptop,totalLaptops);
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();
                    }
                    /************************************************FIM OP��O 2*****************************************************/
                    break;
                case 3:
                    /**********************************************COME�O OP��O 3*****************************************************/

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
                                searchEqualLapId(&equalIndex,laptop,totalLaptops,readedID);

                                //Executa se encontrar um portatil com o ID inserido pelo utliziador
                                if (equalIndex > -1)
                                {
                                    //Armazena em uma variavel a localiza��o (int) atual do portatil
                                    lastLocation = laptop[equalIndex].location;

                                    //Desenha a lista de localiza��es poss�veis
                                    drawLocationsBigList();

                                    //-----Do{}While-----
                                    //Executa o conjuto de instru��es
                                    //a seguir enquanto o utilizador
                                    //pedir para mudar o portatil para
                                    //a posi��o em que j� se encontra
                                    //(lastLocation == laptop[equalIndex].location)
                                    //e enquanto n�o pedir para cancelar
                                    //(cancel == FALSE_0)
                                    do
                                    {
                                        //L� a localiza��o do portatil e sobrep�e a localiza��o anterior
                                        readLapLocation(laptop,equalIndex,&cancel);

                                        //Executa se o utilizador mover o portatil para a localiza��o em que j� se encontra e se n�o pedir pra cancelar
                                        if (lastLocation == laptop[equalIndex].location && cancel == FALSE_0)
                                        {
                                            //Informa o utilizador que est� a tentar mover para o posi��o que o portatil j� est�
                                            printf("        O portatil ja esta nesta localizacao!\n");
                                        }

                                        //Executa se o utilizador mover o portatil para uma localiza��o diferente da que j� se encontra e se n�o pedir pra cancelar
                                        if (lastLocation != laptop[equalIndex].location && cancel == FALSE_0)
                                        {
                                            //Informa o utilizador que a localiza��o do portatil foi alterada com sucesso
                                            printf("        Localizacao alterada com sucesso!\n\n");
                                            //Armazena a informa��o alterada no ficheiro "info.dat"
                                            /*Mais informa��es em "funcoesDeDados.h"*/
                                            storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                            //Desenha a margem a esquerda
                                            printf("        ");
                                            //Aguarda o input do utilizador para dar seguimento ao programa
                                            enterToContinue();
                                        }
                                    }
                                    while (lastLocation == laptop[equalIndex].location && cancel == FALSE_0);
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
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();
                    }
                    /************************************************FIM OP��O 3*****************************************************/
                    break;
                case 4:
                    /**********************************************COME�O OP��O 4*****************************************************/
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

                            //Execita se o utilizador n�o pedir para cancelar
                            if(readedID > 0)
                            {
                                //Procura um portatil com um id igual ao pedido pelo utilizador e guarda no primeiro par�metro, caso contr�rio devolve -1
                                /*Mais informa��es em "funcoesDePortateis.h*/
                                searchEqualLapId(&equalIndex,laptop,totalLaptops,readedID);

                                //Executa se encontrar um portatil com o id inserido pelo utilizador
                                if (equalIndex > -1)
                                {
                                    //Executa se o portatil n�o possuir avarias registadas
                                    if(laptop[equalIndex].damagesCounterTotal == 0)
                                    {
                                        //Inicializa o vetor dinamico da lista de avarias do respetivo portatil a NULL
                                        laptop[equalIndex].damagesList = NULL;
                                    }

                                    //-----Do{}While-----
                                    //Executa o conjunto de instru��es
                                    //a seguir enquanto o utilizador n�o
                                    //pedir para cancelar (readedID != 0)

                                    do
                                    {


                                        //Executa se o portatil selecionado pelo utilizador possuir avarias ativas
                                        if (laptop[equalIndex].damagesCounterActive != 0)
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
                                        //Executa se o portatil selecionado pelo utilizador n�o possuir avarias ativas o que implica s� poder registar avarias
                                        //e n�o repara��es, ou seja, sem avarias � imposs�vel registar repara��es.
                                        else
                                        {
                                            //Define a variavel como 1 (Registar Avaria)
                                            optDamageMenu = 1;
                                        }

                                        //--------------------------------------COME�O SUBMENU DE AVARIAS/REPARA��ES------------------------------------------
                                        switch(optDamageMenu)
                                        {
                                        case 1:
                                            /*******************************************COME�O OP��O 1************************************************/
                                            /** Nesta op��o o utilizador pode:      *
                                              * ->Registar X avarias de um portatil *
                                              *                                     *
                                              * Nesta op��o o utilizador n�o pode:  *
                                              * ->Alterar o poratil j� selecionado  **/

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

                                                    //L� o local/c�digo da avaria se o registo de avaria n�o tiver sido cancelado
                                                    /*Mais informa��es em "funcoesDePortateis.h*/
                                                    readDamageInfoCode(index,numOfDamages,&damageInfo, &cancel);

                                                    //L� o tipo da avaria se o registo de avaria n�o tiver sido cancelado
                                                    /*Mais informa��es em "funcoesDePortateis.h*/
                                                    readDamageInfoType(index,numOfDamages,&damageInfo, &cancel);

                                                    //L� a data da avaria se o registo de avaria n�o tiver sido cancelado
                                                    /*Mais informa��es em "funcoesDePortateis.h*/
                                                    readDamageInfoDate(index,numOfDamages,&damageInfo, &cancel);

                                                    //Armazena na lista de avarias do portatil se o registo de avaria n�o tiver sido cancelado
                                                    /*Mais informa��es em "funcoesDePortateis.h*/
                                                    laptop[equalIndex].damagesList = addDamageRepairInfo(damageInfo, laptop, equalIndex, &cancel);

                                                    //Executa se o registo de avaria n�o tiver sido cancelado
                                                    if(cancel == FALSE_0)
                                                    {
                                                        //Armazena no ficheiro as atualiza��es do portatil
                                                        storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                                    }

                                                    ////Executa se o registo de avaria tiver sido cancelado
                                                    if (cancel == TRUE_1)
                                                    {
                                                        //Iguala o n�mero de avarias ao �ndice para quebrar o ciclo e cancelar o registo de novas avarias
                                                        numOfDamages = index;
                                                    }
                                                }

                                                //Executa se o pedido de registo de avaria tiver sido cancelado
                                                //e o numero de avarias a serem registadas for maior que 0
                                                if (cancel == TRUE_1 && numOfDamages > 0)
                                                {

                                                    //Desenha o aviso que apenas algumas avarias foram registadas
                                                    drawDamageCancel(numOfDamages);

                                                    //Desenha a margem a esquerda
                                                    printf("        ");
                                                    //Aguarda o input do utilizador para dar seguimento ao programa
                                                    enterToContinue();
                                                }
                                            }
                                            //Executa se o utilizador pedir para cancelar
                                            else
                                            {
                                                //Redefine o valor da variavel para verdadeiro
                                                cancel = TRUE_1;
                                            }
                                            /********************************************FIM OP��O 1************************************************/
                                            break;
                                        case 2:
                                            /*******************************************COME�O OP��O 2***********************************************/
                                            /** Nesta op��o o utilizador pode:                       *
                                              * ->Registar o reparo de todas as avarias por arranjar *
                                              *                                                      *
                                              * Nesta op��o o utilizador n�o pode:                   *
                                              * ->Alterar o poratil j� selecionado                   **/
                                            do
                                            {
                                                //Encontra e armazena no vetor dinamico o indice de cada avaria
                                                //temporaria pertencente a lista de avarias do respetivo portatil.
                                                /*Mais informa��es em "funcoesDePortateis.c*/
                                                damagesIndex = searchTemporaryDamagesIndex(&sizeDamageIndex,laptop,equalIndex);
                                                //Executa se encontrar avarias tempor�rias por arranjar
                                                if (sizeDamageIndex>0)
                                                {
                                                    //Desenha a lista de avarias do respetivo portatil
                                                    drawRepairList(laptop,equalIndex,damagesIndex,sizeDamageIndex);

                                                    //Altera o texto da mensagem para fazer sentido ao utilizador
                                                    strcpy(message,"Selecione uma opcao");
                                                    //L� a op��o (int) da avaria para registar o arranjo
                                                    readInt(message,&optRepairMenu,1,sizeDamageIndex+1);

                                                    //Executa se o utilizador n�o pedir para cancelar
                                                    if (optRepairMenu != sizeDamageIndex+1)
                                                    {
                                                        //Altera o texto da mensagem para fazer sentido ao utilizador
                                                        strcpy(message,"Digite quantos dias o portatil esteve avariado");
                                                        //L� e guarda o tempo (int) em dias at� ser reparado
                                                        readInt(message,&laptop[equalIndex].damagesList[damagesIndex[optRepairMenu-1]].duration,0,MAX_DAMAGE_DAYS);
                                                        //Altera o estado da avaria para concluida
                                                        laptop[equalIndex].damagesList[damagesIndex[optRepairMenu-1]].state = COMPLETED;
                                                        //Remove 1 a quantidade de avarias ativas
                                                        laptop[equalIndex].damagesCounterActive--;
                                                        //Armazena no ficheiro as atualiza��es do portatil
                                                        storeInfoToFile(laptop,totalLaptops,request,totalRequests);
                                                        //Remove a avaria acabada de arranjar da lista de avarias tempor�rias
                                                        damagesIndex = removeTemporaryDamage(damagesIndex,sizeDamageIndex,sizeDamageIndex);
                                                        //Executa se n�o houverem mais avarias por reparar
                                                        if(sizeDamageIndex == 0)
                                                        {
                                                            //Iguala a op��o do menu de repara��o ao n�mero que cancela no menu para quebrar o ciclo
                                                            optRepairMenu = sizeDamageIndex+1;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    //Iguala a op��o do menu de repara��o ao n�mero que cancela no menu para quebrar o ciclo
                                                    optRepairMenu = sizeDamageIndex+1;
                                                    //Redefine a variavel para verdadeiro para quebrar o outro ciclo e voltar ao menu dos portateis
                                                    cancel = TRUE_1;
                                                }


                                            }
                                            while(optRepairMenu != sizeDamageIndex+1);
                                            /********************************************FIM OP��O 2************************************************/
                                            break;
                                        case 3:
                                            /*******************************************COME�O OP��O 3***********************************************/
                                            cancel = TRUE_1;
                                            /********************************************FIM OP��O 3************************************************/
                                            break;
                                        }
                                    }
                                    while (cancel == FALSE_0);
                                }
                                //Executa se n�o encontrar um portatil com o ID inserido pelo utilizador
                                if (equalIndex == -1)
                                {
                                    printf("        Nao existe um portatil com este ID!\n");
                                }
                            }
                        }
                        while (readedID != 0 && cancel == FALSE_0);

                        /************************************************FIM OP��O 4*****************************************************/
                        break;
                    }
                    else
                    {
                        //Desenha o alerta de 0 portateis no sistema
                        drawLaptopsNotFound();
                        //Desenha a margem a esquerda
                        printf("        ");
                        //Aguarda o input do utilizador para dar seguimento ao programa
                        enterToContinue();

                    }
                }
                //---------------------------------------------------FIM MENU DE PORTATEIS----------------------------------------------
            }
            while (optLapMenu != 5);
            /************************************************FIM OP��O PORTATEIS******************************************************/
            break;
        case 2:
            /****************************************COME�O OP��O REQUISI��ES/DEVOLU��ES**********************************************/
            printf("Caso 2\n");
            /******************************************FIM OP��O REQUISI��ES/DEVOLU��ES***********************************************/
            break;
        case 3:
            /*********************************************COME�O OP��O ESTATISTICAS***************************************************/
            printf("Caso 3\n");
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
        //--------------------------------------------------FIM MENU PRINCIPAL----------------------------------------------
    }
    while(optExtMenu != 2);
    //Liberta a mem�ria do vertor dinamico
    free(request);
    return 0;
}


