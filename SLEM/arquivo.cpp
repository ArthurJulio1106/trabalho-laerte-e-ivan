#include <cstdio>
#include <iostream>
#include "Arquivo.hpp"
#include "Local.hpp"
#include "Veiculo.hpp"
#include "Pedido.hpp"

void salvarBackup() {
    FILE* f;

    // Salvar locais
    f = fopen("dados/locais.bin", "wb");
    if (!f) {
        std::cout << "Erro ao abrir arquivo locais.bin para escrita\n";
        return;
    }
    fwrite(&totalLocais, sizeof(int), 1, f);
    fwrite(locais, sizeof(Local), totalLocais, f);
    fclose(f);

    // Salvar veículos
    f = fopen("dados/veiculos.bin", "wb");
    if (!f) {
        std::cout << "Erro ao abrir arquivo veiculos.bin para escrita\n";
        return;
    }
    fwrite(&totalVeiculos, sizeof(int), 1, f);
    fwrite(veiculos, sizeof(Veiculo), totalVeiculos, f);
    fclose(f);

    // Salvar pedidos
    f = fopen("dados/pedidos.bin", "wb");
    if (!f) {
        std::cout << "Erro ao abrir arquivo pedidos.bin para escrita\n";
        return;
    }
    fwrite(&totalPedidos, sizeof(int), 1, f);
    fwrite(pedidos, sizeof(Pedido), totalPedidos, f);
    fclose(f);

    std::cout << "Backup salvo com sucesso!\n";
}

void restaurarBackup() {
    FILE* f;

    // Restaurar locais
    f = fopen("dados/locais.bin", "rb");
    if (!f) {
        std::cout << "Arquivo locais.bin n\u00e3o encontrado.\n";
    } else {
        fread(&totalLocais, sizeof(int), 1, f);
        fread(locais, sizeof(Local), totalLocais, f);
        fclose(f);
        std::cout << "Locais restaurados.\n";
    }

    // Restaurar veículos
    f = fopen("dados/veiculos.bin", "rb");
    if (!f) {
        std::cout << "Arquivo veiculos.bin n\u00e3o encontrado.\n";
    } else {
        fread(&totalVeiculos, sizeof(int), 1, f);
        fread(veiculos, sizeof(Veiculo), totalVeiculos, f);
        fclose(f);
        std::cout << "Veículos restaurados.\n";
    }

    // Restaurar pedidos
    f = fopen("dados/pedidos.bin", "rb");
    if (!f) {
        std::cout << "Arquivo pedidos.bin n\u00e3o encontrado.\n";
    } else {
        fread(&totalPedidos, sizeof(int), 1, f);
        fread(pedidos, sizeof(Pedido), totalPedidos, f);
        fclose(f);
        std::cout << "Pedidos restaurados.\n";
    }
}
