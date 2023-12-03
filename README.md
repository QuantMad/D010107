# D010107
Небольшая библиотека для Arduino призванная облегчить управление дисплеем DPD-201 (D010107)

Документация на устройство: [pdf](https://www.datecs.bg/en/downloads/pdf?id=DPD201_user.pdf).

**ВНИМАНИЕ!**

Для подключения индикатора напрямую к микроконтроллеру необходимо либо припаять сигнальный провод напрямую к резистору R9 (см. изображение), либо полностью демонтировать цепь транзистора Q2 заменив её перемычкой, либо же использовать преобразователь уровней UART/RS232 подключив его к штатному разьёму платы. 

В противном случае подключение будет **НЕКОРРЕКТНЫМ И РАБОТАТЬ НОРМАЛЬНО НЕ БУДЕТ!**

![D010107](https://github.com/QuantMad/D010107/assets/40302227/51ba4067-38c0-4e6c-9f2b-b1a988ad9585)
