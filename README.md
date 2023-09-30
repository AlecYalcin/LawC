# LawC
Projeto para o Componente DCT1106 da UFRN - CERES.

LawC

Programa que é um sistema de advocacia, tem como principal  
módulo o Agendamento e Calendário de consultas e disponibilidade  
dos Advogados. Mas conta com uma série de Gestões para facilitar  
a manipulação dessa parte.

# 1. Gestão de Funcionários
> Essa gestão serve para criar, alterar ou deletar funcionários  
como os advogados, assistente jurídico e correspondente jurídico.  

## Funções
1. Criar Funcionários
2. Alterar Funcionários
3. Deletar Funcionários (Verificar se já está salvo.)
4. Ler Funcionários
5. Listar Funcionários

### Objeto: Funcionário
- Nome: *Char*<br>
- Data de Nascimento: *Char*<br>
- CPF: *Char*<br>
- E-mail: *Char*<br>
- Telefone: *Char*<br>
- OAB: *Char*<br>
- Cargo: *Char*<br>
- Descrição Profissional: *Char*<br>

# 2. Gestão de Serviços
> Essa gestão gera os serviços disponibilizados pela advocacia.
Serve para Criar, Alterar ou Deletar serviços. 

## Funções
1. Criar Serviço
2. Alterar Serviço
3. Deletar Serviço (Verificar se já está salvo.)
4. Ler Serviços
5. Listar Serviços

### objeto: Serviços
- Nome: *char*<br>
- Descrição: *char*<br>
- Valor: *float*<br>

# 3. Gestão de Recursos
> Essa gestão serve para manipular os recursos do sistema de advocacia. 
Tal como documentos, papéis, processos, etc... CRUD.

## Funções
1. Criar Recurso
2. Alterar Recurso
3. Deletar Recurso (Verificar se já está salvo.)
4. Ler Recursos
5. Listar Recursos

### Objeto: Recurso
- Nome: *char*<br>
- Descrição: *char*<br>
- Disponibilidade: *char* (Onde encontrar o documento, o dono, onde pertence)<br>

# 4. Gestão de Clientes
> Serve para manipular a criação de clientes. Um CRUD comum com informações que são ligadas com recursos e histórico de serviços.

## Funções
1. Criar Cliente                        
2. Alterar Cliente
3. Deletar Cliente
4. Ler Cliente
5. Listar Clientes

### Objeto: Cliente
- Nome: *char*<br>
- Data de Nascimento: *int*<br>
- CPF: *char*<br>
- E-mail: *char*<br>
- Telefone: *char*<br>

# 5. Agendamento de Serviços
> Módulo principal, aqui todas as partes se juntam na gestão dos casos
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

### Objeto: Agendamento
- Funcionários: *Object Funcionario*<br>
- Clientes: *Object Cliente*<br>
- Recursos: *Object Recurso*<br>
- Serviço: *Object Serviço*<br>
- Data do Serviço: *Date*<br>
- Valor Adicional: *float*<br>
