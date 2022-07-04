SRC_DIREC = ./src/
INCLUDE_DIREC = /usr.local/include
LIB_DIREC = /usr/local/lib

exec:
	export LD_LIBRARY_PATH=${LIB_DIREC}
	g++ -c ${SRC_DIREC}function.cpp -o ${SRC_DIREC}function.o
	g++ -c ${SRC_DIREC}example.cpp -o ${SRC_DIREC}example.o
	g++ ${SRC_DIREC}example.o ${SRC_DIREC}function.o -o ${SRC_DIREC}example\
    	-lgsl -lgslcblas -I${INCLUDE_DIREC} -L${LIB_DIREC} -lm

report:
	xelatex report.tex
	bibtex report.aux
	xelatex report.tex
	xelatex report.tex

slide:
	xelatex slide.tex

clean:
	rm -rf *.aux
	rm -rf *.log
	rm -rf *.nax
	rm -rf *.out
	rm -rf *.nav
	rm -rf *.snm
	rm -rf *.toc
	rm -rf *.vrb
	rm -rf *.bbl
	rm -rf *.blg
	rm -rf *.brf
	rm -rf ${SRC_DIREC}*.o