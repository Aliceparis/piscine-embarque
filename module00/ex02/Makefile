NAME = ex02

SRC = main.c
OBJ = $(SRC:.c=.o)

CC = avr-gcc
FLAGS = -mmcu=atmega328p -D F_CPU=10000000UL


all: $(NAME).elf $(NAME).hex $(NAME).bin

$(NAME).elf: $(OBJ)
	$(CC) $(FLAGS) -o $(NAME).elf $(OBJ)
%.o:%.c 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME).bin: $(NAME).elf
	avr-objcopy -O binary $< $@

$(NAME).hex: $(NAME).elf
	avr-objcopy -O ihex $< $@

hex: $(NAME).bin $(NAME).hex

flash: $(NAME).hex 
	avrdude -p atmega328p -c arduino -P /dev/ttyUSB0 -U flash:w:$(NAME).hex

clean: 
	rm -rf $(NAME).bin $(NAME).hex $(OBJ)

.PHONY: all hex flash clean 
