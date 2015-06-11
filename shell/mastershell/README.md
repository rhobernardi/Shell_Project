# Sobre o MasterShell

---------------------------------------------------
 Instruções
---------------------------------------------------
- Estando no diretório do mastershell/, execute:
	- Para compilar: make
	- Para executar: make test
- Importante: executar export LD_LIBRARY_PATH=. se deseja que a lib seja buscada no diretorio atual (do mastershell)

---------------------------------------------------
 Funções Implementadas
---------------------------------------------------
- Execução de comandos internos 'quit' ou 'exit' e 'cd'
- Execucão de comandos externos via fork() e exec() utilizando o caminho de busca (PATH) herdado do shell padrão (bash)
- Os comandos externos aceitam uma lista variável de argumentos
- Redirecionamento de entrada: leitura (<)
- Redirecionamento de saida: sobrescrita (>), concatenação (>>)
- O comando 'exit' ou 'quit' causam o termino do programa com return EXIT_SUCCESS
- Execução de processos via pipeline

---------------------------------------------------
 Sobre o codigo
---------------------------------------------------
- Foi utilizado o modelo do shell Foosh disponibilizado pelo professor.
- A implementacao das funcionalidades do shell foram feitas dentro do arquivo main.c na funcao main()
- Foi criada uma funcao execute_pipeline() em main.c:96 que faz a execucao recursiva de
  comandos em pipeline.
- A estrutura pipeline_t definida em mastershell.h:41 foi alterada com a adicao de uma variavel
  int redirect parar suportar o comando ">>" de append e junto a isso novas macros foram definidas
  em mastershell.h:37,72
- Uma pequena alteracao na funcao find_modifiers() em parser.c:196 foi necessaria tambem para o suporte
  ao comando ">>" de append

---------------------------------------------------
Grupo:
---------------------------------------------------
- Guilherme Augusto Bileki - 4287189
- Luis Gustavo B. Ferrassini - 7987414
- Rodrigo das Neves Bernardi - 8066395