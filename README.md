<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/1/18/C_Programming_Language.svg" alt="Linguagem C" width="100" height="100"/>
</p>
<h1 align="center">Caixa Eletrônico em C</h1>

Este é um projeto simples de simulação de um caixa eletrônico (ATM) desenvolvido em linguagem C. Ele permite que os usuários realizem operações bancárias básicas em um ambiente de console.

## Funcionalidades

* **Login Seguro:** O sistema possui um mecanismo de login com número de conta e senha (PIN), com um limite de três tentativas antes de bloquear o acesso.
* **Consulta de Saldo:** Permite ao usuário visualizar o saldo atual da sua conta.
* **Depósito:** O usuário pode depositar valores em sua conta.
* **Saque:** É possível realizar saques, respeitando o saldo disponível, um limite máximo por saque e um limite diário.
* **Extrato:** Exibe as últimas 10 transações realizadas (depósitos e saques).
* **Alteração de PIN:** O usuário pode alterar sua senha de acesso.

## Como Compilar e Executar

Para compilar e executar este projeto, você precisará de um compilador C (como o GCC).

1.  **Clone ou baixe o repositório.**
2.  **Abra o terminal ou prompt de comando.**
3.  **Navegue até o diretório onde o arquivo `index.c` está localizado.**
4.  **Compile o código usando o seguinte comando:**
    ```bash
    gcc index.c -o caixa-eletronico
    ```
5.  **Execute o programa:**
    ```bash
    ./caixa-eletronico
    ```

## Credenciais Padrão

Para acessar o sistema, utilize as seguintes credenciais:

* **Número da Conta:** `2575`
* **PIN (Senha):** `1202`

## Detalhes de Implementação

* **Linguagem:** C
* **Constantes:** As informações da conta, como número, PIN inicial, saldo e limites, são definidas como constantes no início do código.
    * `numeroCONTA`: 2575
    * `limiteDIARIO`: 2000
    * `saldoINICIAL`: 500
    * `saqueMAXIMO`: 1000
    * `MAX_OPERACOES`: 10

## 👨‍💻 Autor

* **Autor:** Allan Henrique Rosa Silva
* **Instituição:** UNIPAC Barbacena
* **Curso:** Ciências da Computação
