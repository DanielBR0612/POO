import streamlit as st
from retanguloUI import RetanguloUI
from equacaoUI import EquacaoUI

op = st.sidebar.selectionbox("Menu", ["Retangulo", "Equacao"])

if op == "Retangulo": RetanguloUI.main()
if op == "Equacao": EquacaoUI.main()


#st.header("POO em python com st")

#if st.button("clique aqui"):
#    st.write("bem vindo ao st")
