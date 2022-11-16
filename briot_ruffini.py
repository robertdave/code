# Briot-Ruffini

print('Polinomios  - Briot-Ruffini')
grau = int(input('Grau do px: '))

px = []
for i in range(grau+1):
   xi = float(input('Elemento: '))
   px.append(xi)

print(px)

a = float(input('a, x-a: '))
print(a)

j=0
tx = []
tx.append(px[0])
while j<grau:
   tx.append(tx[j]*a + px[j+1])
   j = j+1

print (tx)
print ('resto: ',tx[grau])