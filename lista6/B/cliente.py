import json

class Cliente:
    def __init__(self, id: int, n, e, f):
        self.__id = id
        self.__nome = n
        self.__email = e
        self.__fone = f
    
    def setID(self, id):
        if id >= 0:
            self.__id = id
        else:
            raise ValueError("Digite um id valido")
    
    def setNome(self, n):
        if n != "":
            self.__nome = n
        else:
            raise ValueError("Digite um nome valido")
    
    def setEmail(self, e):
        if e != "":
            self.__email = e
        else:
            raise ValueError("Digite um email valido")
    
    def setFone(self, f):
        if f != "":
            self.__fone = f
        else:
            raise ValueError("Digite um telefone valido")
    
    def getID(self):
        return self.__id
    def getNome(self):
        return self.__nome
    def getEmail(self):
        return self.__email
    def getFone(self):
        return self.__fone

    def __str__(self):
        return f"ID: {self.__id} - Nome: {self.__nome} - Email: {self.__email} - Telefone: {self.__fone}"
    
class Clientes:
    objetos = []

    @classmethod
    def inserir(cls, obj):
        cls.abrir()

        for x in cls.objetos:
            if x.id > id:
                id = x.id
        obj.id = id + 1

        cls.objetos.append(obj)

        cls.salvar()

    @classmethod
    def listar(cls):
        cls.abrir()

        return cls.objetos
    
    @classmethod
    def listarId(cls, id):
        cls.abrir()

        for x in cls.objetos:
            if x.id == id:
                return x
        return None
    
    @classmethod
    def atualizar(cls, obj):
        x = cls.listarId(obj.id)

        if x != None:
            x.nome = obj.nome
            x.email = obj.email
            x.fone = obj.fone
            
            cls.salvar()
    
    @classmethod
    def excluir(cls, obj):
        x = cls.listarId(obj.id)
        if x != None:
            cls.objetos.remove(x)
            cls.salvar()
    
    @classmethod
    def salvar():
        with open("clientes3.json", mode="w") as arquivo:
            clientes_json = json.dump(cls.objetos, arquivo, default= vars)

    @classmethod
    def abrir(cls):
        cls.objetos = []
        try:
            with open("clientes3.json", mode="r") as arquivo:
                clientes_json = json.load(arquivo)

                for obj in clientes_json:
                    c = Cliente(obj["id"], obj["nome"], obj["email"], obj["fone"])
                    cls.objetos.append(c)
        except FileNotFoundError:
            pass
    