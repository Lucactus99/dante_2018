#!/bin/sh

echo "Entrez la longueur: "
read COMMAND
echo "Entrez la largeur: "
read COMMAND2

./generator/generator "$COMMAND" "$COMMAND2" > file.txt
./solver/solver "file.txt" > output.txt

if grep -q "no solution found" output.txt
then
    echo "Le labyrinthe ne peut pas être résolu !"
else
    echo "Le labyrinthe peut être résolu !"
fi
rm output.txt
rm file.txt