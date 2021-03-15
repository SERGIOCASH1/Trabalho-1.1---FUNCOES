#include <iostream>
using namespace std;
#include <locale.h>
#include <time.h>

void percentual(int rolagens, int lados, int contador[]){
  float porcentagem;

  for(int i=1; i <=lados; i++){
    porcentagem = (contador[i] * 100) / rolagens;
    cout << "O número " << i << " foi sorteado " << contador[i] << " vez(es), com um percentual de " << porcentagem << " %\n";
  }
}
void contador2(int numDados, int rolagens, int ladosDado[]){
  int numSorteado;
  int contador[100] = {0};
  int totalLados = 0;
  int i, j;
  srand(time(NULL));

  for(i = 1; i <= rolagens; i++){
    for(j = 1; j <= numDados; j++){
      if(ladosDado[j] == 0){
        //If para evitar erro "floating point exception"
      }
      else{
        numSorteado = (rand() % ladosDado[j]) + 1;
        contador[numSorteado]++;
        cout  << "O número sorteado do dado nº " << j << " foi: " << numSorteado << "\n";
        }
      }
      cout << "\n";
    }
  for(i = 1; i <= numDados; i++){
      if(totalLados < ladosDado[i]){
        totalLados = ladosDado[i];
      }
      else{

      }
    }
  percentual((rolagens * numDados), totalLados, contador);
}


void contador(int lados, int rolagens){
  int numSorteado;
  int contador[100] = {0};
  int i;
  srand(time(NULL));

  for(i = 1; i <= rolagens; i++){
    numSorteado = (rand() % lados) + 1;
    contador[numSorteado]++;
    cout  << "O número sorteado foi: " << numSorteado << "\n";
  }

  percentual(rolagens, lados, contador);
}
  
void leitura2(){
  int lados;
  int rolagens;
  int numDados;
  int ladosDado[100] = {0};
  int aux = 0;
  do{
    cout << "Insira o nº de dados (entre 1 e 100): ";
    cin >> numDados;

  if ((numDados <= 0) or (numDados > 100)){
      cout << "Números de lados inválida! Digite novamente. \n";
    }
  } while ((numDados <= 0) or (numDados > 100));

  for(int i = 1; i <= numDados; i++){
    do{
      cout << "Insira o nº de lados do dado " << i << " (em que sua soma com os outros não ultrapasse 100): ";
      cin >> lados;
      ladosDado[i] = lados;

      aux = aux + lados;
    
    if ((lados <= 0) or (lados > 100) or (aux > 100)){
      cout << "Números de lados inválida! Digite novamente. \n";
      if(aux > 100){
        aux = aux-lados;
        }
      }
    } while ((lados <= 0) or (lados > 100) or (aux > 100));
  }

  do{
    cout << "Insira o nº de repetições de rolagem do dado (maior que 0): ";
    cin >> rolagens;

  if (rolagens <= 0){
      cout << "Números de repetições inválida! Digite novamente. \n";
    }
  } while (rolagens <= 0);

  contador2(numDados, rolagens, ladosDado);
}


void leitura(){
  int lados;
  int rolagens;
  do{
    cout << "Insira o nº de lados do dado (entre 1 e 100): ";
    cin >> lados;

  if ((lados <= 0) or (lados > 100)){
      cout << "Números de lados inválida! Digite novamente. \n";
    }
  } while ((lados <= 0) or (lados > 100));

  do{
    cout << "Insira o nº de repetições de rolagem do dado (maior que 0): ";
    cin >> rolagens;

  if (rolagens <= 0){
      cout << "Números de repetições inválida! Digite novamente. \n";
    }
  } while (rolagens <= 0);

  contador(lados, rolagens);
}

void opcoes(){
  int opcao;
  do{
    cout << "Selecione uma das opções abaixo: \n";
    cout << "1. Rolar um dado \n";
    cout << "2. Rolar mais de um dado \n";
    cout << "3. Avaliar o problema de Monty Hall\n";
    cin >> opcao;

  if ((opcao <= 0) or (opcao >= 4)){
      cout << "Opção inválida! Selecione novamente. \n";
    }
  } while ((opcao <= 0) or (opcao >= 4));

  while(true){
    if(opcao == 1){
      leitura();
      break;
    }
    else if(opcao == 2){
      leitura2();
      break;
    }
    else{
      cout << "AVALIADO - 10!";
      break;
    }
  }
}


int main() {
  opcoes();
  return (0);
}