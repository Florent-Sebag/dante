##
## Makefile for Makefile in /home/dheilly/rendu/Sauvegarde/1ère année/C-Prog-Elem/dante
##
## Made by Dheilly Joss
## Login   <dheilly@epitech.net>
##
## Started on  Sat May 21 22:06:22 2016 Dheilly Joss
## Last update Sun May 22 20:40:27 2016 Florent Sebag
##

all:
	make -C ./profondeur
	make -C ./largeur
	make -C ./generateur

clean:
	make clean -C ./profondeur
	make clean -C ./largeur
	make clean -C ./generateur

fclean:
	make fclean -C ./profondeur
	make fclean -C ./largeur
	make fclean -C ./generateur

re:
	make re -C ./profondeur
	make re -C ./largeur
	make re -C ./generateur
