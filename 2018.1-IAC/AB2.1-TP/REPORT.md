# Identificação
* Página do repositório do trabalho do GitHub [Link para o github](https://github.com/gabrielalcantarar/teaching/tree/master/2018.1-IAC/AB2.1-TP)

* Discente 1
* 
  * Nome: Gabriel Alcantara Rocha
  * Matrícula: 	18110464
* Discente 2

  * Nome: Luiz Guimarães de Melo Neto
  * Matrícula: 18112707
* Discente 3

    *   Nome: Rafael De Oliveira Guedes Nogueira
    * Matrícula: 18110501
 * Obs.: Distribuição igualitária da nota.
 # Resultados
---
* GRÁFICO (1) QUE EXPRESSA A UTILIZAÇÃO INTENSA DA UCP (./main ucp):
![alt text](https://imgur.com/oPcnFWr.png) 
* GRÁFICO (2) QUE EXPRESSA O COMPORTAMENDO DA MEMÓRIA NA UTILIZAÇÃO INTENSA DA UCP (./main ucp):
 ![alt text](https://imgur.com/bdKTCfj.jpg)
* GRÁFICO(3) QUE EXPRESSA A UTILIZAÇÃO INTENSA DA CPU E MEMÓRIA (./main ucp-mem):
![alt text](https://imgur.com/TNYrF2a.png) 
* GRÁFICO(4) QUE EXPRESSA O COMPORTAMENDO DA MEMÓRIA NA UTILIZAÇÃO INTENSA DA UCP E MEMÓRIA (./main ucp-mem): 
![alt tex](https://i.imgur.com/iGnTyCy.jpg) 

# Discussão
---
 #### Compilando:
---
##### Comando para verificar a intensa utilização da UCP:

*  ./main ucp
##### Comando para verificar a intensa utilização da UCP junto a Memória:

* ./main ucp-mem

 #### Breve introdução a função Fork( ):
 ---
 A priori, julgamos necessário explicar o funcionamento da função fork( ) para o maior entendimento dos processos.
 Ao declarar PID = fork( ), criam-se processos filhos que tem como trabalho elevar o uso da UCP ao máximo e alocar memória para os experimentos. Concomitantemente, é criado um processo pai - tido como principal - que tem como função monitorar o uso dos componentes estudados. 
#### Utilização intensa da UCP
---
Para a utilização intensa da UCP, foi usada a estrutura de repetição For(;;){}. Dada essa instrução, gera-se um loop infinito que eleva os processos da UCP ao máximo e, com isso, registramos o seu comportomento no terminal do linux. O comando usado pelo processo pai, para o monitoramento, foi o "ps -p <pid> -o %cpu | grep -v %CPU". Com isso, foi possível captar os dados que são necessários para o estudo (gráfico 1 e 2).
### Utilização intensa da UCP e Memória
---
Para a utilização intensa da UCP em conjunto com a memória, foi usada a estrutura de repetição For(;;){}, que gera o loop infinito já explicado acima, conjuntamente com a função malloc, que tem como objetivo reservar espaços de memória do sistema para o programa, como está em um loop, o alocamento vai ser cada vez maior. O comando usado pelo processo pai, para o monitoramento, foi o "pmap -x <pid> | grep total | awk '{print $3}'". Com isso, foi possível captar os dados que são necessários para o estudo (gráfico 3 e 4).
### Dificuldades encontradas
---
 É necessário, ainda, ressaltar que para evitar problemas futuros de discentes/interessados que estão usando nosso código para estudo, que ao preenchermos o TODO da intensa utilização de memória, estávamos alocando mais memória do que o sistema aguentaria, resultando assim no travamento do computador. Para consertarmos isso, descobrimos que existe uma função chamada Clock que ajudou a estabilizar o "estouro"da memória, evitando assim o PC de travar. Corrigido isso, o funcionamento do programa ocorreu de forma esperada.
