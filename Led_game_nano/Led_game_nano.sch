EESchema Schematic File Version 4
LIBS:Led_game_nano-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x03_Female J?
U 1 1 5EFDEF6F
P 1700 1700
F 0 "J?" H 1594 1985 50  0000 C CNN
F 1 "Conn_01x03_Female" H 1594 1894 50  0000 C CNN
F 2 "" H 1700 1700 50  0001 C CNN
F 3 "~" H 1700 1700 50  0001 C CNN
F 4 "16x16 led disp" H 1700 1700 50  0001 C CNN "Note"
	1    1700 1700
	-1   0    0    -1  
$EndComp
Text Notes 1300 1600 0    50   ~ 0
Red 5V
Text Notes 1300 1800 0    50   ~ 0
White GND
Text Notes 1300 1700 0    50   ~ 0
Green DIN
$Comp
L MCU_Module:Arduino_Nano_v3.x A?
U 1 1 5EFDF0B5
P 7000 2000
F 0 "A?" H 7000 914 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 7000 823 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 7150 1050 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 7000 1000 50  0001 C CNN
	1    7000 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR?
U 1 1 5EFDF1C0
P 7100 3000
F 0 "#PWR?" H 7100 2800 50  0001 C CNN
F 1 "GNDPWR" H 7104 2846 50  0000 C CNN
F 2 "" H 7100 2950 50  0001 C CNN
F 3 "" H 7100 2950 50  0001 C CNN
	1    7100 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR?
U 1 1 5EFDF253
P 6900 1000
F 0 "#PWR?" H 6900 850 50  0001 C CNN
F 1 "+5VD" H 6915 1173 50  0000 C CNN
F 2 "" H 6900 1000 50  0001 C CNN
F 3 "" H 6900 1000 50  0001 C CNN
	1    6900 1000
	1    0    0    -1  
$EndComp
Text GLabel 1900 1700 2    50   Input ~ 0
LED_sig
Wire Wire Line
	1900 1600 2550 1600
$Comp
L power:+5VD #PWR?
U 1 1 5EFDF3DF
P 4200 1600
F 0 "#PWR?" H 4200 1450 50  0001 C CNN
F 1 "+5VD" H 4215 1773 50  0000 C CNN
F 2 "" H 4200 1600 50  0001 C CNN
F 3 "" H 4200 1600 50  0001 C CNN
	1    4200 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5EFDF466
P 2550 1750
F 0 "C?" H 2668 1796 50  0000 L CNN
F 1 "470uF" H 2668 1705 50  0000 L CNN
F 2 "" H 2588 1600 50  0001 C CNN
F 3 "~" H 2550 1750 50  0001 C CNN
	1    2550 1750
	1    0    0    -1  
$EndComp
Connection ~ 2550 1600
Wire Wire Line
	2550 1600 2900 1600
$Comp
L Device:CP C?
U 1 1 5EFDF57E
P 2900 1750
F 0 "C?" H 3018 1796 50  0000 L CNN
F 1 "470uF" H 3018 1705 50  0000 L CNN
F 2 "" H 2938 1600 50  0001 C CNN
F 3 "~" H 2900 1750 50  0001 C CNN
	1    2900 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5EFDF5A1
P 3250 1750
F 0 "C?" H 3365 1796 50  0000 L CNN
F 1 "100nF" H 3365 1705 50  0000 L CNN
F 2 "" H 3288 1600 50  0001 C CNN
F 3 "~" H 3250 1750 50  0001 C CNN
	1    3250 1750
	1    0    0    -1  
$EndComp
Connection ~ 2900 1600
Wire Wire Line
	2900 1600 3250 1600
Wire Wire Line
	2550 1900 2900 1900
Wire Wire Line
	2900 1900 3250 1900
Connection ~ 2900 1900
Connection ~ 3250 1600
$Comp
L power:GNDPWR #PWR?
U 1 1 5EFDF77B
P 4200 1700
F 0 "#PWR?" H 4200 1500 50  0001 C CNN
F 1 "GNDPWR" H 4204 1546 50  0000 C CNN
F 2 "" H 4200 1650 50  0001 C CNN
F 3 "" H 4200 1650 50  0001 C CNN
	1    4200 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1900 2400 1900
Wire Wire Line
	1900 1900 1900 1800
Connection ~ 2550 1900
$Comp
L Device:CP C?
U 1 1 5EFDFEC3
P 2800 2450
F 0 "C?" H 2918 2496 50  0000 L CNN
F 1 "470uF" H 2918 2405 50  0000 L CNN
F 2 "" H 2838 2300 50  0001 C CNN
F 3 "~" H 2800 2450 50  0001 C CNN
	1    2800 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:CP C?
U 1 1 5EFDFECC
P 3150 2450
F 0 "C?" V 3268 2496 50  0000 L CNN
F 1 "470uF" H 3268 2405 50  0000 L CNN
F 2 "" H 3188 2300 50  0001 C CNN
F 3 "~" H 3150 2450 50  0001 C CNN
	1    3150 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5EFDFED3
P 3500 2450
F 0 "C?" H 3615 2496 50  0000 L CNN
F 1 "100nF" H 3615 2405 50  0000 L CNN
F 2 "" H 3538 2300 50  0001 C CNN
F 3 "~" H 3500 2450 50  0001 C CNN
	1    3500 2450
	1    0    0    -1  
$EndComp
Connection ~ 3150 2600
Text Notes 1150 2650 0    50   ~ 0
Red 5V
Text Notes 1100 2500 0    50   ~ 0
Black GND
Text Notes 4100 1450 0    50   ~ 0
2.5A
Wire Wire Line
	3250 1600 4200 1600
Wire Wire Line
	4200 1700 3700 1700
Wire Wire Line
	3700 1700 3700 1900
Wire Wire Line
	3700 1900 3250 1900
Connection ~ 3250 1900
$Comp
L pspice:DIODE D?
U 1 1 5EFE1C79
P 4000 2600
F 0 "D?" H 4000 2335 50  0000 C CNN
F 1 "DIODE" H 4000 2426 50  0000 C CNN
F 2 "" H 4000 2600 50  0001 C CNN
F 3 "" H 4000 2600 50  0001 C CNN
	1    4000 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5EFE241D
P 1950 4150
F 0 "SW?" H 1950 3783 50  0000 C CNN
F 1 "ENC1" H 1950 3874 50  0000 C CNN
F 2 "" H 1800 4310 50  0001 C CNN
F 3 "~" H 1950 4410 50  0001 C CNN
	1    1950 4150
	-1   0    0    1   
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5EFE3263
P 5200 4200
F 0 "SW?" H 5200 4567 50  0000 C CNN
F 1 "ENC2" H 5200 4476 50  0000 C CNN
F 2 "" H 5050 4360 50  0001 C CNN
F 3 "~" H 5200 4460 50  0001 C CNN
	1    5200 4200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE3B94
P 3700 5900
F 0 "SW?" H 3700 5715 50  0000 C CNN
F 1 "SW_Push" H 3700 5806 50  0000 C CNN
F 2 "" H 3700 6100 50  0001 C CNN
F 3 "" H 3700 6100 50  0001 C CNN
	1    3700 5900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE3CA4
P 3050 6750
F 0 "SW?" H 3050 6565 50  0000 C CNN
F 1 "SW_Push" H 3050 6656 50  0000 C CNN
F 2 "" H 3050 6950 50  0001 C CNN
F 3 "" H 3050 6950 50  0001 C CNN
	1    3050 6750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE3F03
P 4300 6750
F 0 "SW?" H 4300 7035 50  0000 C CNN
F 1 "SW_Push" H 4300 6944 50  0000 C CNN
F 2 "" H 4300 6950 50  0001 C CNN
F 3 "" H 4300 6950 50  0001 C CNN
	1    4300 6750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE415D
P 3700 6750
F 0 "SW?" H 3700 6565 50  0000 C CNN
F 1 "SW_Push" H 3700 6656 50  0000 C CNN
F 2 "" H 3700 6950 50  0001 C CNN
F 3 "" H 3700 6950 50  0001 C CNN
	1    3700 6750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE43D0
P 1300 6950
F 0 "SW?" H 1300 6765 50  0000 C CNN
F 1 "SW_Push" H 1300 6856 50  0000 C CNN
F 2 "" H 1300 7150 50  0001 C CNN
F 3 "" H 1300 7150 50  0001 C CNN
	1    1300 6950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE4636
P 3700 4200
F 0 "SW?" H 3700 4015 50  0000 C CNN
F 1 "SW_Push" H 3700 4106 50  0000 C CNN
F 2 "" H 3700 4400 50  0001 C CNN
F 3 "" H 3700 4400 50  0001 C CNN
	1    3700 4200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5EFE488B
P 3050 4200
F 0 "SW?" H 3050 4015 50  0000 C CNN
F 1 "SW_Push" H 3050 4106 50  0000 C CNN
F 2 "" H 3050 4400 50  0001 C CNN
F 3 "" H 3050 4400 50  0001 C CNN
	1    3050 4200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5EFE612A
P 7200 1000
F 0 "#PWR?" H 7200 850 50  0001 C CNN
F 1 "+5V" H 7215 1173 50  0000 C CNN
F 2 "" H 7200 1000 50  0001 C CNN
F 3 "" H 7200 1000 50  0001 C CNN
	1    7200 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5EFE76CA
P 5600 2600
F 0 "R?" V 5700 2400 50  0000 C CNN
F 1 "470R" V 5700 2600 50  0000 C CNN
F 2 "" V 5530 2600 50  0001 C CNN
F 3 "~" H 5600 2600 50  0001 C CNN
	1    5600 2600
	0    1    1    0   
$EndComp
Text GLabel 5450 2600 0    50   Input ~ 0
LED_sig
Text GLabel 3500 5900 1    50   Input ~ 0
UP
Text GLabel 3500 6750 1    50   Input ~ 0
DOWN
Text GLabel 2850 6750 1    50   Input ~ 0
LEFT
Text GLabel 4100 6750 1    50   Input ~ 0
RIGHT
$Comp
L power:+5V #PWR?
U 1 1 5EFE8877
P 4850 6950
F 0 "#PWR?" H 4850 6800 50  0001 C CNN
F 1 "+5V" V 4865 7078 50  0000 L CNN
F 2 "" H 4850 6950 50  0001 C CNN
F 3 "" H 4850 6950 50  0001 C CNN
	1    4850 6950
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 6950 4500 6950
Text GLabel 1100 6950 0    50   Input ~ 0
ACTION
Text GLabel 2850 4200 1    50   Input ~ 0
OPTION
Text GLabel 3900 4200 1    50   Input ~ 0
START
$Comp
L Device:Speaker LS?
U 1 1 5EFED782
P 5050 5300
F 0 "LS?" H 5220 5296 50  0000 L CNN
F 1 "Active_Speaker" H 5220 5205 50  0000 L CNN
F 2 "" H 5050 5100 50  0001 C CNN
F 3 "~" H 5040 5250 50  0001 C CNN
	1    5050 5300
	1    0    0    -1  
$EndComp
Text GLabel 5650 1700 0    50   Input ~ 0
ENC1.L
Text GLabel 5650 1600 0    50   Input ~ 0
ENC2.L
$Comp
L Device:R R?
U 1 1 5EFEED94
P 5800 1100
F 0 "R?" H 5730 1054 50  0000 R CNN
F 1 "1K" H 5730 1145 50  0000 R CNN
F 2 "" V 5730 1100 50  0001 C CNN
F 3 "~" H 5800 1100 50  0001 C CNN
	1    5800 1100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5EFEFB34
P 5900 1100
F 0 "R?" H 5830 1054 50  0000 R CNN
F 1 "1K" H 5830 1145 50  0000 R CNN
F 2 "" V 5830 1100 50  0001 C CNN
F 3 "~" H 5900 1100 50  0001 C CNN
	1    5900 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 1000 7200 650 
Connection ~ 7200 1000
Wire Wire Line
	5900 950  5800 950 
Wire Wire Line
	5800 1250 5800 1600
Wire Wire Line
	5800 1600 5650 1600
Connection ~ 5800 1600
Wire Wire Line
	5900 1250 5900 1700
Wire Wire Line
	5900 1700 5650 1700
Text GLabel 5650 2000 0    50   Input ~ 0
ENC1.R
Text GLabel 5650 1900 0    50   Input ~ 0
ENC2.R
Wire Wire Line
	5650 1800 6000 1800
$Comp
L Device:R R?
U 1 1 5EFF5D34
P 6000 1100
F 0 "R?" H 5930 1054 50  0000 R CNN
F 1 "1K" H 5930 1145 50  0000 R CNN
F 2 "" V 5930 1100 50  0001 C CNN
F 3 "~" H 6000 1100 50  0001 C CNN
	1    6000 1100
	-1   0    0    1   
$EndComp
Connection ~ 5900 1700
Connection ~ 5900 950 
$Comp
L Device:R R?
U 1 1 5EFFD46A
P 6100 1100
F 0 "R?" H 6030 1054 50  0000 R CNN
F 1 "1K" H 6030 1145 50  0000 R CNN
F 2 "" V 6030 1100 50  0001 C CNN
F 3 "~" H 6100 1100 50  0001 C CNN
	1    6100 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 1250 6000 1800
Connection ~ 6000 1800
Wire Wire Line
	6100 1250 6100 1900
Wire Wire Line
	5900 950  6000 950 
Connection ~ 6000 950 
Wire Wire Line
	6500 2600 5750 2600
NoConn ~ 6500 2700
Text Notes 5950 2750 0    50   ~ 0
Onboard LED
Text GLabel 5650 1800 0    50   Input ~ 0
ENC1.S
Text GLabel 5650 2100 0    50   Input ~ 0
ENC2.S
$Comp
L Device:R R?
U 1 1 5F007D3C
P 6200 1100
F 0 "R?" H 6130 1054 50  0000 R CNN
F 1 "1K" H 6130 1145 50  0000 R CNN
F 2 "" V 6130 1100 50  0001 C CNN
F 3 "~" H 6200 1100 50  0001 C CNN
	1    6200 1100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F007D43
P 6300 1100
F 0 "R?" H 6230 1054 50  0000 R CNN
F 1 "1K" H 6230 1145 50  0000 R CNN
F 2 "" V 6230 1100 50  0001 C CNN
F 3 "~" H 6300 1100 50  0001 C CNN
	1    6300 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6200 950  6300 950 
Connection ~ 6200 950 
Wire Wire Line
	5800 1600 6500 1600
Wire Wire Line
	5900 1700 6500 1700
Wire Wire Line
	6000 1800 6500 1800
Wire Wire Line
	5650 2000 6200 2000
Wire Wire Line
	5650 2100 6300 2100
Wire Wire Line
	6200 1250 6200 2000
Connection ~ 6200 2000
Wire Wire Line
	6200 2000 6500 2000
Wire Wire Line
	6300 1250 6300 2100
Connection ~ 6300 2100
Wire Wire Line
	6300 2100 6500 2100
NoConn ~ 6500 1400
NoConn ~ 6500 1500
Text Notes 6250 1500 0    50   ~ 0
TX/RX
Wire Wire Line
	6300 950  6300 650 
Connection ~ 6300 950 
Wire Wire Line
	6300 650  7200 650 
Text GLabel 2250 4250 2    50   Input ~ 0
ENC1.L
Text GLabel 4900 4100 0    50   Input ~ 0
ENC2.L
Text GLabel 2250 4050 2    50   Input ~ 0
ENC1.R
Text GLabel 4900 4300 0    50   Input ~ 0
ENC2.R
Text GLabel 1650 4250 0    50   Input ~ 0
ENC1.S
Text GLabel 5500 4300 2    50   Input ~ 0
ENC2.S
$Comp
L power:GND #PWR?
U 1 1 5F0177BC
P 2250 4150
F 0 "#PWR?" H 2250 3900 50  0001 C CNN
F 1 "GND" V 2255 4022 50  0000 R CNN
F 2 "" H 2250 4150 50  0001 C CNN
F 3 "" H 2250 4150 50  0001 C CNN
	1    2250 4150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F017A79
P 1650 4050
F 0 "#PWR?" H 1650 3800 50  0001 C CNN
F 1 "GND" V 1655 3922 50  0000 R CNN
F 2 "" H 1650 4050 50  0001 C CNN
F 3 "" H 1650 4050 50  0001 C CNN
	1    1650 4050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F017E75
P 5500 4100
F 0 "#PWR?" H 5500 3850 50  0001 C CNN
F 1 "GND" V 5505 3972 50  0000 R CNN
F 2 "" H 5500 4100 50  0001 C CNN
F 3 "" H 5500 4100 50  0001 C CNN
	1    5500 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F01811C
P 4900 4200
F 0 "#PWR?" H 4900 3950 50  0001 C CNN
F 1 "GND" V 4905 4072 50  0000 R CNN
F 2 "" H 4900 4200 50  0001 C CNN
F 3 "" H 4900 4200 50  0001 C CNN
	1    4900 4200
	0    1    1    0   
$EndComp
Text GLabel 5650 2200 0    50   Input ~ 0
OPTION
Text GLabel 5650 2300 0    50   Input ~ 0
START
Text GLabel 8400 2000 2    50   Input ~ 0
ACTION
Text GLabel 5650 2400 0    50   Input ~ 0
UP
Text GLabel 8400 2400 2    50   Input ~ 0
DOWN
Text GLabel 8400 2500 2    50   Input ~ 0
LEFT
Text GLabel 5650 2500 0    50   Input ~ 0
RIGHT
Text GLabel 4850 5300 0    50   Input ~ 0
SPK
Text GLabel 8400 2700 2    50   Input ~ 0
SPK
Connection ~ 6100 950 
Wire Wire Line
	6100 950  6200 950 
Wire Wire Line
	6000 950  6100 950 
Wire Wire Line
	6100 1900 6500 1900
Wire Wire Line
	6100 1900 5650 1900
Connection ~ 6100 1900
$Comp
L Device:R R?
U 1 1 5F023E25
P 5850 3050
F 0 "R?" H 5780 3004 50  0000 R CNN
F 1 "1K" H 5780 3095 50  0000 R CNN
F 2 "" V 5780 3050 50  0001 C CNN
F 3 "~" H 5850 3050 50  0001 C CNN
	1    5850 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F023E2C
P 5950 3050
F 0 "R?" H 5880 3004 50  0000 R CNN
F 1 "1K" H 5880 3095 50  0000 R CNN
F 2 "" V 5880 3050 50  0001 C CNN
F 3 "~" H 5950 3050 50  0001 C CNN
	1    5950 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F023E36
P 6050 3050
F 0 "R?" H 5980 3004 50  0000 R CNN
F 1 "1K" H 5980 3095 50  0000 R CNN
F 2 "" V 5980 3050 50  0001 C CNN
F 3 "~" H 6050 3050 50  0001 C CNN
	1    6050 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F023E3E
P 6150 3050
F 0 "R?" H 6080 3004 50  0000 R CNN
F 1 "1K" H 6080 3095 50  0000 R CNN
F 2 "" V 6080 3050 50  0001 C CNN
F 3 "~" H 6150 3050 50  0001 C CNN
	1    6150 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 2200 5850 2200
Wire Wire Line
	6500 2300 5950 2300
Wire Wire Line
	5650 2400 6050 2400
Wire Wire Line
	6500 2500 6150 2500
Wire Wire Line
	5850 2900 5850 2200
Connection ~ 5850 2200
Wire Wire Line
	5850 2200 6500 2200
Wire Wire Line
	5950 2900 5950 2300
Connection ~ 5950 2300
Wire Wire Line
	5950 2300 5650 2300
Wire Wire Line
	6050 2900 6050 2400
Connection ~ 6050 2400
Wire Wire Line
	6050 2400 6500 2400
Wire Wire Line
	6150 2900 6150 2500
Connection ~ 6150 2500
Wire Wire Line
	6150 2500 5650 2500
Wire Wire Line
	7000 3000 6400 3000
Wire Wire Line
	6400 3000 6400 3200
Wire Wire Line
	6400 3200 6150 3200
Wire Wire Line
	6050 3200 6150 3200
Connection ~ 6150 3200
Wire Wire Line
	6050 3200 5950 3200
Connection ~ 6050 3200
Wire Wire Line
	5950 3200 5850 3200
Connection ~ 5950 3200
$Comp
L Device:R R?
U 1 1 5F0356C2
P 7650 3050
F 0 "R?" H 7580 3004 50  0000 R CNN
F 1 "1K" H 7580 3095 50  0000 R CNN
F 2 "" V 7580 3050 50  0001 C CNN
F 3 "~" H 7650 3050 50  0001 C CNN
	1    7650 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F0356C9
P 7750 3050
F 0 "R?" H 7680 3004 50  0000 R CNN
F 1 "1K" H 7680 3095 50  0000 R CNN
F 2 "" V 7680 3050 50  0001 C CNN
F 3 "~" H 7750 3050 50  0001 C CNN
	1    7750 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F0356D0
P 7850 3050
F 0 "R?" H 7780 3004 50  0000 R CNN
F 1 "1K" H 7780 3095 50  0000 R CNN
F 2 "" V 7780 3050 50  0001 C CNN
F 3 "~" H 7850 3050 50  0001 C CNN
	1    7850 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	7650 2900 7650 2400
Wire Wire Line
	7750 2900 7750 2500
Wire Wire Line
	8400 2400 7650 2400
Wire Wire Line
	7500 2400 7650 2400
Connection ~ 7650 2400
Wire Wire Line
	8400 2500 7750 2500
Wire Wire Line
	7750 2500 7500 2500
Connection ~ 7750 2500
Wire Wire Line
	7850 3200 7750 3200
Wire Wire Line
	7750 3200 7650 3200
$Comp
L Device:R R?
U 1 1 5F0524D8
P 8150 2700
F 0 "R?" V 7943 2700 50  0000 C CNN
F 1 "150R" V 8034 2700 50  0000 C CNN
F 2 "" V 8080 2700 50  0001 C CNN
F 3 "~" H 8150 2700 50  0001 C CNN
	1    8150 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 2700 8300 2700
Wire Wire Line
	8000 2700 7500 2700
$Comp
L power:GND #PWR?
U 1 1 5F0643F0
P 4850 5400
F 0 "#PWR?" H 4850 5150 50  0001 C CNN
F 1 "GND" V 4855 5272 50  0000 R CNN
F 2 "" H 4850 5400 50  0001 C CNN
F 3 "" H 4850 5400 50  0001 C CNN
	1    4850 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 3200 6400 3200
Connection ~ 6400 3200
Connection ~ 7650 3200
Connection ~ 7750 3200
Wire Wire Line
	3250 4200 3400 4200
Wire Wire Line
	3250 6950 3250 6750
Connection ~ 3250 6950
Wire Wire Line
	4500 6750 4500 6950
Wire Wire Line
	3400 4200 3400 6950
Wire Wire Line
	3250 6950 3400 6950
Connection ~ 3400 4200
Wire Wire Line
	3400 4200 3500 4200
Connection ~ 3400 6950
Wire Wire Line
	8400 2000 7850 2000
Wire Wire Line
	7850 2000 7850 2900
Connection ~ 7850 2000
Wire Wire Line
	7850 2000 7500 2000
NoConn ~ 7500 2200
NoConn ~ 7500 2100
NoConn ~ 7500 2300
NoConn ~ 7500 1800
NoConn ~ 7500 1500
NoConn ~ 7500 1400
NoConn ~ 7100 1000
Wire Wire Line
	2800 2600 3150 2600
Connection ~ 2800 2300
Wire Wire Line
	2800 2300 3150 2300
Connection ~ 3150 2300
Wire Wire Line
	3150 2300 3500 2300
Wire Wire Line
	2400 2300 2400 1900
Wire Wire Line
	2400 2300 2800 2300
Connection ~ 2400 1900
Wire Wire Line
	2400 1900 1900 1900
Wire Wire Line
	3150 2600 3500 2600
Connection ~ 4500 6950
Connection ~ 3900 6950
Wire Wire Line
	3900 6950 4500 6950
$Comp
L power:GND #PWR?
U 1 1 5F014899
P 7500 2200
F 0 "#PWR?" H 7500 1950 50  0001 C CNN
F 1 "GND" H 7505 2027 50  0000 C CNN
F 2 "" H 7500 2200 50  0001 C CNN
F 3 "" H 7500 2200 50  0001 C CNN
	1    7500 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5EFDFC1C
P 1550 2500
F 0 "J?" H 1656 2678 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1550 2800 50  0000 C CNN
F 2 "" H 1550 2500 50  0001 C CNN
F 3 "~" H 1550 2500 50  0001 C CNN
	1    1550 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2300 1750 2500
Connection ~ 2800 2600
Wire Wire Line
	1750 2600 2800 2600
Connection ~ 2400 2300
Wire Wire Line
	1750 2300 2400 2300
Text Notes 4400 2150 0    50   ~ 0
2A
Wire Wire Line
	4200 2600 4350 2600
$Comp
L power:+5VA #PWR?
U 1 1 5EFE0824
P 4350 2300
F 0 "#PWR?" H 4350 2150 50  0001 C CNN
F 1 "+5VA" H 4365 2473 50  0000 C CNN
F 2 "" H 4350 2300 50  0001 C CNN
F 3 "" H 4350 2300 50  0001 C CNN
	1    4350 2300
	1    0    0    -1  
$EndComp
Connection ~ 3500 2600
Wire Wire Line
	3500 2600 3800 2600
Connection ~ 3500 2300
Wire Wire Line
	3500 2300 4350 2300
Wire Wire Line
	4350 2400 4350 2600
Connection ~ 4350 2300
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 5EFE1282
P 4550 2300
F 0 "J?" H 4656 2478 50  0000 C CNN
F 1 "Conn_01x02_Male" H 4550 2600 50  0000 C CNN
F 2 "" H 4550 2300 50  0001 C CNN
F 3 "~" H 4550 2300 50  0001 C CNN
	1    4550 2300
	-1   0    0    -1  
$EndComp
Wire Notes Line
	2100 2050 2100 2800
Wire Notes Line
	2100 2800 1000 2800
Wire Notes Line
	1000 2800 1000 2050
Wire Notes Line
	1350 2050 1350 2100
Wire Notes Line
	1000 2050 2100 2050
Wire Notes Line
	4950 1950 4950 2750
Wire Notes Line
	4950 2750 3750 2750
Wire Notes Line
	3750 2750 3750 1950
Wire Notes Line
	4200 1950 4200 2100
Wire Notes Line
	3750 1950 4950 1950
Text Notes 4300 2850 0    50   ~ 0
In work
Text Notes 1350 2900 0    50   ~ 0
In work
Wire Wire Line
	1500 6950 3250 6950
Wire Wire Line
	3900 5900 3900 6750
Connection ~ 3900 6750
Wire Wire Line
	3900 6750 3900 6950
Wire Wire Line
	3400 6950 3900 6950
$EndSCHEMATC
