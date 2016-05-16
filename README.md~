= Projeto de Programação =

== Apresentação ==

O presente projeto visa desenvolver o aluno na prática de programação
orientada a objetos usando a biblioteca Qt.

O projeto consiste em três programas de computador que trabalham em
conjunto para simular um sistema simples de aquisição e supervisão de
dados usando comunicação TCP/IP em uma rede local.

Em suma, os três módulos devem ser capazes de realizar as seguintes
operações:

* O *servidor* deve esperar conexões TCP destinadas à porta 1234, e
  responder ao cliente conforme os comandos que este enviar.
* O *cliente produtor* de dados deve ser capaz de se conectar a uma
  máquina executando o servidor na porta 1234 e enviar, usando
  comandos específicos, marcações de data/hora juntamente com uma
  informação em ponto flutuante para ser gravada.
* O *cliente supervisor* de dados deve ser capaz de se conectar a uma
  máquina executando o servidor na porta 1234 e recuperar, usando
  comandos específicos, a lista dos clientes produtores de dados, bem
  como listagens de dados produzidos por um destes clientes
  produtores.

== O módulo servidor ==

O módulo servidor implementa o que se chama de servidor TCP. Em outras
palavras, esse programa é capaz de escutar a rede local e aguardar por
conexões remotas destinadas à porta TCP/1234.

Em redes TCP/IP, o protocolo de comunicação TCP permite a criação de
um circuito virtual, um canal de comunicação aberto que pode ser usado
para enviar e receber sequências de bytes 
