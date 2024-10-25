//DECLARAÇÕES
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM_ALUNO 3
#define TAM_PROFESSOR 3
#define TAM_DISCIPLINA 3
#define CAD_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define EXCLUSAO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define SEXO_INVALIDO -6

int menuGeral();
int menuAluno();
typedef struct alu{
    int matricula;
    char sexo;
    char nome[40];
    char nascimento[11];    //formato: dd/mm/aaaa
    char cpf[12];           //formato: 000.000.000-00
    int ativo;
 } Aluno;
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);

typedef struct pro{
    int matricula;
    char sexo;
    char nome[40];
    char nascimento[11];    //formato: dd/mm/aaaa
    char cpf[12];           //formato: 000.000.000-00
    int ativo;
 } Professor;
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

typedef struct dis{
    char nome[40];
    char codigo[6];
    int semestre;
    int professor;
    int alunos[3];
    int ativo;
 } Disciplina;

//FUNÇÕES ALUNO
int menuGeral(){
    int opcao;
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n\n");
    scanf("%d", &opcao);
    return opcao;
}

int menuAluno(){
    int opcaoAluno;
    printf("Módulo Aluno\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}

int cadastrarAluno(Aluno listaAluno[], int qtdAluno){
    int matricula;
    printf("Cadastrar Aluno\n");

    if (qtdAluno >= TAM_ALUNO) {
        return LISTA_CHEIA;
    }
    else {
        printf("Digite a matrícula: ");
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        else {
            listaAluno[qtdAluno].matricula = matricula;

            printf("Digite o nome: ");
            getchar();
            fgets(listaAluno[qtdAluno].nome, sizeof(listaAluno[qtdAluno].nome), stdin);
            listaAluno[qtdAluno].nome[strcspn(listaAluno[qtdAluno].nome, "\n")] = 0;
            //scanf(" %[^\n]", listaAluno[qtdAluno].nome);

            printf("Digite o sexo (M/F): ");
            char sexo[3];
            fgets(sexo, sizeof(sexo), stdin);
            sexo[strcspn(sexo, "\n")] = 0;
            sexo[0] = toupper(sexo[0]);

            if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                return SEXO_INVALIDO; // Defina essa constante
            }
            listaAluno[qtdAluno].sexo = sexo[0];

            printf("Digite a data de nascimento: ");
            scanf(" %[^\n]", listaAluno[qtdAluno].nascimento);

            printf("Digite o cpf: ");
            scanf(" %[^\n]", listaAluno[qtdAluno].cpf);

            listaAluno[qtdAluno].ativo = 1;
            return CAD_SUCESSO;
        }
    }
}

void listarAluno(Aluno listaAluno[], int qtdAluno){
    int achou=0;
    printf("Listar Aluno\n");
    if (qtdAluno==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i = 0; i < qtdAluno; i++) { // Exibir apenas os alunos cadastrados
            if (listaAluno[i].ativo == 1) {
            printf("Matrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("Data de Nascimento: %s\n", listaAluno[i].nascimento);
            printf("CPF: %s\n", listaAluno[i].cpf);
            printf("--------------------------------------\n");
            achou++;}
            }
        if (achou==0) { printf("Lista vazia!\n"); }
    }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno){
    printf("Atualizar Aluno\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdAluno; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo){ //atualização
                /*
                listaAluno[i].matricula = matricula;
                printf("Digite a nova matricula\n");
                int novamatricula;
                scanf("%d", &novamatricula);
                listaAluno[i].matricula = novamatricula;
                */

                printf("Aluno Encontrado!\n");
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome atual: %s\n", listaAluno[i].nome);
                printf("Sexo atual: %c\n", listaAluno[i].sexo);
                printf("Data de nascimento atual: %s\n", listaAluno[i].nascimento);
                printf("CPF atual: %s\n", listaAluno[i].cpf);

                printf("Digite o novo nome: ");
                getchar();
                fgets(listaAluno[i].nome, sizeof(listaAluno[i].nome), stdin);
                listaAluno[i].nome[strcspn(listaAluno[i].nome, "\n")] = 0;

                printf("Digite o sexo atualizado: ");
                char sexo[3];
                fgets(sexo, sizeof(sexo), stdin);
                sexo[strcspn(sexo, "\n")] = 0;
                sexo[0] = toupper(sexo[0]);

                if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                    printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                    return SEXO_INVALIDO; // Defina essa constante
                }
                listaAluno[i].sexo = toupper(sexo[0]);

                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                scanf(" %[^\n]", listaAluno[i].nascimento);

                printf("Digite o novo cpf (000.000.000-00): ");
                scanf(" %[^\n]", listaAluno[i].cpf);

                achou =1;
                break;
            }
        }
        if (achou) {
            printf("Aluno atualizado com sucesso!\n"); }
        else { printf("Matrícula inexistente!\n"); }
    }
}

int excluirAluno(Aluno listaAluno[], int qtdAluno){
    printf("Excluir Aluno\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdAluno; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaAluno[i].matricula){
                //exclusão lógica
                listaAluno[i].ativo = 0;
                for (int j = i; j < qtdAluno -1; j++){                      //SHIFT
                    listaAluno[j].matricula = listaAluno[j+1].matricula;    //SHIFT
                    listaAluno[j].sexo = listaAluno[j+1].sexo;              //SHIFT
                    listaAluno[j].ativo = listaAluno[j+1].ativo;            //SHIFT
                }
                achou =1;
                break;
            }
        }
        if (achou) { return EXCLUSAO_SUCESSO; }
        else { return MATRICULA_INEXISTENTE; }
    }
}

//FUNÇÕES PROFESSOR
int menuProfessor(){
    int opcaoProfessor;
    printf("Módulo Professor\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    scanf("%d", &opcaoProfessor);
    return opcaoProfessor;
}

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor){
    int matricula;
    printf("Cadastrar Professor\n");

    if (qtdProfessor >= TAM_PROFESSOR) {
        return LISTA_CHEIA;
    }
    else {
        printf("Digite a matrícula: ");
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        else {
            listaProfessor[qtdProfessor].matricula = matricula;

            printf("Digite o nome: ");
            getchar();
            fgets(listaProfessor[qtdProfessor].nome, sizeof(listaProfessor[qtdProfessor].nome), stdin);
            listaProfessor[qtdProfessor].nome[strcspn(listaProfessor[qtdProfessor].nome, "\n")] = 0;
            //scanf(" %[^\n]", listaAluno[qtdAluno].nome);

            printf("Digite o sexo (M/F): ");
            char sexo[3];
            fgets(sexo, sizeof(sexo), stdin);
            sexo[strcspn(sexo, "\n")] = 0;
            sexo[0] = toupper(sexo[0]);

            if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                return SEXO_INVALIDO; // Defina essa constante
            }
            listaProfessor[qtdProfessor].sexo = sexo[0];

            printf("Digite a data de nascimento: ");
            scanf(" %[^\n]", listaProfessor[qtdProfessor].nascimento);

            printf("Digite o cpf: ");
            scanf(" %[^\n]", listaProfessor[qtdProfessor].cpf);

            listaProfessor[qtdProfessor].ativo = 1;
            return CAD_SUCESSO;
        }
    }
}

void listarProfessor(Professor listaProfessor[], int qtdProfessor){
    int achou=0;
    printf("Listar Professor\n");
    if (qtdProfessor==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i = 0; i < qtdProfessor; i++) { // Exibir apenas os alunos cadastrados
            if (listaProfessor[i].ativo == 1) {
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                printf("Nome: %s\n", listaProfessor[i].nome);
                printf("Sexo: %c\n", listaProfessor[i].sexo);
                printf("Data de Nascimento: %s\n", listaProfessor[i].nascimento);
                printf("CPF: %s\n", listaProfessor[i].cpf);
                printf("--------------------------------------\n");
                achou++;
            }
        }
        if (achou==0) { printf("Lista vazia!\n"); }
    }
}

int atualizarProfessor(Professor listaProfessor[], int qtdProfessor){


    printf("Atualizar Professor!\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdProfessor; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo){ //atualização
                /*
                listaAluno[i].matricula = matricula;
                printf("Digite a nova matricula\n");
                int novamatricula;
                scanf("%d", &novamatricula);
                listaAluno[i].matricula = novamatricula;
                */

                printf("Professor Encontrado!\n");
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                printf("Nome atual: %s\n", listaProfessor[i].nome);
                printf("Sexo atual: %c\n", listaProfessor[i].sexo);
                printf("Data de nascimento atual: %s\n", listaProfessor[i].nascimento);
                printf("CPF atual: %s\n", listaProfessor[i].cpf);

                printf("Digite o novo nome: ");
                getchar();
                fgets(listaProfessor[i].nome, sizeof(listaProfessor[i].nome), stdin);
                listaProfessor[i].nome[strcspn(listaProfessor[i].nome, "\n")] = 0;

                printf("Digite o sexo atualizado: ");
                char sexo[3];
                fgets(sexo, sizeof(sexo), stdin);
                sexo[strcspn(sexo, "\n")] = 0;
                sexo[0] = toupper(sexo[0]);

                if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                    printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                    return SEXO_INVALIDO; // Defina essa constante
                }
                listaProfessor[i].sexo = toupper(sexo[0]);

                printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                scanf(" %[^\n]", listaProfessor[i].nascimento);

                printf("Digite o novo cpf (000.000.000-00): ");
                scanf(" %[^\n]", listaProfessor[i].cpf);

                achou =1;
                break;
            }
        }
        if (achou) {
            printf("Professor atualizado com sucesso!\n"); }
        else { printf("Matrícula inexistente!\n"); }
    }
}

int excluirProfessor(Professor listaProfessor[], int qtdProfessor){
    printf("Excluir Professor\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdProfessor; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaProfessor[i].matricula){
                //exclusão lógica
                listaProfessor[i].ativo = 0;
                for (int j = i; j < qtdProfessor -1; j++){                      //SHIFT
                    listaProfessor[j].matricula = listaProfessor[j+1].matricula;    //SHIFT
                    listaProfessor[j].sexo = listaProfessor[j+1].sexo;              //SHIFT
                    listaProfessor[j].ativo = listaProfessor[j+1].ativo;            //SHIFT
                }
                achou =1;
                break;
            }
        }
        if (achou) { return EXCLUSAO_SUCESSO; }
        else { return MATRICULA_INEXISTENTE; }
    }
}

//FUNÇÕES DISCIPLINA
int menuDisciplina(){
    int opcaoDisciplina;
    printf("Módulo Disciplina\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplina\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Excluir Disciplina\n");
    scanf("%d", &opcaoDisciplina);
    return opcaoDisciplina;
}

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    int codigo;
    printf("Cadastrar Disciplina!\n");

    if (qtdDisciplina >= TAM_DISCIPLINA) {
        return LISTA_CHEIA;
    }
    else {
        printf("Digite o nome da disciplina:");
        getchar();
        fgets(listaDisciplina[qtdDisciplina].nome, sizeof(listaDisciplina[qtdDisciplina].nome), stdin);
        listaDisciplina[qtdDisciplina].nome[strcspn(listaDisciplina[qtdDisciplina].nome, "\n")] = 0;

        printf("Digite o código da disciplina:");
        getchar();
        fgets(listaDisciplina[qtdDisciplina].codigo, sizeof(listaDisciplina[qtdDisciplina].codigo), stdin);
        listaDisciplina[qtdDisciplina].codigo[strcspn(listaDisciplina[qtdDisciplina].codigo, "\n")] = 0;

        printf("Digite a qual semestre ela pertence: \n");
        scanf(" %d", &listaDisciplina[qtdDisciplina].semestre);

        printf("Qual a matricula do professor que a leciona: \n");
        scanf(" %d", &listaDisciplina[qtdDisciplina].professor);

        listaDisciplina[qtdDisciplina].ativo = 1;

        return CAD_SUCESSO;
    }

}

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    int achou = 0;
    printf("Listar Disciplinas\n");
    if (qtdDisciplina == 0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i = 0; i < qtdDisciplina; i++){
            if (listaDisciplina[i].ativo == 1){
                printf("Nome: %s\n", listaDisciplina[i].nome);
                printf("Código: %s\n", listaDisciplina[i].codigo);
                printf("Semestre: %d\n", listaDisciplina[i].semestre);
                printf("Professor: %d\n", listaDisciplina[i].professor);
                printf("--------------------------------------\n");
                achou++;
            }
        }
        if (achou==0) { printf("Lista vazia!\n"); }
    }
}

int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){

}


int main() {
    setlocale(LC_ALL, "Portuguese");

    Aluno listaAluno[TAM_ALUNO] = {0}; // Inicializar a lista de alunos
    Professor listaProfessor[TAM_PROFESSOR] = {0}; // Inicializar a lista de professores
    Disciplina listaDisciplina[TAM_DISCIPLINA] = {0}; // Inicializar a lista de disciplinas
    int opcao, opcaoAluno, opcaoProfessor, opcaoDisciplina, sair = 0;
    int qtdAluno = 0; // Inicializar a quantidade de alunos
    int qtdProfessor = 0;
    int qtdDisciplina = 0;

    while (!sair) {
        opcao = menuGeral();
        switch (opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                int sairAluno = 0;

                while (!sairAluno) {
                    opcaoAluno = menuAluno();
                    switch (opcaoAluno) {
                        case 0: {
                            sairAluno = 1;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarAluno(listaAluno, qtdAluno);
                            if (retorno == LISTA_CHEIA){ printf("Lista de alunos cheia!\n"); }
                            else if (retorno == MATRICULA_INVALIDA) { printf("Matrícula Inválida!\n"); }
                            else { printf("Cadastrado com sucesso!\n");
                            qtdAluno++;
                            }
                            break;
                        }
                        case 2: {
                            listarAluno(listaAluno, qtdAluno);
                            break;
                        }
                        case 3: {
                            atualizarAluno(listaAluno, qtdAluno);
                            break;
                        }
                        case 4: {
                            int retorno = excluirAluno(listaAluno, qtdAluno);
                                if (retorno == EXCLUSAO_SUCESSO) {  printf("Aluno excluído com sucesso\n");
                                qtdAluno--;
                                }
                                else { printf("Matrícula inexistente!\n"); }
                            break;
                        }
                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    } // fim do switch Aluno
                } // fim do while Aluno
                break;
            }
            case 2: {
                int sairProfessor = 0;

                while (!sairProfessor) {
                    opcaoProfessor = menuProfessor();
                    switch (opcaoProfessor) {
                        case 0: {
                            sairProfessor = 1;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);
                            if (retorno == LISTA_CHEIA){ printf("Lista de professores cheia!\n"); }
                            else if (retorno == MATRICULA_INVALIDA) { printf("Matrícula Inválida!\n"); }
                            else { printf("Cadastrado com sucesso!\n");
                            qtdProfessor++;
                            }
                            break;
                        }
                        case 2: {
                            listarProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 3: {
                            atualizarProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 4: {
                            int retorno = excluirProfessor(listaProfessor, qtdProfessor);
                                if (retorno == EXCLUSAO_SUCESSO) {  printf("Professor excluído com sucesso\n");
                                qtdAluno--;
                                }
                                else { printf("Matrícula inexistente!\n"); }
                            break;
                        }
                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    } // fim do switch Aluno
                } // fim do while Aluno
                break;
            }
            case 3: {
                int sairDisciplina = 0;

                while(!sairDisciplina){
                    opcaoDisciplina = menuDisciplina();
                    switch (opcaoDisciplina){
                        case 0: {
                            sairDisciplina = 1;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
                            if (retorno == LISTA_CHEIA){
                                printf("Lista de disciplinas cheia!\n");
                                break;
                            }
                            if (retorno == CAD_SUCESSO) {
                                printf("Disciplina cadastrada com sucesso!\n");
                                qtdDisciplina++;
                            }
                            break;
                        }
                        case 2: {
                            listarDisciplina(listaDisciplina, qtdDisciplina);
                            break;
                        }



                    }



                }
                break;
            }
            default: {
                printf("Opção inválida!\n");
                break;
            }
        } // fim do switch
    } // fim do while

    return 0;
}
