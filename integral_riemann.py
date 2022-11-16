# Soma de Rieman

import math
from calcula_polinomios import leitura_px,fx
#import calcula_polinomios as pol

def soma_rieman():
    print('Polinomios - Soma de Rieman')
    grau = int(input('Grau do px: '))

    px = leitura_px(grau)
    print(px)

    a = float(input('a='))
    b = float(input('b='))
    n = float(input('n='))
    i = 0

    ax = (b-a)/n
    soma=0.0
    print(ax)

    # calcula a soma de rieman 
    while i<n:
        x= a+(ax*i)
        soma = soma + fx(px,grau,x)*ax
        i=i+1
   
    print(soma)