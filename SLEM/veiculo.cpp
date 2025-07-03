#include <iostream>
#include <cstring>
#include "Veiculo.hpp"

Veiculo veiculos[100];
int totalVeiculos = 0;

void cadastrarVeiculo() {
    if (totalVeiculos >= 100) {
        std::cout << "Limite de veículos atingido!\n";
        return;
    }
    std::cin.ignore();
    std::cout << "Placa: ";
    std::cin.getline(veiculos[totalVeiculos].placa, 10);
    std::cout << "Modelo: ";
    std::cin.getline(veiculos[totalVeiculos].modelo, 50);
    veiculos[totalVeiculos].status = 0; // disponível

    std::cout << "Local atual (nome): ";
    std::cin.getline(veiculos[totalVeiculos].localAtual, 100);

    totalVeiculos++;
    std::cout << "Veículo cadastrado com sucesso!\n";
}

void listarVeiculos() {
    if (totalVeiculos == 0) {
        std::cout << "Nenhum veículo cadastrado.\n";
        return;
    }
    for (int i = 0; i < totalVeiculos; i++) {
        std::cout << i + 1 << ". Placa: " << veiculos[i].placa
                  << ", Modelo: " << veiculos[i].modelo
                  << ", Status: " << (veiculos[i].status == 0 ? "Disponível" : "Ocupado")
                  << ", Local Atual: " << veiculos[i].localAtual << "\n";
    }
}

void atualizarVeiculo() {
    listarVeiculos();
    if (totalVeiculos == 0) return;

    int id;
    std::cout << "Informe o número do veículo para atualizar: ";
    std::cin >> id;
    if (id < 1 || id > totalVeiculos) {
        std::cout << "ID inválido.\n";
        return;
    }
    id--;

    std::cin.ignore();
    std::cout << "Nova placa: ";
    std::cin.getline(veiculos[id].placa, 10);
    std::cout << "Novo modelo: ";
    std::cin.getline(veiculos[id].modelo, 50);
    std::cout << "Status (0 - Disponível, 1 - Ocupado): ";
    std::cin >> veiculos[id].status;
    std::cin.ignore();
    std::cout << "Novo local atual: ";
    std::cin.getline(veiculos[id].localAtual, 100);
    std::cout << "Veículo atualizado com sucesso!\n";
}

void excluirVeiculo() {
    listarVeiculos();
    if (totalVeiculos == 0) return;

    int id;
    std::cout << "Informe o número do veículo para excluir: ";
    std::cin >> id;
    if (id < 1 || id > totalVeiculos) {
        std::cout << "ID inválido.\n";
        return;
    }
    id--;

    for (int i = id; i < totalVeiculos - 1; i++) {
        veiculos[i] = veiculos[i + 1];
    }
    totalVeiculos--;
    std::cout << "Veículo excluído com sucesso!\n";
}

void menuVeiculos() {
    int opcao;
    do {
        std::cout << "\n--- Menu Veículos ---\n"
                  << "1 - Cadastrar veículo\n"
                  << "2 - Listar veículos\n"
                  << "3 - Atualizar veículo\n"
                  << "4 - Excluir veículo\n"
                  << "0 - Voltar\n"
                  << "Escolha: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1: cadastrarVeiculo(); break;
            case 2: listarVeiculos(); break;
            case 3: atualizarVeiculo(); break;
            case 4: excluirVeiculo(); break;
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}
