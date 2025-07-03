#ifndef VEICULO_HPP
#define VEICULO_HPP

struct Veiculo {
    char placa[10];
    char modelo[50];
    int status; // 0 = disponível, 1 = ocupado
    char localAtual[100]; // nome do local onde está o veículo
};

void menuVeiculos();
void cadastrarVeiculo();
void listarVeiculos();
void atualizarVeiculo();
void excluirVeiculo();

extern Veiculo veiculos[100];
extern int totalVeiculos;

#endif
