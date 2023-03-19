#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. Definição de uma estrutura de dados dinâmica (a validar previamente com o docente), para a representação dos meios de mobilidade elétrica, clientes e gestores;
//Definir a estrutura para resentar os meios de mobilidade elétrica
typedef struct veiculo {
    int codigo; //Codigo único de cada veículo
    char tipo[20]; //String com tamanho máximo de 20 caracteres para armazenar o tipo de veículo (por exemplo, bicicleta elétrica, patinete elétrico, etc.)
    char localizacao[100]; //String com tamanho máximo de 100 caracteres para armazenar a localização do veículo
    int carga_bateria; //Inteiro para armazenar a carga atual da bateria do veículo
    float custo; //Float para armazenar o custo do veiculo
    int estado; //Interio para armazenar o estado do veiculo (0=disponivel, 1=alugado)
    struct reserva *reserva; //Ponteiro para uma lista de reservas
    struct veiculo *proximo; //Ponteiro para o próximo nó da lista
} veiculo;

//Definição da estrutura de dados para representar um cliente
typedef struct cliente {
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do cliente
    char endereco[100]; //String com tamanho máximo de 100 caracteres para armazenar o endereço do cliente
    int nif; //Inteiro para armazenar o número de identificação fiscal do cliente
    float saldo; //Float para armazenar o saldo atual do cliente
    struct reserva *historico; //Ponteiro para uma lista de histórico de uso
    struct cliente* proximo; //Ponteiro para o próximo nó da lista
} cliente;

//Definição da estrutura para representar os gestores
typedef struct gestor {
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do gestor
    int contacto; //Inteiro para armazenar o contacto do gestor
    char login[50]; //String com tamanho máximo de 50 caracteres para armazenar o login do gestor
    char senha[50]; //String com tamanho máximo de 50 caracteres para armazenar a senha do gestor
    struct gestor *proximo; //Ponteiro para o próximo nó da lista
} gestor;

//Definição da estrutura de dados para armazenar as reservas
typedef struct reserva {
    int codigo; //Codigo único de cada veículo
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do cliente
    int num_veiculo; //Número de veiculos reservados
    int dia, mes, ano; //Data da reserva
    struct reserva *proximo; //Ponteiro para o próximo nó da lista
} reserva;

//3. Inserção de novos dados (cliente/gestor/meio de mobilidade elétrica)
//Função para adicionar um novo meio de mobilidade à lista encadeada
struct veiculo* adicionar_veiculo(struct veiculo* inicio, int codigo, char *tipo, char *localizacao, int carga_bateria, float custo, int estado) {
    struct veiculo* novo_veiculo = (struct veiculo*) malloc(sizeof(struct veiculo)); //Alocar espaço na memória para a nova estrutura
    novo_veiculo->codigo = codigo; //Definir o codigo do novo veiculo
    strcpy(novo_veiculo->tipo, tipo); //Copiar o tipo de veiculo para o campo 'tipo' da nova estrutura
    strcpy(novo_veiculo->localizacao, localizacao); //Copiar a localização para o campo 'localizacao' da nova estrutura
    novo_veiculo->carga_bateria = carga_bateria; //Definir a carga da bateria do novo veiculo
    novo_veiculo->custo = custo; //Definir o custo do novo veiculo
    novo_veiculo->estado = estado; //Definir o estado do novo veiculo
    novo_veiculo->proximo = inicio; //Definir o próximo nó da lista como o nó que antes era o primeiro nó da lista
    return novo_veiculo; //Retornar a nova estrutura
}

//Função para adicionar um novo cliente à lista encadeada
struct cliente* adicionar_cliente(struct cliente* inicio, char *nome, char *endereco, int nif, float saldo) {
    struct cliente* novo_cliente = (struct cliente*) malloc(sizeof(struct cliente)); //Alocar espaço na memória para a nova estrutura
    strcpy(novo_cliente->nome, nome); //Copiar o nome do cliente para o campo 'nome' da nova estrutura
    strcpy(novo_cliente->endereco, endereco); //Copiar o endereço do cliente para o campo 'endereco' da nova estrutura
    novo_cliente->nif = nif; //Definir o nif do novo cliente
    novo_cliente->saldo = saldo; //Definir o saldo do novo cliente
    novo_cliente->proximo = inicio; //Definir o próximo nó da lista como o nó que antes era o primeiro nó da lista
    return novo_cliente; //Retornar a nova estrutura
}


//Função para adicionar um novo gestor à lista encadeada
struct gestor* adicionar_gestor(struct gestor* inicio, char *nome, int contacto, char *login, char *senha) {
    struct gestor* novo_gestor = (struct gestor*) malloc(sizeof(struct gestor)); //Alocar espaço na memória para a nova estrutura
    strcpy(novo_gestor->nome, nome); //Copiar o nome do gestor para o campo 'nome' da nova estrutura
    novo_gestor->contacto, contacto; //Definir o contacto do novo gestor
    strcpy(novo_gestor->login, login); //Copiar o login do gestor para o campo 'login' da nova estrutura
    strcpy(novo_gestor->senha, senha); //Copirar a senha do gestor para o campo 'senha' da nova estrutura
    novo_gestor->proximo = inicio; //Definir o próximo nó da lista como o nó que antes era o primeiro nó da lista
    return novo_gestor; //Retornar a nova estrutura
}

//2. Armazenamento/leitura dos dados em ficheiro de texto (valores de simulação) e binários (preservar dados)
//Funcao para guardar a lista dos veiculos num ficheiro
int guardar_dados_veiculo (veiculo* inicio) {
    FILE* fp; //Declaração de um ponteiro de arquivo fp
    fp = fopen("dados_veiculo.txt","w"); //Abertura do arquivo "dados_veiculo.txt" no modo de escrita ("w")
    if (fp!=NULL) { //Verifica se a abertura do arquivo foi bem-sucedida
        veiculo* aux= inicio; //Declaração de um ponteiro aux para um veiculo e inicialização com o início da lista encadeada
        while (aux != NULL) //Percorre a lista encadeada, enquanto o ponteiro aux não é nulo
        {
            fprintf(fp,"%d;%s;%s;%d;%f;%d\n", aux->codigo, aux->tipo, aux->localizacao, aux->carga_bateria, aux->custo, aux->estado); 
            /*Grava os dados do veículo apontado por aux no arquivo de texto fp, formatando-os como uma linha de texto que contém as informações 
            do veículo separadas por ponto-e-vírgula*/
            aux = aux->proximo; //Atualiza o ponteiro aux para apontar para o próximo nó da lista
        }
        fclose(fp); //Fecha o arquivo "fp"
        return(1); //Em caso de sucesso retorna 1
    }
    else return(0); //Em caso de falha retorna 0
}

//Funcao para guardar a lista dos clientes num ficheiro
int guardar_dados_cliente (cliente* inicio) {
    FILE* fp;
    fp = fopen("dados_cliente.txt","w");
    if (fp!=NULL) 
    {
        cliente* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%s;%s;%d;%f\n", aux->nome, aux->endereco, aux->nif, aux->saldo);
            aux = aux->proximo;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

//Funcao para guardar a lista dos gestores num ficheiro
int guardar_dados_gestor (gestor* inicio) {
    FILE* fp;
    fp = fopen("dados_gestor.txt","w");
    if (fp!=NULL) 
    {
        gestor* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%s;%d;%s;%s\n", aux->nome, aux->contacto, aux->login, aux->senha);
            aux = aux->proximo;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

//Funcao para ler a lista dos veiculos apartir de um ficheiro
struct veiculo* ler_dados_veiculo() {
    FILE* fp; //Declaração de um ponteiro de arquivo fp
    int codigo;
    char tipo[20];
    char localizacao[100];
    int carga_bateria;
    float custo;
    int estado;
    struct veiculo* aux=NULL;
    fp = fopen("dados_veiculo.txt","r"); //Abertura do arquivo "dados_veiculo.txt" no modo de leitura ("r")
    if (fp!=NULL) {
        while (fscanf(fp,"%d;%19s;%99s;%d;%f;%d\n", &codigo, tipo, localizacao, &carga_bateria, &custo, &estado) == 6) { 
              /*Um loop while é iniciado para ler cada linha do arquivo. A função fscanf é usada para ler os valores de cada linha,
              que são separados por ponto e vírgula (;), e armazená-los nas variáveis locais correspondentes*/
            aux = adicionar_veiculo(aux, codigo, tipo, localizacao, carga_bateria, custo, estado);
            //A função adicionar_veiculo é chamada para adicionar um novo veículo à lista ligada, com os valores lidos do arquivo de texto
        }
        fclose(fp); //Fecha o arquivo "fp".
    }
     return aux; //A função retorna um ponteiro para o início da lista ligada de veículos que foi criada a partir dos dados lidos do arquivo de texto
                 //Se o arquivo não pôde ser aberto, a função retorna um ponteiro nulo (NULL)
}

//Funcao para ler a lista dos clientes apartir de um ficheiro
cliente* ler_dados_cliente() {
    FILE* fp;
    char nome[50];
    char endereco[100];
    int nif;
    float saldo;
    cliente* aux=NULL;
    fp = fopen("dados_cliente.txt","r");
    if (fp!=NULL) {
        while (fscanf(fp,"%s;%s;%d;%f\n", nome, endereco, &nif, &saldo) == 4) {
            aux = adicionar_cliente(aux, nome, endereco, nif, saldo);
        }
        fclose(fp);
    }
     return(aux);
}

//Funcao para ler a lista dos gestores apartir de um ficheiro
gestor* ler_dados_gestor() {
    FILE* fp;
    char nome[50];
    int contacto;
    char login[50];
    char senha[50];
    gestor* aux=NULL;
    fp = fopen("dados_gestor.txt","r");
    if (fp!=NULL)
    {
        while (fscanf(fp,"%s;%d;%s;%s\n", &nome, &contacto, &login, &senha) == 4) {
            aux = adicionar_gestor(aux, nome, contacto, login, senha);
        }
        fclose(fp);
    }
     return(aux);
}

//4. Remoção de determinados dados (cliente/gestor/meio de mobilidade elétrica);
//Função para remover Veiculos
void remover_veiculo(int codigo_veiculo, veiculo **lista_veiculo) {
    //Ponteiros para percorrer a lista
    veiculo *atual = *lista_veiculo;
    veiculo *anterior = NULL;

    //Procurar o veiculo a ser removido na lista
    while (atual != NULL && atual->codigo != codigo_veiculo) {
        anterior = atual;
        atual = atual->proximo;
    }

    //Se o veiculo não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Veiculo não encontrado\n");
        return;
    }

    //Se o veiculo for encontrado, remover da lista e liberar a memória alocada
    if (anterior == NULL) {
        //Se o veiculo for o primeiro nó da lista
        *lista_veiculo = atual->proximo;
    } else {
        //Se o veiculo não for o primeiro nó da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}


//Função para remover Clientes
void remover_cliente(char *nome_cliente, cliente **lista_cliente) {
    //Ponteiros para percorrer a lista
    cliente *atual = *lista_cliente;
    cliente *anterior = NULL;

    //Procurar o cliente a ser removido na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //e o cliente não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Cliente não encontrado\n");
        return;
    }

    //Se o cliente for encontrado, remover da lista e liberar a memória alocada
    if (anterior == NULL) {
        //Se o cliente for o primeiro nó da lista
        *lista_cliente = atual->proximo;
    } else {
        //Se o cliente não for o primeiro nó da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//Função para remover Gestores
void remover_gestor(char *nome_gestor, gestor **lista_gestor) {
    //Ponteiros para percorrer a lista
    gestor *atual = *lista_gestor;
    gestor *anterior = NULL;

    //Procurar o Gestor a ser removido na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestor) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //Se o gestor não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Gestor não encontrado\n");
        return;
    }

    // Se o gestor for encontrado, remover da lista e liberar a memória alocada
    if (anterior == NULL) {
        // Se o gestor for o primeiro nó da lista
        *lista_gestor = atual->proximo;
    } else {
        // Se o gestor não for o primeiro nó da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//5. Alteração de determinados dados (cliente/gestor/meio de mobilidade elétrica);
//Função para alterar o nome do Cliente
void alterar_nome_cliente(cliente *lista_cliente, char *nome_cliente, char *novo_nome) {
    // Ponteiro para percorrer a lista
    cliente *atual = lista_cliente;

    // Procurar o Cliente a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        atual = atual->proximo;
    }

    // Se o cliente não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Cliente não encontrado\n");
        return;
    }

    // Alterar o nome do Cliente
    strcpy(atual->nome, novo_nome);
}

//Função para alterar o endereço do Cliente
void alterar_endereco_cliente(cliente *lista_cliente, char *nome_cliente, char *endereco) {
    // Ponteiro para percorrer a lista
    cliente *atual = lista_cliente;

    // Procurar o Cliente a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        atual = atual->proximo;
    }

    // Se o cliente não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Cliente não encontrado\n");
        return;
    }

    // Alterar o endereço do Cliente
    strcpy(atual->endereco, endereco);
}

//Função para alterar o saldo do Cliente
void alterar_saldo_cliente(cliente *lista_cliente, char *nome_cliente, float saldo) {
    // Ponteiro para percorrer a lista
    cliente *atual = lista_cliente;

    // Procurar o Cliente a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        atual = atual->proximo;
    }

    // Se o cliente não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Cliente não encontrado\n");
        return;
    }

    // Alterar o saldo do Cliente
    atual->saldo = saldo;
}

//Função para alterar o nome do Gestor
void alterar_nome_gestor(gestor **lista_gestor, char *nome_gestor, char *novo_nome) {
    // Ponteiro para percorrer a lista
    gestor *atual = *lista_gestor;

    // Procurar o Gestor a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestor) != 0) {
        atual = atual->proximo;
    }

    // Se o gestor não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Gestor não encontrado\n");
        return;
    }

    // Alterar o nome do Gestor
    strcpy(atual->nome, novo_nome);
}

//Função para alterar o contacto do Gestor
void alterar_contacto_gestor(gestor **lista_gestor, char *nome_gestor, int novo_contacto) {
    // Ponteiro para percorrer a lista
    gestor *atual = *lista_gestor;

    // Procurar o gestor a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestor) != 0) {
        atual = atual->proximo;
    }

    // Se o gestor não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Gestor não encontrado\n");
        return;
    }

    // Alterar o endereço do Gestor
    atual->contacto, novo_contacto;
}

//Funcao para alterar o estado do veiculo
void alterar_estado(veiculo **lista_veiculo, int codigo_veiculo) {
    // Ponteiro para percorrer a lista
    veiculo *atual = *lista_veiculo;

    // Procurar o veiculo a ser alterado na lista
    while (atual != NULL && (atual->codigo == codigo_veiculo) != 0) {
         atual = atual->proximo;
    }

    // Se o veiculo não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Veiculo nao encontrado\n");
    }

    //Alterar o estado do veiculo
    atual->estado = 0;
}

//Funcao para alterar o codigo do veiculo
void alterar_codigo(veiculo **lista_veiculo, int codigo_veiculo, int novo_cod) {
     // Ponteiro para percorrer a lista
    veiculo *atual = *lista_veiculo;

    // Procurar o veiculo a ser alterado na lista
    while (atual != NULL && (atual->codigo == codigo_veiculo) != 0) {
         atual = atual->proximo;
    }

    // Se o veiculo não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Veiculo nao encontrado\n");
    }
    
    //Alterar o codigo do veiculo
    atual->codigo = novo_cod;
}

//Funcao para mudar a localizacao do veiculo
void alterar_localizacao(veiculo **lista_veiculo, int codigo_veiculo, char *localizacao) {
     // Ponteiro para percorrer a lista
    veiculo *atual = *lista_veiculo;

    // Procurar o veiculo a ser alterado na lista
    while (atual != NULL && (atual->codigo == codigo_veiculo) != 0) {
         atual = atual->proximo;
    }

    // Se o veiculo não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Veiculo nao encontrado\n");
    }
    
    //Alterar localizacao do veiculo
    strcpy(atual->localizacao,localizacao);
}

//Funcao para alterar a bateria do veiculo
void alterar_bateria(veiculo **lista_veiculo, int codigo_veiculo, int carga_bateria) {
        // Ponteiro para percorrer a lista
    veiculo *atual = *lista_veiculo;

    // Procurar o veiculo a ser alterado na lista
    while (atual != NULL && (atual->codigo == codigo_veiculo) != 0) {
         atual = atual->proximo;
    }

    // Se o veiculo não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Veiculo nao encontrado\n");
    }
    
    //Alterar a bateria do veiculo
    atual->carga_bateria = carga_bateria;
}

//Funcao para alterar o custo do veiculo
void alterar_custo(veiculo **lista_veiculo, int codigo_veiculo, int custo) {
     // Ponteiro para percorrer a lista
    veiculo *atual = *lista_veiculo;

    // Procurar o veiculo a ser alterado na lista
    while (atual != NULL && (atual->codigo == codigo_veiculo) != 0) {
         atual = atual->proximo;
    }

    // Se o veiculo não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Veiculo nao encontrado\n");
    }
    
    //Alterar custo do veiculo
    atual->custo = custo;
}

//6. Registo do aluguer de um determinado meio de mobilidade elétrica;
int registra_aluguel(veiculo *veiculo, cliente *cliente, char *nome_cliente, int num_veiculo, int codigo_veiculo[], int dia, int mes, int ano) {
    int i;
    for (i = 0; i < num_veiculo; i++) {
        if (veiculo[i].codigo == codigo_veiculo) {
            if (veiculo[i].estado == 0) { // Meio disponível para aluguel
                struct reserva* nova_reserva = (struct reserva*) malloc(sizeof(struct reserva));
                veiculo[i].estado = 1; // Atualiza estado do meio para "alugado"
                nova_reserva->codigo = codigo_veiculo[i]; //Registra o codigo do veiculo
                strcpy(nova_reserva->nome,nome_cliente); // Registra o nome do cliente que alugou o meio
                nova_reserva->dia = dia; //Registra o dia em que foi alogado
                nova_reserva->mes = mes; //Registra o mes em que foi alogado
                nova_reserva->ano = ano; ////Registra o ano em que foi alogado
                nova_reserva->proximo = cliente->historico;
                cliente->historico = nova_reserva;
                veiculo[i].reserva = nova_reserva;
                return 1; // Retorna 1 em caso de sucesso
            } else { // Meio já alugado
                return 0; // Retorna 0 em caso de falha
            }
        }
    }
    return 0; // Retorna 0 em caso de falha
}


int registro_aluguel(veiculo *veiculo, int codigo_veiculo) {
    int i;
    for (i = 0; veiculo->proximo != NULL; i++) {
        if (veiculo->codigo == codigo_veiculo) {
            if (veiculo->estado == 0) {
                printf("Veiculo disponivel.\n");
                return 1; // retorna 1 em caso de sucesso
            } else {
                printf("Veiculo alugado.\n");
                return 0; // retorna 0 em caso de falha
            }
        }
    }
    printf("Veiculo nao encontrado.\n");
    return 0; // retorna 0 em caso de falha
}

//7. Listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia;
void lista_veiculo_por_bateria(veiculo **lista_veiculo, int tamanho_lista) {
    int i, j;
    veiculo *temp;

    // Ordena os meios por ordem decrescente de autonomia usando o algoritmo Bubble Sort
    for (i = 0; i < tamanho_lista - 1; i++) {
        for (j = 0; j < tamanho_lista - i - 1; j++) {
            if ((*lista_veiculo)[j].carga_bateria < (*lista_veiculo)[j + 1].carga_bateria) {
                temp = &(*lista_veiculo)[j];
                (*lista_veiculo)[j] = (*lista_veiculo)[j + 1];
                (*lista_veiculo)[j + 1] = *temp;
            }
        }
    }

    // Imprime a lista de meios ordenada por ordem decrescente de autonomia
    printf("Lista de meios de mobilidade eletrica por ordem decrescente de autonomia:\n");
    for (i = 0; i < tamanho_lista; i++) {
        printf("%d - %s (%d km)\n", (*lista_veiculo)[i].codigo, (*lista_veiculo)[i].tipo, (*lista_veiculo)[i].carga_bateria);
    }
}

//8. Listagem dos meios de mobilidade elétrica existentes numa localização com determinado geocódigo.
void lista_veiculos_por_localizacao(veiculo *veiculo, int tamanho_lista, char *localizacao) {
    int i, j;

    //Imprime a lista dos veiculos com a mesma localização que a indicada
    printf("Lista de meios de mobilidade eletrica na localizacao indicada:\n");
    for (i = 0; i < tamanho_lista; i++) {
        if (strcmp(veiculo[i].localizacao, localizacao) == 0)
            printf("%d - %s\n", veiculo[i].codigo, veiculo[i].tipo);
    }
}

int menu_geral() {
 int op;
 printf("MENU GERAL\n");
 printf("1 Inserção de novo cliente\n");
 printf("2 Alteracao de dados\n");
 printf("3 Alugar veiculo(s)\n");
 printf("4 Registo do aluguer de um determinado meio de mobilidade elétrica\n");
 printf("5 Listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia\n");
 printf("6 Listagem dos meios de mobilidade elétrica existentes numa localização com determinado geocódigo\n");
 printf("7 Guardar dados num ficheiro\n");
 printf("8 Ler um ficheiro\n");
 printf("9 Abrir o menu de gestor\n");
 printf("0 Sair\n");
 printf("Opcao:\n");
 scanf("%d",&op);
 return(op);
}

int menu_gestor() {
    int op2;
    printf("MENU GESTOR\n");
    printf("1 Insercao de novos dados\n");
    printf("2 Alteracao de dados\n");
    printf("3 Remocao de dados\n");
    printf("4 Consulta de historicos\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d",&op2);
    return(op2);
}

int menu3() {
    int op3;
    printf("MENU 2\n");
    printf("1 Alterar o nome do cliente\n");
    printf("2 Alterar o endereco do cliente\n");
    printf("3 Alterar o saldo do cliente\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d",&op3);
    return(op3);
}

int menu4() {
    int op4;
    printf("MENU 3\n");
    printf("1 Selevionar lista dos veiculos\n");
    printf("2 Selevionar lista dos clientes\n");
    printf("3 Selevionar lista dos gestores\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d",&op4);
    return(op4);
}

int menu5() {
    int op5;
    printf("MENU 4\n");
    printf("1 Alterar o codigo do veiculo\n");
    printf("2 Alterar a localizacao do veiculo\n");
    printf("3 Alterar a bateria do veiculo\n");
    printf("4 Alterar o custo do veiculo\n");
    printf("5 Alterar o nome do cliente\n");
    printf("6 Alterar o endereco do cliente\n");
    printf("7 Alterar o saldo do cliente\n");
    printf("8 Alterar o nome do gestor\n");
    printf("9 Alterar o contacto do gestor\n");
    printf("10 Alterar o estado do veiculo\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d",&op5);
    return(op5);
}

int main(){
    veiculo* lista_veiculo = NULL; //Lista ligada vazia dos veiculos
    cliente* lista_cliente = NULL; //Lista ligada vazia dos clientes
    gestor* lista_gestor = NULL; //Lista ligada vazia dos gestores
    int op, op2, op3, op4, op5, i, cod, bat, custo, nif, contacto, num_veiculo, array[5]= {0}, tamanho_lista, novo_cod, dia, mes, ano, estado;
    char tipo[20], localizacao[100], cliente_nome[50], cliente_endereco[100], gestor_nome[50], login[20], senha[20], novo_nome[50], novo_cliente_endereco[100];
    float saldo, novo_cliente_saldo;
    do {
     op = menu_geral();
     switch(op) {
      case 1: printf("Nome do cliente?\n");
           scanf("%s", cliente_nome);
           printf("Endereco?\n");
           scanf("%s", cliente_endereco);
           printf("NIF?\n");
           scanf("%d", &nif);
           printf("Saldo?\n");
           scanf("%f", &saldo);
           lista_cliente = adicionar_cliente(lista_cliente, cliente_nome, cliente_endereco, nif, saldo);
      break;
      case 2: do {
           op3 = menu3();
           switch(op3) {
                       case 1: printf("Nome do cliente?\n");
                            scanf("%s", cliente_nome);
                            printf("Novo nome?\n");
                            scanf("%s", novo_nome);
                            alterar_nome_cliente(lista_cliente, cliente_nome, novo_nome);
                       break;
                       case 2: printf("Nome do cliente?\n");
                            scanf("%s", cliente_nome);
                            printf("Novo endereco?\n");
                            scanf("%s", novo_cliente_endereco);
                            alterar_endereco_cliente(lista_cliente, cliente_nome, novo_cliente_endereco);
                       break;
                       case 3: printf("Nome do cliente?\n");
                            scanf("%s", cliente_nome);
                            printf("Novo saldo?\n");
                            scanf("%f", novo_cliente_saldo);
                            alterar_saldo_cliente(lista_cliente,cliente_nome, novo_cliente_saldo);
                       break;
           }
      } while (op3!=0);
      break;
      case 3: printf("Nome do cliente que em que vai ficar o aluguel?\n");
           scanf("%s", cliente_nome);
           printf("Qunatos veiculos vai querer alugar?\n");
           scanf("%d", &num_veiculo);
           for(i = 1; i <= num_veiculo; i++){
              if(num_veiculo == 1) {
                 printf("Qual o codigo do veiculo que quer alugar?\n");
                 scanf("%d", &array[i]);
              } else {
                 printf("Qual e o codigo do %d veiculo que quer alugar?\n", &i);
                 scanf("%d", &array[i]);
              }
           }
           printf("Qual e o dia?\n");
           scanf("%d", &dia);
           printf("Qual e o mes?\n");
           scanf("%d", &mes);
           printf("Qual e o ano?\n");
           scanf("%d", &ano);
	       registra_aluguel(lista_veiculo, lista_cliente, cliente_nome, num_veiculo, array, dia, mes, ano);
      break;
      case 4: printf("Codigo do veiculo?\n");
	     scanf("%d", &cod);
           lista_veiculo = registro_aluguel(lista_veiculo, cod);           
      break;
      case 5: tamanho_lista = 0;
           veiculo *atual = lista_veiculo;
           while (atual != NULL) {
                tamanho_lista++;
           }
           lista_veiculo_por_bateria(lista_veiculo, tamanho_lista);
      break;
      case 6: printf("Qual a localizacao?\n");
           scanf("%s", &localizacao);
           tamanho_lista = 0;
           veiculo *atual = lista_veiculo;
           while (atual != NULL) {
                tamanho_lista++;
           }
           lista_veiculo = lista_veiculos_por_localizacao(lista_veiculo, tamanho_lista, localizacao);
      break;
      case 7: lista_veiculo = guardar_dados_veiculo;
           lista_cliente = guardar_dados_cliente;
           lista_gestor = guardar_dados_gestor;
      break;
      case 8: lista_veiculo = ler_dados_veiculo;
           lista_cliente = ler_dados_cliente;
           lista_gestor = ler_dados_gestor;
      break;
      case 9: do {
           op2 = menu_gestor();
           switch(op2) {
                       case 1: do {
                            op4 = menu4();
                            switch(op4) {
                                        case 1: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             printf("Tipo?\n");
                                             scanf("%s", &tipo);
                                             printf("Localizacao?\n");
                                             scanf("%s", localizacao);
                                             printf("Carga da bateria?\n");
                                             scanf("%d", &bat);
                                             printf("Custo?\n");
                                             scanf("%f", &custo);
                                             printf("Estado?\n");
                                             scanf("%d", &estado);
                                             lista_veiculo = adicionar_veiculo(lista_veiculo, cod, tipo, localizacao, bat, custo, estado);
                                        break;
                                        case 2: printf("Nome?\n");
                                             scanf("%s", &cliente_nome);
                                             printf("Enderco?\n");
                                             scanf("%s", &cliente_endereco);
                                             printf("NIF?\n");
                                             scanf("%d", &nif);
                                             printf("Saldo?\n");
                                             scanf("%f", &saldo);
                                             lista_cliente = adicionar_cliente(lista_cliente, cliente_nome, cliente_endereco, nif, saldo);
                                        break;
                                        case 3: printf("Nome?\n");
                                             scanf("%s", &gestor_nome);
                                             printf("Contacto?\n");
                                             scanf("%d", &contacto);
                                             printf("Login?\n");
                                             scanf("%s", &login);
                                             printf("Senha?\n");
                                             scanf("%s", &senha);
                                             lista_gestor = adicionar_gestor(lista_gestor, gestor_nome, contacto, login, senha);
                                        break;
                            }
                       } while (op4!=0);     
                       break;
                       case 2: do {
                            op5 = menu5();
                            switch(op5) {
                                        case 1: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             printf("Novo codigo?\n");
                                             scanf("%d", &novo_cod);
                                             lista_veiculo = alterar_codigo(lista_veiculo, cod, novo_cod);
                                        break;
                                        case 2: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             printf("Nova localizacao?\n");
                                             scanf("%s", &localizacao);
                                             lista_veiculo = alterar_localizacao(lista_veiculo, cod, localizacao);
                                        break;
                                        case 3: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             printf("Quanta bateria tem?\n");
                                             scanf("%d", &bat);
                                             lista_veiculo = alterar_bateria(lista_veiculo, cod, bat);
                                        break;
                                        case 4: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             printf("Novo custo?\n");
                                             scanf("%f", &custo);
                                             lista_veiculo = alterar_custo(lista_veiculo, cod, custo);
                                        break;
                                        case 5: printf("Nome do cliente?\n");
                                             scanf("%s", &cliente_nome);
                                             printf("Novo nome?\n");
                                             scanf("%s", &novo_nome);
                                             lista_cliente = alterar_nome_cliente(lista_cliente, cliente_nome, novo_nome);
                                        break;
                                        case 6: printf("Nome do cliente?\n");
                                             scanf("%s", &cliente_nome);
                                             printf("Novo endereco?\n");
                                             scanf("%s", &novo_cliente_endereco);
                                             lista_cliente = alterar_endereco_cliente(lista_cliente, cliente_nome, novo_cliente_endereco);
                                        break;
                                        case 7: printf("Nome do cliente?\n");
                                             scanf("%s", &cliente_nome);
                                             printf("Novo saldo?\n");
                                             scanf("%f", &novo_cliente_saldo);
                                             lista_cliente = alterar_saldo_cliente(lista_cliente, cliente_nome, novo_cliente_saldo);
                                        break;
                                        case 8: printf("Nome do gestor?\n");
                                             scanf("%s", &gestor_nome);
                                             printf("Novo nome?\n");
                                             scanf("%s", &novo_nome);
                                             lista_gestor = alterar_nome_gestor(lista_gestor, gestor_nome, novo_nome);
                                        break;
                                        case 9: printf("Nome do gestor?\n");
                                             scanf("%s", &gestor_nome);
                                             printf("Novo contacto?\n");
                                             scanf("%d", &contacto);
                                             lista_gestor = alterar_contacto_gestor(lista_gestor, gestor_nome, contacto);
                                        break;
                                        case 10: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             lista_veiculo = alterar_estado(lista_veiculo, cod);
                                        break;
                            }
                       } while (op5!=0);
                       break;
                       case 3: do {
                            op4 = menu4();
                            switch(op4) {
                                        case 1: printf("Codigo?\n");
                                             scanf("%d", &cod);
                                             lista_veiculo = remover_veiculo(lista_veiculo, cod);
                                        break;
                                        case 2: printf("Nome?\n");
                                             scanf("%s", &cliente_nome);
                                             lista_cliente = remover_cliente(lista_cliente, cliente_nome);
                                        break;
                                        case 3: printf("Nome?\n");
                                             scanf("%s", &gestor_nome);
                                             lista_gestor = remover_gestor(lista_gestor, gestor_nome);
                                        break;
                            }
                       } while (op4!=0);     
                       break;
                       case 4: printf("Nome do cliente?\n");
                            scanf("%s", &cliente_nome);
                            // Ponteiro para percorrer a lista
                            cliente *atual = lista_cliente;

                            //
                            while (atual != NULL && strcmp(atual->nome, cliente_nome) != 0) {
                            atual = atual->proximo;
                            }

                            // Se o  não for encontrado, encerrar a função
                            if (atual == NULL) {
                            printf("Cliente nao encontrado\n");
                            
                            
                       break;
           }
          } while (op2!=0);
          break;
  }
 } while (op!=0);

 return(0);
}

