import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("dados.csv")


# =========================
# FIGURE 1 - MELHOR CASO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(df["n"], df["binaria_melhor"], marker="o", label="Binária")
plt.plot(df["n"], df["sequencial_melhor"], marker="o", label="Sequencial")

plt.title("Melhor Caso - Busca Binária vs Sequencial")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()

plt.tight_layout()


# =========================
# FIGURE 2 - CASO MÉDIO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(df["n"], df["binaria_media"], marker="o", label="Binária")
plt.plot(df["n"], df["sequencial_media"], marker="o", label="Sequencial")

plt.title("Caso Médio - Busca Binária vs Sequencial")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()

plt.tight_layout()


# =========================
# FIGURE 3 - PIOR CASO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(df["n"], df["binaria_pior"], marker="o", label="Binária")
plt.plot(df["n"], df["sequencial_pior"], marker="o", label="Sequencial")

plt.title("Pior Caso - Busca Binária vs Sequencial")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()

plt.tight_layout()



# Insertion Sort
plt.figure(figsize=(10, 6))

plt.plot(df["n"], df["insertion_melhor"], marker="o", label="Insert Sort")
plt.plot(df["n"], df["merge_melhor"], marker="o", label="Merge Sort")

plt.title("Melhor Caso - Insertion Sort vs Merge Sort")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()

plt.tight_layout()


# =========================
# FIGURE 2 - CASO MÉDIO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(df["n"], df["insertion_media"], marker="o", label="Insertion Sort")
plt.plot(df["n"], df["merge_media"], marker="o", label="Merge Sort")

plt.title("Caso Médio - Insertion Sort vs Merge Sort")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()

plt.tight_layout()


# =========================
# FIGURE 3 - PIOR CASO
# =========================
plt.figure(figsize=(10, 6))

plt.plot(df["n"], df["insertion_pior"], marker="o", label="Insertion Sort")
plt.plot(df["n"], df["merge_pior"], marker="o", label="Merge Sort")

plt.title("Pior Caso - Insertion Sort vs Merge Sort")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s)")
plt.grid()
plt.legend()

plt.tight_layout()

plt.show()