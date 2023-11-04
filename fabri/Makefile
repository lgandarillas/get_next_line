#CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

all:
	gcc $(CFLAGS) main.c get_next_line.c get_next_line.h get_next_line_utils.c

clean:
	@rm ./a.out
	@rm get_next_line.h.gch 
	@rm -rf a.out.dSYM
	@echo eliminaos nwn

#generate debug information
debug:
	gcc $(CFLAGS) main.c get_next_line.c get_next_line.h get_next_line_utils.c -g3
	@echo Listop
# @echo compilando nwn
# @lldb -- a.out prueba.txt

re:
	make clean
	make all

re_debug:
	make clean
	make debug

#if you want to change the buffer size
#	Do:
#		make bf bf=<size of your buffer>
#		make debug bf bf=<size of your buffer> (if you want to generate debug information)

bf: CFLAGS += -D BUFFER_SIZE=$(bf)
bf: CFLAGS += -g3
bf: all

.PHONY: all size clean debug re re_debug

#flopez-r
