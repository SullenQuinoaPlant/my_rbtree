NAME = myrbtree
LIBNAME = lib$(NAME)
GIT_REPO = https://github.com/SullenQuinoaPlant/my_rbtree.git

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(ROOT)/targets.mk

DEPENDENCIES = libft

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBS_I)
endif
CFLAGS += $(CFLAGS_MORE)

UTEST_DIR := $(ROOT)/tests
