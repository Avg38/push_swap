# Push Swap
Le projet Push Swap consiste à trier une pile d'entiers à l'aide d'un ensemble limité d'instructions de manipulation de pile, avec l'objectif de le faire de la manière la plus efficace possible.

## Exemple
```bash
./push_swap 4 2 9 1 5`
```
## Vérificateur (Checker)
Un vérificateur est également inclus pour valider le tri effectué par push_swap. Il prend en entrée la même séquence d'entiers et vérifie si les instructions de manipulation de pile trient correctement la pile.

```bash
./push_swap [entiers à trier] | ./checker [entiers à trier]
```
## Exemple :
```bash
./push_swap 4 2 9 1 5 | ./checker 4 2 9 1 5
```
## Options
`-v` : Affiche les étapes du tri.
`-c` : Affiche le nombre total d'instructions utilisées pour trier la pile.
## Exemple :
```bash
./push_swap -v -c 4 2 9 1 5
```
