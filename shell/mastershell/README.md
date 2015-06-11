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
