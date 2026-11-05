# 🍽️ Comanda — Sistema de Gerenciamento de Restaurante

<div align="center">
  <img src="https://skillicons.dev/icons?i=cpp,git,github,vscode" alt="Tech Stack" />
</div>

<br>

Aplicação de terminal (CLI) em **C++** para o gerenciamento de comandas de um restaurante, desenvolvida como projeto prático do treinamento da liga acadêmica de tecnologia **PUC Tech** (PUC-SP).

## 📋 Sobre o Projeto

Este sistema foi projetado para controlar o fluxo de pedidos e comandas abertas de um restaurante diretamente pelo terminal. Toda a manipulação de dados, controle de status e visualização gráfica das comandas em tempo real são estruturados em memória através de `structs`, garantindo agilidade nas operações de abertura, edição e fechamento de contas.

## ✨ Funcionalidades

- **Gerenciamento de Comandas Abertas:** Criação e listagem rápida de mesas/clientes ativos.
- **Edição em Tempo Real:** Adição ou alteração de itens e quantidades dentro de uma comanda existente.
- **Exclusão e Cancelamento:** Remoção de itens específicos ou cancelamento integral de uma comanda.
- **Controle de Status:** Acompanhamento do estado atual do pedido (ex: aberta, em preparo, fechada/cancelada).
- **Visualização no Terminal:** Exibição formatada dos dados armazenados na `struct` principal da comanda, facilitando a conferência dos pedidos e valores.

## 🛠️ Tecnologias e Conceitos Utilizados

- **Linguagem:** C++
- **Estruturas de Dados:** Manipulação de tipos compostos (`struct`) para armazenamento centralizado das informações da comanda.
- **Interface:** Linha de Comando (CLI) com atualização de tela em tempo real.

## 🚀 Como Executar o Projeto

### Pré-requisitos
Você precisará de um compilador C++ instalado na sua máquina (como o **GCC/G++** via MinGW no Windows ou nativo no Linux/macOS).

### Passo a passo

Clone este repositório:
```bash
git clone [https://github.com/hellen-pyphile/comanda.git](https://github.com/hellen-pyphile/comanda.git)

```
Acesse a pasta do projeto:
```Bash
cd comanda
```

Compile o código-fonte:

```Bash
g++ main.cpp -o comanda
```

Execute a aplicação:

No Linux / macOS:

```Bash
./comanda
```

No Windows (CMD / PowerShell):

```Bash
comanda.exe
```
📂 Estrutura de Dados Principal

O núcleo do sistema baseia-se em uma struct responsável por agrupar os atributos essenciais de cada atendimento, permitindo que as funções de edição, exclusão e exibição acessem e modifiquem o estado da comanda em tempo real.

👩‍💻 Autoria
Desenvolvido por Hellen Araujo da Silva como parte do treinamento da PUC Tech.
