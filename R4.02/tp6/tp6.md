# TP6

## 2.1 Vérification de la validation

### massifs1.xml

1. Une balise ou un attribut doit être correctement fermé
2. Le seul élément qui peut être directement dans massifs est massif.
3. La séquence (sommet, glacier, massif) n'est pas respectée.
4. L'élement lac n'existe pas.
5. Nom est obligatoire.
6. L'attribut nature n'existe pas.
7. Une alititude ne doit pas dépasser 5000.

### schema_massifs.xsd

1. C'est la ligne des Pyrénées car c'est le troisième massif qui est déclaré.
Car le nombre de massifs dans un massif est toujours "unbounded".
2. Les massifs mit en erreur sont ceux qui n'ont pas de glacier.
3. TOut les noms de massifs doivent être écrit en integer.
4. Tout les sommets qui ont du texte associé ne sont plus valides.
5. On est maintenant obligé de mettre une altitude dans un glacier, tout ceux qui n'en ont pas ne sont pas valides.

## 2.2 Augmentation des fichiers
