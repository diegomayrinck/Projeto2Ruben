#include "Validacoes.h"
#include "Common.h"

using namespace std;

// Fun��o auxiliar para limpar o buffer de entrada e tratar erros
void limparBufferEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//fun��o para tratar entrada inv�lida.
void tratarErroEntrada() {
    cout << "Entrada inv�lida. Por favor, tente novamente.\n";
    cin.clear(); // Limpa os flags de erro
    limparBufferEntrada(); // Descarta a entrada inv�lida
}

// Fun��o para obter um float v�lido do usu�rio
float obterFloat(const string& prompt) {// Usado em cin's para validar ints e retornar os valores se forem validos. Se n�o forem repete at� serem.
    float valor;
    while (true) {
        cout << prompt;
        if (cin >> valor && valor > 0) {
            limparBufferEntrada();
            return valor;
        }
        else {
            tratarErroEntrada();
        }
    }
}

int validacaoInt(const string& prompt) { // Usado em cin's para validar ints e retornar os valores se forem validos. Se n�o forem repete at� serem.
    int n;

    while (true) {
        cout << prompt;
        if (cin >> n) {
            limparBufferEntrada();
            return n;
        }
        else {
            tratarErroEntrada();
        }
    }

    return n;
}