
PUBLIC		= /home/linux/ieng6/cs100w/public
HW1_DIR		= $(PUBLIC)/Homeworks/HW1/Program

TESTSORT_HEADER	= $(HW1_DIR)

SOURCE		= $(HW1_DIR)/mainTest.cpp 

testSort:	$(SOURCE)
		@echo "Compiling and Loading testSort ..."
		@rm -f testSort.hpp mainTest.cpp
		@cp $(HW1_DIR)/mainTest.cpp .
		@cp $(HW1_DIR)/testSort.hpp .
		@g++ mainTest.cpp -g -lm -o testSort
		@echo "done"

clean:
		rm -rf testSort core

#	this makefile assumes your version of testSort.cpp and the makefile are in \
	the same directory/folder.
