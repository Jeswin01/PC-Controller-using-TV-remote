import serial
import time
import pyautogui, sys
print('Press Ctrl-C to quit.')

AS=serial.Serial('COM4',9600);
time.sleep(2);
x=10;
y=10;
try:
    while True:
        msg = AS.read(AS.inWaiting())
        if(msg==b''):
            continue
        print(msg)
        if(msg==b'u'):
            pyautogui.moveRel(0,-y)
        elif(msg==b'd'):
            pyautogui.moveRel(0,y)
        elif(msg==b'l'):
            pyautogui.moveRel(-x,0)
        elif(msg==b'r'):
            pyautogui.moveRel(x,0)
        elif(msg==b'c'):
            pyautogui.click()
        elif(msg==b'xi'):
            x=x+100;
        elif(msg==b'xd'):
            x=x-100;    
        elif(msg==b'yd'):
            y=y-100;     
        elif(msg==b'yi'):
            y=y+100;
        elif(msg==b'n'):
            x=10
            y=10    
        else:
            a=1
except KeyboardInterrupt:
    print('\n')
