
# Serie de Leibniz

def calc_pi(n_termos):
    numerador = 4
    denominador = 1
    operacao = 1
    pi = 0

    for _ in range(n_termos):
        pi+= operacao * (numerador / denominador)
        denominador += 2.0
        operacao *= -1.0
    
    return pi