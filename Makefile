# LaTeX Makefile
FILE=ALICE_analysis_note
all: $(FILE).pdf
.PHONY: clean
clean:
	\rm *.aux *.blg  *.bbl *.log $(FILE).pdf
$(FILE).pdf: $(FILE).tex
	pdflatex $(FILE)
	pdflatex $(FILE)
	bibtex $(FILE)
	pdflatex $(FILE)
	pdflatex $(FILE)
