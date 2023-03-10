//Definir a estrutura para representar os meios de mobilidade elétrica
typedef struct veiculo {
    char tipo[20]; //String com tamanho máximo de 20 caracteres para armazenar o tipo de veículo (por exemplo, bicicleta elétrica, patinete elétrico, etc.);
    char localizaca[100]; //String com tamanho máximo de 100 caracteres para armazenar a localização do veículo;
    int carga_bateria; //Inteiro para armazenar a carga atual da bateria do veículo;
    struct reserva *reservas; //Ponteiro para uma lista de reservas;
    struct veiculo *proximo; //Ponteiro para o próximo nó da lista;
} Veiculo;

//Definição da estrutura de dados para representar um cliente
typedef struct cliente {
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do cliente;
    char endereco[100]; //String com tamanho máximo de 100 caracteres para armazenar o endereço do cliente;
    char nif[15]; //String com tamanho máximo de 15 caracteres para armazenar o número de identificação fiscal do cliente;
    struct historico *historico; //Ponteiro para uma lista de histórico de uso;
    float saldo; //Float para armazenar o saldo atual do cliente;
    struct cliente* proximo; //Ponteiro para o próximo nó da lista;
} Cliente;

//Definir a estrutura para representar os gestores
typedef struct gestor {
    char nome[50]; //String com tamanho máximo de 50 caracteres para armazenar o nome do gestor;
    char contato[50]; //String com tamanho máximo de 50 caracteres para armazenar o contato do gestor;
    char login[50]; //String com tamanho máximo de 50 caracteres para armazenar o login do gestor;
    char senha[50]; //String com tamanho máximo de 50 caracteres para armazenar a senha do gestor;
    struct gestor *proximo; //Ponteiro para o próximo nó da lista;
} Gestor;

//Função para adicionar um novo meio de mobilidade à lista encadeada
struct Veiculo* adicionar_Veiculo(struct Veiculo* inicio, char tipo[], float localizacao[], int carga_bateria) {
    struct Veiculo* novo_meio = (struct Veiculo*) malloc(sizeof(struct Veiculo)); //Alocar espaço na memória para a nova estrutura
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

//Função para remover Veiculos
void removerveiculos(char *nome_veiculo, veiculo **lista_veiculos) {
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
