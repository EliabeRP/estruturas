import time

arquivos = [
  "num.1000.1.in",
  "num.1000.2.in",
  "num.1000.3.in",
  "num.1000.4.in",
  "num.10000.1.in",
  "num.10000.2.in",
  "num.10000.3.in",
  "num.10000.4.in",
  "num.100000.1.in",
  "num.100000.2.in",
  "num.100000.3.in",
  "num.100000.4.in",
]


def insertion_sort(arr):
    for i in range(1, len(arr)):
        maior_valor = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > maior_valor:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = maior_valor


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        minimo = i
        for j in range(i + 1, n):
            if arr[j] < arr[minimo]:
                minimo = j
        arr[i], arr[minimo] = arr[minimo], arr[i]


for arquivo in arquivos:
    print(f"\nArquivo: {arquivo}")

    with open(arquivo, 'r') as f:
        numeros = [int(l) for l in f]

    lista_insertion = numeros[:]
    lista_selection = numeros[:]

    inicio = time.perf_counter()
    insertion_sort(lista_insertion)
    tempo_insertion = time.perf_counter() - inicio

    inicio = time.perf_counter()
    selection_sort(lista_selection)
    tempo_selection = time.perf_counter() - inicio

    print(f"Tempo Insertion Sort: {tempo_insertion:.6f} segundos")
    print(f"Tempo Selection Sort: {tempo_selection:.6f} segundos")

    if tempo_insertion < tempo_selection:
        print("===== Insertion Sort foi mais rápido. =====")
    elif tempo_insertion > tempo_selection:
        print("===== Selection Sort foi mais rápido. =====")
    else:
        print("===== Ambos tiveram o mesmo tempo. =====")
