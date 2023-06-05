#!/bin/bash

TITLE="\033[34;43m"
RESET="\033[0m"
RED="\033[31m"
SRC_DIR="../src/"
DIRECTORY="../"
if [[ -d "$SRC_DIR" ]]
then
    DIRECTORY=${SRC_DIR}
fi
echo -e "${TITLE}NORMINETTE${RESET}"
norminette | grep -w Error
echo
echo -e "${TITLE}GCC${RESET}"
gcc -Wall -Wextra -Werror -I ${DIRECTORY} *.c ${DIRECTORY}*.c -o a.out
echo
echo -e "${TITLE}TEST${RESET}"
if [ -f "a.out" ];
then
    ./a.out
else
    echo -e "  ${RED}Error: no se generó el ejecutable ${RESET}"
fi
echo
rm -f a.out
rm -f printf.output
rm -f ft_printf.output
