ifndef ROOT
 ROOT = ..
 include $(ROOT)/Makefile
endif


.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)
	@echo "$(DEPENDENCIES)"


define BUILD_LIB
	$(MAKE) -C $@/ 
	cp $@/$(@F).a $(LIBS_L)
	cp $@/includes/$(@F).h $(LIBS_I)
endef
	

.PHONY : libft
libft : $(LIB_DIR)/libft 

$(LIB_DIR)/libft :
	-rm -rf $@
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)

.PHONY : libmystupidmath
libmystupidmath : $(LIB_DIR)/libmystupidmath 

$(LIB_DIR)/libmystupidmath :
	-rm -rf $@
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_stupidmath.git\
		--depth 1 \
		$@/
	$(BUILD_LIB)


.PHONY : clean-lib*
clean-lib% :
	-rm -rf $(LIB_DIR)/lib$*
	-rm $(LIBS_I)/lib$*.h
	-rm $(LIBS_L)/lib$*.a
