NAME =
LIBNAME = lib$(NAME)

CALL_DIR := $(shell pwd)
SRC_DIR	:= $(ROOT)/
OBJ_DIR := $(ROOT)/
LIB_DIR := $(ROOT)/
LIBS_L := $(LIB_DIR)/
LIBS_I := $(LIB_DIR)/
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(SRC_DIR)/targets.mk

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror
endif
CFLAGS += $(CFLAGS_MORE)
