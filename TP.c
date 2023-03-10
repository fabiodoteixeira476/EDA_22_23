//Definir a estrutura para representar os meios de mobilidade el�trica
typedef struct veiculo {
    char tipo[20]; //String com tamanho m�ximo de 20 caracteres para armazenar o tipo de ve�culo (por exemplo, bicicleta el�trica, patinete el�trico, etc.);
    char localizaca[100]; //String com tamanho m�ximo de 100 caracteres para armazenar a localiza��o do ve�culo;
    int carga_bateria; //Inteiro para armazenar a carga atual da bateria do ve�culo;
    struct reserva *reservas; //Ponteiro para uma lista de reservas;
    struct veiculo *proximo; //Ponteiro para o pr�ximo n� da lista;
} Veiculo;

//Defini��o da estrutura de dados para representar um cliente
typedef struct cliente {
    char nome[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o nome do cliente;
    char endereco[100]; //String com tamanho m�ximo de 100 caracteres para armazenar o endere�o do cliente;
    char nif[15]; //String com tamanho m�ximo de 15 caracteres para armazenar o n�mero de identifica��o fiscal do cliente;
    struct historico *historico; //Ponteiro para uma lista de hist�rico de uso;
    float saldo; //Float para armazenar o saldo atual do cliente;
    struct cliente* proximo; //Ponteiro para o pr�ximo n� da lista;
} Cliente;

//Definir a estrutura para representar os gestores
typedef struct gestor {
    char nome[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o nome do gestor;
    char contato[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o contato do gestor;
    char login[50]; //String com tamanho m�ximo de 50 caracteres para armazenar o login do gestor;
    char senha[50]; //String com tamanho m�ximo de 50 caracteres para armazenar a senha do gestor;
    struct gestor *proximo; //Ponteiro para o pr�ximo n� da lista;
} Gestor;

//Fun��o para adicionar um novo meio de mobilidade � lista encadeada
struct Veiculo* adicionar_Veiculo(struct Veiculo* inicio, char tipo[], float localizacao[], int carga_bateria) {
    struct Veiculo* novo_meio = (struct Veiculo*) malloc(sizeof(struct Veiculo)); //Alocar espa�o na mem�ria para a nova estrutura
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

//Fun��o para remover Veiculos
void removerveiculos(char *nome_veiculo, veiculo **lista_veiculos) {
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
