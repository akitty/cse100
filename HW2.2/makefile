
PUBLIC		= /home/linux/ieng6/cs100w/public
HW2_DIR		= $(PUBLIC)/Homeworks/HW2/Programs

SOURCE0		= $(HW2_DIR)/main0.cpp
SOURCE1		= $(HW2_DIR)/main1.cpp
SOURCE2		= $(HW2_DIR)/main2.cpp
SOURCE3		= $(HW2_DIR)/main3.cpp

main0:		$(SOURCE0)
		@echo "Compiling and Loading main0 ..."
		@cp $(SOURCE0) .
		@g++ main0.cpp -g -lm -o main0
		@echo "done"

main1:		$(SOURCE1)
		@echo "Compiling and Loading main1 ..."
		@cp $(SOURCE1) .
		@g++ main1.cpp -g -lm -o main1
		
		@echo "done"

main2:		$(SOURCE1)
		@echo "Compiling and Loading main2 ..."
		@cp $(SOURCE2) .
		@g++ main2.cpp -g -lm -o main2
		
		@echo "done"

main3:		$(SOURCE3)
		@echo "Compiling and Loading main3 ..."
		@cp $(SOURCE3) .
		@g++ main3.cpp -g -lm -o main3
	
		@echo "done"

clean:
		rm -rf main0 main1 main2 main3 core

#	this makefile assumes your version of table.cpp, table.hpp and the makefile are in \
	the same directory/folder.
