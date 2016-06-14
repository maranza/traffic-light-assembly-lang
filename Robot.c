;Traffic Light System
;Author:lebobtse
;This program switches on Green LED
;for one minute, Amber LED for 10sec
;and Red LED for 1 min 10 sec

;Version 30

list p = PIC16F84 , r=hex
#include <p16f84.inc>

;----Declarations-----

Status equ 03H
Trisa equ 85H
Trisb equ 86H
Porta equ 05H
Portb equ 06H
count equ 0CH
count1 equ 0DH
count2 equ 0EH
count3 equ 0FH
count4 equ 10H
count5 equ 11H

;-----Port Initialization----
			org 0X00
			bsf Status, 5
			clrf Trisa
			clrf Trisb
			bcf Status, 5
			goto start

;----Subroutine----

Delay10s 	movlw .200
			movwf count5
loop1		movlw .100
			movwf .165
loop2	 	movlw count
			decfsz count, 1
			goto $-1
			decfsz count2, 1
			goto loop
			decfsz count5, 1
			goto loop1
			return

;----Delay To Generate 60s----

Delay60s 	movlw .10
			movwf count3
loop4 		movlw .100
			movwf count2
loop3 		movlw .120
			movwf count1
loop 		movlw .165
			movwf count
			decfsz count, 1
			goto $-1
			decfsz count1, 1
			goto loop
			decfsz count2, 1
			goto loop3
			decfsz count3, 1
			goto loop4
			return

;Main Program

start 		
			movlw b'00100001'
			call Delay60s
			bcf Portb, 5   ;clear pin5 (green to off)
			bsf Portb, 4   ;activate port4
			call Delay10s
			clrf Portb     ;clears all port for switch
			movlw b'00001100'
			call Delay60s
			bcf Portb, 2
			bsf Portb, 1
			call Delay10s
			clrf Portb
			goto start   ;repeats sequence
			end