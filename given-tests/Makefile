#
# Josh Hursey
# CS 441/541: Project 5 Given Tests
#

#check: check_mode banner_help check-clean check-build
check: check_mode check-clean check-build
	@echo ""
	@echo "Additional tests may be added later"
	@echo ""

#check: pagefault banner_help \
#	check-level-1 check-level-2 check-level-3 \
#	check-level-4 check-level-5 check-level-6

banner_help:
	@echo "By default check will run all levels."
	@echo "You can run an individual level by using one of the following:"
	@echo "   check-level-1"
	@echo "   check-level-2"
	@echo "   check-level-3"
	@echo "   check-level-4"
	@echo ""
	@sleep 0

###############################################
# Setup Check
###############################################
check-clean:
	@cd given-tests && sh cleanup.sh

check-build:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Establish Tests mmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@cd given-tests && sh create.sh

###############################################
# Tests - Level 1
###############################################
