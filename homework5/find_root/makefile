INCLUDE_DIRECTORY="/usr/local/include"
LIB_DIRECTORY="/usr/local/lib"
LD_LIBRARY_PATH_STR="/usr/local/lib"

run:
	gcc -o ./bin/roots ./src/roots.c\
	 -lgsl -lgslcblas -I${INCLUDE_DIRECTORY} -L${LIB_DIRECTORY} -lm
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH_STR}


report:
	xelatex ./doc/report.tex
	rm -rf report.aux
	rm -rf report.log
	rm -rf report.out