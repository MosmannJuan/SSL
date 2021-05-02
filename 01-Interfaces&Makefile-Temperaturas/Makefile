Conversion: Conversion.o ConversionTest.o
	gcc Conversion.o ConversionTest.o -o Conversion

TablasDeConversion: Conversion.o TablasDeConversion.o FuncionesPrint.o
	gcc Conversion.o TablasDeConversion.o FuncionesPrint.o -o TablasDeConversion

TablasDeConversion.o: TablasDeConversion.c
	gcc -c TablasDeConversion.c -std=c18

Conversion.o: Conversion.c
	gcc -c Conversion.c -std=c18

ConversionTest.o: ConversionTest.c
	gcc -c ConversionTest.c -std=c18

FuncionesPrint.o: FuncionesPrint.c
	gcc -c FuncionesPrint.c -std=c18
