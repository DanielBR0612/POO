from datetime import datetime

class Item:
    def __init__(self, produto, qtd, preco):
        self.__produto = produto
        self.__qtd = qtd
        self.__preco = preco

    @property
    def produto(self):
        return self.__produto

    @produto.setter
    def produto(self, valor):
        if valor != "":
            self.__produto = valor
        else:
            raise ValueError("Digite um produto válido")

    @property
    def qtd(self):
        return self.__qtd

    @qtd.setter
    def qtd(self, valor):
        if valor >= 0:
            self.__qtd = valor
        else:
            raise ValueError("Digite uma quantidade válida")

    @property
    def preco(self):
        return self.__preco

    @preco.setter
    def preco(self, valor):
        if valor >= 0:
            self.__preco = valor
        else:
            raise ValueError("Digite um preço válido")

    def total(self):
        return self.__qtd * self.__preco

    def __str__(self):
        return f"Produto: {self.__produto} - Quantidade: {self.__qtd} - Preço: {self.__preco:.2f}"


class Carrinho:
    def __init__(self, cliente, data):
        self.__cliente = cliente
        self.__data = data
        self.__itens = []

    @property
    def cliente(self):
        return self.__cliente

    @cliente.setter
    def cliente(self, valor):
        if valor != "":
            self.__cliente = valor
        else:
            raise ValueError("Digite um cliente válido")

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, valor):
        self.__data = valor

    def inserir(self, item):
        self.__itens.append(item)

    def remover(self, item):
        if item in self.__itens:
            self.__itens.remove(item)

    def total(self):
        return sum(item.total() for item in self.__itens)

    def listar(self):
        for item in self.__itens:
            print(item)

    def __str__(self):
        return f"Cliente: {self.__cliente}, Data: {self.__data}, Número de Itens: {len(self.__itens)}, Total do Carrinho: {self.total():.2f}"


# Criando objetos Item
item1 = Item("Notebook", 1, 3000.0)
item2 = Item("Mouse", 2, 50.0)
item3 = Item("Teclado", 1, 150.0)

# Criando um carrinho
carrinho = Carrinho("Daniel Braga", "26/11/2024")

# Inserindo itens no carrinho
carrinho.inserir(item1)
carrinho.inserir(item2)
carrinho.inserir(item3)

# Listando itens
print("Itens no carrinho:")
carrinho.listar()

# Removendo um item
carrinho.remover(item2)

# Exibindo os dados do carrinho
print("\nDados do carrinho após remoção:")
print(carrinho)
