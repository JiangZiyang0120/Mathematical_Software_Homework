FILENAME=homework4
PYTHONNAME = mandelbrot
SETUPNAME = setup
${FILENAME}.pdf:${FILENAME}.dvi
	dvipdfm $^ -o $@
${FILENAME}.dvi:${FILENAME}.tex
	xelatex $^
clean:
	-rm ${FILENAME}.log
	-rm ${FILENAME}.dvi
	-rm ${FILENAME}.pdf
	-rm ${FILENAME}.aux
	-rm ${FILENAME}.bbl
	-rm ${FILENAME}.blg
	-rm ${FILENAME}.out
	-rm ${FILENAME}.brf
	-echo 'clean fnished!'
report:
	-xelatex ${FILENAME}.tex
	-bibtex ${FILENAME}.aux
	-xelatex ${FILENAME}.tex
	-xelatex ${FILENAME}.tex
	evince ${FILENAME}.pdf
build:
	# 需下载 cython包
	# pip install cython
	python3 ${SETUPNAME}.py build_ext --inplace
	python3 ${PYTHONNAME}.py