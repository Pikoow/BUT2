# TD1

```mermaid
---
title: Exercice 1
---
classDiagram
    Circonscription "1" -- "1..*" Citoyen : habite
    Circonscription "0..1" -- "1" Citoyen : administre
    Circonscription "0..1" -- "2" Citoyen : co-administre

    Circonscription "1..*" --o "1" Ville : appartient
    Metropole --|> Ville
    Commune --|> Ville

    class Citoyen{
        -numEs : String
        -nomC : String
        -prenomC : String
        -dateN : Date
        -age : integer
    }

    class Circonscription{
        -libelle : String
        -nbHab : String
    }

    class Ville{
        -nomV : String
        -dept : integer
        -nbHab : integer
        +preparerEl() void
    }

    class Metropole {
        +preparerEl() void
    }

    class Commune {
        +preparerEl() void
    }
```

```mermaid
---
title: Exercice 2
---
classDiagram
    Eleve "1..*" -- "1..*" Classe : appartient

    class Eleve {
        -numEleve : String
        -nom : String
        -prenom : String
    }

    class Classe {
        -codeClasse : String
    }

    class Annee {
        -anneeScol : Date
    }
```

## Question 1

{nbHab > 200000}\
{nbHab <= 200000}\
{age >= 18}\
numEs {frozen.id}\
{today - dateN >= 18}

## Question 2
