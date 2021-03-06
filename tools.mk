##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile's tools
##

define draw_debug_mode
	@tput setaf 1; tput bold
	@echo "                                                                                                    ";
	@echo " :::::::\            ::\                                 ::\      ::\                 ::\           ";
	@echo " ::  __::\           :: |                                :::\    ::: |                :: |          ";
	@echo " :: |  :: | ::::::\  :::::::\  ::\   ::\  ::::::\        ::::\  :::: | ::::::\   ::::::: | ::::::\  ";
	@echo " :: |  :: |::  __::\ ::  __::\ :: |  :: |::  __::\       ::\::\:: :: |::  __::\ ::  __:: |::  __::\ ";
	@echo " :: |  :: |:::::::: |:: |  :: |:: |  :: |:: /  :: |      :: \:::  :: |:: /  :: |:: /  :: |:::::::: |";
	@echo " :: |  :: |::   ____|:: |  :: |:: |  :: |:: |  :: |      :: |\:  /:: |:: |  :: |:: |  :: |::   ____|";
	@echo " :::::::  |\:::::::\ :::::::  |\::::::  |\::::::: |      :: | \_/ :: |\::::::  |\::::::: |\:::::::\ ";
	@echo " \_______/  \_______|\_______/  \______/  \____:: |      \__|     \__| \______/  \_______| \_______|";
	@echo "                                         ::\   :: |                                                 ";
	@echo "                                         \::::::  |                                                 ";
	@echo "                                          \______/                                                  ";
	@echo "                                                                                                    ";
	@tput sgr0
endef

define run_command
	@echo -n $(1)
	@$(2)
	@echo "OK"
endef

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"
