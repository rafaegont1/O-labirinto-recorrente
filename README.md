<h1>O labirinto recorrente</h1>

<p>Agora que produzimos um trabalho de aquecimento que envolve o caminhamento de matrizes, está na hora de incluir nesse processo execuções mais elaboradas, as quais nos permita analisar o custo computacional de todo o processo. Sendo assim, considere o seguinte problema:</p>

<ul>
    <li>Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).</li>

    <li>Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.</li>

    <li>Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.</li>

    <li>O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas conforme exercício anterior. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.</li>

    <li>Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.</li>
</ul>
  
<p>Qual o custo computacional da sua estratégia randômica? Se mostrou uma boa alternativa de execução?</p>

<p><b>Observações:</b></p>

<ol>
    <li>Certifique-se de que seu código possa ser executado em Linux, para tanto, faça uso de máquinas virtuais, wsl ou distribuições como Ubuntu instaladas no seu ambiente de trabalho.</li>

    <li>Utilize o padrão de compilação por Makefile conforme projetos disponíveis no Git (https://github.com/mpiress). Nesse repositório há inúmeros projetos com o Makefile, isso ajuda muito a automatizar processos de compilação para que o mesmo não produza erros ao ser realizado pelo professor.</li>

    <li>Estruturar seu código para utilizar no mínimo 4 arquivos: um representando sua biblioteca de assinaturas (i.e., .h ou .hpp); um para definição dos métodos descritos na sua biblioteca (i.e., .c ou .cpp) e, por fim, um arquivo para representar o programa principal (i.e., main.c ou main.cpp) e outro para a entrada (arquivo .mat com a descrição das matrizes a serem utilizadas). Como dica, deixe nesse arquivo não somente a informação das matrizes como também o tamanho das mesmas, isso facilitará seu trabalho a longo prazo.</li>

    <li>Elaborar seu conceito de solução utilizando corretamente as diretrizes do padrão de codificação adotado, ou seja, C ANSI ou C++/Orientação a Objetos.</li>

    <li>Elabore documentação completa, que detalhe o problema, detalhe a forma e execução e solução. Além disso, espera-se que se tenha discussão de como poderia ser aperfeiçoado em uma seção de trabalhos futuros, bem como, ampla discussão de possíveis custos de execução.</li>
</ol>
