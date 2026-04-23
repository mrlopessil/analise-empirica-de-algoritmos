import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("dados.csv")
n = df["n"]

# Funções assintóticas
f_const = np.ones_like(n)       # O(1)
f_log = np.log2(n)              # O(log n)
f_n = n                         # O(n)
f_nlogn = n * np.log2(n)        # O(n log n)
f_n2 = n**2                     # O(n^2)

# Alinha a função teórica aos dados aos dados obtidos
def ajustar(f, y):
    return f * (y.mean() / f.mean())

# =========================
# FIGURE 1 - MELHOR CASO BUSCA
# =========================
plt.figure(figsize=(10, 6))

plt.plot(n, df["binaria_melhor"], marker="o", label="Binária")
plt.plot(n, df["sequencial_melhor"], marker="o", label="Sequencial")

plt.plot(n, ajustar(f_const, df["sequencial_melhor"]), "--", label="O(1)")

plt.title("Melhor Caso - Busca Binária vs Sequencial")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()
plt.tight_layout()

# =========================
# FIGURE 2 - CASO MÉDIO BUSCA
# =========================
plt.figure(figsize=(10, 6))

plt.plot(n, df["binaria_media"], marker="o", label="Binária")
plt.plot(n, df["sequencial_media"], marker="o", label="Sequencial")

plt.plot(n, ajustar(f_log, df["binaria_media"]), "--", label="O(log n)")
plt.plot(n, ajustar(f_n, df["sequencial_media"]), "--", label="O(n)")

plt.title("Caso Médio - Busca Binária vs Sequencial")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()
plt.tight_layout()

# =========================
# FIGURE 3 - PIOR CASO BUSCA
# =========================
plt.figure(figsize=(10, 6))

plt.plot(n, df["binaria_pior"], marker="o", label="Binária")
plt.plot(n, df["sequencial_pior"], marker="o", label="Sequencial")

plt.plot(n, ajustar(f_log, df["binaria_pior"]), "--", label="O(log n)")
plt.plot(n, ajustar(f_n, df["sequencial_pior"]), "--", label="O(n)")

plt.title("Pior Caso - Busca Binária vs Sequencial")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()
plt.tight_layout()

# =========================
# FIGURE 4 - MELHOR CASO ORDENAÇÃO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(n, df["insertion_melhor"], marker="o", label="Insertion Sort")
plt.plot(n, df["merge_melhor"], marker="o", label="Merge Sort")

plt.plot(n, ajustar(f_n, df["insertion_melhor"]), "--", label="O(n)")
plt.plot(n, ajustar(f_nlogn, df["merge_melhor"]), "--", label="O(n log n)")

plt.title("Melhor Caso - Insertion Sort vs Merge Sort")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()
plt.tight_layout()

# =========================
# FIGURE 5 - CASO MÉDIO ORDENAÇÃO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(n, df["insertion_media"], marker="o", label="Insertion Sort")
plt.plot(n, df["merge_media"], marker="o", label="Merge Sort")

plt.plot(n, ajustar(f_n2, df["insertion_media"]), "--", label="O(n²)")
plt.plot(n, ajustar(f_nlogn, df["merge_media"]), "--", label="O(n log n)")

plt.title("Caso Médio - Insertion Sort vs Merge Sort")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()
plt.tight_layout()

# =========================
# FIGURE 6 - PIOR CASO ORDENAÇAO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(n, df["insertion_pior"], marker="o", label="Insertion Sort")
plt.plot(n, df["merge_pior"], marker="o", label="Merge Sort")

plt.plot(n, ajustar(f_n2, df["insertion_pior"]), "--", label="O(n²)")
plt.plot(n, ajustar(f_nlogn, df["merge_pior"]), "--", label="O(n log n)")

plt.title("Pior Caso - Insertion Sort vs Merge Sort")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()
plt.tight_layout()

plt.show()