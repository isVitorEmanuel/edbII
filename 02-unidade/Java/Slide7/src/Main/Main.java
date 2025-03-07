package Main;

import Entidades.Arvore;
import Aplicacoes.Metodos;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Arvore<String> arvore = new Arvore<>();
        Metodos<String> metodos = new Metodos<>();

        int opcao = 0;
        do {
            System.out.println("\n--- Menu AVL ---");
            System.out.println("1 - Inserir");
            System.out.println("2 - Buscar");
            System.out.println("3 - Remover");
            System.out.println("4 - Exibir (In-Ordem)");
            System.out.println("0 - Sair");
            System.out.print("Opção: ");
            opcao = sc.nextInt();
            sc.nextLine();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o ID (int) do nó: ");
                    int idInserir = sc.nextInt();
                    sc.nextLine(); 
                    System.out.print("Digite os dados (String) do nó: ");
                    String dados = sc.nextLine();
                    metodos.inserir(arvore, idInserir, dados);
                    System.out.println("Nó inserido com sucesso!");
                    break;

                case 2:
                    System.out.print("Digite o ID do nó a buscar: ");
                    int idBuscar = sc.nextInt();
                    sc.nextLine();
                    var resultado = metodos.buscar(arvore, idBuscar);
                    if (resultado != null) {
                        System.out.println("Nó encontrado: ID = " + resultado.getId() + ", Dados = " + resultado.getDados());
                    } else {
                        System.out.println("Nó não encontrado.");
                    }
                    break;

                case 3:
                    System.out.print("Digite o ID do nó a remover: ");
                    int idRemover = sc.nextInt();
                    sc.nextLine();
                    metodos.remover(arvore, idRemover);
                    System.out.println("Se o nó existia, foi removido.");
                    break;

                case 4:
                    System.out.println("Árvore em ordem: ");
                    exibirEmOrdem(arvore.getRaiz());
                    System.out.println();
                    break;

                case 0:
                    System.out.println("Saindo...");
                    break;

                default:
                    System.out.println("Opção inválida!");
                    break;
            }
        } while (opcao != 0);

        sc.close();
    }

    private static <T> void exibirEmOrdem(Entidades.No<T> raiz) {
        if (raiz != null) {
            exibirEmOrdem(raiz.getEsq());
            System.out.print("[" + raiz.getId() + ": " + raiz.getDados() + "] ");
            exibirEmOrdem(raiz.getDir());
        }
    }
}
