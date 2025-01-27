# TD1

## Exercice 1 :
+---+---+---+---+
| A | B | C | D |
+---+---+---+---+
| a1| b1| c1| d1|
| a1| B1| c1| d2|
| a1| b1| C1| d3|
| a2| b2| c2| d4|
| a2| b2| C2| d5|
+---+---+---+---+

## Exercice 2
1.
NumPokémon -> Nom
NumPokémon -> Type
NumPokémon -> Niveau
NumPokémon -> Attaque
NumPokémon -> PV
NumPokémon -> Dresseur

2. 
{NumPokémon}+ = {NumPokémon} {NumPokémon}+
{NumPokémon}+ = {NumPokémon, Nom} {NumPokémon}+
{NumPokémon}+ = {NumPokémon, Nom, Type} {NumPokémon}+
{NumPokémon}+ = {NumPokémon, Nom, Type, Niveau} {NumPokémon}+
{NumPokémon}+ = {NumPokémon, Nom, Type, Niveau, Attaque} {NumPokémon}+
{NumPokémon}+ = {NumPokémon, Nom, Type, Niveau, Attaque, PV} {NumPokémon}+
{NumPokémon}+ = {NumPokémon, Nom, Type, Niveau, Attaque, PV, Dresseur} {NumPokémon}+

3.
Pokémon -> NumPokémon, Nom, Type, Niveau
Dresseur -> NumPokémon, Dresseur
Attaque -> NumPokémon, Niveau, Attaque
PV -> NumPokémon, Niveau, PV


## Exercice 3
SELECT Name, Type
FROM Pokemon;

SELECT 