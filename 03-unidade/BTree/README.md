# EDB II -  Implementação de árvore B para controle de estoque

Este projeto implementa uma Árvore B para armazenar e organizar informações de um sistema de controle de estoque. A árvore B permite a inserção, exclusão e busca de itens no estoque com base em um ID único.

## 1. Fluxograma da Função de Exclusão em uma Árvore B
![Image](https://github.com/user-attachments/assets/ae63c1c1-d189-4290-9ef8-a82c2bd26c1b)

---

## 2. Implementação Computacional 

A árvore B foi implementada para armazenar os itens de estoque, com as seguintes informações em cada nó:
- **ID do item**: chave única (inteiro).
- **Nome do item**: descrição (string).
- **Quantidade em estoque**: quantidade disponível (inteiro).

A árvore B possui as operações básicas:
- **Inserção**: Adiciona um novo item no sistema de controle de estoque.
- **Busca**: Permite buscar um item pelo ID (por exemplo, `buscar pelo ID 109` deve retornar `{109, "SSD", 30}`).
- **Exclusão**: Remove um item da árvore com base no ID (por exemplo, `excluir o ID 140`).
- **Visualização da Árvore**

## 3. Arquivo de Dados

Os dados dos itens de estoque a serem inseridos na árvore B estão disponíveis no arquivo [`./assets/dadosB.txt`](./assets/dadosB.txt). Este arquivo contém uma lista de itens no seguinte formato:

```text
{ID, "Nome", Quantidade}
```

## 4. Organização do Projeto

```plaintext
├── assets
│   └── dadosB.txt
├── include
│   ├── bTree.h
│   └── product.h
├── main.cpp
├── Makefile
├── program
├── README.md
└── src
    ├── bTree.cpp
    └── product.cpp
```

### Explicando a organização

- `/assets` - Contém arquivos auxiliares ou de dados usados no projeto.
  - `dadosB.txt`: Um arquivo de dados utilizado pela aplicação para alimentar a estrutura de árvore B.
- `/include` - Diretório que contém os arquivos de cabeçalho (headers) do projeto.
  - `bTree.h`: Declaração da classe da árvore B.
  - `product.h`: Declaração da classe relacionada a `product`.

- `/src` - Diretório que contém a implementação das classes e funções definidas nos cabeçalhos.
  - `bTree.cpp`: Implementação dos métodos relacionados à árvore B.
  - `product.cpp`: Implementação dos métodos relacionados à entidade `product`.

- **Arquivos da raiz**
  - `main.cpp`: Arquivo principal responsável pela execução do programa.
  - `Makefile`: Arquivo que automatiza o processo de compilação do projeto.
  - `README.md`: Documento que descreve o propósito, as funcionalidades e as instruções de uso do projeto.
  - `.gitignore`: Arquivo que especifica quais arquivos ou diretórios devem ser ignorados pelo sistema de controle de versão Git

## 5. Compilação e Execução

Para compilar e executar o programa, siga os passos abaixo:

1. **Compilação**:
   ```bash
    make
   ```

2. **Execução**:
   ```bash
    ./program
   ```
## 6. Vídeo

[Link do vídeo]()

## 7. Componentes e Listagem das tarefas realizadas por cada integrante

- [Felipe Augusto Lemos Barreto](https://github.com/felipe130520)
  - Produziu o fluxograma para a função de exclusão de uma informação em uma árvore B
  - Implementou a busca
- [Francisca Gabrielly Lopes Freire](https://github.com/gabrielly-freire)
  - Implementou  a leitura dos dados do arquivo txt
  - Ficou responsável pela organização do repositório
- [Gustavo Henrique Araujo de Sales Leite](https://github.com/Gustavohasleite)
  - Implementou a exclusão
- [João Lucas de Moraes Pereira](https://github.com/JJoaoll)
  - Criou a estrutura da árvore
  - Gravou o vídeo
- [Vitor Emanuel Rodrigues de Alencar](https://github.com/isVitorEmanuel)
  - Implementou a inserção
  - Implementou a visualização da árvore


