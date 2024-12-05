import streamlit as st
import math

class Equacao:
    def __init__(self, a, b, c):
        self.__a = a
        self.__b = b
        self.__c = c
    
    @property
    def a(self):
        return self.__a
    
    @a.setter
    def a(self, a):
        if a > 0:
            self.__a = a
        else:
            raise ValueError("Digite um valor valido")
    
    @property
    def b(self):
        return self.__b
    
    @a.setter
    def b(self, b):
        if b != "":
            self.__b = b
        else:
            raise ValueError("Digite um valor valido")
    
    @property
    def c(self):
        return self.__c
    
    @c.setter
    def c(self, c):
        if c != "":
            self.__c = c
        else:
            raise ValueError("Digite um valor valido")
    
    def delta(self):
        d = self.__b**2 - (4 * self.__a * self.__c)
        return d

    def y(self, x):
        y = self.__a * x * x + self.__b * x + self.__c
        return y

    def x1(self):
        if self.delta() >=0:
            return (-self.__b - math.sqrt(self.delta())) / (2 * self.__a)
        return None

    def x2(self):
        if self.delta() >= 0:
            return (-self.__b + math.sqrt(self.delta())) / (2 * self.__a)
        return None

    #def grafico(self):
        

    def __str__(self):
        return f"A = {self.__a} - B = {self.__b} C = {self.__c}"
    

    
