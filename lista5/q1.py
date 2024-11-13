from datetime import datetime 

class Paciente:
    def __init__(self, nome, cpf, telefone, nascimento: datetime):
        self.__nome = nome
        self.__cpf = cpf
        self.__telefone = telefone
        self.__nascimento = nascimento
    
    def idade(self):
        today = datetime.today()
        age = today.year - self.__nascimento.year - ((today.month, today.day) < (self.__nascimento.month, self.__nascimento.day))
        
        return f"{age} anos"
    
    def __str__(self):
        return f"Nome: {self.__nome}, CPF: {self.__cpf}, Telefone: {self.__telefone}, Nascimento: {self.__nascimento.strftime('%d/%m/%Y')}"
    

nascimento = datetime.strptime(input("Digite o dia que vc nasceu: "), "%d/%m/%Y")

paciente = Paciente("Daniel Braga", "100.506.574-88", "1234-5678", nascimento)

print(paciente.idade())
print(paciente)