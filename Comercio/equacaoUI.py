import streamlit as st
from equacao import Equacao
import pandas as pd

class EquacaoUI:
    def main():
            st.header("Calculos de equções do segundo grau")
            a = st.text_input("informe o A: ")
            b = st.text_input("Informe o B: ")
            c = st.text_input("Informe o C: ")

            if st.button("Calcular "):
                e = Equacao(float(a), float(b), float(c))
                st.write(e)
                st.write(f"Delta = {e.delta()}")
                st.write(f"x1 = {e.x1()}")
                st.write(f"x2 = {e.x2()}")

                px = []
                py = []

                if Equacao.delta() >= 0:
                    x1 = Equacao.x1()
                    x2 = Equacao.x2()
                    d = x2 - x1
                    xmin = x1 - d/2
                    xmax = x2 + d/2
                    npontos = 8
                    d = (xmax - xmin) / npontos
                    x = xmin

                    while x < xmax:
                        px.append(x)
                        py.append(Equacao.y(x))
                        x += d
                    px.append(xmax)
                    py.append(Equacao.y(xmax))
                    dic = {"x" : px, "y" : py}
                    chart_data = pd.DataFrame()
                    st.line_chart(chart_data)

