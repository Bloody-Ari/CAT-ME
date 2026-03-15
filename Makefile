# To make this file I followed https://github.com/clementvidon/Makefile_tutor?tab=readme-ov-file#version-1
# so check it out if you have any doubts! (This file is extensively tho).

NAME := "cat-me" #carpinchos aid tool, melissa edition 
# PS: (windows reference intended)

#-------------------------------------------------------------------------------------------#
# Build Variables      																						 													#
#-------------------------------------------------------------------------------------------#
# CC = compiler, could probably be changed to clang																					#
# CFLAGS = *mandatory* compiler flags																												#
# CPPFLAGS = opcional compiler preprocessor flags																						#
# OCFLAGS = opcional compiler flags, doesn't exsist for now																	#
#           																																							  #
# SRC_DIR = source directory, location of the .c files                                      #
# SRCS = actual source files																																#
# HEADERS_DIR = headers directory, location of the .h files                                 #
# LIB_DIR = external libraries directory, not in use for now!                               #
# 																																													#
# TARGET_DIR = target location for the final binaries (like, where your executable will be) #
# DOCS_DIR = no use for now, but the location for the docs, I may use this in the future... #
#																																														#
# OBJECTS = object files, .o, the compiled .c files.               													#
#-------------------------------------------------------------------------------------------#

CC := gcc 
CFLAGS := -ansi -Wall -Werror -Wpedantic 
CPPFLAGS := -MMD

SRC_DIR := src
SRCS := \
				main.c \
				reaction_functions.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR := build
OBJS := \
				main.o \
				reaction_functions.o
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET_DIR := bin
BINS := cat-me
TARGETS := $(BINS:%=$(TARGET_DIR)/%)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(TARGETS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	rm $(OBJS) $(TARGETS)
