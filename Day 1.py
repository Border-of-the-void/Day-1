import serial
ok = True
c= 0


try:
    ser = serial.Serial ('COM6', 9600)
except Exception:
    print('Проверьте порт')
    ok = False
run = True

if ok:
    print('Успешно')
    while run:
        try:
            Input = input()
            if Input == 'OK': ser.write('O'.encode('utf-8').strip())
            else: ser.write(Input.encode('utf-8').strip())
        except:
            print('Поломка')
            run = False            
    ser.close() 
