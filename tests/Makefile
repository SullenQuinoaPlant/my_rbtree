ifndef ROOT
 ROOT := ..
 include $(ROOT)/Makefile
endif

TEST_SRCS := $(wildcard $(TEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CFLAGS_TEST = -fno-builtin -g
CFLAGS_TEST += $(CFLAGS_MORE) #$(CFLAGS) were annoying the hell out of me

AUX_DIR = $(TEST_DIR)/auxilliaries
include $(AUX_DIR)/Makefile



############
#BUILD TESTS

.PHONY : build-tests
build-tests\
:\
set_utest_flags def\
test_prerequisites\
$(TEST_OBJS)
	@echo $(TEST_SRCS)
	@echo $(TEST_OBJS)


.PHONY : set_utest_flags
set_utest_flags :
	$(eval CFLAGS += $(CFLAGS_TEST))


.PHONY : test_prerequisites
test_prerequisites : cmocka libaux


.PHONY : cmocka
cmocka : 
	@if $(CC) $(CFLAGS_TEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
	 	$(TEST_DIR)/cmocka/check_install.c\
		-lcmocka -o test.o\
		-Wl,-rpath $(LIBS_L)\
		&& ./test.o .;\
	then\
		echo "cmocka already installed";\
	else\
		echo "installing cmocka";\
		$(MAKE) -C $(TEST_DIR)/cmocka/;\
	fi
	-@rm ./test.o


$(TEST_DIR)/%.test.o\
:\
$(TEST_DIR)/%.test.c\
$(LIBS_L)/$(LIBNAME).a
	$(CC) $(CFLAGS_TEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(INC_DIR)\
		$<\
		-L $(LIBS_L)\
		-lcmocka\
		-laux\
		-l$(NAME)\
		-lft\
		-o $@\
		-Wl,-rpath $(LIBS_L)\

.PHONY : maintest
maintest : $(TEST_DIR)/main.test.o

$(TEST_DIR)/main.test.o\
:\
$(TEST_DIR)/main.test.c\
$(LIBS_L)/$(LIBNAME).a
	$(CC) $(CFLAGS_TEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(INC_DIR)\
		$<\
		-L $(LIBS_L)\
		-laux\
		-l$(NAME)\
		-lft\
		-o $@\


%.test.c : $(TEST_DIR)/cmocka/my_macro_overlay.h
	@:



############
#RUN TESTS :

.PHONY : unit-tests ut
unit-tests ut : list_tests build-tests run_tests

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.o
	-./$*.o "$(TEST_DIR)" \
	&& touch $@



###############
#MISCELLANEOUS:

.PHONY : all_unit_tests aut
all_unit_tests aut : clean-tests ut



.PHONY : clean-tests
clean-tests :
	-rm $(TEST_DIR)/*.o
	-rm $(TEST_DIR)/*.stamp



.PHONY : list-tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
