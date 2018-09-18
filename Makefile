TARGETS := \
	apply_inord \
	apply_postord \
	apply_postrevord \
	apply_preord \
	apply_prerevord \
	apply_revord \
	delete_apply \
	delete \
	init \
	insert \
	insert_rebalance \
	rbtn_remove \
	removal_rebalance_blackparent \
	removal_rebalance \
	removal_rebalance_redparent \
	remove1 \
	remove2 \
	reposition_anchor \
	retrieve \
	rotate \
	search

NAME = myrbtree
LIBNAME = lib$(NAME)

ROOT = .
SRC_DIR	:= $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)
LIBS_I := $(INC_DIR)
OUT_DIR_LIB := $(ROOT)
OUT_DIR_H := $(LIBS_I)

OBJS = $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

all : header library

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

$(OUT_DIR_H)/$(LIBNAME).h :
	sed -e'4s@\($(NAME).h\)   @lib\1@'\
		-e'13,14s@M@LIB&@'\
		$(INC_DIR)/$(NAME).h > $@

.PHONY : library
library : $(OUT_DIR_LIB)/$(LIBNAME).a

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	-ar rcs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-o $@ -c $<


.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
