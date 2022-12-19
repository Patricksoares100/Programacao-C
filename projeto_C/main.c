#include <stdio.h>
#include <stdlib.h>


//DECLARAÇÃO DAS CONSTANTES
#define maximo_participantes 5000  //MAXIMO PERMITIDO DE PARTICIPANTES
#define maximo_atividades 200  //MAXIMO PERMITIDO DE ATIVIDADES
#define maximo_inscricoes 10000  //MAXIMO PERMITIDO DE INSCRICOES


// DECLARAÇÃO DAS ESTRUTURAS
typedef struct
{
    char nome_participante[50], escola_participante[10], email_participante[30];
    int nif_participante, contacto_participante, id_part;
} participantes;

typedef struct
{
    char designacao_atividade[30], local_atividade[20], tipo_atividade[20], assoc_estudantes[10];
    int datahora_atividade;
    float valor;
} atividade;

typedef struct
{
    int id_participante, id_atividade, datahora_inscricao;
    float valor_pago;
} inscricao;


//DECLARAÇO DAS FUNÇÕES
int main_menu();
int menu_consulta_regista_participante();
int menu_consulta_regista_atividades();
int menu_consulta_regista_inscricoes();
int menu_estatisticas();
/*int id (int id_minimo, int id_maximo);*/


//INICIO DA FUNÇÃO MAIN
int main()
{
    int opcao;
    participantes participante[10];/*definir a constante*/
    int id_participante = 0;

    do{
    printf("\n\t\t\t\t\tM  E  N  U \n\n");
    printf("Escolha a opcao:\n\n");
    printf("1 - Registar / consultar dados dos participantes.\n");
    printf("2 - Registar / consultar dados das atividades.\n");
    printf("3 - Registar / consultar dados das inscricoes.\n");
    printf("4 - Estatisticas.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        menu_consulta_regista_participante(participante, id_participante);
        break;

    case 2:
        menu_consulta_regista_atividades();
        break;

    case 3:
        menu_consulta_regista_inscricoes();
        break;

    case 4:
        menu_estatisticas();
        break;

    case 0:
        printf("\n\n A sair do programa!\n");
        break;

    default:
        printf("\nInsira uma opcao valida!\n");
        return opcao;
    }
    }while(opcao != 0);

    /*        struct participantes alunos[maximo_participantes];
            int i;

            for (i=0; i<maximo_participantes; i++)
            {
                printf("\nInsira o seu nome.");
                fgets(alunos[i].nome_participante);
            }*/

    /*struct atividade ve_atividade;
      struct inscricao ve_inscricao;*/
}


//FUNÇÃO MENU PRINCIPAL
int main_menu(void)
{


}


//FUNÇÃO MENU DOS REGISTOS E DAS CONSULTAS DOS PARTICIPANTES
int menu_consulta_regista_participante(participantes participante[], int id_participante)
{
    int opcao;
    int id_part;

    do{
    printf("\n\t\tR E G I S T A R / C O N S U L T A R   P A R T I C I P A N T E S\n\n");
    printf("Escolha a opcao:\n\n");
    printf("1 - Registar.\n");
    printf("2 - Consultar.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        id_part = registar_participante(participante, id_participante);
        break;

    case 2:
        break;

    case 0:
        break;

    default:
        printf("\nInsira uma opcao valida!\n");
        return opcao;
    }
    }while(opcao != 3);  /*verificar se nao é while !=  0*/
}

//FUNÇÃO PARA FAZER O REGISTO DE CADA PARTICIPANTE QUE SE INSCREVER (id_participante++), É ATRIBUIDO O VALOR À VARIAVEL DO VETOR PARTICIPANTE DO TIPO PARTICIPANTES QUE DEVOLVE PARA A OUTRA FUNÇÃO COM O RETURN ?!? perguntar ao prof!
int registar_participante(participantes participante[], int id_participante) {
    printf("Insira o nome de participante: ");
    fflush(stdin);
    fgets(participante[id_participante].nome_participante, 50, stdin);

    printf("\nInsira a escola: ");
    fgets(participante[id_participante].escola_participante, 10, stdin);

    printf("\nInsira o e-mail: ");
    fgets(participante[id_participante].email_participante, 30, stdin);

    printf("\nInsira o seu NIF: ");
    scanf("%d", &participante[id_participante].nif_participante);

    printf("\nInsira o seu contacto: ");
    scanf("%d", &participante[id_participante].contacto_participante);

    id_participante++;

    return id_participante;
}

void consultar_participante(participantes participante[], int id_participante) {

}

//FUNÇÃO MENU DOS REGISTOS E DAS CONSULTAS DAS ATIVIDADES
int menu_consulta_regista_atividades()
{
    int opcao;

    do{
    printf("\n\t\tR E G I S T A R / C O N S U L T A R   A T I V I D A D E S\n\n");
    printf("Escolha a opcao:\n\n");
    printf("1 - Registar.\n");
    printf("2 - Consultar.\n");
    printf("3 - Voltar ao menu principal.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 0:
        break;

    default:
        printf("\nInsira uma opcao valida!\n");
        return opcao;
    }
    }while(opcao != 3);
}


//FUNÇÃO MENU DOS REGISTOS E DAS CONSULTAS DAS INSCRIÇÕES
int menu_consulta_regista_inscricoes()
{
    int opcao;
    do{
    printf("\n\t\tR E G I S T A R / C O N S U L T A R   I N S C R I C O E S\n\n");
    printf("Escolha a opcao:\n\n");
    printf("1 - Registar.\n");
    printf("2 - Consultar.\n");
    printf("3 - Voltar ao menu principal.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 0:
        break;

    default:
        printf("\nInsira uma opcao valida!\n");
        return opcao;
    }
    }while(opcao != 3);
}


//FUNÇÃO MENU DAS ESTATISTICAS
int menu_estatisticas()
{
    int opcao;

    do{
    printf("\n\t\t\t\tE S T A T I S T I C A S\n\n");
    printf("Escolha a opcao:\n\n");
    printf("1 - Numero de atividades realizadas por cada associacao.\n");
    printf("2 - Percentagem de inscricoes por escola.\n");
    printf("3 - Valor total das inscricoes.\n");
    printf("4 - Voltar ao menu principal.\n");
    printf("0 - Sair.\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 0:
        break;

    default:
        printf("\nInsira uma opcao valida!\n");
        return opcao;
    }
    }while(opcao != 4);
}


/*FUNÇÃO PARA CONSULTAR PARTICIPANTES
int consula_participantes()
{
    printf("\nNome: ", alunos.nome_participante);
    printf("Escola: ", alunos.escola_participante);
    printf("E-mail: ", alunos.email_participante);
    printf("NIF: ", alunos.nif_participante);
    printf("Contacto: ", alunos.contacto_participante);
}

*/



//FUN플O PARA CRIAR IDENTIFICADOR DOS PARTICIPANTES
/*int id (int id_minimo, int id_maximo)
{
    int id;
    do
    {
        printf("\nInsira um numero entre %d e %d:", id_minimo, id_maximo);
        scanf("%d", &id);
    }
    while(id < id_minimo || id > id_maximo);
    return id;
}*/



