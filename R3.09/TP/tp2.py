def fermat_test(p, a=2):
    if p <= 1:
        return False
    # Si p est divisible par a, il n'est pas premier
    if p % a == 0:
        return False
    # Calcul a^(p-1) % p
    return pow(a, p - 1, p) == 1

nombre = 41
print(f"Test de Fermat pour {nombre}:", fermat_test(nombre))

def fermat_test_multiple_bases(p):
    if p <= 1:
        return False
    # Bases utilisées pour le test
    bases = [2, 3, 5, 7]
    # Vérifie si p est divisible par une base ou échoue au test de Fermat
    for a in bases:
        if p % a == 0 and p != a:  # Si p est divisible par a (et n'est pas égal à a), il n'est pas premier
            return False
        if pow(a, p - 1, p) != 1:  # Si Fermat échoue pour cette base
            return False
    return True

nombre = 41
print(f"Test de Fermat pour {nombre}:", fermat_test(nombre))

