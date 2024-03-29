STL - совместимый контейнер "Циклический буфер", с поддержкой возможности расширения и фиксированным размером.

[Циклический буфер](https://en.wikipedia.org/wiki/Circular_buffer) - структура данных, которая часто применяется для буферизации в задачах по передачи и обработки потока данных.

## Описание

Реализация двух классов:
CCirtucalBuffer и CCircularBufferExt - для циклического буфера и циклического буфера с возможностью расширения (см ниже).

Реализовация циклического буфер для хранения данных произвольного типа в виде stl-совместимого контейнера.
Шаблон класс(ы) должен параметризироваться типом хранимого значения и  аллокатором.

## Описание

Контейнер удовлетворяет [следующим требованиям](https://en.cppreference.com/w/cpp/named_req/Container) для stl-контейнера.
А также [требования для последовательного контейнера](https://en.cppreference.com/w/cpp/named_req/SequenceContainer)

Исключая rvalue и move-семантику.

## Итератор

Класс предоставляет итератор произвольного доступа.

## Кольцевой буфер с расширением максимального размера.

Класс CCircularBufferExt обладает функциональностью для расширения свой максимального размера.
Реализует следующее поведение: в случае достижения размера кольцевого буфера максимального возможного своего размера, значение максимального размера удваивается.





