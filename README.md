<div style="display: inline-block;">
    <img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
    <img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
    <img align="center" height="20px" width="60px" th="60px" src="https://img.shields.io/badge/Linux-E34F26?style=for-the-badge&logo=linux&logoColor=black"/>
</div>

<h1>O labirinto recorrente</h1>

<p align="justify">
  Um garoto se encontra perdido em um labirinto, o qual é compreendido por <b>N</b> matrizes quadráticas de mesmo tamanho. A posição do garoto é definida por valores <b>x</b> e <b>y</b> e, caso o garoto exceda os limites da matriz, ele será teletransportado para uma posição aleatória da próxima matriz. No labirinto, existem paredes (<b>#</b>) que bloqueiam certos passos, perigos (<b>*</b>) que consomem parte de sua vida e trajetórias contendo itens.
</p>

<p align="justify">
  As casas que possuem itens são representadas por números positivos. Cada vez que o garoto passa por uma dessas casas, um item é consumido pelo garoto, subtraindo um item da casa atual. Após consumir quatro itens, o garoto ganha uma vida extra e seus itens zeram. O garoto começa o jogo com 10 vidas, sendo este o máximo de vidas que ele pode acumular. As casas que não possuem mais itens ainda podem ser utilizadas, mas sem consumir um item.
</p>

<p align="justify">
  O garoto percorrerá as matrizes dando um passo de cada vez de forma aleatória. Ao escolher a direção, o garoto, se possível, irá até a casa definida. Caso exista uma parede na posição definida, está será descartada, e então uma nova direção válida será definida. Os perigos não podem ser evitados, então, se a posição escolhida for um, o garoto o enfrentará e perderá uma vida. a intenção global do problema não é encontrar uma não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.
</p>

<p align="justify">
  O labirinto é lido do arquivo localizado em <i>./dataset/input.data</i>, o qual apresentará várias matrizes, todas quadráticas. A primeira linha do arquivo informa, respectivamente, a largura, a altura e a quantidade de matrizes que o arquivo contém. O objetivo do garoto é percorrer as matrizes até que todo o caminho percorrido se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é apresentado como resultado:
</p>

<ol type="a">
	<li>Quantas casas foram percorridas ao todo;</li>
	<li>Qual a soma de itens consumidos pelo caminho;</li>
	<li>Quantas casas do labirinto ficaram inexploradas;</li>
	<li>Total de perigos enfrentados ao decorrer do percurso.</li>
</ol>

<p align="justify">
  Quanto as paredes, não o garoto irá desviar e continuar a rota. Já os perigos, a cada passada, será subtraída uma vida do total de 10. Assim, ao ficar sem pontos de vida, o algoritmo irá parar e indicar a derrota do garoto.
</p>

<p align="justify">
  O garoto andará aleatoriamente nas oito direções, ou ficará parado no mesmo lugar. Quando o garoto fica parado, ele interage com a casa novamente. Ou seja, caso a casa possua um inimigo, o garoto perderá mais uma vida e, se for um item, consumirá mais um item.
</p>

<table align="center">
  <tr>
      <td align="center">&#x21d6;</td>
      <td align="center">&#x21D1;</td>
      <td align="center">&#x21d7;</td>
  </tr>
  <tr>
      <td align="center">&#x21D0;</td>
      <td align="center">&#x27F3;</td>
      <td align="center">&#x21D2;</td>
  </tr>
  <tr>
      <td align="center">&#x21D9;</td>
      <td align="center">&#x21D3;</td>
      <td align="center">&#x21d8;</td>
  </tr>
</table>

<p align="justify">
  A seguir, é mostrado um exemplo de um labirinto de apenas um matriz como entrada. O garoto começará na primeira coluna da primeira linha, e caminhará na diagonal até a última coluna da última linha. Supondo que o garoto comece com 10 vidas, 0 itens, a interação dele com as casas mudará estas estatísticas. A tabela de cima representa a entrada, enquanto a de baixo mostra a saída.
</p>

<table align="center">
  <tr>
    <td align="center">$\colorbox{olive}{2}$</td>
    <td align="center">#</td>
    <td align="center">*</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">$\colorbox{olive}{*}$</td>
    <td align="center">#</td>
  </tr>
  <tr>
    <td align="center">#</td>
    <td align="center">#</td>
    <td align="center">$\colorbox{olive}{0}$</td>
  </tr>
</table>

<table align="center">
  <tr>
    <td align="center">$\colorbox{olive}{1}$</td>
    <td align="center">#</td>
    <td align="center">*</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">$\colorbox{olive}{*}$</td>
    <td align="center">#</td>
  </tr>
  <tr>
    <td align="center">#</td>
    <td align="center">#</td>
    <td align="center">$\colorbox{olive}{0}$</td>
  </tr>
</table>

<p align="justify">
  É possível perceber que o garoto consumiu um item na primeira casa, que tinha dois itens e passou a ter apenas um. O garoto ainda enfrentou um perigo no meio da matriz, e chegou a última casa que não tinha nehum item. Com isso, o garoto passou a ter 9 vidas e 1 item no inventário.
</p>

<h2>Decisões de implementação</h2>

<p align="justify">
  Ao contar o número de casas inexploradas, foram consideradas as paredes. Ou seja, caso haja paredes no labirinto, o garoto não conseguirá visitar todas as casas. Caso a casa em que o garoto se encontra não tenha sido somada ao total de casas únicas visitadas, esta é somada e a casa é marcada na matriz booleana como já explorada. No final do programa, é multiplicado a largura pela altura, para então multiplicar pelo número de matrizes e subtrair pelo número de casas visitadas, resultando assim no número de casas inexploradas.
</p>

<p align="justify">
  Optou-se por ler as matrizes do arquivo de entrada um por um, pois esta escolha diminui o uso de memória primária do computador. Com isso, é possível utilizar o programa em labirintos com várias martizes, ficando estas armazenadas no próprio arquivo de entrada.
</p>

<h2>Arquivos</h2>

<ul>
  <li>
    <code><strong>main.cpp</strong></code> Possui a função <i>int main()</i>, que define o local de início (<i>entry point</i>) do programa e returna o <i>exit code</i>.
  </li>
  <li>
    <code><strong>Maze.hpp</strong></code> Arquivo <i>header</i> que define a classe <i>Maze</i>, assim como seus atributos e métodos que será compartilhado entre os arquivos do programa.
  </li>
  <li>
    <code><strong>Maze.cpp</strong></code> Possui o corpo do construtor, destrutor e métodos da classe <i>Maze</i> definidos no arquivo <i>Maze.hpp</i>.
  </li>
  <li>
    <code><strong>Player.hpp</strong></code> Arquivo <i>header</i> que define a classe <i>Player</i>, assim como seus atributos e métodos que será compartilhado entre os arquivos do programa.
  </li>
  <li>
    <code><strong>Player.cpp</strong></code> Possui o corpo do construtor, destrutor e métodos da classe <i>Player</i> definidos no arquivo <i>Player.hpp</i>.
  </li>
</ul>

<h2>Casos especiais</h2>

<p align="justify">
  Conforme discorrido anteriormente, pode ser que o garoto, de acordo com a função que define a sua direção aleatoriamente, fique parado no mesmo lugar. Caso isto ocorra, ele interage novamente com a mesma casa, consumindo um item ou tomando dano, dependendo do que a casa for.
</p>

<p align="justify">
  Com isso, o algoritmo considera que o garoto consumiu mais um item ou enfrentou mais um inimigo, porém, não considera que o garoto andou. Por isso, pode ser que ocorra o caso em que o garoto consuma, por exemplo, 25 itens, enfrente 7 inimigos, e tenha percorrido um caminho de apenas 29 casas.
</p>

<h2>Casos sem tratamento</h2>

<p align="justify">
  O programa não verifica se o labirinto possui casas em que o garoto não pode sair. Logo, se for inserida uma matriz com casas isoladas por paredes, o programa terá um comportamento indefinido (provavelmente entrando em um loop infinito.
</p>

<p align="justify">
  O algoritmo é altamente dependente da entrada do arquivo <i>input.data</i>. Isto significa que, caso o usuário insira um labirinto válido, no formato pré-determinado, o programa não fará tal verificação, resultando também terá um compotamento indefinido.
</p>

<p align="justify">
  Caso o arquivo <i>input.data</i> possua apenas paredes, o programa não aceitará nenhuma posição inicial. Com isso, o programa deverá ser fechado manualmente no terminal, e a entrada deverá ser então corrigida para uma nova entrada válida.
</p>

<h2>Código-fonte</h2>

<h3>main.cpp</h3>

<p align="justify">
  O arquivo <i>main.cpp</i> possui apenas a função <i>int main</i>. Nela, é feita uma instanciação da classe <i>Maze</i>, para então requerir ao usuário uma posição inicial válida na primeira matriz. Logo, é iniciado o jogo e, caso o programa seja finalizado com sucesso, é retornado zero como <i>exit code</i>.
</p>

<h3>Maze.hpp e Maze.cpp</h3>

<p align="justify">
  Em C++, a biblioteca padrão é uma coleção de classes, funções e variáveis escritas na própria linguagem para facilitar o desenvolvimento de aplicações. O C++ ainda permite utilizar a biblioteca padrão do C, garantindo assim uma ampla gama de possibilidades para criar um programa. No arquivo de cabeçalho <i>Maze.hpp</i>, forma incluídas cinco bibliotecas: <i>fstream</i>, <i>vector</i>, <i>random</i>, <i>limits</i> e <i>unistd.h</i>.
</p>

<p align="justify">
   Primeiramente, quando o construtor da classe <i>Maze</i> é invocado, o arquivo <i>input.data</i> é copiado com nome de saída de <i>output.data</i>. Este novo arquivo contém uma matriz booleana de mesmo tamanho das matrizes originais ao lado das próprias matrizes, que informa as casas visitadas. Logicamente, esta matriz começa apenas com zeros, sendo preenchidas com um após o garoto visitá-las.
</p>

<p align="justify">
  A classe <i>Maze</i> possui uma instância da classe <i>Player</i>, que representa o garoto. Os caracteres presentes no arquivo serão lidos e armazenados no <i>vector</i> <b>mat</b>. Já as casas visitadas serão armazenadas no <i>vector</i> <b>mat_visited</b>. É válido destacar que o programa lê uma matriz de cada vez e armazena os dados nos <i>vectors</i> até que chegue ao final do arquivo. Caso o labirinto ainda possua itens, ou o garoto tenha pego algum item desde que começou a percorrer o labirinto, o arquivo <i>tmp.data</i> é sobrescrito no lugar de <i>output.data</i>, e este é relido novamente.
</p>

<p align="justify">
  O arquivo <i>output.data</i> funciona como entrada, enquanto o <i>tmp.data</i> funciona como saída. O programa lê a matriz do <i>output.data</i>, a utiliza no jogo, e salva as modificações no <i>tmp.data</i>. Por exemplo, assim que o garoto é teletransportado para a próxima matriz, a matriz atual é salvada no <i>tmp.data</i>, e a próxima matriz é carregada do <i>output.data</i>. Isso ocorre até que o programa leia as <b>N</b> matrizes. Quando isso ocorre, o <i>tmp.data</i> se torna o novo <i>output.data</i>, o <i>tmp.data</i> fica em branco para as novas entradas e o programa retorna até o a primeira matriz.
</p>

<p align="justify">
  A entrada de posição inicial do garoto, fornecida pelo usuário, é verificada, para que os valores nem passem dos limites da matriz e nem sejam referentes a uma parede. Ainda existe uma verificação do valor do retorno da função <i>cin</i> que garante que a entrada seja válida.
</p>

<p align="justify">
  Ao iniciar o programa, o garoto já interage com a primeira casa, tomando dano ou pegando o item desta casa. Esta casa é então marcada como visitada, a fim de verificar a quantidade de casas inexploradas posteriormente. O garoto caminha até que acabe suas vidas, ou ele ganhe, seja por acabar os itens no labirinto, ou por caminhar todas as matrizes sem consumir um item.
</p>

<p align="justify">
  A classe <i>Maze</i> ainda possui atributos que definem o tamanho da matriz, a quantidade de matrizes e qual matriz está no <i>vector</i> mat, além de duas <i>streams</i> de arquivo e dois booleanos que informam se o garoto ganhou o jogo e se foi encontrado um item nas matrizes lidas até então.
</p>

<h4>Métodos da classe Maze</h4>

<ul>
  <li>
    <code><strong>Maze()</strong></code> Construtor da classe <i>Maze</i> que lê o arquivo <i>input.data</i>, o reescreve com as matrizes booleanas no arquivo <i>output.data</i>, define o tamanho e a quantidade de matrizes e coloca o arquivo <i>output.data</i> como entrada e o <i>tmp.data</i> como saída;
  </li>
  <li>
    <code><strong>~Maze()</strong></code> Destrutor da classe que fecha os arquivos de entrada e saída;
  </li>
  <li>
    <code><strong>void open_files(const std::string &in, const std::string &out)</strong></code> Abre os arquivos de entrada e saída de acordo com as <i>strings</i> de entrada;
  </li>
  <li>
    <code><strong>write_sizes()</strong></code> Escreve a primeira linha que contém o tamanho e a quantidade de matrizes no arquivo de saída;
  </li>
  <li>
    <code><strong>void read(const bool &read_visited = true)</strong></code> Lê uma matriz do arquivo de entrada (possui uma argumento com <i>default=true</i> que define se a matriz de booleanas também deve ser lida);
  </li>
  <li>
    <code><strong>void run()</strong></code> Começa o jogo, chamando todas as funções necessárias para executar o jogo de acordo com as regras previamente estabelecidas;
  </li>
  <li>
    <code><strong>void action()</strong></code> Faz o garoto interagir com a casa e adiciona esta casa à matriz booleana de casas visitadas;
  </li>
  <li>
    <code><strong>void joystick()</strong></code> Define aleatoriamente a casa para a qual o garoto deve se mover, em um loop que continua até que a casa escolhida não seja uma parede;
  </li>
  <li>
    <code><strong>void out_of_bounds(const short &move_x, const short &move_y)</strong></code> Verifica se a casa em que o garoto deseja se mover está dentro dos limites da matriz;
  </li>
  <li>
    <code><strong>void teleport()</strong></code> Caso a casa não esteja dentro dos limites da matriz, está função é chamada, fazendo com que o garoto se teletransporte para a próxima matriz;
  </li>
  <li>
    <code><strong>void write_matrix()</strong></code> A matriz atual é escrita no arquivo de saída;
  </li>
  <li>
    <code><strong>void write_file()</strong></code> A matriz atual e as matrizes restantes são escritas no arquivo de saída;
  </li>
  <li>
    <code><strong>void rewind()</strong></code> Caso o garoto ultrapasse os limites da última matriz do arquivo de entrada e tenha coletado algum item, esta função volta à primeira matriz atualizada pela última vez que o garoto caminhou nela;
  </li>
  <li>
    <code><strong>void random_start()</strong></code> Quando o garoto é teletransportado, esta função é chamada para que o garoto apareça em alguma casa aleatória válida da nova matriz;
  </li>
  <li>
    <code><strong>void mat_have_item()</strong></code> Verifica se a matriz atual possui itens;
  </li>
  <li>
    <code><strong>bool only_zeros()</strong></code> Verifica se ainda restam itens no labirinto e, caso não hajam, concede a vitória no jogo;
  </li>
  <li>
    <code><strong>void print()</strong></code> Imprime a mensagem de fim de jogo, dando informações relativas ao caminhamento do garoto durante o jogo.
  </li>
</ul>

<h3>Player.hpp e Player.cpp</h3>

<p align="justify">
  O arquivo <i>Player.hpp</i> contém o cabeçalho que define a classe <i>Player</i>. Nele, estão os atributos relativos à posição do garoto, número de vidas, itens na mochila, distância percorrida, total de itens consumidos, casas únicas visitadas, perigos enfrentados e dois booleanos que informam se o garoto pegou algum item na rodada e se ele excedeu os limites da matriz atual.
</p>

<h4>Métodos da classe Player</h4>

<ul>
  <li>
    <code><strong>Player()</strong></code> Construtor da classe <i>Player</i> que o instancia com valores padrão;
  </li>
  <li>
    <code><strong>void action(char &item)</strong></code> Faz com que o garoto interaja com a casa em que ele se encontra;
  </li>
  <li>
    <code><strong>bool is_alive()</strong></code> Retorna verdadeiro se o garoto ainda estiver vivo.
  </li>
</ul>

<h2>Exemplo</h2>

<p align="justify">
  Foi realizada um teste com um arquivo de entrada <i>input.data</i> com duas matrizes quadráticas de tamanho três, a fim de demonstrar a execução do programa.
</p>

<table align="center" style="width: 50%">
  <tr>
      <td align="center" style="width: 33%">2</td>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">#</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">4</td>
      <td align="center" style="width: 33%">4</td>
      <td align="center" style="width: 33%">4</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">3</td>
      <td align="center" style="width: 33%">5</td>
      <td align="center" style="width: 33%">#</td>
  </tr>
</table>
<br>
<table align="center" style="width: 50%">
  <tr>
      <td align="center" style="width: 33%">#</td>
      <td align="center" style="width: 33%">#</td>
      <td align="center" style="width: 33%">2</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">3</td>
      <td align="center" style="width: 33%">5</td>
      <td align="center" style="width: 33%">#</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">*</td>
      <td align="center" style="width: 33%">3</td>
      <td align="center" style="width: 33%">5</td>
  </tr>
</table>

<p align="justify">
  Após compilar e executar o programa, este requere ao usuário um ponto de início para o garoto. Foi escolhida a primeira coluna da primeira matriz. A partir disso, o programa faz com que o garoto ande até que, ou suas vidas acabem, ou ele percorra o labirinto sem pegar um item, ou acabe os itens no labirinto. A seguir é mostrado as matrizes do arquivo de saída <i>output.data</i>.
</p>

<table align="center" style="width: 50%">
  <tr>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">#</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">4</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">#</td>
  </tr>
</table>
<br>
<table align="center" style="width: 50%">
  <tr>
      <td align="center" style="width: 33%">#</td>
      <td align="center" style="width: 33%">#</td>
      <td align="center" style="width: 33%">0</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">#</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">*</td>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">2</td>
  </tr>
</table>

<p align="justify">
  Ao lado da saída das matrizes de entrada, ainda são geradas matrizes de booleanos que informam por quais casas o garoto passou.
</p>

<table align="center" style="width: 50%">
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">0</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">0</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">0</td>
  </tr>
</table>
<br>
<table align="center" style="width: 50%">
  <tr>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">0</td>
      <td align="center" style="width: 33%">1</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">0</td>
  </tr>
  <tr>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">1</td>
      <td align="center" style="width: 33%">1</td>
  </tr>
</table>

<p align="justify">
  O exemplo aqui exposto foi compilado com o GNU Compiler Collection (gcc) versão 4:11.2.0-1ubuntu1, no sistema operacional Ubuntu 22.04.2 LTS (Jammy Jellyfish). O computador possuia uma placa-mãe ASUS AM1M-A/BR, 8 GB de memória RAM DDR3 e um processador AMD Athlon 5150 (arquitetura x86_64).
</p>

<h2>Conclusão</h2>

<p align="justify">
  Pode-se afirmar que a código cumpriu com o que foi proposto na atividade, criando um jogo em que o <i>player</i> se move de forma aleatória no labirinto. A execução do programa ocorreu conforme esperado, como foi possível verificar no exemplo citado.
</p>

<p align="justify">
  Dessa forma, é possível afirmar que a utilização de classes para representar o garoto e o labirinto mostrou-se eficiente, uma vez que a agregação, formada pelo objeto filho (Player) em conjunto com o objeto pai (Maze), constitui uma maneira útil de realizar a lógica do programa.
</p>

<p align="justify">
  Ainda existem alguns pontos de possível melhora no programa, como a verificação das exceções vistas nos casos sem tratamento. Portanto, uma revisão do programa o tornaria ainda melhor, pois, nestas atuais condições, o usuário poderá comprometer a execução do programa, dependendo do que este colocar como entrada no <i>input.data</i>.
</o>

<h2>Compilação e Execução</h2>

<p align="justify">
  O algoritmo do labirinto decorrente disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</p>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


<h2>Contato</h2>

<a style="color:black" href="mailto:rafaelg000@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
    ✉️ <i>rafaelg000@gmail.com</i>
</a>
