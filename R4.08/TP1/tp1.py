import time
import random

class EllipticCurve:
    def __init__(self, a, b, p):
        self.a = a
        self.b = b
        self.p = p
    
    def is_on_curve(self, x, y):
        """ Vérifie si un point appartient à la courbe """
        return (y**2 - (x**3 + self.a * x + self.b)) % self.p == 0
    
    def add(self, P, Q):
        """ Addition de deux points sur la courbe elliptique """
        if P == Q:
            return self.double(P)
        if P is None:
            return Q
        if Q is None:
            return P
        
        x1, y1 = P
        x2, y2 = Q

        if x1 == x2 and y1 == -y2 % self.p:
            return None

        M = ((y2 - y1) * pow(x2 - x1, -1, self.p)) % self.p
        x3 = (M**2 - x1 - x2) % self.p
        y3 = (M * (x1 - x3) - y1) % self.p

        return (x3, y3)
    
    def double(self, P):
        """ Doublement d'un point sur la courbe elliptique """
        if P is None:
            return None
        
        x1, y1 = P

        M = ((3 * x1**2 + self.a) * pow(2 * y1, -1, self.p)) % self.p
        x3 = (M**2 - 2 * x1) % self.p
        y3 = (M * (x1 - x3) - y1) % self.p

        return (x3, y3)

    def scalar_mult(self, k, P):
        """ Multiplication scalaire d'un point par un entier k (Double & Add) """
        Q = None
        while k > 0:
            if k & 1:
                Q = self.add(Q, P)
            P = self.double(P)
            k >>= 1
        return Q

# 1. Définir la courbe et le point de base
p = 521
a = 1
b = 37
curve = EllipticCurve(a, b, p)

P = (19, 244)

# Test pour savoir si le point appartient bien à la courbe
print("P appartient à la courbe :", curve.is_on_curve(P[0], P[1]))

# 2.  En utilisant un algorithme d’exponentiation rapide, ecrire un algorithme double and add pour la muliplication scalaire pour ECC.
# Ajout du double(), add() et scalar_mult()

# 3. Testez votre MS avec la courbe et le point de base définis précédemment.
k = 20
Q = curve.scalar_mult(k, P)
print(f"{k} * P =", Q)

# 4. Mesurez le temps d’exécution de votre programme pour 100 multiplications scalaires
start_time = time.time()

for _ in range(100):
    k = random.randint(1, p-1)
    curve.scalar_mult(k, P)

end_time = time.time()
print("Temps d'exécution pour 100 multiplications :", end_time - start_time, "secondes")
