#pragma once

#include "Loja.h"

// Defini��o de todas as fun��es "n�o valida��es/metodos" do programa

int vendaGratis();
float calcValorVenda(float);
float calcIVA(float);
string toMinuscula(string);
// void inicializarMatriz(float**&, int); EM ANALISE DE NECESSIDADE
bool registrarVenda(int, float**, Produto*&, vector<int>&);
bool checkout(float**, int, float&, float&);
void imprimirTalao(float**, int, int, int, float, float, float, float);
void venda();
void exibirMenu();