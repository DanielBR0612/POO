def aprovado(x,y):
     media = ((x * 2) + (y * 3)) / 5

     if media >= 60:
          return True
     else:
          return False
     
x, y = map(int, input("Digite a nota dos dois bimestres: ").split())

if aprovado(x,y):
     print("O aluno foi aprovado")
else:
     print("O aluno esta de prova final")