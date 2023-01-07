#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DECLARAÇÃO DAS CONSTANTES
#define maximo_participantes 5000  //MAXIMO PERMITIDO DE PARTICIPANTES
#define maximo_atividades 200  //MAXIMO PERMITIDO DE ATIVIDADES
#define maximo_inscricoes 10000  //MAXIMO PERMITIDO DE INSCRICOES


// DECLARAÇÃO DAS ESTRUTURAS
typedef struct
{
    char nome_participante[50], escola_participante[10], email_participante[30];
    int nif_participante, contacto_participante, id_parti;
} participantes;

typedef struct
{
    char designacao_atividade[30], local_atividade[20], tipo_atividade[20], assoc_estudantes[10];
    int datahora_atividade/*falta buscar estes dados*/, id_ativi;
    float valor_atividade;
} atividades;

typedef struct
{
    int id_participante, id_atividade, datahora_inscricao, id_inscri;
    float valor_pago;
} inscricoes;

typedef struct
{
    int segundos, minutos, horas;
} hora;

typedef struct
{
    int dia, mes ,ano;
} data;

//DECLARAÇÃO DAS FUNÇÕES
int menu_consulta_regista_participantes(participantes participante[], int id_participante);  //FUNÇÕES PARA OS PARTICIPANTES
int registar_participante(participantes participante[], int id_participante);
void consultar_participante(participantes participante[], int id_participante);

int menu_consulta_regista_atividades(atividades atividade[], int id_atividade);  //FUNÇÕES PARA AS ATIVIDADES
int registar_atividade(atividades atividade[], int id_atividade);
void consultar_atividade(atividades atividade[], int id_atividade);

int menu_consulta_regista_inscricoes(inscricoes inscricao[],int id_inscricao);  //FUNÇÕES PARA AS INSCRIÇÕES
int registar_inscricao(inscricoes inscricao[], int id_inscricao);
void consultar_inscricao(inscricoes inscricao[], int id_inscricao);

int menu_estatisticas();  //FUNÇÕES PARA AS ESTATISTICAS

int menu_guardar_ler_dados();  //FUNÇÕES PARA GUARDAR / LER DADOS

int menu_guardar_ler_participante(participantes participante[], int id_participante);  //PARTICIPATNES
void guardar_participante(participantes participante[], int id_participante);
int ler_participante(participantes participante[]);

int menu_guardar_ler_atividade(atividades atividade[], int id_atividade);  //ATIVIDADES
void guardar_atividade(atividades atividade[], int id_atividade);
int ler_atividade(atividades atividade[]);

int menu_guardar_ler_inscricao(inscricoes inscricao[], int id_inscricao);  //INSCRICOES
void guardar_inscricao(inscricoes inscricao[], int id_inscricao);
int ler_inscricao(inscricoes inscricao[]);



//INICIO DA FUNÇÃO MAIN
int main()
{
    int opcao, id_participante = 0, id_atividade = 0, id_inscricao = 0;
    participantes participante[maximo_participantes];/*definir a constante*/
    atividades atividade[maximo_atividades];
    inscricoes inscricao[maximo_inscricoes];

    do
    {
        printf("\n\t\t\t\t\tM  E  N  U \n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Registar / consultar dados dos participantes.\n");
        printf("2 - Registar / consultar dados das atividades.\n");
        printf("3 - Registar / consultar dados das inscricoes.\n");
        printf("4 - Estatisticas.\n");
        printf("5 - Guardar / ler dados.\n");
        printf("0 - Sair.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            id_participante = menu_consulta_regista_participantes(participante, id_participante);
            break;

        case 2:
            menu_consulta_regista_atividades(atividade, id_atividade);
            break;

        case 3:
            menu_consulta_regista_inscricoes(inscricao, id_inscricao);
            break;

        case 4:
            menu_estatisticas();
            break;

        case 5:
            menu_guardar_ler_dados();
            break;

        case 0:
            printf("\n\n A sair do programa!\n");
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
}



//FUNÇÃO MENU DOS REGISTOS E DAS CONSULTAS DOS PARTICIPANTES
int menu_consulta_regista_participantes(participantes participante[], int id_participante)
{
    int opcao;

    do
    {
        printf("\n\t\tR E G I S T A R / C O N S U L T A R   P A R T I C I P A N T E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Registar.\n");
        printf("2 - Consultar.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            id_participante = registar_participante(participante, id_participante);
            break;

        case 2:
            consultar_participante(participante, id_participante);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
    return id_participante;
}

//FUNÇÃO PARA FAZER O REGISTO DE CADA PARTICIPANTE QUE SE INSCREVER (id_participante++), É ATRIBUIDO O VALOR À VARIAVEL DO VETOR PARTICIPANTE DO TIPO PARTICIPANTES QUE DEVOLVE PARA A OUTRA FUNÇÃO COM O RETURN ?!? perguntar ao prof!
int registar_participante(participantes participante[], int id_participante)
{
    participante[id_participante].id_parti = id_participante;

    printf("\nInsira o nome de participante: ");
    fflush(stdin);
    fgets(participante[id_participante].nome_participante, 49, stdin);

    printf("\nInsira a escola: ");
    fgets(participante[id_participante].escola_participante, 9, stdin);

    printf("\nInsira o e-mail: ");
    fgets(participante[id_participante].email_participante, 29, stdin);

    printf("\nInsira o seu NIF: ");
    scanf("%d", &participante[id_participante].nif_participante);

    printf("\nInsira o seu contacto: ");
    scanf("%d", &participante[id_participante].contacto_participante);

    id_participante++;
    return id_participante;
}

//FUNÇÃO PARA CONSULTAR OS PARTICIPANTES
void consultar_participante(participantes participante[], int id_participante)
{
    int cont;

    for (cont=0; cont < id_participante; cont++)
    {
        printf("\n\nID do participante: %d\n", participante[cont].id_parti);
        printf("\nNome: %s", participante[cont].nome_participante);
        printf("\nEscola: %s", participante[cont].escola_participante);
        printf("\nE-mail: %s", participante[cont].email_participante);
        printf("\nNIF: %d\n", participante[cont].nif_participante);
        printf("\nContacto: %d\n\n", participante[cont].contacto_participante);
    }
}



//FUNÇÃO MENU DOS REGISTOS E DAS CONSULTAS DAS ATIVIDADES
int menu_consulta_regista_atividades(atividades atividade[], int id_atividade)
{
    int opcao;

    do
    {
        printf("\n\t\tR E G I S T A R / C O N S U L T A R   A T I V I D A D E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Registar.\n");
        printf("2 - Consultar.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            id_atividade = registar_atividade(atividade, id_atividade);
            break;

        case 2:
            consultar_atividade(atividade, id_atividade);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0 );
    return id_atividade;
}

//FUNÇÃO PARA FAZER OS REGISTOS DE CADA ATIVIDADE QUE EXISTIR (id_atividade++)
int registar_atividade(atividades atividade[], int id_atividade)
{
    atividade[id_atividade].id_ativi = id_atividade;

    printf("\nInsira a designacao da atividade: ");
    fflush(stdin);
    fgets(atividade[id_atividade].designacao_atividade, 29, stdin);

    printf("\nIndique o local da atividade: ");
    fgets(atividade[id_atividade].local_atividade, 19, stdin);

    printf("\nQual o tipo de atividade: ");
    fgets(atividade[id_atividade].tipo_atividade, 19, stdin);

    printf("\nAssociacao de estudantes organizadora: ");
    fgets(atividade[id_atividade].assoc_estudantes, 9, stdin);

    printf("\nInsira o montante pago: ");
    scanf("%.2f", &atividade[id_atividade].valor_atividade);

    printf("\nHora da atividade: 10:00 H");
    //estruturar melhor este print pois é para digitar a hora? a hora aparecer consoante o tipo de evento? qual o tipo de dados int, float...?
    fflush(stdin);
    id_atividade++;
    return id_atividade;
}

//FUNÇÃO PARA CONSULTAR AS ATIVIDADES
void consultar_atividade(atividades atividade[], int id_atividade)
{
    int cont;

    for (cont=0; cont < id_atividade; cont++)
    {
        printf("\n\nID da atividade: %d\n", atividade[cont].id_ativi);
        printf("\nDesignacao da atividade: %s", atividade[cont].designacao_atividade);
        printf("\nData e hora da atividade: 10:00 H \n"/*%d, atividade[cont].datahora_atividade*/);
        printf("\nLocal: %s", atividade[cont].local_atividade);
        printf("\nTipo de atividade: %s", atividade[cont].tipo_atividade);
        printf("\nAssociacao de estudantes organizadora: %s", atividade[cont].assoc_estudantes);
        printf("\nMontante pago pela inscricao: %.2f\n\n", atividade[cont].valor_atividade);
    }
}



//FUNÇÃO MENU DOS REGISTOS E DAS CONSULTAS DAS INSCRIÇÕES
int menu_consulta_regista_inscricoes(inscricoes inscricao[], int id_inscricao)
{
    int opcao;

    do
    {
        printf("\n\t\tR E G I S T A R / C O N S U L T A R   I N S C R I C O E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Registar.\n");
        printf("2 - Consultar.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            id_inscricao = registar_inscricao(inscricao, id_inscricao);
            break;

        case 2:
            consultar_inscricao(inscricao, id_inscricao);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao !=0);
    return id_inscricao;
}

//FUNÇÃO PARA FAZER OS REGISTOS DE CADA INSCRIÇÃO QUE EXISTIR (id_inscricao++)
int registar_inscricao(inscricoes inscricao[], int id_inscricao)
{
    inscricao[id_inscricao].id_inscri = id_inscricao;

    printf("\nInsira ID de participante: ");
    scanf("%d", &inscricao[id_inscricao].id_participante);

    printf("\nInsira ID de atividade: ");
    scanf("%d", &inscricao[id_inscricao].id_atividade);

    printf("\nInsira o montante pago: ");
    scanf("%.2f", &inscricao[id_inscricao].valor_pago);

    printf("\nData e hora da inscricao: ");
    //como fazer para aparecer hora?

    id_inscricao++;
    return id_inscricao;
}

//FUNÇÃO PARA CONSULTAR AS INSCRIÇÕES
void consultar_inscricao(inscricoes inscricao[], int id_inscricao)
{
    int cont;

    for (cont=0; cont < id_inscricao; cont++)
    {
        printf("\n\nID da inscricao: %d\n", inscricao[cont].id_inscri);
        printf("\nID do participante: %d\n", inscricao[cont].id_participante);
        printf("\nID da atividade: %d\n", inscricao[cont].id_atividade);
        printf("\nMontante pago: %d\n",inscricao[cont].valor_pago);
        printf("\nData e hora da inscricao: \n"/*inscricao[id_insscricao].datahora_inscricao*/);

    }
}


//FUNÇÃO MENU DAS ESTATISTICAS
int menu_estatisticas()
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tE S T A T I S T I C A S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Numero de atividades realizadas por cada associacao.\n");
        printf("2 - Percentagem de inscricoes por escola.\n");
        printf("3 - Valor total das inscricoes entre datas.\n");
        printf("0 - Voltar.\n\n");
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
        }
    }
    while(opcao != 0);
}


//FUNÇÃO MENU GUARDAR / LER DADOS DE FICHEIROS BINÁRIOS DOS PARTICIPANTES, ATIVIDADES E INSCRICOES
int menu_guardar_ler_dados(participantes participante[], atividades atividade[], inscricoes inscricao[], int id_participante, int id_atividade, int id_inscricao)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tG U A R D A R / L E R   D A D O S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Participantes.\n");
        printf("2 - Atividades.\n");
        printf("3 - Inscricoes.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            menu_guardar_ler_participante(participante, id_participante);
            break;

        case 2:
            menu_guardar_ler_atividade(atividade, id_atividade);
            break;

        case 3:
            menu_guardar_ler_inscricao(inscricao, id_inscricao);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
}



int menu_guardar_ler_participante(participantes participante[], int id_participante)
{
int opcao;

    do
    {
        printf("\n\t\tG U A R D A R / L E R   P A R T I C I P A N T E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Guardar Participantes.\n");
        printf("2 - Ler Participantes.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            guardar_participante(participante, id_participante);
            break;

        case 2:
            ler_participante(participante);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
    return id_participante;
}

void guardar_participante(participantes participante[], int id_participante)
{
    FILE *ficheiro;
    ficheiro = fopen("participantes.bin","wb");
    if (ficheiro == NULL)
        printf("Nao foi possivel criar o ficheiro!");
    else
    {
        fwrite(&id_participante, sizeof(int), 1, ficheiro);
        fwrite(participante, sizeof(participantes), id_participante, ficheiro);
        fclose(ficheiro);
        printf("\nEscrita dos dados de %d participantes em ficheiro com sucesso.",
               id_participante);
    }
}

int ler_participante(participantes participante[])
{
    int id_participante, numero_alunos_lido;
    FILE *ficheiro;
    ficheiro = fopen("participantes.dat","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&id_participante, sizeof(int), 1, ficheiro);
        numero_alunos_lido = fread(participante, sizeof(participantes), id_participante, ficheiro);
        fclose(ficheiro);
        if (numero_alunos_lido != id_participante)
        {
            id_participante = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d alunos de ficheiro com sucesso.", id_participante);
        }

    return id_participante;
}



int menu_guardar_ler_atividade(atividades atividade[], int id_atividade)
{
int opcao;

    do
    {
        printf("\n\t\tG U A R D A R / L E R   A T I V I D A D E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Guardar Atividades.\n");
        printf("2 - Ler Atividades.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            guardar_atividade(atividade, id_atividade);
            break;

        case 2:
            ler_atividade(atividade);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
    return id_atividade;
}

void guardar_atividade(atividades atividade[], int id_atividade)
{
    FILE *ficheiro;
    ficheiro = fopen("atividades.bin","wb");
    if (ficheiro == NULL)
        printf("Nao foi possivel criar o ficheiro!");
    else
    {
        fwrite(&id_atividade, sizeof(int), 1, ficheiro);
        fwrite(atividade, sizeof(atividades), id_atividade, ficheiro);
        fclose(ficheiro);
        printf("\nEscrita dos dados de %d participantes em ficheiro com sucesso.",
               id_atividade);
    }
}

int ler_atividade(atividades atividade[])
{
    int id_atividade, numero_alunos_lido;
    FILE *ficheiro;
    ficheiro = fopen("atividades.dat","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&id_atividade, sizeof(int), 1, ficheiro);
        numero_alunos_lido = fread(atividade, sizeof(atividades), id_atividade, ficheiro);
        fclose(ficheiro);
        if (numero_alunos_lido != id_atividade)
        {
            id_atividade = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d alunos de ficheiro com sucesso.", id_atividade);
        }

    return id_atividade;
}



int menu_guardar_ler_inscricao(inscricoes inscricao[], int id_inscricao)
{
    int opcao;

    do
    {
        printf("\n\t\tG U A R D A R / L E R   I N S C R I C O E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Guardar Inscricoes.\n");
        printf("2 - Ler Inscricoes.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            guardar_inscricao(inscricao, id_inscricao);
            break;

        case 2:
            ler_inscricao(inscricao);
            break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
    return id_inscricao;
}

void guardar_inscricao(inscricoes inscricao[], int id_inscricao)
{
    FILE *ficheiro;
    ficheiro = fopen("inscricoes.bin","wb");
    if (ficheiro == NULL)
        printf("Nao foi possivel criar o ficheiro!");
    else
    {
        fwrite(&id_inscricao, sizeof(int), 1, ficheiro);
        fwrite(inscricao, sizeof(inscricoes), id_inscricao, ficheiro);
        fclose(ficheiro);
        printf("\nEscrita dos dados de %d participantes em ficheiro com sucesso.",
               id_inscricao);
    }
}

int ler_inscricao(inscricoes inscricao[])
{
    int id_inscricao, numero_alunos_lido;
    FILE *ficheiro;
    ficheiro = fopen("inscricoes.dat","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&id_inscricao, sizeof(int), 1, ficheiro);
        numero_alunos_lido = fread(inscricao, sizeof(inscricoes), id_inscricao, ficheiro);
        fclose(ficheiro);
        if (numero_alunos_lido != id_inscricao)
        {
            id_inscricao = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d alunos de ficheiro com sucesso.", id_inscricao);
        }

    return id_inscricao;
}
