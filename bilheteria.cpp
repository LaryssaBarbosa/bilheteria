#include <iostream>
#include <iomanip>

using namespace std;

const int LINHAS = 15;
const int LUGARES = 40;

char sala[LINHAS][LUGARES];

void inicializarSala() {
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < LUGARES; j++)
            sala[i][j] = '.';
}

float calcularPrecoLinha(int linha) {
    if (linha <= 1 && linha <= 5)
        return 50.0;
    else if (linha >= 6 && linha <= 10)
        return 30.0;
    else
        return 15.0;
}

void realizarReserva() {
    int linha, lugar;
    cout << "Informe o número da linha (1 a 15): ";
    cin >> linha;
    cout << "Informe o número do lugar (1 a 40): ";
    cin >> lugar;
    
    if (linha < 1 || linha > 15 || lugar < 1 || lugar > 40){
        cout << "Entrada inválida. Tente novamente. \n";
        return;
    }
    
    if (sala[linha - 1][lugar - 1] == '.') {
        sala[linha - 1][lugar - 1] = '#';
        cout << "Reserva efetuada com sucesso.\n";
    } else {
        cout << "Esse lugar já está ocupado.\n";
    }
}

void exibirMapa() {
    cout << "\nMapa de Ocupação:\n";
    for (int i = 0; i < LINHAS; i++) {
        cout << "Linha " << setw(2) << (i + 1) << ": ";
        for (int j = 0; j < LUGARES; j++) {
            cout << sala[i][j];
        }
        cout << endl;
    }
    cout << "Legenda: '.' = Disponível | '#' = Ocupado\n\n";
}

void exibirFaturamento() {
    int ocupados = 0;
    float total = 0.0;
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < LUGARES; j++) {
            if (sala[i][j] == '#') {
                ocupados++;
                total += calcularPrecoLinha(i + 1);
            }
        }
    }
    
    cout << "Quantidade de lugares ocupados: " << ocupados << endl;
    cout << fixed << setprecision(2);
    cout << "Total da bilheteira: R$ " << total << endl << endl;
}

int main() {
    int opcao;
    inicializarSala();
    
    do {
        cout << "Menu:\n";
        cout << "0. Encerrar\n";
        cout << "1. Reservar lugar\n";
        cout << "2. Exibir mapa de ocupação\n";
        cout << "3. Exibir faturamento\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        
        switch (opcao) {
            case 0:
                cout << "Sistema encerrado.\n";
                break;
            case 1:
                realizarReserva();
                break;
            case 2:
                exibirMapa();
                break;
            case 3:
                exibirFaturamento();
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);
    
    return 0;
}
