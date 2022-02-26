//funcao para ler o .txt e dele extrair o numero de palavras e de letras
void setup(char nomeDoArquivo[], int *palavras, int *letras);

//funcao pra copiar as palavras do .txt para uma matriz
void preencheTabela(char nomeDoArquivo[], int palavras, int letras, char tabela[][letras]);

//funcao pra testar se a palavra digitada eh realmente valida
int validaPalavra(int palavras, int letras, char chute[], char tabelaPalavras[][letras]);

//funcao pra escolher palavra secreta da tabela de palavras
void sorteiaPalavraChave(int palavras, int letras, char tabelaPalavras[][letras], char palavraSecreta[]);

//funcao pra redefinir as tabelas de armazenamentos de acordo com as tentativas
void atualizaTabela(int tentativa, int tentativaMax, int letras, char listaChutes[][letras], char listaResultados[][letras], char chute[], char resultado[]);
                    
//funcao pra imprimir inteface do jogo
void imprimeTela(int tentativa, int tentativasMax, int letras, char listaChutes[][letras], char listaResultados[][letras]);

//funcao pra analisar se o chute e igual a palavra secreta definido um resultado
int checaPalavra(char chute[], char palavraSecreta[], char resultado[], int letras);