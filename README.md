# QuineMcCluskey implementation
## Integrantes da equipe:
#### Emmanuel Victor Barbosa Sampaio, 417180<br>
#### Eduardo Serpa, 418972<br>
#### Carlos Alfredo Cordeiro de Vasconcelos Filho, 419020<br>
# Descrição do projeto:
O projeto consiste na determinação da equação lógica simplificada que representa um circuito lógico digital desconhecido.
O cortex M0 será responsável por criar as entradas no circuito lógico e recebe a saída do cricuito desconhecido gerando a tabela verdade do circuito.<br>
A equação simplificada será obtida pela aplicação do algorítimo de Quine McCluskey utilizando a tebela verdade recebida e ira mostrar a equação lógica simplificada correspondente ao sistema analisado.<br>A equação simplificada vai ser mostrada juntamente com os CIs que podem ser utilizado no circuito simplificado.<br> 
![alt text](https://github.com/ManoloSampaio/Implementacaoquinemccluskey/blob/master/Diagrama%20de%20Blocos.png)
## Organização das atividades:
- Carlos Alfredo :Repassar o código de python para C.[Feito]<br>
- Emmanuel Sampaio :Desenvolver a interface que vai ser utilizada para mostrar o circuito simplificado
- Eduardo Serpa :Realizar o processo da interface da greenpill com o computador.
## Algoritmo Quine-McCluskey:
Passo 1. Obter a tabela verdade do circuito.

Passo 2. Para todas as posições da tabela verdade cuja saída do circuito seja 1(pois estamos trabalhando com soma de produtos, caso estivéssemos trabalhando com produto de somas usaríamos 0) criamos o seu respectivo mintermo, que é a versão binária da posição na tabela verdade. Por exemplo:

|A|B|C|X|
|----|----|----|----|
|0|0|0|0|
|0|0|1|0|
|0|1|0|1|
|0|1|1|0|
|1|0|0|1|
|1|0|1|0|
|1|1|0|1|
|1|1|1|1|


Na tabela acima os mintermos são: 010,100,110,111.

Passo 3. Agora devemos simplificar os mintermos obtidos através de combinações. Dois mintermos se combinam caso haja apenas um algarismo diferente entre eles. O resultado da combinação de 2 mintermos é um novo mintermo similar à eles, porém com um “-” no algarismo que eles diferem. Usando o exemplo anterior:

010 + 110 = -10

100 + 110 = 1-0

110 + 111 = 11-

Passo 4. Caso um dos mintermos não participe de nenhuma combinação, ele deve ser adicionado à equação de simplificação do circuito. Agora devemos realizar o passo 3 novamente utilizando os novos mintermos, até que não hajam mais novos mintermos.

Continuando o exemplo:

-10 *(não há combinações possíveis)
1-0 *(não há combinações possíveis)
11- *(não há combinações possíveis)

Como -10, 1-0 e 11- não são utilizados em nenhuma combinação, solução: -10,1-0,11-. Como não existem novos mintermos o algoritmo terminou e a solução é: -10,1-0,11-.

Passo 5. Para traduzir da forma binária para a forma booleana basta realizar as seguintes substituições: Onde tem ‘-’ não se coloca nada, onde tem 0 se coloca a forma barrada da variável, onde tem 1 se coloca a variável. Como trabalhamos com soma de produtos, cada termo da solução é um produto de variáveis e a solução completa é a soma da tradução desses termos. Utilizando o exemplo:

-10 -> BC’

1-0 -> AC’

11-> AB

Solução: BC’ + AC’ + AB

OBS: Entenda-se X’ como X barrado.

Uso da memória

A alocação de memória para guardar a lista de mintermos é o maior gargalo na implementação desse método.
O pior caso, onde o número de mintermos é o maior possível, é justamente o caso onde todos os números da tabela são 1. Como todos os elementos da tabela estão presentes, serão gerados todos os mintermos possíveis em cada iteração do algoritmo.
Para economizar memória, reciclaremos os vetores usados para armazenar os mintermos, sendo assim serão necessários 2 vetores(um para guardar os mintermos atuais e outro para guardar os mintermos que surgiram das combinações dos atuais) com um tamanho igual ao pior caso de alocação de memória para um grupo de mintermos.
Suponha que estejamos na K-ésima iteração do algoritmo, onde cada mintermo possui k “-” em seus termos e os outros n-k termos podem ser 0 ou 1. No pior caso(onde todas as combinações estão presentes) existem nk2n-k mintermos, onde cada mintermo ocupa n+1 espaços de memória(n algarismos e 1 para as divisórias entre mintermos). Logo deve-se escolher criar 2 vetores cujo tamanho seja o valor máximo de:
nk2n-k(n+1),k0,n.
${n \choose k}$
## Acompanhando a atividade:
|Semana|Dias|Descrição da atividade|
|----|----|----|
|Semana 1|19-25|EU SEI QUE VCS ESTÃO NA SETIC|
|Semana 2|26-1| JÁ PASSOU 1 SEMANA|
|Semana 3|2-8 | JÁ PASSOU 15 DIAS|
|Semana 4|9-15| ESTAMOS ATRASADOS OU ESTAMOS DE BOA?|
|Semana 5|16-22| É BOM TA PERTO DO FIM|
|Semana 6|23-29| DEAD FUCKING LINE|

