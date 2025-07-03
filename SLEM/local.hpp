#ifndef LOCAL_HPP
#define LOCAL_HPP

struct Local {
    char nome[100];
    int x;
    int y;
};

void menuLocais();
void cadastrarLocal();
void listarLocais();
void atualizarLocal();
void excluirLocal();

extern Local locais[100];
extern int totalLocais;

#endif
