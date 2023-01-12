#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DECLARAÇÃO DAS CONSTANTES
#define maximo_participantes 5000  //MAXIMO PERMITIDO DE PARTICIPANTES
#define maximo_atividades 200  //MAXIMO PERMITIDO DE ATIVIDADES
#define maximo_inscricoes 10000  //MAXIMO PERMITIDO DE INSCRICOES
#define max_nome 50  //PERMITIDOS 50 CARCATERES PARA O NOME
#define max_escola 10  //PERMITIDOS 10 CARACTERES PARA A ESCOLA/AE
#define max_email 30  //PERMITIDOS 30 CARACTERES PARA O EMAIL
#define min_nif 100000000  //NUMERO MINIMO PARA O NIF
#define max_nif 999999999  //NUMERO MAXIMO PARA O NIF
#define min_tlm 910000000  //NUMERO MINIMO PARA TELEMOVEL
#define max_tlm 999999999  //NUMERO MAXIMO PARA TELEMOVEL
#define min_tlf 210000000  //NUMERO MINIMO PARA TELEFONE
#define max_tlf 299999999  //NUMERO MAXIMO PARA TELEFONE
#define max_atividade 30  //PERMITIDOS 30 CARACTERES PARA A ATIVIDADE
#define max_local_tipo 20  //PERMITIDOS 20 CARACTERES PARA O LOCAL E TIPO DE ATIVIDADE


// DECLARAÇÃO DAS ESTRUTURAS
typedef struct
{
    char nome_participante[max_nome], escola_participante[max_escola], email_participante[max_email];
    int nif_participante, contacto_participante, id_parti;
} participantes;

typedef struct
{
    char designacao_atividade[max_atividade], local_atividade[max_local_tipo], tipo_atividade[max_local_tipo];
    int datahora_atividade/*falta buscar estes dados*/, id_ativi, assoc_estudantes;
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
int menu_consulta_regista_participantes(participantes participante[], int id_participante);  //FUNÇÕES PARA OS PARTICIPANTES, REGISTAR E CONSULTAR
int registar_participante(participantes participante[], int id_participante);
void consultar_participante(participantes participante[], int id_participante);

int menu_consulta_regista_atividades(atividades atividade[], int id_atividade);  //FUNÇÕES PARA AS ATIVIDADES, REGISTAR E CONSULTAR
int registar_atividade(atividades atividade[], int id_atividade);
void consultar_atividade(atividades atividade[], int id_atividade);

int menu_consulta_regista_inscricoes(inscricoes inscricao[],int id_inscricao);  //FUNÇÕES PARA AS INSCRIÇÕES, REGISTAR E CONSULTAR
int registar_inscricao(inscricoes inscricao[], int id_inscricao);
void consultar_inscricao(inscricoes inscricao[], int id_inscricao);

int menu_estatisticas();  //FUNÇÕES PARA AS ESTATISTICAS

void menu_guardar_ler_dados(participantes participante[], atividades atividade[], inscricoes inscricao[], int id_participante, int id_atividade, int id_inscricao);  //FUNÇÕES PARA GUARDAR / LER DADOS DOS
void guardar_participante(participantes participante[], int id_participante);
int ler_participante(participantes participante[]);

void guardar_atividade(atividades atividade[], int id_atividade);
int ler_atividade(atividades atividade[]);

void guardar_inscricao(inscricoes inscricao[], int id_inscricao);
int ler_inscricao(inscricoes inscricao[]);

//void gravar_ficheiro(participantes vet_parti[], int id_parti, atividades vet_ativi[], int id_ativi, inscricoes vet_inscri[], int id_inscri);
//void ler_ficheiro(participantes vet_parti[], int *id_parti, atividades vet_ativi[], int *id_ativi, inscricoes vet_inscri[], int *id_inscri);

int menu_associacao_estudantes (void);  //FUNÇÃO PARA AS AE

//INICIO DA FUNÇÃO MAIN
int main()
{
    int opcao, id_participante = 0, id_atividade = 0, id_inscricao = 0;
    participantes participante[maximo_participantes];/*definir a constante*/
    atividades atividade[maximo_atividades];
    inscricoes inscricao[maximo_inscricoes];

    //ler_ficheiro(participante,  *id_participante);
    //id_atividade = ler_dados(atividade, sizeof(atividades), maximo_atividades, "atividades.bin");
    //id_inscricao = ler_dados(inscricao, sizeof(inscricoes), maximo_inscricoes, "inscricoes.bin");

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
            if (id_participante == 0)
                printf("\nRegiste primeiro um participante!\n");
            else
                menu_consulta_regista_atividades(atividade, id_atividade);
            break;

        case 3:
            if (id_participante == 0 && id_atividade == 0)
                printf("\nRegiste primeiro um participante e depois uma atividade!\n");
            else
                menu_consulta_regista_inscricoes(inscricao, id_inscricao);
            break;

        case 4:
            if (id_participante == 0 && id_atividade  == 0 && id_inscricao == 0)
                printf("\nRegiste primeiro um participante, uma atividade e uma inscricao!\n");
            else
                menu_estatisticas();
            break;

        case 5:
            menu_guardar_ler_dados(participante, atividade, inscricao, id_participante, id_atividade, id_inscricao);
            break;

        case 0:
             if (id_participante != 0 || id_atividade != 0 || id_inscricao != 0)
            {
                //guardar_dados(participante, sizeof(participantes), id_participante, "participantes.bin");
               // guardar_dados(atividade, sizeof(atividades), id_atividade, "atividades.bin");
               // guardar_dados(inscricao, sizeof(inscricoes), id_inscricao, "inscricoes.bin");
                printf("\nGravacao de dados concluida com sucesso!\n");
                printf("\n A sair do programa!\n");
            }
            else
                printf("\nNao ha dados a serem guardados!\n");
                printf("\n A sair do programa!\n");
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
            if (id_participante >= maximo_participantes)
            {
                printf("\nEsgotou o limite maximo de participantes!\n");
            }
            else
                system("cls");
                id_participante = registar_participante(participante, id_participante);
            break;

        case 2:
            if (id_participante == 0)
                printf("\nRegiste primeiro um participante!\n");
            else
                system("cls");
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

//FUNÇÃO PARA FAZER O REGISTO DE CADA PARTICIPANTE QUE SE INSCREVER, É ATRIBUIDO O VALOR AOS ELEMENTOS DO VETOR PARTICIPANTE DO TIPO PARTICIPANTES QUE DEVOLVE PARA A OUTRA FUNÇÃO COM O RETURN
int registar_participante(participantes participante[], int id_participante)
{
    participante[id_participante].id_parti = id_participante;

    printf("\nInsira o nome de participante: ");
    fflush(stdin);
    fgets(participante[id_participante].nome_participante, max_nome, stdin);

    printf("\nInsira a escola: ");
    fgets(participante[id_participante].escola_participante, max_escola, stdin);

    printf("\nInsira o e-mail: ");
    fgets(participante[id_participante].email_participante, max_email, stdin);

    printf("\nInsira o seu NIF: ");
    scanf("%d", &participante[id_participante].nif_participante);                                   //----------> fazer do...while para validar nif?
    /*if (participante[].nif_participante < min_nif || participante[].nif_participante > max_nif)
        printf("\nInsira um numero de identificacao fiscal correto!\n");*/

    printf("\nInsira o seu contacto: ");
    scanf("%d", &participante[id_participante].contacto_participante);                              //aqui tambem do...while?

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
            if (id_atividade >= maximo_atividades)
            {
                printf("\nEsgotou o limite maximo de atividades!\n");
            }
            else
                system("cls");
                id_atividade = registar_atividade(atividade, id_atividade);
            break;

        case 2:
            if(id_atividade == 0)
                printf("\nRegiste uma atividade!\n");
            else
                system("cls");
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
    fgets(atividade[id_atividade].designacao_atividade, max_atividade, stdin);

    printf("\nIndique o local da atividade: ");
    fgets(atividade[id_atividade].local_atividade, max_local_tipo, stdin);

    printf("\nQual o tipo de atividade: ");
    fgets(atividade[id_atividade].tipo_atividade, max_local_tipo, stdin);

    atividade[id_atividade].assoc_estudantes = menu_associacao_estudantes();
    printf("%d", atividade[id_atividade].assoc_estudantes);
    //printf("\nAssociacao de estudantes organizadora: ");
   // fgets(atividade[id_atividade].assoc_estudantes, max_escola, stdin);

    printf("\nInsira o montante pago: ");
    scanf("%.2f", &atividade[id_atividade].valor_atividade);

    printf("\nHora da atividade: 10:00 H");
    //estruturar melhor este print pois é para digitar a hora? a hora aparecer consoante o tipo de evento?
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
        printf("\nAssociacao de estudantes organizadora: ");
        escolha_associacao(atividade[cont].assoc_estudantes);
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
            if (id_inscricao >= maximo_inscricoes)
            {
                printf("\nEsgotou o limite maximo de inscricoes!\n");
            }
            else
                system("cls");
                id_inscricao = registar_inscricao(inscricao, id_inscricao);
            break;

        case 2:
            if (id_inscricao == 0)
                printf("\nRegiste uma inscricao!\n");
            else
                system("cls");
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
        printf("\nData e hora da inscricao: \n"/*inscricao[cont].datahora_inscricao*/);

    }
}



//FUNÇÃO MENU DAS ESTATISTICAS
int menu_estatisticas()
{
    int opcao;

    do
    {
        system("cls");
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
void menu_guardar_ler_dados(participantes participante[], atividades atividade[], inscricoes inscricao[], int id_participante, int id_atividade, int id_inscricao)
{
    int opcao;

    do
    {
        printf("\n\t\t\t\tG U A R D A R / L E R   D A D O S \n\n");
        printf("\t\tP A R T I C I P A N T E S  |  A T I V I D A D E S  |  I N S C R I C O E S\n\n");
        printf("Escolha a opcao:\n\n");
        printf("1 - Guardar Dados.\n");
        printf("2 - Ler Dados.\n");
        printf("0 - Voltar.\n\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            if (id_participante != 0 || id_atividade != 0 || id_inscricao != 0)
            {
                guardar_participante(participante, id_participante);
                guardar_atividade(atividade, id_atividade);
                guardar_inscricao (inscricao, id_inscricao);
            }
            else
                printf("\nAinda nao ha dados para serem guardados!\n");
                break;

        case 2:
                ler_participante(participante);
                ler_atividade(atividade);
                ler_inscricao(inscricao);  // atividade, id_atividade, inscricao, id_inscricao);
                break;

        case 0:
            break;

        default:
            printf("\nInsira uma opcao valida!\n");
        }
    }
    while(opcao != 0);
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
    int id_participante, numero_participantes_lido;
    FILE *ficheiro;
    ficheiro = fopen("participantes.bin","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&id_participante, sizeof(int), 1, ficheiro);
        numero_participantes_lido = fread(participante, sizeof(participantes), id_participante, ficheiro);
        fclose(ficheiro);
        if (numero_participantes_lido != id_participante)
        {
            id_participante = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d alunos de ficheiro com sucesso.", id_participante);
        }

    return id_participante;
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
    int id_atividade, numero_atividades_lido;
    FILE *ficheiro;
    ficheiro = fopen("atividades.bin","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&id_atividade, sizeof(int), 1, ficheiro);
        numero_atividades_lido = fread(atividade, sizeof(atividades), id_atividade, ficheiro);
        fclose(ficheiro);
        if (numero_atividades_lido != id_atividade)
        {
            id_atividade = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d alunos de ficheiro com sucesso.", id_atividade);
        }

    return id_atividade;
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
    int id_inscricao, numero_inscricoes_lido;
    FILE *ficheiro;
    ficheiro = fopen("inscricoes.bin","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&id_inscricao, sizeof(int), 1, ficheiro);
        numero_inscricoes_lido = fread(inscricao, sizeof(inscricoes), id_inscricao, ficheiro);
        fclose(ficheiro);
        if (numero_inscricoes_lido != id_inscricao)
        {
            id_inscricao = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d alunos de ficheiro com sucesso.", id_inscricao);
        }

    return id_inscricao;
}


int menu_associacao_estudantes (void)
{
     int opcao;
     do
        {
        printf("\n\tEscolha a Associacao de Estudantes:\n\n");
        printf("1 - AE / ESECS.\n");
        printf("2 - AE / ESTG.\n");
        printf("3 - AE / ESSLei.\n");
        printf("4 - AE / ESAD.\n");
        printf("5 - AE / ESTM.\n\n");
        scanf("%d", &opcao);
        }
        while (opcao < 1 || opcao > 5);
    return opcao;
}

int escolha_associacao (int opcao)
{

        switch(opcao)
        {
        case 1:
            printf("AE / ESECS");
            break;

        case 2:
            printf("AE / ESTG");
            break;

        case 3:
            printf("AE / ESSLei");
            break;

        case 4:
            printf("AE / ESAD");
            break;

        case 5:
            printf("AE / ESTM");
            break;

        default:
            printf("\nDigite uma opcao valida!\n");
        }
}





/*void gravar_ficheiro(participantes vet_parti[], int id_parti, atividades vet_ativi[], int id_ativi, inscricoes vet_inscri[], int id_inscri)
{
    FILE *ficheiro;
    ficheiro = fopen("save.bin","wb");
    if (ficheiro == NULL)
        printf("Nao foi possivel criar o ficheiro!");
    else
    {
        fwrite(&id_parti, sizeof(int), 1, ficheiro);
        fwrite(vet_parti, sizeof(participantes), id_parti, ficheiro);
        fwrite(&id_ativi, sizeof(int), 1, ficheiro);
        fwrite(vet_ativi, sizeof(atividades), id_ativi, ficheiro);
        fwrite(&id_inscri, sizeof(int), 1, ficheiro);
        fwrite(vet_inscri, sizeof(inscricoes), id_inscri, ficheiro);
        fclose(ficheiro);
        printf("\nEscrita dos dados de %d alunos, %d atividades, %d inscricoes em ficheiro com sucesso.",
               id_parti, id_ativi, id_inscri);
    }
}
void ler_ficheiro(participantes vet_parti[], int *id_parti, atividades vet_ativi[], int *id_ativi, inscricoes vet_inscri[], int *id_inscri)
{
    int numero_parti_lido, numero_ativi_lido, numero_inscri_lido;
    FILE *ficheiro;
    ficheiro = fopen("save.bin","rb");
    if (ficheiro == NULL)
        printf("Nao foi possivel abrir o ficheiro!");
    else
    {
        fread(&*id_parti, sizeof(int), 1, ficheiro);
        numero_parti_lido = fread(vet_parti, sizeof(participantes), *id_parti, ficheiro);

        fread(&*id_ativi, sizeof(int), 1, ficheiro);
        numero_ativi_lido = fread(vet_ativi, sizeof(atividades), *id_ativi, ficheiro);

        fread(&*id_inscri, sizeof(int), 1, ficheiro);
        numero_inscri_lido = fread(vet_inscri, sizeof(inscricoes), *id_inscri, ficheiro);

        fclose(ficheiro);
        if (numero_parti_lido != *id_parti || numero_ativi_lido != *id_ativi || numero_inscri_lido != *id_inscri)
        {
            *id_parti = 0;
            *id_ativi = 0;
            *id_inscri = 0;
            printf("Erro na leitura de dados do ficheiro!");
        }
        else
            printf("\nLeitura dos dados de %d participantes, %d atividades e %d inscricoes de ficheiro com sucesso.", *id_parti, *id_ativi, *id_inscri);
        }

}*/
