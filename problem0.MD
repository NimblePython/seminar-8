# Задача: Демонстрация работы RTTI с помощью оператора typeid

**Описание задачи:**

Вам необходимо продемонстрировать работу механизма RTTI (Run-Time Type Information) с использованием оператора **`typeid`**. Задача состоит в том, чтобы:

1. Продемонстрировать работу оператора **`typeid`** для переменных всех базовых типов, таких как:
   - `int`
   - `double`
   - `char`
   - `bool`
   - `float`
   - и другие стандартные типы.

2. Показать, как **`typeid`** работает для указателей на эти базовые типы.

3. Продемонстрировать работу **`typeid`** с объектами стандартных библиотек, таких как:
   - **`std::string`**
   - **`std::vector`**

4. Продемонстрировать использование **`typeid`** с вашим шаблонным классом `MyClass<>`:
   - Для объекта этого класса.
   - Для указателя на объект этого класса.

## Требования

- Оператор **`typeid`** должен быть применён ко всем указанным переменным и указателям на них.
- Для шаблонного класса **`MyClass<>`** продемонстрировать работу **`typeid`** с различными типами данных (например, с `int`, `double`, `std::string`).
