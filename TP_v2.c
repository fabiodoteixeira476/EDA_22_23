#include <stdio.h>
#include <string.h>

//1. Defini��o de uma estrutura de dados din�mica (a validar previamente com o docente), para a representa��o
//dos meios de mobilidade el�trica, clientes e gestores;
//Definir a estrutura para representar os meios de mobilidade el�trica
typedef struct veiculo {
    int codigo; //Codigo �nico de cada ve�culo;
    char tipo[20]; //String com tamanho m�ximo de 20 caracteres para armazenar o tipo de ve�culo (por exemplo, bicicleta el�trica, patinete el�trico, etc.);
    char localizacao[100]; //String com tamanho m�ximo de 100 caracteres para armazenar a localiza��o do ve�culo;
    int carga_bateria; //Inteiro para armazenar a carga atual da bateria do ve�culo;
    struct reserva *reservas; //Ponteiro para uma lista de reservas;
    struct veiculo *proximo; //Ponteiro para o pr�ximo n� da lista;
} veiculo;

//Defini��o da estrutura de dados para representar um cliente
typedef struct cliente {
    char nome[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o nome do cliente;
    char endereco[100]; //String com tamanho m�ximo de 100 caracteres para armazenar o endere�o do cliente;
    char nif[15]; //String com tamanho m�ximo de 15 caracteres para armazenar o n�mero de identifica��o fiscal do cliente;
    struct historico *historico; //Ponteiro para uma lista de hist�rico de uso;
    float saldo; //Float para armazenar o saldo atual do cliente;
    struct cliente* proximo; //Ponteiro para o pr�ximo n� da lista;
} cliente;

//Definir a estrutura para representar os gestores
typedef struct gestor {
    char nome[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o nome do gestor;
    char contato[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o contato do gestor;
    char login[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o login do gestor;
    char senha[50]; //String com tamanho m�ximo de 50 caracteres para armazenar a senha do gestor;
    struct gestor *proximo; //Ponteiro para o pr�ximo n� da lista;
} gestor;

//2. Armazenamento/leitura dos dados em ficheiro de texto (valores de simula��o) e bin�rios (preservar dados);
int guardarveiculo(veiculo* inicio)
{FILE* fp;
 fp = fopen("veiculo.txt","w");
 if (fp!=NULL)
 {
 veiculo* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%s;%f\n", aux->codigo, aux->tipo, aux->localizacao, aux->carga_baterira);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

veiculo* lerMeios()
{FILE* fp;
 int codigo;
 char tipo[20];
 char localizacao[100];
 float carga_bateria;
 veiculo* aux=NULL;
 fp = fopen("veiculo.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%[^\n]s;%[^\n]s;%f\n", &codigo, tipo, localizacao, &carga_bateria);
    aux = adicionar_veiculo(aux, codigo, tipo, localizacao, aut);
  }
  fclose(fp);
 }
 return(aux);
}

//3. Inser��o de novos dados (cliente/gestor/meio de mobilidade el�trica);
//Fun��o para adicionar um novo meio de mobilidade � lista encadeada
struct veiculo* adicionar_veiculo(struct veiculo* inicio, char tipo[], float localizacao[], int carga_bateria) {
    struct veiculo* novo_meio = (struct veiculo*) malloc(sizeof(struct veiculo)); //Alocar espa�o na mem�ria para a nova estrutura
    strcpy(novo_meio->tipo, tipo); //Copiar o tipo de meio de mobilidade para o campo 'tipo' da nova estrutura
    novo_meio->localizacao[0] = localizacao[0]; //Definir a coordenada X da localiza��o do meio de mobilidade
    novo_meio->localizacao[1] = localizacao[1]; //Definir a coordenada Y da localiza��o do meio de mobilidade
    novo_meio->carga_bateria = carga_bateria; //Definir a carga da bateria do meio de mobilidade
    novo_meio->proximo = inicio; //Definir o pr�ximo n� da lista como o n� que antes era o primeiro n� da lista
    return novo_meio; //Retornar a nova estrutura
}

//Fun��o para adicionar um novo cliente � lista encadeada
struct cliente* adicionar_cliente(struct cliente* inicio, char nome[], char contato[], char endereco[], char pagamento[]) {
    struct cliente* novo_cliente = (struct cliente*) malloc(sizeof(struct cliente)); //Alocar espa�o na mem�ria para a nova estrutura
    strcpy(novo_cliente->nome, nome); //Copiar o nome do cliente para o campo 'nome' da nova estrutura
    strcpy(novo_cliente->contato, contato); //Copiar o contato do cliente para o campo 'contato' da nova estrutura
    strcpy(novo_cliente->endereco, endereco); //Copiar o endere�o do cliente para o campo 'endereco' da nova estrutura
    strcpy(novo_cliente->pagamento, pagamento); //Copiar o m�todo de pagamento do cliente para o campo 'pagamento' da nova estrutura
    novo_cliente->proximo = inicio; //Definir o pr�ximo n� da lista como o n� que antes era o primeiro n� da lista
    return novo_cliente; //Retornar a nova estrutura
}


//Fun��o para adicionar um novo gestor � lista encadeada
struct gestor* adicionar_gestor(struct gestor* inicio, char nome[], char contato[], char login[]) {
    struct gestor* novo_gestor = (struct gestor*) malloc(sizeof(struct gestor)); //Alocar espa�o na mem�ria para a nova estrutura
    strcpy(novo_gestor->nome, nome); //Copiar o nome do gestor para o campo 'nome' da nova estrutura
    strcpy(novo_gestor->contato, contato); //Copiar o contato do gestor para o campo 'contato' da nova estrutura
    strcpy(novo_gestor->login, login); //Copiar o login do gestor para o campo 'login' da nova estrutura
    strcpy(novo_gestor->senha, senha); //Copirar a senha do gestor para o campo 'senha' da nova estrutura
    novo_gestor->proximo = inicio; //Definir o pr�ximo n� da lista como o n� que antes era o primeiro n� da lista
    return novo_gestor; //Retornar a nova estrutura
}

//4. Remo��o de determinados dados (cliente/gestor/meio de mobilidade el�trica);
//Fun��o para remover Veiculos *conferir
void removerveiculo(int *codigo_veiculo, veiculo **lista_veiculos) {
    //Ponteiros para percorrer a lista
    veiculo *atual = *lista_veiculos;
    veiculo *anterior = NULL;

    //Procurar o veiculo a ser removido na lista
    while (atual != NULL && strcmp(atual->tipo, tipo_veiculo) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //Se o veiculo n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Veiculo n�o encontrado\n");
        return;
    }

    //Se o veiculo for encontrado, remover da lista e liberar a mem�ria alocada
    if (anterior == NULL) {
        //Se o veiculo for o primeiro n� da lista
        *lista_veiculos = atual->proximo;
    } else {
        //Se o veiculo n�o for o primeiro n� da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//Fun��o para remover Clientes
void removercliente(char *nome_cliente, Cliente **lista_clientes) {
    //Ponteiros para percorrer a lista
    Cliente *atual = *lista_clientes;
    Cliente *anterior = NULL;

    //Procurar o cliente a ser removido na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //e o cliente n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Cliente n�o encontrado\n");
        return;
    }

    //Se o cliente for encontrado, remover da lista e liberar a mem�ria alocada
    if (anterior == NULL) {
        //Se o cliente for o primeiro n� da lista
        *lista_clientes = atual->proximo;
    } else {
        //Se o cliente n�o for o primeiro n� da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//Fun��o para remover Gestores
void removergestore(char *nome_gestore, gestore **lista_gestores) {
    //Ponteiros para percorrer a lista
    gestore *atual = *lista_gestores;
    gestore *anterior = NULL;

    //Procurar o Gestore a ser removido na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestore) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //Se o gestore n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Gestore n�o encontrado\n");
        return;
    }

    // Se o gestore for encontrado, remover da lista e liberar a mem�ria alocada
    if (anterior == NULL) {
        // Se o gestore for o primeiro n� da lista
        *lista_gestores = atual->proximo;
    } else {
        // Se o gestore n�o for o primeiro n� da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//5. Altera��o de determinados dados (cliente/gestor/meio de mobilidade el�trica);
//Fun��o para alterar o nome do Cliente
void alterarnomecliente(char *nome_cliente, char *novo_nome, cliente **lista_clientes) {
    // Ponteiro para percorrer a lista
    cliente *atual = *lista_clientes;

    // Procurar o Cliente a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        atual = atual->proximo;
    }

    // Se o cliente n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Cliente n�o encontrado\n");
        return;
    }

    // Alterar o nome do Cliente
    strcpy(atual->nome, novo_nome);
}

//Fun��o para alterar o endere�o do Cliente
void alterarenderecocliente(char *endereco_cliente, char *novo_endereco, cliente **lista_clientes) {
    // Ponteiro para percorrer a lista
    cliente *atual = *lista_clientes;

    // Procurar o Cliente a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        atual = atual->proximo;
    }

    // Se o cliente n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Cliente n�o encontrado\n");
        return;
    }

    // Alterar o endere�o do Cliente
    strcpy(atual->endereco, novo_endereco);
}

//Fun��o para alterar o saldo do Cliente
void alterarsaldocliente(char *saldo_cliente, char *novo_saldo, cliente **lista_clientes) {
    // Ponteiro para percorrer a lista
    cliente *atual = *lista_clientes;

    // Procurar o Cliente a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_cliente) != 0) {
        atual = atual->proximo;
    }

    // Se o cliente n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Cliente n�o encontrado\n");
        return;
    }

    // Alterar o saldo do Cliente
    strcpy(atual->saldo, novo_saldo);
}

//Fun��o para alterar o nome do Gestor
void alterarnomegestor(char *nome_gestor, char *novo_nome, gestor **lista_gestors) {
    // Ponteiro para percorrer a lista
    gestor *atual = *lista_gestors;

    // Procurar o Gestor a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestor) != 0) {
        atual = atual->proximo;
    }

    // Se o gestor n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Gestor n�o encontrado\n");
        return;
    }

    // Alterar o nome do Gestor
    strcpy(atual->nome, novo_nome);
}

//Fun��o para alterar o endere�o do Gestor
void alterarenderecogestor(char *endereco_gestor, char *novo_endereco, gestor **lista_gestors) {
    // Ponteiro para percorrer a lista
    gestor *atual = *lista_gestors;

    // Procurar o gestor a ser alterado na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestor) != 0) {
        atual = atual->proximo;
    }

    // Se o gestor n�o for encontrado, encerrar a fun��o
    if (atual == NULL) {
        printf("Gestor n�o encontrado\n");
        return;
    }

    // Alterar o endere�o do Gestor
    strcpy(atual->endereco, novo_endereco);
}

//6. Registo do aluguer de um determinado meio de mobilidade el�trica;
int registra_aluguel(veiculo *veiculo, int num_veiculo, int codigo_veiculo, char nome_cliente) {
    int i;
    for (i = 0; i < num_veiculo; i++) {
        if (veiculo[i].codigo == codigo_veiculo) {
            if (veiculo[i].estado == 0) { // Meio dispon�vel para aluguel
                veiculo[i].estado = 1; // Atualiza estado do meio para "alugado"
                veiculo[i].nome_cliente_aluguel = nome_cliente; // Registra o id do cliente que alugou o meio
                return 1; // Retorna 1 em caso de sucesso
            } else { // Meio j� alugado
                return 0; // Retorna 0 em caso de falha
            }
        }
    }
    return 0; // Retorna 0 em caso de falha
}

//7. Listagem dos meios de mobilidade el�trica por ordem decrescente de autonomia;
void lista_veiculo_por_bateria(veiculo *veiculo, int codigo_veiculo) {
    int i, j;
    veiculo temp;

    // Ordena os meios por ordem decrescente de autonomia usando o algoritmo Bubble Sort
    for (i = 0; i < codigo_veiculo - 1; i++) {
        for (j = 0; j < codigo_veiculo - i - 1; j++) {
            if (veiculo[j].carga_bateria < veiculo[j + 1].carga_bateria) {
                temp = veiculo[j];
                veiculo[j] = veiculo[j + 1];
                veiculo[j + 1] = temp;
            }
        }
    }

    // Imprime a lista de meios ordenada por ordem decrescente de autonomia
    printf("Lista de meios de mobilidade eletrica por ordem decrescente de autonomia:\n");
    for (i = 0; i < codigo_veiculo; i++) {
        printf("%d - %s (%d km)\n", veiculo[i].codigo, veiculo[i].tipo, veiculo[i].carga_bateria);
    }
}

//8. Listagem dos meios de mobilidade el�trica existentes numa localiza��o com determinado geoc�digo.


int menu()
{int op;
 printf("M E N U\n");
 printf("1 Inserir Meio\n");
 printf("2 Listar Meios\n");
 printf("3 Remover Meio\n");
 printf("4 Guardar Meios\n");
 printf("5 Ler Meios\n");
 printf("0 Sair\n");
 printf("Opcao:\n");
 scanf("%d",&op);
 return(op);
}

int main(){
    Meio* meios = NULL; // Lista ligada vazia 
    int op, cod;
    float bat, aut;
    char tipo[50];
    do
    {
     op = menu();
     switch(op)
     {case 1: printf("Codigo?\n");
	   scanf("%d",&cod);
	   scanf("%*c"); 
	   printf("Tipo\n");
	   scanf("%[^\n]s",tipo);
	   printf("Nivel da bateria?\n");
	   scanf("%f",&bat);
	   printf("Autonomia\n");
	   scanf("%f",&aut);
           meios = inserirMeio(meios,cod,tipo,bat,aut);
	   break;
    case 2: listarMeios(meios); break;
    case 3: printf("Codigo do meio de mobilidade a remover?\n");
	   scanf("%d",&cod);
	   meios = removerMeio(meios, cod);
	   break;
    case 4: guardarMeios(meios); break;
    case 5: meios = lerMeios(); break;
  }
 } while (op!=0);

 return(0);
}
