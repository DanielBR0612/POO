import json

class Cliente:
    def __init__(self, id: int, n, e, f):
        self.__id = id
        self.__nome = n
        self.__email = e
        self.__fone = f
    
    def __str__(self):
        return f"id: {self.__id}; nome: {self.__nome}; email: {self.__email}; fone: {self.__fone}"

    @property
    def id(self):
        return self.__id

    @property
    def nome(self):
        return self.__nome

    @property
    def email(self):
        return self.__email

    @property
    def fone(self):
        return self.__fone

class Clientes:
    objetos = []

    @staticmethod
    def inserir(obj: Cliente):
        Clientes.objetos.append(obj)
    
    @staticmethod
    def Listar():
        return Clientes.objetos
    
    @staticmethod
    def listarID(id: int):
        for cliente in Clientes.objetos:
            if cliente.id == id:
                return cliente
    
    @staticmethod
    def atualizar(obj: Cliente):
        for i, cliente in enumerate(Clientes.objetos):
            if cliente.id == obj.id:
                Clientes.objetos[i] = obj
                break

    @staticmethod
    def excluir(obj: Cliente):
        Clientes.objetos = [cliente for cliente in Clientes.objetos if cliente.id != obj.id]

    @staticmethod
    def salvar():
        with open("clientes2.json", mode="w") as arquivo:
            json.dump([{'id': cliente.id, 'nome': cliente.nome, 'email': cliente.email, 'fone': cliente.fone} for cliente in Clientes.objetos], arquivo)

    @staticmethod
    def abrir():
        with open("clientes2.json", mode="r") as arquivo:
            clientes_json = json.load(arquivo)
            Clientes.objetos = []  
            for obj in clientes_json:
                c = Cliente(obj["id"], obj['nome'], obj['email'], obj['fone'])
                Clientes.objetos.append(c)

cliente1 = Cliente(1, "Braga", "gilbert@example.com", "1234-5678")
cliente2 = Cliente(2, "Eduardo", "eduardo@example.com", "9876-5432")
cliente3 = Cliente(3, "Daniel", "daniel@example.com", "5555-5555")

Clientes.inserir(cliente1)
Clientes.inserir(cliente2)
Clientes.inserir(cliente3)

Clientes.salvar()  

Clientes.abrir()  
for cliente in Clientes.Listar():
    print(cliente)
