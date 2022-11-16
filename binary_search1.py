# Implementa pesquisa binária iterativamente.

def pesquisa_binaria(A, item):
    
    esquerda = 0
    direita = len(A) - 1 
    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        if A[meio] < item:
            esquerda = meio + 1
        elif A[meio] > item:
            direita = meio - 1
        else: 
            return meio
    return -1