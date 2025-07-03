#include <iostream>
#include <cmath>
#include <cstring>
#include "Rota.hpp"
#include "Veiculo.hpp"
#include "Local.hpp"
#include "Pedido.hpp"

// Função para calcular distância euclidiana entre dois Locais
double distancia(Local a, Local b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// Encontra índice do local pelo nome (exemplo simplificado)
int buscaLocalPorNome(const char* nome) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(locais[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Encontra índice do veículo disponível mais próximo de um local
int veiculoMaisProximo(Local origem) {
    int indice = -1;
    double menorDist = 1e9;
    for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].status == 0) { // disponível
            int idxLocalVeiculo = buscaLocalPorNome(veiculos[i].localAtual);
            if (idxLocalVeiculo == -1) continue;
            double dist = distancia(origem, locais[idxLocalVeiculo]);
            if (dist < menorDist) {
                menorDist = dist;
                indice = i;
            }
        }
    }
    return indice;
}

void calcularRota() {
    if (totalPedidos == 0) {
        std::cout << "Nenhum pedido para entrega.\n";
        return;
    }

    std::cout << "Pedidos pendentes:\n";
    for (int i = 0; i < totalPedidos; i++) {
        std::cout << pedidos[i].id << ". Origem: " << pedidos[i].origem << ", Destino: " << pedidos[i].destino << "\n";
    }

    int idPedido;
    std::cout << "Informe o ID do pedido para calcular a rota: ";
    std::cin >> idPedido;

    int idxPedido = -1;
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == idPedido) {
            idxPedido = i;
            break;
        }
    }
    if (idxPedido == -1) {
        std::cout << "Pedido não encontrado.\n";
        return;
    }

    int idxOrigem = buscaLocalPorNome(pedidos[idxPedido].origem);
    int idxDestino = buscaLocalPorNome(pedidos[idxPedido].destino);
    if (idxOrigem == -1 || idxDestino == -1) {
        std::cout << "Origem ou destino não cadastrados.\n";
        return;
    }

    int idxVeiculo = veiculoMaisProximo(locais[idxOrigem]);
    if (idxVeiculo == -1) {
        std::cout << "Nenhum veículo disponível próximo ao local de origem.\n";
        return;
    }

    double distOrigemDestino = distancia(locais[idxOrigem], locais[idxDestino]);
    double distVeiculoOrigem = distancia(locais[idxVeiculo], locais[idxOrigem]);

    double distanciaTotal = distOrigemDestino + distVeiculoOrigem;

    std::cout << "\nRota calculada:\n";
    std::cout << "Veículo selecionado: " << veiculos[idxVeiculo].placa << " - " << veiculos[idxVeiculo].modelo << "\n";
    std::cout << "Local origem: " << locais[idxOrigem].nome << "\n";
    std::cout << "Local destino: " << locais[idxDestino].nome << "\n";
    std::cout << "Distância total (veículo até origem + origem até destino): " << distanciaTotal << "\n";

    // Simular entrega
    std::cout << "\nIniciando entrega...\n";
    veiculos[idxVeiculo].status = 1; // ocupado

    // Aqui poderia ter uma pausa ou simulação, mas será instantâneo
    std::cout << "Entrega concluída!\n";

    veiculos[idxVeiculo].status = 0; // disponível
    strcpy(veiculos[idxVeiculo].localAtual, locais[idxDestino].nome);
}
