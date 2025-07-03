#include <iostream>
#include <cstring>
#include "Pedido.hpp"

Pedido pedidos[100];
int totalPedidos = 0;

void cadastrarPedido() {
    if (totalPedidos >= 100) {
        std::cout << "Limite de pedidos atingido!\n";
        return;
    }
    pedidos[totalPedidos].id = totalPedidos + 1;

    std::cin.ignore();
    std::cout << "Origem (nome do local): ";
    std::cin.getline(pedidos[totalPedidos].origem, 100);
    std::cout << "Destino (nome do local): ";
    std::cin.getline(pedidos[totalPedidos].destino, 100);
    std::cout << "Peso (kg): ";
    std::cin >> pedidos[totalPedidos].peso;

    totalPedidos++;
    std::cout << "Pedido cadastrado com sucesso!\n";
}

void listarPedidos() {
    if (totalPedidos == 0) {
        std::cout << "Nenhum pedido cadastrado.\n";
        return;
    }
    for (int i = 0; i < totalPedidos; i++) {
        std::cout << pedidos[i].id << ". Origem: " << pedidos[i].origem
                  << ", Destino: " << pedidos[i].destino
                  << ", Peso: " << pedidos[i].peso << " kg\n";
    }
}

void atualizarPedido() {
    listarPedidos();
    if (totalPedidos == 0) return;

    int id;
    std::cout << "Informe o número do pedido para atualizar: ";
    std::cin >> id;
    if (id < 1 || id > totalPedidos) {
        std::cout << "ID inválido.\n";
        return;
    }
    id--;

    std::cin.ignore();
    std::cout << "Nova origem: ";
    std::cin.getline(pedidos[id].origem, 100);
    std::cout << "Novo destino: ";
    std::cin.getline(pedidos[id].destino, 100);
    std::cout << "Novo peso: ";
    std::cin >> pedidos[id].peso;
    std::cout << "Pedido atualizado com sucesso!\n";
}

void excluirPedido() {
    listarPedidos();
    if (totalPedidos == 0) return;

    int id;
    std::cout << "Informe o número do pedido para excluir: ";
    std::cin >> id;
    if (id < 1 || id > totalPedidos) {
        std::cout << "ID inválido.\n";
        return;
    }
    id--;

    for (int i = id; i < totalPedidos - 1; i++) {
        pedidos[i] = pedidos[i + 1];
    }
    totalPedidos--;
    std::cout << "Pedido excluído com sucesso!\n";
}

void menuPedidos() {
    int opcao;
    do {
        std::cout << "\n--- Menu Pedidos ---\n"
                  << "1 - Cadastrar pedido\n"
                  << "2 - Listar pedidos\n"
                  << "3 - Atualizar pedido\n"
                  << "4 - Excluir pedido\n"
                  << "0 - Voltar\n"
                  << "Escolha: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1: cadastrarPedido(); break;
            case 2: listarPedidos(); break;
            case 3: atualizarPedido(); break;
            case 4: excluirPedido(); break;
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}
