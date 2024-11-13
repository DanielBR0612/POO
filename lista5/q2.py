from datetime import datetime
from enum import Enum

class Pagamento(Enum):
    emAberto = 1
    pagoParcial = 2
    pago = 3

class Boleto:
    def __init__(self, codBarras, emisao: datetime, vencimento: datetime, valor):
        self.__codBarras = codBarras
        self.__dateEmissao = emisao
        self.__dateVencimento = vencimento
        self.__datePago = None
        self.__valorBoleto = valor
        self.__valorPago = 0
        self.__situacaoPagamento = Pagamento.emAberto

    def pagar(self, valorPago):
        self.__valorPago += valorPago
        self.__datePago = datetime.now()

        if self.__valorPago >= self.__valorBoleto:
            self.__situacaoPagamento = Pagamento.pago
        elif self.__valorPago > 0:
            self.__situacaoPagamento = Pagamento.pagoParcial
        else:
            self.__situacaoPagamento = Pagamento.emAberto
    
    def situacao(self):
        return self.__situacaoPagamento
    
    def ToString(self):
        return (f"Código de Barras: {self.__codBarras}\n"
                f"Data de Emissão: {self.__dateEmissao}\n"
                f"Data de Vencimento: {self.__dateVencimento}\n"
                f"Valor do Boleto: {self.__valorBoleto}\n"
                f"Data do Pagamento: {self.__datePago}\n"
                f"Valor Pago: {self.__valorPago}\n"
                f"Situação do Pagamento: {self.__situacaoPagamento.name}")

boleto = Boleto("123456789", datetime(2023, 11, 7), datetime(2023, 12, 7), 100.0)
print(boleto.ToString())
boleto.pagar(50)
print(boleto.situacao().name)
boleto.pagar(50)
print(boleto.situacao().name)
print(boleto.ToString())
