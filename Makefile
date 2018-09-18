.PHONY : def
def : targets
	$(MAKE) all


############
#VARIABLES :
ifndef ROOT
 ROOT := .
endif
include $(ROOT)/make_vars.mk


#######
#CORE :
include $(ROOT)/core.mk


########################
#TARGETS & DEPENDENCIES:
include $(SRC_DIR)/Makefile

#######
#LIBS :
include $(LIB_DIR)/Makefile

########
#TESTS :
include $(TEST_DIR)/Makefile
include $(AUX_DIR)/Makefile



##########
#RELEASE :

RELEASE_DIR = release_$(NAME)

.PHONY : release
release :

.PHONY : $(RELEASE_DIR)
$(RELEASE_DIR) :
	if [ -d $@ ];\
	then rm -rf $(RELEASE_DIR)/;\
	fi
	git clone \
		--single-branch \
		-b release \
		$(GIT_REPO) \
		$(RELEASE_DIR)
	cd $(RELEASE_DIR) && git rm -rf *
	cp auteur $(RELEASE_DIR)/
	mkdir $@/sources
	cp $(SRCS) $@/sources
	mkdir $@/includes
	cp $(INCS) $@/includes
	cp $(patsubst %,$(LIBS_I)/%.h,$(DEPENDENCIES)) $@/includes
	cp $(ROOT)/core.mk $@/Makefile
	cat $(ROOT)/targets.mk $(ROOT)/release_vars.mk > $@/make_vars.mk
	cd $(RELEASE_DIR) && \
		git add * && \
		git commit -m make_release && \
		git push origin release
