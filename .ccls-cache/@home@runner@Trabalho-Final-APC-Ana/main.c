#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Num_L 3
#define Num_C 3
int calcularPontos(int tentativas) {
if (tentativas < 5) {
return 100;
} else if (tentativas < 10) {
return 50;
} else {
return 20;
}
}
int main() {
int pontuacoes[Num_L][Num_C] = {0};
int scanVar;
int i;
int j;
int opcao = 0;
int nivel, limiteInferior, linha, coluna, limiteSuperior, numeroSecreto,
status_1, palpite, resetar, idade,tamanho, plataforma, pontos = 0;
int tentativas = 0;
int rodadas = 1;
struct jogador_t {
int jogo;
int pontos;
char nickname[61];
};
system("clear");
printf("\x1b[31mescolha a sua plataforma de jogo\x1b[0m\n");
printf("\n");
printf("\x1b[35mcelular aperte 1\x1b[0m\n");
printf("\x1b[34m _________\x1b[0m\n");
printf("\x1b[34m|         |\x1b[0m\n");
printf("\x1b[34m|         |\x1b[0m\n");
printf("\x1b[34m|         |\x1b[0m\n");
printf("\x1b[34m|         |\x1b[0m\n");
printf("\x1b[34m|         |\x1b[0m\n");
printf("\x1b[34m|_________|\x1b[0m\n");
printf("\x1b[34m|___(*)___|\x1b[0m\n");
printf("\n");
printf("\x1b[35mcomputador aperta 2\x1b[0m\n");
printf("\x1b[34m ________   ___ \x1b[0m\n");
printf("\x1b[34m|        | | _ |\x1b[0m\n");
printf("\x1b[34m|        | |(*)|\x1b[0m\n");
printf("\x1b[34m|        | | _ |\x1b[0m\n");
printf("\x1b[34m --------  |___|\x1b[0m\n");
printf("\x1b[34m  |____|  |_____|\x1b[0m\n");
printf("\n");
printf("\x1b[31mSua opção =>\x1b[0m");
scanVar = scanf("%i", &plataforma);
(void)("clear");
if (plataforma == 1){
while (1){
system("clear");
printf("\x1b[34m--------- Menu ---------\x1b[0m\n");
printf("\x1b[35m| 1. login |\x1b[0m\n");
printf("\x1b[35m| 2. jogar |\x1b[0m\n");
printf("\x1b[35m| 3. status |\x1b[0m\n");
printf("\x1b[35m| 0. Sair |\x1b[0m\n");
printf("\x1b[34m------------------------\n");
printf("\x1b[31mSua opção =>\x1b[0m");
scanVar = scanf("%i", &opcao);
getchar();
switch (opcao) {
case 1:
system("clear");
struct jogador_t jogador[1];
for (int i = 0; i < 1; i++) {
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[34m|entre com a idade do jogador|\x1b[0m\n");
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[37ma idade é: \x1b[0m");
scanVar = scanf("%d", &jogador[i].jogo);
getchar();
printf("\x1b[37m----------------------------\x1b[0m\n");
printf("\x1b[34m|entre com o nick do jogador|\x1b[0m\n");
printf("\x1b[37m----------------------------\x1b[0m\n");
printf("\x1b[37mo nickname é: \x1b[0m");
scanVar = scanf("%s", jogador[i].nickname);
getchar();
}
break;
printf("\x1b[31mPressione ENTER para continuar...\x1b[0m");
getchar();
case 2:
system("clear");
printf("\x1b[37m----------------------------\x1b[0m\n");
printf("\x1b[36mentre com a quantidade de rodadas que quer jogar:\x1b[0m\n");
printf("\x1b[37m----------------------------\x1b[0m\n");
scanVar = scanf("%d", &rodadas);
getchar();
for (int i = 0; i < rodadas; i++) {
srand(time(0));
system("clear");
printf("\x1b[31mseja bem vindo ao jogo,escolha o nivel pelo qual "
"queira se desafiar!\x1b[0m\n");
printf("\x1b[34mEscolha um nível:\x1b[0m\n");
printf("\x1b[35m1 - basico (números entre 1 a 100)\x1b[0m\n");
printf("\x1b[35m2 - Médio (números entre 1 a 300)\x1b[0m\n");
printf("\x1b[35m3 - avançado (números entre 1 a 1000)\x1b[0m\n");
printf("\x1b[34mDigite o número do nível:\x1b[0m\n ");
scanVar = scanf("%d", &nivel);
getchar();
// Define os limites com base no nível escolhido
if (nivel == 1) {
limiteInferior = 1;
limiteSuperior = 100;
} else if (nivel == 2) {
limiteInferior = 1;
limiteSuperior = 300;
} else if (nivel == 3) {
limiteInferior = 1;
limiteSuperior = 1000;
} else {
printf("\x1b[41mNível inválido! Reinicie o jogo.\x1b[0m\n");
}
// Gera um número aleatório dentro do intervalo do nível escolhido
numeroSecreto =
rand() % (limiteSuperior - limiteInferior + 1) + limiteInferior;
system("clear");
printf("\x1b[35mUm número foi gerado entre %d e %d.\x1b[0m\n",
limiteInferior, limiteSuperior);
do {
printf("\x1b[39mDigite um número:\x1b[0m\n ");
scanVar = scanf("%i", &palpite);
getchar();
tentativas++;
if (palpite > numeroSecreto) {
printf(
"\x1b[31mNúmero esta muito alto! Tente novamente.\x1b[0m\n");
} else if (palpite < numeroSecreto) {
printf(
"\x1b[33mNúmero esta muito baixo! Tente novamente.\x1b[0m\n");
} else if (palpite == numeroSecreto) {
printf("\x1b[32mparabens voce acertou o numero %d\x1b[0m\n",
tentativas);
} else {
printf("\x1b[31mNumero inválido! Reinicie o jogo.\x1b[0m\n");
return 0;
}
} while (palpite != numeroSecreto);
int score[Num_L][Num_C];
system("clear");
printf(
"\x1b[32mparabens voce acertou o numero em %d tentativas \x1b[0m\n",tentativas);
system("clear");
pontos = calcularPontos(tentativas);
for (int j = 0; j < Num_C; j++) {
pontuacoes[i][j] = pontos;
}
printf("|\x1b[39mo numero certo é %d\x1b[0m|\n", numeroSecreto);
printf("|\x1b[39macertou em %i tentativas\x1b[0m\n|", tentativas);
// pontos = calcularPontos(tentativas);
// pontuacoes[i] == pontos;
}
break;
case 3: {
system("clear");
int jogo = 0;
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[33mEntre com a idade do jogador: \x1b[0m\n");
printf("\x1b[37m-----------------------------\x1b[0m\n");
scanVar = scanf("%i", &jogo);
getchar();
int jogadorEncontrado = -1;
for (int i = 0; i < 1; i++) {
if (jogo == jogador[i].jogo) {
jogadorEncontrado = i;
break;
}
}
if (jogadorEncontrado < 0) {
printf("\x1b[41mNão existe um jogador com essa quantidade de jogos.\x1b[0m\n");
} else {
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[33mO nickname do jogador com idade %i é %s\x1b[0m\n",
jogador[jogadorEncontrado].jogo, jogador[jogadorEncontrado].nickname);
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[31mPontuações:\x1b[0m\n");
for (int i = 0; i < rodadas; i++) {
printf("\x1b[32mRodada %d: %d pontos\x1b[0m\n", i + 1,
pontuacoes[i][jogadorEncontrado]);
}
}
break;
}
case 0:
system("clear");
break;
default:
printf("\x1b[31mOpcao invalida\x1b[0m\n");
}
if (opcao == 0) {
system("clear");
break;
}
printf("Pressione ENTER para continuar...");
getchar();
}
return 0;
}if (plataforma == 2){
while (1) {
system("clear");
printf("\x1b[34m --------- Menu ---------\x1b[0m\n");
printf("\x1b[35m | 1. login |\x1b[0m\n");
printf("\x1b[35m | 2. jogar |\x1b[0m\n");
printf("\x1b[35m | 3. status |\x1b[0m\n");
printf("\x1b[35m | 0. Sair |\x1b[0m\n");
printf("\x1b[34m ------------------------\n");
printf("\x1b[31m Sua opção =>\x1b[0m");
scanVar = scanf("%i", &opcao);
getchar();
switch (opcao) {
case 1:
system("clear");
struct jogador_t jogador[1];
for (int i = 0; i < 1; i++) {
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[34m|entre com a idade do jogador|\x1b[0m\n");
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[37ma idade é: \x1b[0m");
scanVar = scanf("%d", &jogador[i].jogo);
getchar();
printf("\x1b[37m----------------------------\x1b[0m\n");
printf("\x1b[34m|entre com o nick do jogador|\x1b[0m\n");
printf("\x1b[37m----------------------------\x1b[0m\n");
printf("\x1b[37mo nickname é: \x1b[0m");
scanVar = scanf("%s", jogador[i].nickname);
getchar();
}
break;
printf("\x1b[31mPressione ENTER para continuar...\x1b[0m");
getchar();
case 2:
system("clear");
printf("\x1b[37m----------------------------\x1b[0m\n");
printf("\x1b[36mentre com a quantidade de rodadas que quer jogar:\x1b[0m\n");
printf("\x1b[37m----------------------------\x1b[0m\n");
scanVar = scanf("%d", &rodadas);
getchar();
for (int i = 0; i < rodadas; i++) {
srand(time(0));
system("clear");
printf("\x1b[31mseja bem vindo ao jogo,escolha o nivel pelo qual "
"queira se desafiar!\x1b[0m\n");
printf("\x1b[34mEscolha um nível:\x1b[0m\n");
printf("\x1b[35m1 - basico (números entre 1 a 100)\x1b[0m\n");
printf("\x1b[35m2 - Médio (números entre 1 a 300)\x1b[0m\n");
printf("\x1b[35m3 - avançado (números entre 1 a 1000)\x1b[0m\n");
printf("\x1b[34mDigite o número do nível:\x1b[0m\n ");
scanVar = scanf("%d", &nivel);
getchar();
// Define os limites com base no nível escolhido
if (nivel == 1) {
limiteInferior = 1;
limiteSuperior = 100;
} else if (nivel == 2) {
limiteInferior = 1;
limiteSuperior = 300;
} else if (nivel == 3) {
limiteInferior = 1;
limiteSuperior = 1000;
} else {
printf("\x1b[41mNível inválido! Reinicie o jogo.\x1b[0m\n");
}
// Gera um número aleatório dentro do intervalo do nível escolhido
numeroSecreto =
rand() % (limiteSuperior - limiteInferior + 1) + limiteInferior;
system("clear");
printf("\x1b[35mUm número foi gerado entre %d e %d.\x1b[0m\n",
limiteInferior, limiteSuperior);
do {
printf("\x1b[39mDigite um número:\x1b[0m\n ");
scanVar = scanf("%i", &palpite);
getchar();
tentativas++;
if (palpite > numeroSecreto) {
printf(
"\x1b[31mNúmero esta muito alto! Tente novamente.\x1b[0m\n");
} else if (palpite < numeroSecreto) {
printf(
"\x1b[33mNúmero esta muito baixo! Tente novamente.\x1b[0m\n");
} else if (palpite == numeroSecreto) {
printf("\x1b[32mparabens voce acertou o numero %d\x1b[0m\n",
tentativas);
} else {
printf("\x1b[31mNumero inválido! Reinicie o jogo.\x1b[0m\n");
return 0;
}
} while (palpite != numeroSecreto);
int score[Num_L][Num_C];
system("clear");
printf(
"\x1b[32mparabens voce acertou o numero em %d tentativas \x1b[0m\n",tentativas);
system("clear");
pontos = calcularPontos(tentativas);
for (int j = 0; j < Num_C; j++) {
pontuacoes[i][j] = pontos;
}
printf("|\x1b[39mo numero certo é %d\x1b[0m|\n", numeroSecreto);
printf("|\x1b[39macertou em %i tentativas\x1b[0m\n|", tentativas);
// pontos = calcularPontos(tentativas);
// pontuacoes[i] == pontos;
}
break;
case 3: {
system("clear");
int jogo = 0;
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[33mEntre com a idade do jogador: \x1b[0m\n");
printf("\x1b[37m-----------------------------\x1b[0m\n");
scanVar = scanf("%i", &jogo);
getchar();
int jogadorEncontrado = -1;
for (int i = 0; i < 1; i++) {
if (jogo == jogador[i].jogo) {
jogadorEncontrado = i;
break;
}
}
if (jogadorEncontrado < 0) {
printf("\x1b[41mNão foi encontrado um jogador com essa quantidade de jogos.x1b[0m\n");
} else {
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[33mO nickname do jogador com idade %i é %s\x1b[0m\n",
jogador[jogadorEncontrado].jogo, jogador[jogadorEncontrado].nickname);
printf("\x1b[37m-----------------------------\x1b[0m\n");
printf("\x1b[31mPontuações:\x1b[0m\n");
for (int i = 0; i < rodadas; i++) {
printf("\x1b[32mRodada %d: %d pontos\x1b[0m\n", i + 1,
pontuacoes[i][jogadorEncontrado]);
}
}
break;
}
case 0:
system("clear");
break;
default:
printf("\x1b[31mOpcao invalida\x1b[0m\n");
}
if (opcao == 0) {
system("clear");
break;
}
printf("Pressione ENTER para continuar...");
getchar();
}
}
return 0;
}