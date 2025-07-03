#include <iostream>
#include <cstring>
#include "Local.hpp"

Local locais[100];
int totalLocais = 0;

void cadastrarLocal() {
    if (totalLocais >= 100) {
        std::cout << "Limite de locais atingido!\n";
        return;
    }
    std::cin.ignore();
    std::cout << "Nome do local: ";
    std::cin.getline(locais[totalLocais].nome, 100);
    std::cout << "Coordenada X: ";
    std::cin >> locais[totalLocais].x;
    std::cout << "Coordenada Y: ";
    std::cin >> locais[totalLocais].y;
    totalLocais++;
    std::cout << "Local cadastrado com sucesso!\n";
}

void listarLocais() {
    if (totalLocais == 0) {
        std::cout << "Nenhum local cadastrado.\n";
        return;
    }
    for (int i = 0; i < totalLocais; i++) {
        std::cout << i + 1 << ". " << locais[i].nome
                  << " (" << locais[i].x << ", " << locais[i].y << ")\n";
    }
}

void atualizarLocal() {
    listarLocais();
    if (totalLocais == 0) return;

    int id;
    std::cout << "Informe o número do local para atualizar: ";
    std::cin >> id;
    if (id < 1 || id > totalLocais) {
        std::cout << "ID inválido.\n";
        return;
    }
    id--;

    std::cin.ignore();
    std::cout << "Novo nome: ";
    std::cin.getline(locais[id].nome, 100);
    std::cout << "Nova coordenada X: ";
    std::cin >> locais[id].x;
    std::cout << "Nova coordenada Y: ";
    std::cin >> locais[id].y;
    std::cout << "Local atualizado com sucesso!\n";
}

void excluirLocal() {
    listarLocais();
    if (totalLocais == 0) return;

    int id;
    std::cout << "Informe o número do local para excluir: ";
    std::cin >> id;
    if (id < 1 || id > totalLocais) {
        std::cout << "ID inválido.\n";
        return;
    }
    id--;

    for (int i = id; i < totalLocais - 1; i++) {
        locais[i] = locais[i + 1];
    }
    totalLocais--;
    std::cout << "Local excluído com sucesso!\n";
}

void menuLocais() {
    int opcao;
    do {
        std::cout << "\n--- Menu Locais ---\n"
                  << "1 - Cadastrar local\n"
                  << "2 - Listar locais\n"
                  << "3 - Atualizar local\n"
                  << "4 - Excluir local\n"
                  << "0 - Voltar\n"
                  << "Escolha: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1: cadastrarLocal(); break;
            case 2: listarLocais(); break;
            case 3: atualizarLocal(); break;
            case 4: excluirLocal(); break;
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}
