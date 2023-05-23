# Написання модулю для серводвигуна

Модуль створений для зчитування відстані та інтерфейсу між ним з user space.

## Модуль має таку вихідну структуру:
- ultrasound_main - Головний файл який керує усіма бібліотеками.
- platform_driver - Бібліотека для створення платформеного драйверу. Як тільки device tree ультразвукового датчику буде завантажено в систему, його властивості буде перевірено та модуль почне працювати з датчиком. 
- proc - Бібліотека для створення файлу  FP-ultrasound в файловій системі /proc/*, з викликом read(). Після виклику, буде виведено інформацію про модуль, та про описання ультразвукового датчику та його роботи.
- sys_dev - Бібліотека для створення файлу servo_control у файловій системі /dev/*, з викликами read(). Після виклику read() буде відображатись поточна відстань між об'єктом та датчиком відстані.
- timer_and_irq - Бібліотека, в якій описанні функції управління ультразвуковим датчиком. В бібліотеці використовуються два типи переривань:
	- System timer - для trigger контакту, який буде запускатись для того щоб послати сигнал.
	- Irq - для echo контакту, в якому буде вираховуватись відстань за рахунок затримки між відправкою та прийняттям сигналу.
- dt_servo.dts - Device Tree Overlay файл для описання номерів gpio контактів датчику. 