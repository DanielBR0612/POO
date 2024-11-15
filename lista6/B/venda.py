import json
from datetime import datetime
from cliente import Cliente, Clientes

class Venda:
    def __init__(self, id: int):
        self.__id = id
        self.__data = None
        self.__carrinho = None
        self.__total = 0
        self.__idCliente = Cliente.getID()
    
    def setID(self, id):
        if id >= 0:
            self.__id = id
        else:
            raise ValueError("Digite um id valido")
    
    def setData(self, )