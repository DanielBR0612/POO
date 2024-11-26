from cliente import Cliente, Clientes

class UI:
    def menu():
        print("Cadastro de Clientes")
        print("1 - Cliente, 2 - Categoria, 9 - Sair")

        return int(input("Informe a opcao: "))
    
    def menu_cliente():
        print("Cadastro de Clientes")
        print("1 - Inserir, 2 - Listar, 3 - Atualizar, 4 - Excluir, 9 - Sair")

        return int(input("Informe a opcao: "))
    def main():
        op = 0
        while op != 9:
            op = UI.menu()
            match op: 
                case 1:
                    op = UI.menu_cliente()
                    
                    if(op == 1):
                        UI.inserir_cliente()
                    if op == 2:
                        UI.listar_clientes()
                    if op == 3:
                        UI.atualizar_cliente()
                    if op == 4:
                        UI.excluir_cliente()
                    break
                case 2:
                    UI.listar_clientes()

    @classmethod
    def inserir_cliente(cls):
        nome = input("Digite o nome: ")
        email = input("Digite o email: ")
        fone = input("Digite o telefone: ")

        cliente = Cliente(0, nome, email, fone)

        Clientes.inserir(cliente)
    
    @classmethod
    def listar_clientes(cls):
        clientes = Clientes.listar()
        if len(clientes) == 0:
            print("Nenhum cliente cadastrado")
        else:
            for cliente in clientes:
                print(cliente)
    
    @classmethod
    def atualizar_cliente(cls):
        id = int(input("Informe o id do cliente a ser alterado"))
        nome = input("Informe o novo nome")
        email = input("Informe o novo email")
        fone = input("Informe o novo telefone")

        cliente = Cliente(id, nome, email, fone)

        Clientes.atualizar(cliente)
    
    @classmethod
    def excluir_cliente(cls):
        cls.listar_clientes()

        id = int(input("Informe o id a ser excluido"))
        cliente = Cliente(id, "", "", "")

        Clientes.excluir(cliente)

UI.main()