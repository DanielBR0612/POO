class Item:
    def __init__(self, prod, qtd, preco):
        self.__produto = prod
        self.__qtd = qtd
        self.__preco = preco
    
    @property
    def produto(self):
        return self.__produto
    
    @produto.setter
    def produto(self, p):
        if p != "":
            self.__produto = p
        else:
            raise ValueError("Digite um produto valido")
        
    @property
    def qtd(self):
        return self.__qtd
    
    @qtd.setter
    def qtd(self, qtd):
        if qtd >= 0:
            self.__qtd = qtd
        else:
            raise ValueError("Digite um produto valido")

    @property
    def preco(self):
        return self.__preco
    
    @preco.setter
    def produto(self, preco):
        if preco >= 0:
            self.__preco = preco
        else:
            raise ValueError("Digite um produto valido")
    
    def total(self):
        return self.__preco * self.__qtd
    
    def __str__(self):
        return f"Produto: {self.__produto} - Quantidade: {self.__qtd} - Preco: {self.__preco}"
    
class Carrinho:
    def __init__(self, c, d):
        self.__cliente = c
        self.__data = d
        self.__itens = []
    
    @property
    def cliente(self):
        return self.__cliente

    @cliente.setter
    def cliente(self, c):
        if c != "":
            self.__cliente = c
        else:
            raise ValueError("Digite um cliente valido")
    
    @property 
    def data(self):
        return self.__data

    @data.setter
    def data(self, d):
        self.__data = d
    
    def inserir(self, item):
        self.__itens.append(item)
    
    def remover(self, item):
        if item in self.__itens:
            self.__itens.remove(item)
    
    def listar(self):
        for item in self.__itens:
            print(item)

    def total(self):
        return sum(item.total() for item in self.__itens)

    def __str__(self):
        return f"Cliente: {self.__cliente}, Data: {self.__data}, Número de Itens: {len(self.__itens)}, Total do Carrinho: {self.total():.2f}"

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