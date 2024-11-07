from datetime import datetime, timedelta

a = datetime.now()

print(a, type(a))

b = datetime.strptime("06/12/2004 21:40", "%d/%m/%Y %H:%M")
print(b)

c = datetime.strptime(input("Digite o dia que vc nasceu: "), "%d/%m/%Y")

print(c)
