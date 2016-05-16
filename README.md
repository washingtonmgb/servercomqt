# Projeto de Programação 

## Apresentação 

O presente projeto visa desenvolver o aluno na prática de programação
orientada a objetos usando a biblioteca Qt.

O projeto consiste em três programas de computador que trabalham em
conjunto para simular um sistema simples de aquisição e supervisão de
dados usando comunicação TCP/IP em uma rede local.

Em suma, os três módulos devem ser capazes de realizar as seguintes
operações:

- O **servidor** deve esperar conexões TCP destinadas à porta 1234, e
  responder ao cliente conforme os comandos que este enviar.
- O **cliente produtor** de dados deve ser capaz de se conectar a uma
  máquina executando o servidor na porta 1234 e enviar, usando
  comandos específicos, marcações de data/hora juntamente com uma
  informação em ponto flutuante para ser gravada.
- O **cliente supervisor** de dados deve ser capaz de se conectar a uma
  máquina executando o servidor na porta 1234 e recuperar, usando
  comandos específicos, a lista dos clientes produtores de dados, bem
  como listagens de dados produzidos por um destes clientes
  produtores.

## O módulo servidor

O módulo servidor implementa o que se chama de servidor TCP. Em outras
palavras, esse programa é capaz de escutar a rede local e aguardar por
conexões remotas destinadas à porta TCP/1234.

Em redes TCP/IP, o protocolo de comunicação TCP permite a criação de
um circuito virtual, um canal de comunicação que pode ser usado para
enviar e receber sequências de bytes pela Internet. O canal é fechado
apenas quando a conexão é interrompida.

Para se abrir uma conexão com uma máquina que executa um determinado
serviço usando o protocolo TCP é necessário que se conheça seu
endereço IP (ou nome) e uma _porta_ onde o serviço será
provido. Quando a conexão é aberta para um novo cliente, inicia-se um
_socket_ de comunicação, identificado, entre outras coisas, pela
combinação IP+porta. Cada _socket_ possui um número único que
pode ser usado para distinguir entre as várias conexões que podem
chegar à mesma porta. Isso é comum em máquinas que provêem serviços a
vários clientes.

Máquinas que aguardam conexões comumente chamadas de **servidores**. O
servidor implementado neste projeto _escuta_  a porta **1234**. Uma
vez que um cliente se conecte a esta, as tarefas que o servidor irá
executar dependerão de mensagens enviadas pelo cliente. Para cada
mensagem, uma tarefa diferente é executada. É dessa maneira que os
vários serviços na Internet funcionam.

O servidor do projeto não necessita de modificações para
funcionar. Basta abrir o projeto no QtCreator, compilar e executar o
código. O servidor é capaz de interpretar mensagens em texto simples
que lhe forem enviadas. As mensagens aceitas pelo servidor formam o
que se chama de **protocolo de aplicação** para este serviço. Três
mensagens são suportadas nesse protocolo:

```
list
get NUMERO_IP
set DATA_E_HORA DADO
```

O comando **_list_** retorna a lista de máquinas cujos dados
produzidos encontram-se armazenados no servidor. ex:
```
$ telnet 127.0.0.1 1234
list
127.0.0.1
```

O comando **_get_** precisa que se forneça também o número IP do
**cliente produtor** que se deseja recuperar o conjunto de dados
produzidos. ex:

```
$ telnet 127.0.0.1 1234
get 127.0.0.1
2016-05-04T10:24:14 34
```

O comando **_set_** precisa que se forneça uma combinação DATA e HORA,
bem como o dado que se deseja armazenar no servidor. ex:

```
$ telnet 127.0.0.1 1234
set 127.0.0.1
set 2016-05-04T10:24:14 34
``
Todos os comandos devem ser enviados na forma de literais. O servidor,
uma vez que receba essas sequências de literais, separa-as conforme a
quantidade de espaços presentes e armazena os dados associados em uma
estrutura local criada para esse fim.

Em se tratando de um projeto meramente acadêmico, pouco controle de
erro é realizado nessa versão inicial.

Quando o servidor é executado, uma mensagem é exibida na aba
**Application Output** do QtCreator mostrando o IP local do servidor,
como ilustram as linhas a seguir:

```
server started at:
"192.168.1.106"
```
