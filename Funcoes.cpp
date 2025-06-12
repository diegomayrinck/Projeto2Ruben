﻿#include "Common.h"
#include "Loja.h"

using namespace std;

// Função para converter uma string para minúsculas
string toMinuscula(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

//// Fun��o para gerar venda aleatoria gratis com 25% de chance         
//int vendaGratis() {
//    return (rand() % 4) == 0;
//}
//
//// Fun��o para adicionar 30% ao valor de custo
//float calcValorVenda(float precoCusto) {
//    return precoCusto * 1.3;
//}
//
//// Fun��o para calular o iva
//float calcIVA(float precoTotal) {
//    return precoTotal * 0.23;
//}
//
//// EM ANALISE DE NECESSIDADE!!!!!!!
///* //Função para iniciar a matriz 
//void inicializarMatriz(float**& mat, int qtdProdutoVenda) {
//    mat = new float* [qtdProdutoVenda];
//    for (int i = 0; i < qtdProdutoVenda; ++i) {
//        mat[i] = new float[6];
//    }
//}*/
//
////função para registrar a venda
//bool registrarVenda(int i, float** mat, Produto*& produtoSelecionado, vector<int>& produtosVendidos) {
//    int idProduto, qtdVenda;
//    float precoSemIVA, ivaUnitario, precoUnit, precoTotal, IVA, totalComIVA;
//    bool produtoValido = false;
//
//    while (!produtoValido) {
//        idProduto = validacaoInt("Digite o id do " + to_string(i + 1) + "º produto: ");
//
//        // Verificar se o produto já foi adicionado
//        bool produtoRepetido = false;
//        for (int idVendido : produtosVendidos) {
//            if (idVendido == idProduto) {
//                produtoRepetido = true;
//                cout << "Este produto já foi adicionado à venda. Escolha outro.\n";
//                break;
//            }
//        }
//        if (produtoRepetido) {
//            continue; // Volta ao início do loop para inserir um novo ID
//        }
//
//        checarProdutoEstoque(idProduto, produtoSelecionado);
//        if (!produtoSelecionado) {
//            cout << "Produto nao encontrado. Tente novamente.\n";
//            continue; // Volta ao início do loop para inserir um novo ID
//        }
//
//        if (produtoSelecionado->quantidade == 0) {
//            cout << "Produto '" << produtoSelecionado->nome << "' (ID: " << idProduto << ") está fora de estoque. Escolha outro produto.\n";
//
//            continue;
//        }
//
//        produtoValido = true; // Produto encontrado, não repetido E COM ESTOQUE, podemos prosseguir
//    }
//
//    while (true) {
//        qtdVenda = validacaoInt("Digite a quantidade de " + produtoSelecionado->nome + " que deseja: ");
//
//        if (qtdVenda == 0) {
//            cout << "Item cancelado.\n";
//            return false;
//        }
//        else if (qtdVenda > produtoSelecionado->quantidade) {
//            cout << "Quantidade insuficiente (" << produtoSelecionado->quantidade << " em estoque).\n";
//            continue; // Solicita a quantidade novamente
//        }
//        else if (qtdVenda < 0) { // Corrigido para verificar se é menor que zero
//            cout << "Quantidade inválida. Digite um número maior ou igual a zero.\n";
//            continue; // Solicita a quantidade novamente
//        }
//        else {
//            break; // Quantidade válida
//        }
//    }
//
//    precoSemIVA = calcValorVenda(produtoSelecionado->precoCusto);
//    ivaUnitario = calcIVA(precoSemIVA);
//    precoUnit = precoSemIVA + ivaUnitario;
//    precoTotal = precoUnit * qtdVenda;
//    IVA = ivaUnitario * qtdVenda;
//    totalComIVA = precoTotal;
//
//    mat[i][0] = idProduto;     // ID do produto
//    mat[i][1] = qtdVenda;       // Quantidade vendida
//    mat[i][2] = precoSemIVA;    // Preço de venda sem IVA (unitário)
//    mat[i][3] = IVA;            // IVA total para a quantidade vendida
//    mat[i][4] = totalComIVA;    // Preço total com IVA para a quantidade vendida
//    mat[i][5] = precoUnit;      // Preço de venda unitário com IVA
//
//    produtosVendidos.push_back(idProduto); // Adiciona o ID do produto VÁLIDO ao vetor
//    return true;
//}
//
//// função checkout
//bool checkout(float** mat, int numItensProcessados, float& somaTotal, float& somaIVA) {
//    Produto* produtoSelecionado = nullptr;
//    somaTotal = 0;
//    somaIVA = 0;
//    vector<pair<int, int>> carrinhoOriginal;
//    string input;
//    char confirmacao;
//
//    system("cls");
//
//    cout << "=========== Checkout ===========\n";
//    for (int i = 0; i < numItensProcessados; ++i) {
//        int idProduto = static_cast<int>(mat[i][0]);
//        int quantidadeVendida = static_cast<int>(mat[i][1]);
//        checarProdutoEstoque(idProduto, produtoSelecionado);
//        if (produtoSelecionado) {
//            cout << "Produto: " << produtoSelecionado->nome << "\n";
//            cout << "Quantidade: " << quantidadeVendida << "\n";
//            cout << "Preço Unitário: " << fixed << setprecision(2) << mat[i][5] << " euros\n";
//            cout << "Preço s/IVA: " << fixed << setprecision(2) << mat[i][2] << " euros\n";
//            cout << "IVA (23%): " << fixed << setprecision(2) << mat[i][3] / quantidadeVendida << " euros\n"; // IVA unitário
//            cout << "---------------------------------\n";
//
//            carrinhoOriginal.push_back({ idProduto, quantidadeVendida });
//            produtoSelecionado->quantidade -= quantidadeVendida; // Atualiza o estoque (temporariamente)
//
//            somaTotal += mat[i][4]; // Acumula o preço total COM IVA
//            somaIVA += mat[i][3];   // Acumula o IVA total
//        }
//    }
//
//    cout << "Subtotal s/IVA: " << fixed << setprecision(2) << somaTotal - somaIVA << " euros\n";
//    cout << "Total IVA: " << fixed << setprecision(2) << somaIVA << " euros\n";
//    cout << "Total c/IVA: " << fixed << setprecision(2) << somaTotal << " euros\n\n";
//
//    while (true) {
//        do {
//            cout << "Confirmar compra (Y - Sim) ou Desistir da venda (N - Não)? ";
//            getline(cin, input);
//            if (!input.empty()) {
//                confirmacao = input[0];
//            }
//            else {
//                confirmacao = '\0'; // Ou algum valor que não corresponda a 'Y' ou 'N' para repetir o loop
//            }
//        } while (confirmacao != 'y' && confirmacao != 'n' && confirmacao != 'Y' && confirmacao != 'N');
//
//        if (confirmacao == 'y' || confirmacao == 'Y') {
//            cout << "Compra confirmada.\n";
//            return true; // Retorna true se a compra for confirmada
//        }
//        else {
//            cout << "Venda cancelada no checkout. Revertendo estoque.\n";
//            // Reverter as alterações no estoque
//            for (const auto& item : carrinhoOriginal) {
//                checarProdutoEstoque(item.first, produtoSelecionado);
//                if (produtoSelecionado) {
//                    produtoSelecionado->quantidade += item.second;
//                }
//            }
//            somaTotal = 0; // Zera o total para indicar que a venda foi cancelada
//            somaIVA = 0;
//            return false; // Retorna false se a venda for cancelada
//        }
//    }
//    return false;
//}
//
////função para imprimir o talão
//void imprimirTalao(float** mat, int qtdProdutoVenda, int numFatura, int numCliente, float somaTotal, float somaIVA, float valorPago, float troco) {
//    Produto* produtoSelecionado = nullptr; //transforma a posição de memória separada em null, para não ter lixo
//    time_t t = time(nullptr);
//    tm* dataAtual = localtime(&t);
//
//    system("cls");
//
//    cout << "======= TALÃO DE COMPRAS =======\n";
//    cout << "Fatura N: " << numFatura << "\n";
//    cout << "Data: " << put_time(dataAtual, "%d/%m/%Y %H:%M") << "\n";
//    cout << "Cliente N: " << numCliente << "\n\n";
//    cout << "----- Detalhes dos Produtos -----\n";
//
//    for (int i = 0; i < qtdProdutoVenda; ++i) {
//        int idProduto = mat[i][0];
//        checarProdutoEstoque(idProduto, produtoSelecionado);
//        if (produtoSelecionado) {
//            cout << "Produto: " << produtoSelecionado->nome << "\n";
//            cout << "Quantidade: " << static_cast<int>(mat[i][1]) << "\n";
//            cout << "Preço Unitário: " << fixed << setprecision(2) << mat[i][5] << " euros\n";
//            cout << "Preço s/IVA: " << fixed << setprecision(2) << mat[i][2] << " euros\n";
//            cout << "IVA (23%): " << fixed << setprecision(2) << mat[i][3] << " euros\n";
//            cout << "---------------------------------\n";
//        }
//    }
//
//    cout << "Subtotal s/IVA: " << fixed << setprecision(2) << somaTotal - somaIVA << " euros\n";
//    cout << "Total IVA: " << fixed << setprecision(2) << somaIVA << " euros\n";
//    cout << "Total c/IVA: " << fixed << setprecision(2) << somaTotal << " euros\n";
//    cout << "Valor Pago: " << fixed << setprecision(2) << valorPago << " euros\n";
//    cout << "Troco: " << fixed << setprecision(2) << troco << " euros\n";
//    cout << "=====================================\n";
//}
//
//
////Função para escolher os produtos e a quantidade.
//void venda() {
//    int qtdProdutoVenda, numCliente;
//    float valorPago = 0, troco = 0, somaTotal = 0, somaIVA = 0;
//    static int numFatura = 1;
//
//    Produto* produtoSelecionado = nullptr;
//    float** mat = nullptr; // Inicializar mat para evitar problemas com delete[]
//    vector<int> produtosVendidos; // Para rastrear os produtos já adicionados
//
//    system("cls");
//    mostrarEstoque();
//
//    while (true) {
//        qtdProdutoVenda = validacaoInt("Inserir a quantidade de produtos a serem vendidos: ");
//
//        if (qtdProdutoVenda > 0) {
//            break; // Sai do loop se a entrada for válida
//        }
//        else {
//            cout << "Quantidade invalida. Por favor, insira um número maior que zero.\nPressione Enter para continuar...";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//    }
//
//    inicializarMatriz(mat, qtdProdutoVenda);
//
//    int produtosProcessados = 0;
//    for (int i = 0; i < qtdProdutoVenda; ++i) {
//        if (registrarVenda(i, mat, produtoSelecionado, produtosVendidos)) {
//            produtosProcessados++;
//        }
//    }
//
//    if (produtosProcessados == 0) {
//        cout << "Nenhum produto válido foi processado. Venda cancelada.\n";
//        _getch();
//        // Liberar a memória alocada para mat, mesmo que a venda seja cancelada
//        for (int i = 0; i < qtdProdutoVenda; ++i) {
//            delete[] mat[i];
//        }
//        delete[] mat;
//        return;
//    }
//
//    // Chama a função checkout e verifica o resultado
//    if (checkout(mat, qtdProdutoVenda, somaTotal, somaIVA)) {
//        bool vendaSorteada = vendaGratis();
//        if (vendaSorteada) {
//            somaTotal = 0;
//            somaIVA = 0;
//            cout << "Venda sorteada! Cliente não pagará.\n";
//        }
//        else {
//            cout << "Total a pagar: " << fixed << setprecision(2) << somaTotal << " euros\n";
//            while (true) {
//                valorPago = obterFloat("Insira o valor pago pelo cliente: ");
//
//                if (valorPago >= somaTotal) {
//                    break; // Sai do loop se a entrada for válida
//                }
//                else {
//                    do {
//                        valorPago = obterFloat("Valor pago não pode ser menor que o total a pagar\nInsira o valor pago pelo cliente: ");
//                    } while (valorPago < somaTotal);
//                    break;
//                }
//            }
//        }
//
//        troco = valorPago - somaTotal;
//
//        while (true) {
//            numCliente = validacaoInt("Digite o codigo do cliente: ");
//            if (numCliente != 0) {
//                break; // Sai do loop se o código do cliente for diferente de zero
//            }
//            else {
//                cout << "O código do cliente não pode ser zero. Digite um valor válido.\n";
//            }
//        }
//
//        imprimirTalao(mat, qtdProdutoVenda, numFatura++, numCliente, somaTotal, somaIVA, valorPago, troco);
//    }
//
//    // Liberar a memória alocada para mat
//    if (mat != nullptr) {
//        for (int i = 0; i < qtdProdutoVenda; ++i) {
//            delete[] mat[i];
//        }
//        delete[] mat;
//    }
//
//    _getch();
//}

//função menu
void exibirMenu() {
    int opcao;
    Loja l;

    vector<pair<int, string>> menuOpcoes = {
        {1, "Efetuar Venda"},
        {2, "Criar Novo / Atualizar Artigo"},
        {3, "Excluir Produto"},
        {4, "Exibir Stock"},
        {5, "Sair"}
    };

    // Definir as larguras das colunas
    const int larguraID = 7;
    const int larguraOpcao = 40;

    // Calcular a largura total da linha
    const int larguraTotal = larguraID + 2 + larguraOpcao + 2; // ID + " | " + Opção + " |"

    string linhaSeparadora(larguraTotal, '-');

    do {
        system("cls");

        cout << "------------------ MENU PRINCIPAL -----------------" << endl;
        cout << left << setw(larguraID) << "Opção" << " | " << left << setw(larguraOpcao) << "Descrição" << endl;
        cout << linhaSeparadora << endl;

        for (const auto& item : menuOpcoes) {
            cout << left << setw(larguraID) << item.first << " | " << left << setw(larguraOpcao) << item.second << endl;
        }

        cout << linhaSeparadora << endl;
        opcao = validacaoInt("Escolha uma opcao: ");
        switch (opcao) {
		case 1: l.efetuarVenda();
            // chamar funcao de venda aqui
            // venda();
            break;
		case 2: l.adicionarProduto();
            // chamar funcao de criacao
            ;
            break;
        case 3:
            // chamar funcao de eliminacao
            l.removerProduto();
            break;
        case 4:
            // chamar funcao mostrar estoque
            l.mostrarEstoque();
            cout << "Prima qualquer tecla...";
            _getch();
            break;
        case 5:
            cout << "Pressione qualquer tecla..." << endl;
            _getch();
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            _getch();
        }

        cout << endl;

    } while (opcao != 5);
}