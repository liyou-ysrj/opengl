exist = $(shell if [ -f $(FILE) ]; then echo "exist"; else echo "notexist"; fi;)

simple:s_clean
	gcc -O2 -g -osimple simple.c -lGL -lGLU -lglut `pkg-config --libs opencv` -lGLEW
s_ebi:
	emacs simple.c 
s_eac:s_ebi simple

s_clean:
	-rm simple


tutorial2:
	g++ -otutorial2 tutorial02.cpp -lGL -lGLU -lglut -lGLEW `pkg-config --libs opencv`
t_ebi:
	emacs tutorial02.cpp
t_eac:t_ebi tutorial02
