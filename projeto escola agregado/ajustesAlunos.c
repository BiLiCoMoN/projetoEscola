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
