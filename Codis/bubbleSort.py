from easyinput import read
def Bubble_Sort(llista):
    for i in range(n-1):
        for j in range(n-i-1):
            if llista[j] > llista[j+1]:
                llista[j], llista[j + 1] = llista[j + 1], llista[j]
    llista_ordenada = []
    
    for i in range(n):
        llista_ordenada.append(llista[i])
    
    print(llista_ordenada)

n = read(int)
llista = []

for i in range(n):
    x = read(int)
    llista.append(x)

Bubble_Sort(llista)









                







