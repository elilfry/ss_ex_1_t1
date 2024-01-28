
CC=gcc
AR=ar
FLAGS= -Wall -g

OBJ_ADL = advancedClassificationLoop.o 
OBJ_ADR = advancedClassificationRecursion.o
OBJ_BC = basicClassification.o

all:  mains loops recursives recursived maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so
 

# Target for the static library libclassloops.a, depends on advancedClassificationLoop.o basicClassification.o
libclassloops.a : $(OBJ_BC) $(OBJ_ADL)
	$(AR) -rcs libclassloops.a $(OBJ_BC) $(OBJ_ADL)

# Target for the static library libclassRec.a, depends on advancedClassificationLoop.o basicClassification.o
libclassrec.a : $(OBJ_BC) $(OBJ_ADR)
	$(AR) -rcs libclassrec.a $(OBJ_BC) $(OBJ_ADR)

 #Target for the dinamic library libclassRec.a, depends on advancedClassificationRec.o basicClassification.o
libclassrec.so: $(OBJ_BC) $(OBJ_ADR)
	$(CC) -shared  -fPIC -o  libclassrec.so $(OBJ_BC) $(OBJ_ADR)


#Target for the dinamic library libclassloops.so, depends on advancedClassificationLoop.o basicClassification.o
libclassloops.so: $(OBJ_BC) $(OBJ_ADL)
	$(CC) -shared -fPIC -o libclassloops.so $(OBJ_BC) $(OBJ_ADL)

#creating the 3 O files 
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS)  -fPIC -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c  NumClass.h
	$(CC) $(FLAGS)  -fPIC -c advancedClassificationLoop.c
	
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c	
#the mains

mains: main.o libclassrec.a 
	$(CC) $(FLAGS) -o mains main.o libclassrec.a



maindloop: main.o libclassloops.so	
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so	
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so


main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

	

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
