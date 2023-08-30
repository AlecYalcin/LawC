# LawC
Projeto para o Componente DCT1106 da UFRN - CERES.

LawC

Programa que é um sistema de advocacia, tem como principal
módulo o Agendamento e Calendário de consultas e disponibilidade
dos Advogados. Mas conta com uma série de Gestões para facilitar
a manipulação dessa parte

# 1. Gestão de Funcionários
-> Essa gestão serve para criar, alterar ou deletas funcionários
como os advogados, assistente jurídico e correspondente jurídico.

## Funções:
1. Criar Funcionários
2. Alterar Funcionários
3. Deletar Funcionários (Verificar se já está salvo.)
4. Ler Funcionários
5. Listar Funcionários

> ### Objeto: Funcionário
> 1.Nome<br>
> 2.Idade<br>
> 3.CPF<br>
> 4.E-mail<br>
> 5.Telefone<br>
> 6.OAB? Id da OAB?<br>
> 7.Cargo<br>
> 8.Descrição Profissional<br>

# 2. Gestão de Serviços
-> Essa gestão gera os serviços disponibilizados pela advocacia.
Serve para Criar, Alterar ou Deletar serviços. 

## Funções:
1. Criar Serviço
2. Alterar Serviço
3. Deletar Serviço (Verificar se já está salvo.)
4. Ler Serviços
5. Listar Serviços

> ### objeto: Serviços
> 1.Nome do Serviço<br>
> 2.Descrição do Serviço<br>
> 3.Valor Inicial<br>

# 3. Gestão de Recursos
-> Essa gestão serve para manipular os recursos do sistema de advocacia. 
Tal como documentos, papéis, processos, etc... CRUD.

## Funções:
1. Criar Serviço
2. Alterar Serviço
3. Deletar Serviço (Verificar se já está salvo.)
4. Ler Serviços
5. Listar Serviços

> ### Objeto: Recurso
> 1. Nome <br>
> 2. Descrição <br>
> 3. Disponibilidade <br>

# 4. Gestão de Clientes
-> Serve para manipular a criação de clientes. Um CRUD comum com informações que são ligadas com recursos e histórico de serviços.

## Funções:
1. Criar Cliente
2. Alterar Cliente
3. Deletar Cliente
4. Ler Cliente
5. Listar Clientes

> ### Objeto: Cliente
> 1. Nome<br>
> 2. Idade<br>
> 3. CPF<br>
> 4. E-mail<br>
> 5. Telefone<br>

# 5. Agendamento de Serviços
-> Módulo principal, aqui todas as partes se juntam na gestão dos casos
e no agendamento dos serviços disponibilizados. Aqui você CRIA agendamentos,
altera eles, deleta eles, finaliza eles, designa, etc...

## Funções:
1. Criar Agendamento
2. Alterar Agendamento
3. Deletar Agendamento
4. Finalizar Agendamento (Marcar que foi terminado)
5. Ler Agendamento
6. Listar Agendamentos
7. Listar por Data

> ### Objeto: Agendamento
> 1. Funcionários
> 2. Clientes
> 3. Recursos 
> 4. Serviço
> 5. Data do Serviço
> 6. Valor Adicional
