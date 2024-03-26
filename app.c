#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[10000];
    char tipo[10000];
    int quantia;
    float valor_uni;
} Produto;
typedef struct {
    char nome[10000];
    char data_nsc[10000];
    int rg;
    int cpf;
} Clientes;
typedef struct {
    int cpf_cliente;
    int codigo_produto;
    int quantidade;
    float valor_total;
} Venda;
Produto lista_produtos[10000];
Clientes lista_clientes[10000];
Venda lista_vendas[10000];
int n=0,c=0,op,i,quantidadeprodutosvendidos=0,quantiavendas=0;
float valorcaixa=0.0;
void produtos(); //linha 78
void clientes(); //linha 104
void vendas(); //linha 129
void cadastrar_produto(); //linha 154
void consultar_produto(); //linha 168
void editar_produto(); //linha 175
void excluir_produto(); //linha 211
void cadastrar_cliente(); //linha 245
void consultar_cliente(); //linha 257
void editar_cliente(); //linha 264
void excluir_cliente(); //linha 395
void realizar_vendas(); //linha 326
void valor_caixa(); //linha 391
void vendas_realizadas(); //linha 395
void quantidade_produtos_vendidos(); //linha 402
float calcular_valor_caixa(); //linha 405
void salvar_produtos();//linha 412
void salvar_clientes(); //linha 424
void salvar_vendas(); //linha 436
int carregar_produtos(); //linha 451
int carregar_clientes(); //linha 480
int carregar_vendas();//linha 506
int main() {
    int op;
    n = carregar_produtos();
    c = carregar_clientes();
    quantiavendas = carregar_vendas();
    do {
        printf("\n-----MENU----- \n");
        printf("1 - Produtos \n");
        printf("2 - Clientes \n");
        printf("3 - Vendas \n");
        printf("4 - Sair \n");
        scanf("%d", &op);
        system("cls");
        switch (op) {
            case 1:
                produtos();
                break;
            case 2:
                clientes();
                break;
            case 3:
                vendas();
                break;
        }
    } while (op != 4);

    return 0;
}
void produtos() {
    do {
        printf("\n -----PRODUTOS----- \n");
        printf("1 - Cadastrar Produto \n");
        printf("2 - Consultar Produto \n");
        printf("3 - Editar Produto \n");
        printf("4 - Excluir Produto \n");
        printf("5 - Voltar \n");
        scanf("%d", &op);
        system("cls");
        switch (op) {
             case 1:
                cadastrar_produto();
                break;
             case 2:
                consultar_produto();
                break;
             case 3:
                editar_produto();
                break;
             case 4:
                excluir_produto();
                break;
        }
    } while (op!=5);
}
void clientes(){
    do{
        printf("\n-----Clientes----- \n");
        printf("1 - Cadastrar Cliente \n");
        printf("2 - Consultar Cliente \n");
        printf("3 - Editar Cliente \n");
        printf("4 - Excluir Cliente \n");
        printf("5 - Voltar \n");
        scanf("%d",&op);
        switch(op){
            case 1:
            cadastrar_cliente();
            break;
            case 2:
            consultar_cliente();
            break;
            case 3:
            editar_cliente();
            break;
            case 4:
            excluir_cliente();
            break;
        }
    }while(op!=5);
}
void vendas(){
    do{
        printf("\n-----Vendas-----\n");
        printf("1 - Realizar Venda \n");
        printf("2 - Valor do Caixa \n");
        printf("3 - Vendas Realizadas\n");
        printf("4 - Quantia de Produtos Vendidos \n");
        printf("5 - Sair \n");
        scanf("%d",&op);
        switch(op){
            case 1:
            realizar_vendas();
            break;
            case 2:
            valor_caixa();
            break;
            case 3:
            vendas_realizadas();
            break;
            case 4:
            quantidade_produtos_vendidos();
            break;
        }
    }while(op!=5);
}
void cadastrar_produto() {
    printf("Informe o Nome do produto: \n");
    scanf("%s", lista_produtos[n].nome);
    printf("Informe o Tipo do produto: \n");
    scanf("%s", lista_produtos[n].tipo);
    printf("Informe a Quantia do produto: \n");
    scanf("%d", &lista_produtos[n].quantia);
    printf("Informe o Valor unitario do produto: \n");
    scanf("%f", &lista_produtos[n].valor_uni);
    printf("Informe o codigo do produto: \n");
    scanf("%d", &lista_produtos[n].codigo);
    n++;
    salvar_produtos();
}
void consultar_produto() {
    n = carregar_produtos();
    printf("Produtos cadastrados: \n");
    for (int i=0;i<n;i++) {
        printf("nome: %s || tipo: %s || quantia: %d || valor unitario: %.2f || codigo:%d \n",lista_produtos[i].nome, lista_produtos[i].tipo, lista_produtos[i].quantia, lista_produtos[i].valor_uni, lista_produtos[i].codigo);
    }
}
void editar_produto() {
    n = carregar_produtos();
    printf("Produtos cadastrados: \n");
    for (i = 0; i < n; i++) {
        printf("Codigo: %d || Nome: %s || Tipo: %s || Quantia: %d || Valor unitario: %.2f\n", lista_produtos[i].codigo, lista_produtos[i].nome, lista_produtos[i].tipo, lista_produtos[i].quantia, lista_produtos[i].valor_uni);
    }
    int codigo;
    printf("Informe o codigo do produto que deseja editar: ");
    scanf("%d", &codigo);

    int index = -1;
    for (i = 0; i < n; i++) {
        if (lista_produtos[i].codigo == codigo) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Informe o novo nome do produto: ");
        scanf("%s", lista_produtos[index].nome);

        printf("Informe o novo tipo do produto: ");
        scanf("%s", lista_produtos[index].tipo);

        printf("Informe a nova quantia do produto: ");
        scanf("%d", &lista_produtos[index].quantia);

        printf("Informe o novo valor unitario do produto: ");
        scanf("%f", &lista_produtos[index].valor_uni);

        salvar_produtos();
        printf("Produto editado com sucesso!\n");
    } else {
        printf("O codigo do produto não foi encontrado.\n");
    }
}
void excluir_produto() {
    n = carregar_produtos();
    if (n == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados: \n");
    for (i = 0; i < n; i++) {
        printf("Codigo: %d || Nome: %s || Tipo: %s || Quantia: %d || Valor unitario: %.2f\n", lista_produtos[i].codigo, lista_produtos[i].nome, lista_produtos[i].tipo, lista_produtos[i].quantia, lista_produtos[i].valor_uni);
    }
    int codigo;
    printf("Informe o codigo do produto que deseja excluir: ");
    scanf("%d", &codigo);

    int index = -1;
    for (i = 0; i < n; i++) {
        if (lista_produtos[i].codigo == codigo) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int j = index; j < n - 1; j++) {
            lista_produtos[j] = lista_produtos[j + 1];
        }
        n--;

        salvar_produtos();
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("O codigo do produto nao foi encontrado.\n");
    }
}
void cadastrar_cliente() {
    printf("informe o nome do cliente: \n");
    scanf("%s", lista_clientes[c].nome);
    printf("informe a data de nascimento do cliente: \n");
    scanf("%s", lista_clientes[c].data_nsc);
    printf("informe o rg do cliente: \n");
    scanf("%d", &lista_clientes[c].rg);
    printf("informe o cpf do cliente: \n");
    scanf("%d", &lista_clientes[c].cpf);
    c++;
    salvar_clientes();
}
void consultar_cliente() {
    c = carregar_clientes();
    printf("Clientes cadastrados: \n");
    for (i = 0; i < c; i++) {
        printf("nome:%s || data_de_nascimento:%s || rg:%d || cpf:%d \n", lista_clientes[i].nome, lista_clientes[i].data_nsc, lista_clientes[i].rg, lista_clientes[i].cpf);
    }
}
void editar_cliente(){
    c = carregar_clientes();
    printf("produtos cadastrados: \n");
    for (i=0;i<c;i++){
        printf("cpf:%d || nome:%s || data_de_nascimento:%s || rg:%d \n",lista_clientes[i].cpf, lista_clientes[i].nome, lista_clientes[i].data_nsc, lista_clientes[i].rg);
    }
    int cpf;
    printf("informe o cpf do cliente que deseja editar: ");
    scanf("%d",&cpf);
    int index = -1;
    for (i=0;i<c;i++){
        if(lista_clientes[i].cpf == cpf){
            index = i;
            break;
        }
    }
    if(index!=-1){
        printf("informe o novo nome do cliente: ");
        scanf("%s", lista_clientes[index].nome);
        printf("informe a nova data de nascimento do cliente: ");
        scanf("%s", lista_clientes[index].data_nsc);
        printf("informe o novo rg do cliente: ");
        scanf("%d",&lista_clientes[index].rg);
        printf("informe o novo cpf do cliente: ");
        scanf("%d",&lista_clientes[index].cpf);
        salvar_clientes();
        printf("cliente editado com sucesso \n");
    }else{
        printf("cpf invalido \n");
    }
}
void excluir_cliente(){
    c = carregar_clientes();
    if(c==0){
        printf("nenhum cliente cadastrado \n");
        return;
    }
    printf("produtos cadastrados: \n");
    for(i=0;i<c;i++){
        printf("nome:%s || data_de_nascimento:%s || rg:%d || cpf:%d \n", lista_clientes[i].nome, lista_clientes[i].data_nsc, lista_clientes[i].rg, lista_clientes[i].cpf);
    }
    int cpf;
    printf("informe o cliente que deseja deletar: ");
    scanf("%d",&cpf);
    int index=-1;
    for(i=0;i<c;i++){
        if(lista_clientes[i].cpf == cpf){
            index=i;
            break;
        }
    }
    if(index!=-1){
        for (int j=index;j<c-1;j++){
            lista_clientes[j] = lista_clientes[j+1];
        }
        c--;
        salvar_clientes();
        printf("produtos excluido com sucesso \n");
    }else{
        printf("cpf invalido \n");
    }
}
void realizar_vendas() {
    int codigo, quantidade;
    float valor_total = 0;
    int cpf_cliente;
    printf("Informe o CPF do cliente: ");
    scanf("%d", &cpf_cliente);
    int codigo_produto;
    printf("Informe o codigo do produto que deseja comprar (-1 para finalizar): ");
    scanf("%d", &codigo);
    int produtos_vendidos = 0;
    while (codigo != -1) {
        printf("Informe a quantidade do produto: ");
        scanf("%d", &quantidade);

        int index = -1;
        for (int i = 0; i < n; i++) {
            if (lista_produtos[i].codigo == codigo) {
                index = i;
                break;
            }
        }
        if (index != -1 && lista_produtos[index].quantia >= quantidade && quantidade > 0) {
            lista_produtos[index].quantia -= quantidade;
            valor_total += lista_produtos[index].valor_uni * quantidade;
            codigo_produto = codigo;
            produtos_vendidos++;
        } else {
            printf("Produto nao encontrado, quantidade insuficiente em estoque ou quantidade invalida.\n");
        }

        printf("Informe o codigo do produto que deseja comprar (-1 para finalizar): ");
        scanf("%d", &codigo);
    }
    if (produtos_vendidos > 0) {
        int cliente_cadastrado = 0;
        for (int i = 0; i < c; i++) {
            if (lista_clientes[i].cpf == cpf_cliente) {
                cliente_cadastrado = 1;
                break;
            }
        }
        if (cliente_cadastrado && valor_total > 0) {
            lista_vendas[quantiavendas].cpf_cliente = cpf_cliente;
            lista_vendas[quantiavendas].codigo_produto = codigo_produto;
            lista_vendas[quantiavendas].quantidade = produtos_vendidos;
            lista_vendas[quantiavendas].valor_total = valor_total;
            quantiavendas++;
            valorcaixa += valor_total;

            printf("Venda realizada com sucesso\n");
        } else {
            int resp;
            printf("Cliente nao cadastrado ou valor da compra igual a zero. Venda nao realizada.\n");
            printf("Deseja fazer o cadastro do cliente?(1-sim/2-nao) \n");
            scanf("%d",&resp);
            if (resp == 1){
                cadastrar_cliente();
            }else{
                printf("Voltando... \n");
            }
        }
        salvar_vendas();
        salvar_produtos();
    }
}
void valor_caixa() {
    float total_caixa = calcular_valor_caixa();
    printf("Valor total em caixa: R$ %.2f\n", total_caixa);
}
void vendas_realizadas() {
    printf("Valor total em caixa: R$ %.2f\n", calcular_valor_caixa());
    printf("Vendas realizadas:\n");
    for (int i = 0; i < quantiavendas; i++) {
        printf("CPF Cliente: %d || Codigo Produto: %d || Quantidade: %d || Valor Total: %.2f\n", lista_vendas[i].cpf_cliente, lista_vendas[i].codigo_produto, lista_vendas[i].quantidade, lista_vendas[i].valor_total);
    }
}
void quantidade_produtos_vendidos(){
    printf("Quantia total de produtos vendidos: %d\n", quantiavendas);
}
float calcular_valor_caixa() {
    float total_caixa = 0.0;
    for (int i = 0; i < quantiavendas; i++) {
        total_caixa += lista_vendas[i].valor_total;
    }
    return total_caixa;
}
void salvar_produtos() {
    FILE *arquivo;
    arquivo = fopen("produtos.txt", "w");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "nome: %s || tipo: %s || quantia: %d || valor_unitario: %.2f || codigo:%d \n", lista_produtos[i].nome, lista_produtos[i].tipo, lista_produtos[i].quantia, lista_produtos[i].valor_uni, lista_produtos[i].codigo);
    }
    fclose(arquivo);
}
void salvar_clientes() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (i = 0; i < c; i++) {
        fprintf(arquivo, "nome: %s || data_de_nascimento: %s || rg: %d || cpf: %d \n",lista_clientes[i].nome, lista_clientes[i].data_nsc, lista_clientes[i].rg, lista_clientes[i].cpf);
    }
    fclose(arquivo);
}
void salvar_vendas() {
    FILE *arquivo;
    arquivo = fopen("vendas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < quantiavendas; i++) {
        fprintf(arquivo, "CPF Cliente: %d || Codigo Produto: %d || Quantidade: %d || Valor Total: %.2f\n", lista_vendas[i].cpf_cliente, lista_vendas[i].codigo_produto, lista_vendas[i].quantidade, lista_vendas[i].valor_total);
    }
    float total_caixa = calcular_valor_caixa();
    fprintf(arquivo, "Total Caixa: %.2f\n", total_caixa);
    
    fclose(arquivo);
}
    int carregar_produtos() {
    FILE *arquivo;
    arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }
    int lo = 0;
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int codigo;
        char nome[10000];
        char tipo[10000];
        int quantia;
        float valor_uni;
        int result = sscanf(linha, "nome: %[^|] || tipo: %[^|] || quantia: %d || valor_unitario: %f || codigo:%d", nome, tipo, &quantia, &valor_uni, &codigo);

        if (result == 5) {
            strcpy(lista_produtos[lo].nome, nome);
            strcpy(lista_produtos[lo].tipo, tipo);
            lista_produtos[lo].quantia = quantia;
            lista_produtos[lo].valor_uni = valor_uni;
            lista_produtos[lo].codigo = codigo;
            lo++;
        }
    }
    fclose(arquivo);
    return lo;
}
int carregar_clientes(){
    FILE *arquivo;
    arquivo = fopen("clientes.txt","r");
    if (arquivo == NULL){
        printf("erro ao abrir o arquivo\n");
        return 0;
    }
    int lo = 0;
    char linha[200];
    while (fgets(linha, sizeof(linha),arquivo) != NULL){
        char nome[10000];
        char data_nsc[10000];
        int rg;
        int cpf;
        int result = sscanf(linha, "nome: %[^|] || data_de_nascimento: %[^|] || rg:%d || cpf:%d", nome, data_nsc, &rg, &cpf);
        if (result == 4){
            strcpy(lista_clientes[lo].nome,nome);
            strcpy(lista_clientes[lo].data_nsc, data_nsc);
            lista_clientes[lo].rg = rg;
            lista_clientes[lo].cpf = cpf;
            lo++;
        }
    }
    fclose(arquivo);
    return lo;
}
int carregar_vendas() {
    FILE *arquivo;
    arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    int lo = 0;
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int cpf_cliente, codigo_produto, quantidade;
        float valor_total;
        int result = sscanf(linha, "CPF Cliente: %d || Codigo Produto: %d || Quantidade: %d || Valor Total: %f", &cpf_cliente, &codigo_produto, &quantidade, &valor_total);
        if (result == 4) {
            lista_vendas[lo].cpf_cliente = cpf_cliente;
            lista_vendas[lo].codigo_produto = codigo_produto;
            lista_vendas[lo].quantidade = quantidade;
            lista_vendas[lo].valor_total = valor_total;
            lo++;
        } else if (sscanf(linha, "Total Caixa: %f", &valorcaixa) == 1) {
        }
    }
    fclose(arquivo);
    return lo;
}
