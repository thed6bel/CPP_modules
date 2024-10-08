# Modules CPP - École 42

## Description
Les modules CPP sont une série de projets de l'École 42 conçus pour introduire les étudiants à la programmation orientée objet en C++. Chaque module se concentre sur des aspects spécifiques du langage et des concepts de la POO.

## Objectifs généraux
- Apprendre les bases et les concepts avancés de C++
- Comprendre et appliquer les principes de la programmation orientée objet
- Maîtriser la syntaxe et les fonctionnalités spécifiques à C++
- Développer des compétences en résolution de problèmes et en conception de logiciels

## Liste des modules

### Module 00 : Introduction à C++
- Namespaces, classes, fonctions membres, stdio streams, listes d'initialisation, static, const, et autres bases

### Module 01 : Mémoire et pointeurs
- Allocation mémoire, pointeurs sur membres, références, switch statement

### Module 02 : Polymorphisme ad-hoc, surcharge d'opérateurs et forme canonique
- Surcharge d'opérateurs, forme canonique des classes

### Module 03 : Héritage
- Héritage, classes dérivées, polymorphisme d'héritage

### Module 04 : Polymorphisme sous-type, classes abstraites, interfaces
- Polymorphisme, classes abstraites, interfaces

### Module 05 : Try/Catch et exceptions
- Répétitions et exceptions

### Module 06 : Casts en C++
- Different types de casts en C++

### Module 07 : Templates
- Templates en C++

### Module 08 : Containers templates, itérateurs, algorithmes
- STL containers, itérateurs, algorithmes

### Module 09 : Containers STL
- Utilisation avancée des containers STL

## Compilation et exécution
Chaque exercice dans chaque module a généralement ses propres instructions de compilation. En général, vous utiliserez un Makefile avec les commandes suivantes :

```
make        # Pour compiler
make clean  # Pour supprimer les fichiers objets
make fclean # Pour supprimer les fichiers objets et l'exécutable
make re     # Pour recompiler le projet
```

## Structure générale d'un module
```
CPPxx/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   └── [autres fichiers .hpp et .cpp]
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   └── [autres fichiers .hpp et .cpp]
└── [autres exercices...]
```

## Normes de code
- Utilisation du C++98 standard
- Compilation avec les flags : -Wall -Wextra -Werror
- Nommage des classes en UpperCamelCase
- Utilisation des getters/setters pour les attributs privés
- Implémentation de la forme canonique pour les classes

## Conseils généraux
- Lisez attentivement chaque sujet d'exercice
- Testez abondamment votre code
- Pratiquez la gestion propre de la mémoire (pas de fuites)
- Respectez la norme de codage demandée
- Comprendre plutôt que simplement copier-coller du code

## Ressources utiles
- [cplusplus.com](http://www.cplusplus.com/)
- [C++ Reference](https://en.cppreference.com/)
- [LearnCPP.com](https://www.learncpp.com/)

