#include <stdio.h>
#include <string.h>

//1. Definição de uma estrutura de dados dinâmica (a validar previamente com o docente), para a representação
//dos meios de mobilidade elétrica, clientes e gestores;
//Definir a estrutura para representar os meios de mobilidade elétrica
typedef struct veiculo {
    int codigo; //Codigo único de cada veículo;
    char tipo[20]; //String com tamanho máximo de 20 caracteres para armazenar o tipo de veículo (por exemplo, bicicleta elétrica, patinete elétrico, etc.);
    char localizacao[100]; //String com tamanho máximo de 100 caracteres para armazenar a localização do veículo;
    int carga_bateria; //Inteiro para armazenar a carga atual da bateria do veículo;
    struct reserva *reservas; //Ponteiro para uma lista de reservas;
    struct veiculo *proximo; //Ponteiro para o próximo nó da lista;
} veiculo;

//Definição da estrutura de dados para representar um cliente
typedef struct cliente {
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do cliente;
    char endereco[100]; //String com tamanho máximo de 100 caracteres para armazenar o endereço do cliente;
    char nif[15]; //String com tamanho máximo de 15 caracteres para armazenar o número de identificação fiscal do cliente;
    struct historico *historico; //Ponteiro para uma lista de histórico de uso;
    float saldo; //Float para armazenar o saldo atual do cliente;
    struct cliente* proximo; //Ponteiro para o próximo nó da lista;
} cliente;

//Definir a estrutura para representar os gestores
typedef struct gestor {
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do gestor;
    char contato[50]; //String com tamanho máximo de 50 caracteres para armazenar o contato do gestor;
    char login[50]; //String com tamanho máximo de 50 caracteres para armazenar o login do gestor;
    char senha[50]; //String com tamanho máximo de 50 caracteres para armazenar a senha do gestor;
    struct gestor *proximo; //Ponteiro para o próximo nó da lista;
} gestor;

//2. Armazenamento/leitura dos dados em ficheiro de texto (valores de simulação) e binários (preservar dados);
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

//3. Inserção de novos dados (cliente/gestor/meio de mobilidade elétrica);
//Função para adicionar um novo meio de mobilidade à lista encadeada
struct veiculo* adicionar_veiculo(struct veiculo* inicio, char tipo[], float localizacao[], int carga_bateria) {
    struct veiculo* novo_meio = (struct veiculo*) malloc(sizeof(struct veiculo)); //Alocar espaço na memória para a nova estrutura
    strcpy(novo_meio->tipo, tipo); //Copiar o tipo de meio de mobilidade para o campo 'tipo' da nova estrutura
    novo_meio->localizacao[0] = localizacao[0]; //Definir a coordenada X da localização do meio de mobilidade
    novo_meio->localizacao[1] = localizacao[1]; //Definir a coordenada Y da localização do meio de mobilidade
    novo_meio->carga_bateria = carga_bateria; //Definir a carga da bateria do meio de mobilidade
    novo_meio->proximo = inicio; //Definir o próximo nó da lista como o nó que antes era o primeiro nó da lista
    return novo_meio; //Retornar a nova estrutura
}

//Função para adicionar um novo cliente à lista encadeada
struct cliente* adicionar_cliente(struct cliente* inicio, char nome[], char contato[], char endereco[], char pagamento[]) {
    struct cliente* novo_cliente = (struct cliente*) malloc(sizeof(struct cliente)); //Alocar espaço na memória para a nova estrutura
    strcpy(novo_cliente->nome, nome); //Copiar o nome do cliente para o campo 'nome' da nova estrutura
    strcpy(novo_cliente->contato, contato); //Copiar o contato do cliente para o campo 'contato' da nova estrutura
    strcpy(novo_cliente->endereco, endereco); //Copiar o endereço do cliente para o campo 'endereco' da nova estrutura
    strcpy(novo_cliente->pagamento, pagamento); //Copiar o método de pagamento do cliente para o campo 'pagamento' da nova estrutura
    novo_cliente->proximo = inicio; //Definir o próximo nó da lista como o nó que antes era o primeiro nó da lista
    return novo_cliente; //Retornar a nova estrutura
}


//Função para adicionar um novo gestor à lista encadeada
struct gestor* adicionar_gestor(struct gestor* inicio, char nome[], char contato[], char login[]) {
    struct gestor* novo_gestor = (struct gestor*) malloc(sizeof(struct gestor)); //Alocar espaço na memória para a nova estrutura
    strcpy(novo_gestor->nome, nome); //Copiar o nome do gestor para o campo 'nome' da nova estrutura
    strcpy(novo_gestor->contato, contato); //Copiar o contato do gestor para o campo 'contato' da nova estrutura
    strcpy(novo_gestor->login, login); //Copiar o login do gestor para o campo 'login' da nova estrutura
    strcpy(novo_gestor->senha, senha); //Copirar a senha do gestor para o campo 'senha' da nova estrutura
    novo_gestor->proximo = inicio; //Definir o próximo nó da lista como o nó que antes era o primeiro nó da lista
    return novo_gestor; //Retornar a nova estrutura
}

//4. Remoção de determinados dados (cliente/gestor/meio de mobilidade elétrica);
//Função para remover Veiculos *conferir
void removerveiculo(int *codigo_veiculo, veiculo **lista_veiculos) {
    //Ponteiros para percorrer a lista
    veiculo *atual = *lista_veiculos;
    veiculo *anterior = NULL;

    //Procurar o veiculo a ser removido na lista
    while (atual != NULL && strcmp(atual->tipo, tipo_veiculo) != 0) {
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
        *lista_veiculos = atual->proximo;
    } else {
        //Se o veiculo não for o primeiro nó da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//Função para remover Clientes
void removercliente(char *nome_cliente, Cliente **lista_clientes) {
    //Ponteiros para percorrer a lista
    Cliente *atual = *lista_clientes;
    Cliente *anterior = NULL;

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
        *lista_clientes = atual->proximo;
    } else {
        //Se o cliente não for o primeiro nó da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//Função para remover Gestores
void removergestore(char *nome_gestore, gestore **lista_gestores) {
    //Ponteiros para percorrer a lista
    gestore *atual = *lista_gestores;
    gestore *anterior = NULL;

    //Procurar o Gestore a ser removido na lista
    while (atual != NULL && strcmp(atual->nome, nome_gestore) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    //Se o gestore não for encontrado, encerrar a função
    if (atual == NULL) {
        printf("Gestore não encontrado\n");
        return;
    }

    // Se o gestore for encontrado, remover da lista e liberar a memória alocada
    if (anterior == NULL) {
        // Se o gestore for o primeiro nó da lista
        *lista_gestores = atual->proximo;
    } else {
        // Se o gestore não for o primeiro nó da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

//5. Alteração de determinados dados (cliente/gestor/meio de mobilidade elétrica);
//Função para alterar o nome do Cliente
void alterarnomecliente(char *nome_cliente, char *novo_nome, cliente **lista_clientes) {
    // Ponteiro para percorrer a lista
    cliente *atual = *lista_clientes;

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
void alterarenderecocliente(char *endereco_cliente, char *novo_endereco, cliente **lista_clientes) {
    // Ponteiro para percorrer a lista
    cliente *atual = *lista_clientes;

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
    strcpy(atual->endereco, novo_endereco);
}

//Função para alterar o saldo do Cliente
void alterarsaldocliente(char *saldo_cliente, char *novo_saldo, cliente **lista_clientes) {
    // Ponteiro para percorrer a lista
    cliente *atual = *lista_clientes;

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
    strcpy(atual->saldo, novo_saldo);
}

//Função para alterar o nome do Gestor
void alterarnomegestor(char *nome_gestor, char *novo_nome, gestor **lista_gestors) {
    // Ponteiro para percorrer a lista
    gestor *atual = *lista_gestors;

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

//Função para alterar o endereço do Gestor
void alterarenderecogestor(char *endereco_gestor, char *novo_endereco, gestor **lista_gestors) {
    // Ponteiro para percorrer a lista
    gestor *atual = *lista_gestors;

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
    strcpy(atual->endereco, novo_endereco);
}

//6. Registo do aluguer de um determinado meio de mobilidade elétrica;
int registra_aluguel(veiculo *veiculo, int num_veiculo, int codigo_veiculo, char nome_cliente) {
    int i;
    for (i = 0; i < num_veiculo; i++) {
        if (veiculo[i].codigo == codigo_veiculo) {
            if (veiculo[i].estado == 0) { // Meio disponível para aluguel
                veiculo[i].estado = 1; // Atualiza estado do meio para "alugado"
                veiculo[i].nome_cliente_aluguel = nome_cliente; // Registra o id do cliente que alugou o meio
                return 1; // Retorna 1 em caso de sucesso
            } else { // Meio já alugado
                return 0; // Retorna 0 em caso de falha
            }
        }
    }
    return 0; // Retorna 0 em caso de falha
}

//7. Listagem dos meios de mobilidade elétrica por ordem decrescente de autonomia;
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

//8. Listagem dos meios de mobilidade elétrica existentes numa localização com determinado geocódigo.


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
