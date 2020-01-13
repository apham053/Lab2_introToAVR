# Test file for Lab2_introToAVR


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Add tests below

# ZERO
test "PINA: 0x00, PINB: 0x00, PINC 0x00 => PORTD: 0x00"
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x00
checkResult

# A = 40, B = 40, C = 70: TOTALWEIGHT 150, DIFFERENCE = 30
test "PINA: 0x28, PINB: 0x28, PINC 0x46 => PORTD: 0x97"
setPINA 0x28
setPINB 0x28
setPINC 0x46
continue 5
expectPORTD 0x97
checkResult

# A = 30, B = 40, C = 50: TOTALWEIGHT 120, DIFFERENCE = 20 
test "PINA: 0x1E, PINB: 0x28, PINC 0x32 => PORTD: 0x78"
setPINA 0x1E
setPINB 0x28
setPINC 0x32
continue 5
expectPORTD 0x78
checkResult

#A = 30, B = 0, C = 200: TOTALWEIGHT 230, DIFFERENCE = 170 
test "PINA: 0x1E, PINB: 0x00, PINC 0xC8 => PORTD: 0xE7"
setPINA 0x1E
setPINB 0x00
setPINC 0xC8
continue 5
expectPORTD 0xE7
checkResult

#A = 20, B = 5, C = 110: TOTALWEIGHT 135, DIFFERENCE = 90
test "PINA: 0x14, PINB: 0x05, PINC 0x6E => PORTD: 0x87"
setPINA 0x14
setPINB 0x05
setPINC 0x6E
continue 5
expectPORTD 0x87
checkResult

#A = 20, B = 10, C = 110: TOTALWEIGHT 140, DIFFERENCE = 90
test "PINA: 0x14, PINB: 0x0A, PINC 0x6E => PORTD: 0x8E"
setPINA 0x14
setPINB 0x0A
setPINC 0x6E
continue 5
expectPORTD 0x8E
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
