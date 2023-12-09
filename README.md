# LawC
### Projeto para o Componente DCT1106 da UFRN - CERES.

Programa que é um sistema de advocacia, tem como principal módulo o Agendamento e Calendário de consultas e disponibilidade dos Advogados. Mas conta com uma série de Gestões para facilitar a manipulação dessa parte.

# Instalação

Para utilizar de LawC, é preciso primeiramente verificar o seu OS Para sistemas baseados em Linux e Windows há uma diferença. Primeiramente, tenha o GIT instalado em seu computador. Depois, adicione o repositório

```shell
> git clone https://github.com/AlecYalcin/LawC.git
```

## Linux
1. Acesse a branch 'Main'
2. Após isso, rode o `makefile` para ter seu programa compilado.
3. Por fim, rode o programa
```shell
> git switch main
> make
> ./main
```
## Windows
1. Acesse a branch 'win'
2. Após isso, rode o `makefile` para ter seu programa compilado.
3. Por fim, rode o programa
```shell
> git switch win
> make
> main.exe
```

# Sessão Para Desenvolvedores
Toda a explicação dos módulos do arquivo. Estão separados em pastas principalmente na pasta `modules` e dentro delas há 5 arquivos que designam os módulos.

> Caso algum erro aconteça durante a compilação dos arquivos, utilize o comando ```make clean / make cleanWin``` para limpar os arquivos.

## 1. Gestão de Funcionários
Essa gestão serve para criar, alterar ou deletar funcionários como os advogados, assistente jurídico e correspondente jurídico ou demais funcionários da empresa. Sua pasta é `modules/employer/`

### Funções

1. Criar Funcionário
> Criação de structs de Employer e `create` em arquivos
2. Alterar Funcionário
> Alteração de structs de Employer e `update` em arquivos
3. Deletar Funcionário
> Alteração de status de structs de Employer e `delete` em arquivos
4. Ler Funcionário
> Leitura e retorno de structs de Employer e `read` em arquivos
5. Listar Funcionários
> Listagem dos índices do arquivo de structs

#### Struct: Employer

- status: *int*<br> 
- name: *Char[75]*<br>
- birth_date: *Char[12]*<br>
- cpf: *Char[12]*<br>
- email: *Char[75]*<br>
- tel: *Char[12]*<br>
- OAB: *Char[100]*<br>
- role: *Char[75]*<br>
- desc: *Char[300]*<br>

### Arquivos
1. `modules/employer/_employers.dat` > Informações salvas dos structs de Employer<br>
2. `modules/employer/data_employers.c` > Funções de manipulação de arquivos<br>
3. `modules/employer/data_employers.h` > Declaração de Funções<br>
4. `modules/employer/employers.c` > Funçãos do módulo<br>
5. `modules/employer/employers.h` > Declaração de Funções<br>


## 2. Gestão de Serviços
Essa gestão gera os serviços disponibilizados pela advocacia. Serve para Criar, Alterar ou Deletar serviços. Sua pasta é `modules/service`

### Funções
1. Criar Serviço
> Criação de structs de Service e `create` em arquivos
2. Alterar Serviço
> Alteração de structs de Service e `update` em arquivos
3. Deletar Serviço
> Alteração de status de structs de Service e `delete` em arquivos
4. Ler Serviço
> Leitura e retorno de structs de Service e `read` em arquivos
5. Listar Serviços
> Listagem dos índices do arquivo de structs

### Struct: Service
- status: *int*<br> 
- name: *char[75]*<br>
- desc: *char[300]*<br>
- value: *float*<br>

### Arquivos
1. `modules/service/_services.dat` > Informações salvas dos structs de service<br>
2. `modules/service/data_services.c` > Funções de manipulação de arquivos<br>
3. `modules/service/data_services.h` > Declaração de Funções<br>
4. `modules/service/services.c` > Funçãos do módulo<br>
5. `modules/service/services.h` > Declaração de Funções<br>

## 3. Gestão de Recursos
Essa gestão serve para manipular os recursos do sistema de advocacia. Tal como documentos, papéis, processos, etc... CRUD.

### Funções
1. Criar Recurso
> Criação de structs de Resource e `create` em arquivos
2. Alterar Recurso
> Alteração de structs de Resource e `update` em arquivos
3. Deletar Recurso
> Alteração de status de structs de Resource e `delete` em arquivos
4. Ler Recurso
> Leitura e retorno de structs de Resource e `read` em arquivos
5. Listar Recursos
> Listagem dos índices do arquivo de structs

### Struct: Resource
- status: *int*<br> 
- name: *char[75]*<br>
- desc: *char[300]*<br>
- available_at: *char[100]*<br>

### Arquivos
1. `modules/resource/_resources.dat` > Informações salvas dos structs de resource<br>
2. `modules/resource/data_resources.c` > Funções de manipulação de arquivos<br>
3. `modules/resource/data_resources.h` > Declaração de Funções<br>
4. `modules/resource/resources.c` > Funçãos do módulo<br>
5. `modules/resource/resources.h` > Declaração de Funções<br>

## 4. Gestão de Clientes
Serve para manipular a criação de clientes. Um CRUD comum com informações que são ligadas com recursos e histórico de serviços.

### Funções
1. Criar Cliente
> Criação de structs de Cliente e `create` em arquivos
2. Alterar Cliente
> Alteração de structs de Cliente e `update` em arquivos
3. Deletar Cliente
> Alteração de status de structs de Cliente e `delete` em arquivos
4. Ler Cliente
> Leitura e retorno de structs de Cliente e `read` em arquivos
5. Listar Clientes
> Listagem dos índices do arquivo de structs

### Struct: Cliente
- status: *int*<br> 
- name: *char[75]*<br>
- birth_date: *char[12]*<br>
- CPF: *char[12]*<br>
- email: *char[75]*<br>
- tel: *char[12]*<br>

### Arquivos
1. `modules/client/_clients.dat` > Informações salvas dos structs de cliente<br>
2. `modules/client/data_clients.c` > Funções de manipulação de arquivos<br>
3. `modules/client/data_clients.h` > Declaração de Funções<br>
4. `modules/client/clients.c` > Funçãos do módulo<br>
5. `modules/client/clients.h` > Declaração de Funções<br>

## 5. Agendamento de Serviços
Módulo principal, aqui todas as partes se juntam na gestão dos casos e no agendamento dos serviços disponibilizados. Aqui você CRIA agendamentos, altera, deleta, finaliza, designa, etc...

### Funções:
1. Criar Agendamento
> Criação de structs de Schedule e `create` em arquivos
2. Alterar Agendamento
> Alteração de structs de Schedule e `update` em arquivos
3. Deletar Agendamento
> Alteração de status de structs de Schedule e `delete` em arquivos
4. Ler Agendamento
> Leitura e retorno de structs de Schedule e `read` em arquivos
5. Listar Agendamentos
> Listagem dos índices do arquivo de structs
6. Finalizar Agendamento

### Struct: schedule
- status: *int*<br> 
- finalizado: *int*<br> 
- name: *char[75]*<br>
- desc: *char[300]*<br>
- id_employer: *char[12]*<br>
- id_client: *char[12]*<br>
- id_service: *char[75]*<br>
- date: *char[12]*<br>

### Arquivos
1. `modules/schedule/_schedules.dat` > Informações salvas dos structs de schedule<br>
2. `modules/schedule/data_schedules.c` > Funções de manipulação de arquivos<br>
3. `modules/schedule/data_schedules.h` > Declaração de Funções<br>
4. `modules/schedule/schedule.c` > Funçãos do módulo<br>
5. `modules/schedule/schedule.h` > Declaração de Funções<br>
