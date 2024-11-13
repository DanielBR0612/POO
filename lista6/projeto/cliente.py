import json

class Cliente:
    def __init__(self, id: int, n, e, f):
        self.id = id
        self.nome = n
        self.email = e
        self.fone = f
    
    def __str__(self):
        return f"id: {self.id}; nome: {self.nome}; email: {self.email}; fone: {self.fone}"

class Clientes:
    objetos = []

    @classmethod
    def inserir(cls, obj: Cliente):
        cls.abrir()
        #calcula o id do objeto
        id = 0
        for x in cls.objetos:
            if x.id > id:
                id = x.id
        obj. id = id + 1

        cls.objetos.append(obj)
        cls.salvar()
    
    @classmethod
    def Listar(cls):
        cls.abrir()
        return cls.objetos
    
    @classmethod
    def listarID(id: int):
        for cliente in Clientes.objetos:
            if cliente.id == id:
                return cliente
    
    @classmethod
    def atualizar(cls, obj: Cliente):
        cls.abrir()

        for x in cls.objetos:
            if x.id == obj.id:
                x.nome = obj.nome
                x.email = obj.email
                x.fone = obj.fone
        cls.salvar()        
    @classmethod
    def excluir(obj: Cliente):
        Clientes.objetos = [cliente for cliente in Clientes.objetos if cliente.id != obj.id]

    @classmethod
    def salvar(cls):
        # open - cria e abre  arquivo clientes.json
        # vars - converte um objeto em dicionario
        # dump - pega a lista de objetos e salva no arquivo
        with open("clientes2.json", mode="w") as arquivo:
            json.dump(cls.objetos, arquivo, default= vars)

    @classmethod
    def abrir(cls):
        # esvazia a lista
        cls.objetos = []
        with open("clientes2.json", mode="r") as arquivo:
            # abre o arquivo com a lista de dicionarios 
            clientes_json = json.load(arquivo)
            for obj in clientes_json:
                # recupera cada dicionario e cria um objeto
                c = Cliente(obj["id"], obj['nome'], obj['email'], obj['fone'])
                #insere o objeto na lista
                cls.objetos.append(c)

Clientes.salvar()  

Clientes.abrir()  
for cliente in Clientes.Listar():
    print(cliente)
