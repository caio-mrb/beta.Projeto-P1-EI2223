#ifndef FUNCOESDEDESIGN_H
#define FUNCOESDEDESIGN_H

#include "funcoesDeDados.h"

/** Este ficheiro engloba todas as funções  *
  * relacionadas a design de alguma maneira *
  * desde o desenho das informações no ecrã *
  * até o alinhamento das margens da janela *
  * --------------//------//--------------- *
  * Abaixo de cada função há uma explicação *
  * sobre o seu funcionamento e no ficheiro *
  * .c há a explicação passo a passo.       */

//Titulo e Bem-Vindo

void drawTittle(void);
/**Funcão para desenhar o titulo do projeto no ecrã**/

void drawWelcome(void);
/**Funcão para desenhar a mensagem de bem-vindo no ecrã**/

void drawWelcomeBack(void);
/**Funcão para desenhar a mensagem de bem-vindo no ecrã**/

//Menus

void drawMainMenu(int totalLaptops, int availableLaptops, int activeRequests, int totalRequests);
/**Função para desenhar o menu principal no ecrã com a informação de "total de portateis existentes",   *
  *"total de portateis disponeiveis", "total de requisições existentes" e "total de requisições ativas" *
  *Como usar:                                                                                           *
  *-> Criar 1 variavel para cada parametro, ao todo são 4                                               *
  *-> Adicionar uma função de leitura para receber a informação do utilizador                           **/

void drawLaptopMenu(void);
/**Função para desenhar o menu dos portateis no ecrã                          *
  *Como usar:                                                                 *
  *-> Adicionar uma função de leitura para receber a informação do utilizador **/

void drawInfoMenu(void);
/**Função para desenhar o menu das informações dos portateis no ecrã          *
  *Como usar:                                                                 *
  *-> Adicionar uma função de leitura para receber a informação do utilizador **/

void drawLaptopDamagesSubMenu(int laptopId);
/**Função para desenhar o menu das avarias/reaparações no ecrã                *
  *Como usar:                                                                 *
  *-> Adicionar uma função de leitura para receber a informação do utilizador **/

void drawConfirmExit(void);
/**Função para desenhar a confirmação de saída no ecrã                        *
  *Como usar:                                                                 *
  *-> Adicionar uma função de leitura para receber a informação do utilizador **/


//Funções de mostrar informações

void drawLaptopIdInfoWindow(int laptopId);
void drawNameInfoWindow(char *extraText,char *laptopName);
void drawLaptopStateInfoWindow(int laptopState);
void drawLaptopLocationInfoWindow(int laptopLocation);
void drawLaptopTotalDamagesInfoWindow(int damagesTotal);
void drawLaptopRamInfoWindow(int laptopRam);
void drawLaptopPurchaseDateInfoWindow(DateType purchaseDate);
void drawLaptopDamageTypeInfoWindow(int damageType);
void drawLaptopDamageDescInfoWindow(DamageType *damagesList,int indexDamage);
void drawLaptopProcessorInfoWindow(int laptopProcessor);
void drawLaptopPriceInfoWindow(float laptopPrice);
void drawLaptopTotalRequestsInfoWindow(int requestTotal);

void drawRequestDelayFeeInfoWindow(int delayFee);
void drawRequestTotalDurationInfoWindow(int durationTotal);
void drawRequestLocationInfoWindow(int returnLocation);
void drawRequestStateInfoWindow(int requestState);
void drawLaptopDaysRequested(int daysRequested);
void drawRequestLaptopIdInfoWindow(int laptopId);
void drawRequestApplicantTypeInfoWindow(int applicantType);
void drawRequestDurationInfoWindow(int duration);


//Alertas

void drawMaxLaptopsReachAlert(void);
/**Função para desenhar o aviso que o número máximo de portateis existentes foi atingido**/

void drawLaptopsNotFound(void);
/**Função para desenhar o aviso que não foram encontrados portateis no sistema**/

void drawAllReturnSucessful(void);
void drawLaptopsUnavailable(void);
void drawAllRepairSucessful(void);
void drawActiveRequestsNotFound(void);
void drawReturnDelayFeeAlert(int delayFee);
void drawLaptopSelectedInfo(int laptopIndex, LaptopType laptop[MAX_LAPTOPS]);


void drawRequestsNotFound(void);
/**Função para desenhar o aviso que não foram encontradas requisições no sistema**/

void drawAddLaptopCancel(int numOfLaptops);
/**Função para desenhar o aviso que o utilizador interrompeu a adição de novos portateis com                        *
  *a informação "total de portateis adicionados antes do cancelamento"                                              *
  *Como usar:                                                                                                       *
  *-> Criar uma variável que armazene o numero de portateis adicionados a medida que o utilizador introduz os dados **/

void drawDamageCancel(int numOfDamages);
/**Função para desenhar o aviso que o utilizador interrompeu a adição de novas avarias ao                         *
  *portatil com a informação "total de avarias adicionados antes do cancelamento"                                 *
  *Como usar:                                                                                                     *
  *-> Criar uma variável que armazene o numero de avarias adicionados a medida que o utilizador introduz os dados **/

void drawRequestCancel(int numOfRequests);

void drawReturnCancel(int numOfReturns);

void drawRenewCancel(int numOfRenews);

void drawDamagensNoneActive(int laptopId);
/**Função para desenhar o aviso que o utilizador interrompeu a adição de novas avarias ao                         *
  *portatil com a informação "total de avarias adicionados antes do cancelamento"                                 *
  *Como usar:                                                                                                     *
  *-> Criar uma variável que armazene o numero de avarias adicionados a medida que o utilizador introduz os dados **/

//Solicitações

void drawLaptopInfoAsk(int index, int totalLaptops);
/**Função para desenhar a mensagem sobre pedir os dados do portatil a adicionar          *
  *com a informação "portatil atual a ser adicionado" e "total de portateis a adicionar" *
  *Como usar:                                                                            *
  *-> Criar um ciclo que re-execute a função o numero de vezes inserido pelo utilizador  *
  *-> Armazenar a posição do ciclo em "portatil atual a ser adicionado"                  **/

void drawRequestInfoAsk(int index,int numOfRequests);

void drawReturnInfoAsk(int index, int numOfReturns);

void drawRenewInfoAsk(int index, int numOfRenews);

void drawLaptopIdToMove(void);
/**Função para desenhar a mensagem sobre pedir os dados do portatil a adicionar          *
  *com a informação "portatil atual a ser adicionado" e "total de portateis a adicionar" *
  *Como usar:                                                                            *
  *-> Criar um ciclo que re-execute a função o numero de vezes inserido pelo utilizador  *
  *-> Armazenar a posição do ciclo em "portatil atual a ser adicionado"                  **/

void drawLaptopIdDamageAsk(void);
/**Função para desenhar a mensagem sobre pedir o id do portatil em que pretende registar a avaria**/

void drawAddLaptop(int totalLaptops);
/**Função para desenhar a mensagem sobre pedir o número de portateis a adicionar *
  *com a informação de "total de portateis já adicionados"                       *
  *Como usar:                                                                    *
  *-> Adicionar uma função de leitura para receber a informação do utilizador    **/

void drawLocationsMiniList(void);
/**Função para desenhar a lista de localizações sem o efeito de janela**/

void drawLocationsBigList(void);
/**Função para desenhar a lista de localizações com o efeito de janela**/

void drawRepairList(LaptopType laptop[MAX_LAPTOPS], int laptopIndex, int *damagesIndexList, int sizeDamagesIndexList);
/**Função para desenhar a lista de avarias por arranjar de um respetivo portatil        *
  *com a informação "data de cada avaria" e "local de cada avaria"                      *
  *Como usar:                                                                           *
  *-> Utilizar o vetor estatico de portateis                                            *
  *-> Utilizar o indice do portatil escolhido pelo utilizador                           *
  *-> Utilizar o vetor dinamico da lista de indices das avarias temporarias po portatil *
  *-> Utilizar o tamanho do vetor dinamico da lista de indices                          **/

//Design

void clearScreen(void);
/**Função para limpar o ecrã**/

void enterToContinue(void);
/**Função para aguardar o input do utilizador antes de continuar**/

void drawPercentageBar(float percentage);

void centerTittle(char *extraText, char *tittle, int windowSize);

void alignMargin(int contentSize, int totalSpaces);
/**Função para alinhar a margem da janela simulada de acordo com o                                                        *
  *conteúdo a ser escrito                                                                                                 *
  *Como usar:                                                                                                             *
  *-> Utilizar o tamanho de espaços do conteúdo a ser escrito                                                             *
  *-> Utilizar o tamanho máximo que o conteúdo pode ocupar na janela                                                      *
  *(valor obtido ao subtrair o total de espaços por linha da janela com o número de caracteres que a linha já ocupa       *
  *                                                                                                                       *
  *Exemplo: Se há uma janela com o seguinte formato                                                                       *
  * ___________                                                                                                           *
  *|           |                                                                                                          *
  *| 123456789 |                                                                                                          *
  *|___________|                                                                                                          *
  *                                                                                                                       *
  *quer dizer que a janela possui 9 espaços ao todo por linha                                                             *
  *                                                                                                                       *
  *Se quiser escrever um conteúdo que varia entre 1 e 3                                                                   *
  *                                                                                                                       *
  *Chama-se da seguinte maneira                                                                                           *
  *alignMargin("variavel que armazena o número de digitos a serem escritos","tamanho disponível para ser escrito(9 - 0)") **/



#endif // FUNCOESDEDESIGN_H
