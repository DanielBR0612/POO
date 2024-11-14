import json

class Categoria:
    def __init__(self, id, descricao):
        self.__id = id
        self.__descricao = descricao
    
    def __str__(self):
        return f"ID: {self.__id} - Descricao: {self.__descricao}"

    @property
    def getID(self):
        return self.__id

    def setID(self, id):
        if id >= 0:
            self.__id = id
        else:
            raise ValueError("Digite um ID valido")
    
    @property
    def getDescricao(self):
        return self.__descricao

    def setDescricao(self, d):
        if d != "":
            self.__descricao
        else:
            raise ValueError("Digite uma descricao valida")

class Categorias:
    objetos = []

    @classmethod
    def inserir(cls, obj):
        cls.abrir()

        id = 0
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
            x.descricao = obj.descricao
           
            cls.salvar()
    
    @classmethod
    def excluir(cls, obj):
        x = cls.listarId(obj.id)
        if x != None:
            cls.objetos.remove(x)
            cls.salvar()

    @classmethod
    def salvar(cls):
        with open("categorias.json", mode="w") as arquivo:
            json.dump(cls.objetos, arquivo ,default = vars)

    @classmethod
    def abrir(cls):
        cls.objetos = []
        try:
            with open("clientes.json", mode = "r") as arquivo:
                categorias_json = json.load(arquivo)

                for obj in categorias_json:
                    c = Categoria(obj["_Categoria__id"], obj["_Categoria__descricao"])
                    cls.objetos.append(c)
        except KeyError:
            pass
        except FileNotFoundError:
            pass