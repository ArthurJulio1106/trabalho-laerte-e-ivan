#ifndef PEDIDO_HPP
#define PEDIDO_HPP

struct Pedido {
    int id;
    char origem[100];
    char destino[100];
    float peso;
};

void menuPedidos();
void cadastrarPedido();
void listarPedidos();
void atualizarPedido();
void excluirPedido();

extern Pedido pedidos[100];
extern int totalPedidos;

#endif
