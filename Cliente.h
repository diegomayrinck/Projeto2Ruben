#pragma once
#include<string>
using namespace std;

class Cliente {
private:
	int id;
	string nome;
	double telefone;
	string morada;

public:
	// Construtor
	Cliente();
	Cliente(int id, string nome, double telefone, string morada);
	// M�todos
	void setId(int);
	int getId() const;
	void setNome(string);
	string getNome() const;
	void setTelefone(double);
	double getTelefone() const;
	void setMorada(string);
	string getMorada() const;
	// M�todo para imprimir os dados do cliente
	void imprimirDados() const;
};


