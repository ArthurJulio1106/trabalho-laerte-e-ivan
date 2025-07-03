#include <iostream>
#include "Local.hpp"
#include "Veiculo.hpp"
#include "Pedido.hpp"
#include "Rota.hpp"
#include "Arquivo.hpp"

int main() {
    int opcao;
    do {
        std::cout << "\n=== Sistema SLEM ===\n"
                  << "1 - Gerenciar Locais\n"
                  << "2 - Gerenciar Veículos\n"
                  << "3 - Gerenciar Pedidos\n"
                  << "4 - Calcular Rota\n"
                  << "5 - Backup de Dados\n"
                  << "6 - Restaurar Dados\n"
                  << "0 - Sair\n"
                  << "Escolha: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: menuLocais(); break;
            case 2: menuVeiculos(); break;
            case 3: menuPedidos(); break;
            case 4: calcularRota(); break;
            case 5: salvarBackup(); break;
            case 6: restaurarBackup(); break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
