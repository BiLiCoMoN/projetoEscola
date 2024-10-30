#define MAX_ALUNOS_POR_DISCIPLINA 40

typedef struct dis {
    char nome[40];
    char codigo[6];
    int semestre;
    int professor;
    int alunos[TAM_ALUNO];
    int numAlunos; // Novo campo para rastrear o número de alunos matriculados
    int ativo;
} Disciplina;

// Função para matricular um aluno em uma disciplina
int matricularAluno(Disciplina listaDisciplina[], int qtdDisciplina, int matriculaAluno) {
    for (int i = 0; i < qtdDisciplina; i++) {
        if (listaDisciplina[i].ativo && listaDisciplina[i].numAlunos < MAX_ALUNOS_POR_DISCIPLINA) {
            for (int j = 0; j < TAM_ALUNO; j++) {
                if (listaDisciplina[i].alunos[j] == 0) { // Encontrou um slot vazio
                    listaDisciplina[i].alunos[j] = matriculaAluno;
                    listaDisciplina[i].numAlunos++;
                    return CAD_SUCESSO; // Matrícula realizada com sucesso
                }
            }
        }
    }
    return LISTA_CHEIA; // Não foi possível matricular o aluno
}

// Função para listar alunos com menos de 3 disciplinas
void listarAlunosComPoucasDisciplinas(Aluno listaAluno[], int qtdAluno, Disciplina listaDisciplina[], int qtdDisciplina) {
    for (int i = 0; i < qtdAluno; i++) {
        int numDisciplinas = 0;
        for (int j = 0; j < qtdDisciplina; j++) {
            for (int k = 0; k < listaDisciplina[j].numAlunos; k++) {
                if (listaDisciplina[j].alunos[k] == listaAluno[i].matricula) {
                    numDisciplinas++;
                    break;
                }
            }
        }
        if (numDisciplinas < 3) {
            printf("Matrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Número de disciplinas: %d\n", numDisciplinas);
            printf("--------------------------------------\n");
        }
    }
}

// Função para listar disciplinas com mais de 40 alunos
void listarDisciplinasComMuitosAlunos(Disciplina listaDisciplina[], int qtdDisciplina) {
    for (int i = 0; i < qtdDisciplina; i++) {
        if (listaDisciplina[i].numAlunos > 40) {
            printf("Nome da Disciplina: %s\n", listaDisciplina[i].nome);
            printf("Número de alunos: %d\n", listaDisciplina[i].numAlunos);
            printf("--------------------------------------\n");
        }
    }
}

// Função para detalhar uma disciplina e listar os alunos matriculados
void detalharDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno) {
    int codigoDisciplina;
    printf("Digite o código da disciplina para detalhes: ");
    scanf("%d", &codigoDisciplina);

    for (int i = 0; i < qtdDisciplina; i++) {
        if (listaDisciplina[i].ativo && strcmp(listaDisciplina[i].codigo, codigoDisciplina) == 0) {
            printf("Detalhes da Disciplina:\n");
            printf("Nome: %s\n", listaDisciplina[i].nome);
            printf("Código: %s\n", listaDisciplina[i].codigo);
            printf("Semestre: %d\n", listaDisciplina[i].semestre);
            printf("Professor: %d\n", listaDisciplina[i].professor);
            printf("Número de alunos matriculados: %d\n", listaDisciplina[i].numAlunos);
            printf("Alunos matriculados:\n");
            for (int j = 0; j < listaDisciplina[i].numAlunos; j++) {
                for (int k = 0; k < qtdAluno; k++) {
                    if (listaDisciplina[i].alunos[j] == listaAluno[k].matricula) {
                        printf("Matrícula: %d\n", listaAluno[k].matricula);
                        printf("Nome: %s\n", listaAluno[k].nome);
                        printf("--------------------------------------\n");
                        break;
                    }
                }
            }
            return;
        }
    }
    printf("Disciplina não encontrada ou não está ativa.\n");
}



-------------------------------------------------------
    #define MAX_ALUNOS_POR_DISCIPLINA 40
#define TAM_ALUNO 100 // Exemplo de tamanho máximo de alunos

typedef struct dis {
    char nome[40];
    char codigo[6];
    int semestre;
    int id_professor; // ID do professor que leciona a disciplina
    int alunos[TAM_ALUNO];
    int numAlunos; // Número de alunos matriculados
    int ativo;
} Disciplina;

typedef struct professor {
    int id;
    char nome[100];
} Professor;

// ... Outras funções existentes ...

// Função para listar professores com turmas com mais de 40 alunos
void listarProfessoresComTurmasGrandes(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor) {
    for (int i = 0; i < qtdDisciplina; i++) {
        if (listaDisciplina[i].numAlunos > MAX_ALUNOS_POR_DISCIPLINA && listaDisciplina[i].ativo) {
            for (int j = 0; j < qtdProfessor; j++) {
                if (listaDisciplina[i].id_professor == listaProfessor[j].id) {
                    printf("Professor: %s\n", listaProfessor[j].nome);
                    printf("Disciplina: %s\n", listaDisciplina[i].nome);
                    printf("Número de alunos: %d\n", listaDisciplina[i].numAlunos);
                    printf("--------------------------------------\n");
                    break; // Sai do loop após encontrar o professor correspondente
                }
            }
        }
    }
}

// ... Restante do código existente ...
