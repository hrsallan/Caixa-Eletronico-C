#include <stdio.h>
#include <locale.h>

#define numeroCONTA 2575
#define limiteDIARIO 2000
#define saldoINICIAL 500
#define saqueMAXIMO 1000
#define MAX_OPERACOES 10

int pin = 1202;
double saldo = 500;
double limiteUSUARIO = 0;
char extratoCompleto[MAX_OPERACOES][50];
int numOperacoes = 0;

int login(){
    setlocale(LC_ALL, "Portuguese"); 

    int contaDigitada;
    int pinDigitado;
    int tentativas = 1;

    while(tentativas <= 3){
        printf("\n===== LOGIN CAIXA ELETRÔNICO =====\n");

        printf("Digite seu número de conta: ");
        scanf("%d", &contaDigitada);

        printf("Digite sua senha: ");
        scanf("%d", &pinDigitado);

        if(contaDigitada == numeroCONTA && pinDigitado == pin){
            printf("\nLogin realizado com sucesso!\n");
            return 1;
        }
        else{
            printf("\nCredenciais INCORRETAS!\n");
            printf("Tentativa [%d/3]\n", tentativas);
            tentativas++;
        }
    }

    printf("\nNúmero máximo de tentativas excedido. Acesso bloqueado.\n");
    return 0;
}

int consultar_saldo(){
    printf("Saldo atual: R$ %.2lf\n",saldo);
    return 0;
}

int registrarTransacao(const char* tipo, double valor) {
    if (numOperacoes < MAX_OPERACOES) {
        sprintf(extratoCompleto[numOperacoes], "%s: R$ %.2f", tipo, valor);
        numOperacoes++;
    }
    return 0;
}

int depositar(){
    float valor_deposito;
    printf("Informe o valor do deposito: ");
    scanf("%f",&valor_deposito);
    if(valor_deposito>0){
        saldo += valor_deposito;
        registrarTransacao("DEPOSITO", valor_deposito);
        printf("Deposito realizado R$ %.2lf\n",valor_deposito);
        printf("Novo Saldo: R$ %.2lf\n",saldo);
    }
    else{
        printf("Valor INVÁLIDO!\n");
    }
    return 0;
}

int saque(){
    double valor;
    printf("Informe o valor do saque: ");
    scanf("%lf", &valor);

    if (valor <= 0) {
        printf("ERRO | Valor invalido.\n");
    } else if (valor > saldo) {
        printf("ERRO | Saldo insuficiente.\n");
    } else if (valor > saqueMAXIMO) {
        printf("ERRO | Limite máximo: R$ %.2f.\n", saqueMAXIMO);
    } else if (limiteUSUARIO + valor > limiteDIARIO) {
        printf("ERRO | Limite diário EXCEDIDO.\n", saqueMAXIMO);
    } else {
        saldo = saldo - valor;
        limiteUSUARIO += valor;
        registrarTransacao("SAQUE", valor);
        printf("Saque realizado: R$ %.2f\n", valor);
        printf("Novo saldo: R$ %.2f\n", saldo);
    }
return 0;
}


int mostrarExtrato() {
    printf("\n--- EXTRATO (ultimas %d operacoes) ---\n", MAX_OPERACOES);
    for (int i = 0; i < numOperacoes; i++) {
        printf("[%d] %s\n", i + 1, extratoCompleto[i]);
    }
    return 0;
}


int alterarPIN(){
    int entradaPIN,novoPIN,novaxPIN;
    printf("Digite o PIN atual: ");
    scanf("%d",&entradaPIN);

    if(entradaPIN == pin){
        printf("Digite o novo PIN [4 DIGITOS]: ");
        scanf("%d",&novoPIN);

        printf("Confirme o novo PIN: ");
        scanf("%d",&novaxPIN);

        if (novoPIN == novaxPIN) {
        pin = novaxPIN;
        printf("PIN alterado com sucesso.\n");
        } else {
        printf("Os PINs não coincidem. Operacão cancelada.\n");
        }
        } else {
        printf("PIN atual incorreto.\n");
        }
        return 0;
    }

int main(){
    int loginSucedido;
    int opcao, entrada = 1;
    loginSucedido = login();

    if (loginSucedido == 1){
        while(entrada == 1){

            printf("\n===== CAIXA ELETRONICO ====\n");
            printf("1 | Consultar saldo\n");
            printf("2 | Deposito\n");
            printf("3 | Saque\n");
            printf("4 | Extrato\n");
            printf("5 | Alterar PIN\n");
            printf("6 | Encerrar Sessão\n");
            printf("Escolha uma opção: ");
            scanf("%d",&opcao);

            switch(opcao){
                case 1:
                    consultar_saldo();
                    break;
                case 2:
                    depositar();
                    break;
                case 3:
                    saque();
                    break;
                case 4:
                    mostrarExtrato();
                    break;
                case 5:
                    alterarPIN();
                    break;
                case 6:
                    entrada = 0;
                    break;
                default:
                    printf("Opção inválida! Tente novamente!\n");
            }
        }

    } else {
        printf("Encerrando o programa.\n");
    }
    return 0;
}
