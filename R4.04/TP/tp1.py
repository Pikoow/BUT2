# TP1

import numpy as np

# A. Algorithme du Gradient pour une fonction à 1 variable

# Question 1
# Sur papier. Calculer les dérivées de f1, f2 et f3.
# f1'(x) = 2x - 4
# f2'(x) = 3x² - 6
# f3'(x) = e^x - 10

# En Python. Créer les fonctions Python f1prime(x), f2prime(x) et f3prime(x) correspondant à ces dérivées.

def f1prime(x):
    return 2*x - 4

def f2prime(x):
    return 3*(x**2) - 6

def f3prime(x):
    return np.exp(x) - 10

# Question 2
# Ecrire une fonction Python Gradient1D(x0,alpha,n,fp), qui renvoie l’itération xn de l’algorithme du gradient.
    
def Gradient1D(x0, alpha, n, fp):
    xn = x0
    for _ in range(n):
        xn = xn - alpha * fp(xn)
    return xn

# Question 3
# Tester votre fonction Gradient1D avec la fonction f1prime et plusieurs choix d’initialisations et de pas.

x_values = [0, 2, 5]
alpha_values = [0.1, 0.5, 0.01]
n = 100

for x in x_values:
    for alpha in alpha_values:
        x_min = Gradient1D(x, alpha, n, f1prime)
        print("Le minimum estimé de f1 est en x =", x_min)

# Question 4
# Tester votre fonction Gradient1D avec la fonction f2prime et plusieurs choix d’initialisations et de pas.
'''
for x in x0:
    for alpha in alphas:
        x_min = Gradient1D(x, alpha, n, f2prime)
        print("Le minimum estimé de f2 est en x =", x_min)
'''
# Question 5
# Tester votre fonction Gradient1D avec la fonction f23prime et plusieurs choix d’initialisations et de pas.

for x in x_values:
    for alpha in alpha_values:
        x_min = Gradient1D(x, alpha, n, f3prime)
        print("Le minimum estimé de f3 est en x =", x_min)

# B. Algorithme du gradient pour une fonction à 2 variables

# Question 6
# Sur papier. Calculer les dérivées partielles de f1 et de f2 par rapport à x et par rapport à y.
# f1'(x) = 4x + 2 + y
# f1'(y) = 10y + x
# f2'(x) = 2x - 1.9
# f2'(y) = 2y

# En Python. Définir ces dérivées partielles comme des fonctions Python df1x(x,y), df1y(x,y), df2x(x,y) et df2y(x,y).
def df1x(x, y):
    return 4*x + 2 + y

def df1y(x, y):
    return 10*y + x

def df2x(x, y):
    return 2*x - 1.9

def df2y(x, y):
    return 2*y

# Question 7
# Ecrire une fonction Python Gradient2D(fx,fy,x0,y0,alpha,n).
def Gradient2D(fx, fy, x0, y0, alpha, n):
    x, y = x0, y0
    for i in range(n):
        x -= alpha * fx(x, y)
        y -= alpha * fy(x, y)
    
    return x, y

# Question 8
# Tester votre fonction Gradient2D avec df1x et df1y et plusieurs choix d’initialisations, de pas et de nombres d’itérations.

x_initials = [0, 1, -1]
y_initials = [0, 1, -1]
alpha_values = [0.1, 0.01, 0.5]
iterations = 100

for x0 in x_initials:
    for y0 in y_initials:
        for alpha in alpha_values:
            x_min, y_min = Gradient2D(df1x, df1y, x0, y0, alpha, iterations)
            print("Le minimum estimé de f1 est en x =", x_min, "y =", y_min)

# Question 9
# Tester votre fonction Gradient2D avec df2x et df2y et plusieurs choix d’initialisations, de pas et de nombres d’itérations.

x_initials = [0, 1, -1]
y_initials = [0, 1, -1]
alpha_values = [0.1, 0.01, 0.5]
iterations = 100

for x0 in x_initials:
    for y0 in y_initials:
        for alpha in alpha_values:
            x_min, y_min = Gradient2D(df2x, df2y, x0, y0, alpha, iterations)
            print("Le minimum estimé de f2 est en x =", x_min, "y =", y_min)

# C. Algorithme du gradient pour la régression linéaire