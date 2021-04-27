# RTOS_qemu

Demo użycia **QEMU** i **FreeRTOS** z płytką **STM32F4-Discovery**.

W projekcie wybrano port **FreeRTOS** dla procesora **STM32 Cortex M3**. Ten procesor różni się od użytego na płytce STM32F4-Discovery głównie brakiem **FPU** *(ang. Floating Point Unit)* oraz mniejszą ilością pamięci RAM i FLASH. W całym projekcie ustawiono procesor **M4** tylko port **FreeRTOS** jesk kompilowany na **M3**, zatem mamy dostępną całą pamięć RAM i FLASH jaka jest dostępna w procesorze **M4**.

Co jest zaimplementowane: 
1. FreeRTOS, 
    * zadania tworząno są przez dwie funkcje:
        * `led_task_init()`
        * `DefaultTask()`
    * obie funkcje znajdują się w pliku `freertos.c`. Pierwsza tworzy 4 zadania używająć API FreeRTOS, a druga jest bezpośrednio kodem domyuślnego zadania we FreeRTOS.
    * kody źródłowe FreeRTOS są umieszczone w katalogu `freertos`.
2. miganie diodami.
     * w pliku `main.h` przygotowano specjalne makra `LEDx_On()`/`LEDx_OFF()`/`LEDx_TOGGLE()`, które pozwalają na możliwie szybką zmianę stanu diody.

     
Proszę o korzystanie z API FreeRTOS. 
W tym projekcie nakładka **CMSIS** nie jest w ogóle dostępna.
