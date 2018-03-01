#!/bin/sh

make

echo "Parcours en largeur :\nBig lab : "
time ./largeur/solver ./mazes/big.lab > .tmp
echo "Medium lab : "
time ./largeur/solver ./mazes/medium.lab > .tmp
echo "Small lab : "
time ./largeur/solver ./mazes/small.lab > .tmp

echo "\n\nParcours en profondeur :\nBig lab : "
time ./profondeur/solver ./mazes/big.lab > .tmp1
echo "Medium lab : "
time ./profondeur/solver ./mazes/medium.lab > .tmp
echo "Small lab : "
time ./profondeur/solver ./mazes/small.lab > .tmp

rm .tmp
rm .tmp1

make fclean
