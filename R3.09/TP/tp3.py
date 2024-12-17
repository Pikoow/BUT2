def pgcd(a, b):
    if b == 0:
        return a
    else:
        return pgcd(b, a % b)

a = 450
b = 198
resultat = pgcd(a, b)
print(f"Le PGCD de {a} et {b} est : {resultat}")

import random
import math

def approx_Pn(n, nbr_essai):
    compteur = 0
    
    for _ in range(nbr_essai):
        a = random.randint(1, n)
        b = random.randint(1, n)
        if math.gcd(a, b) == 1:
            compteur += 1
    c
    Pn = compteur / nbr_essai
    return Pn

# Comparaison avec 6 / pi^2
n = 1000  # Choix de n
nbr_essai = 1000000
Pn_approx = approx_Pn(n, nbr_essai)
valeur_theorique = 6 / math.pi**2

print(f"Approximation de Pn pour n = {n} : {Pn_approx:.6f}")
print(f"Valeur theorique de 6 / pi^2 : {valeur_theorique:.6f}")