# list
Linked list data structure which stores integer numbers.

List does not include repeating elements. List elements are in ascending order.

This Data Structure contains: 

- Constructor 
- Move Constructor
- Destructor
- Operation "+=" for adding elements to the list
- Operation "<<" for printing elements
- Operation "==" for comparing elements as a class method
- Operation "&" for creation a third list which contains elements from first AND second input lists as a friend function
- Operation "|" for creation a third list which contains elements from first OR second input lists as a friend function
- Merge method which adds elements from list to another, deleting it from the list where they were originally. 
(list1 [1, 2, 3], list2 [4, 5] => list1.merge(list2) => list1 [1, 2, 3, 4, 5], list2 [])

Element movement is done by pointer changing

Deleting elements does not cause memory leekage

Were accounted special cases when testing e.g. (null lists, lack of required elements, etc.)

# Односвязный список
Создать класс, реализующий односвязный список из целых чисел.

Список не должен содержать повторяющиеся элементы. 

Элементы списка должны быть упорядочены по возрастанию.

Класс должен иметь:
- конструктор
- конструктор перемещения
- деструктор
- операцию “+=” для добавления элемента в список
- операцию “<<” для вывода элементов
- операцию “==” для сравнения списков как метод класса
- операцию “&” для формирования третьего списка, состоящего из элементов, присутствующих в первом и втором как дружественную функцию
- операцию “|” для формирования третьего списка, состоящего из элементов, присутствующих в первом или во втором как дружественную функцию. Новый список не должен содержать повторяющихся элементов.
- метод merge, добавляющий в исходный список элементы списка, заданного параметром метода. Результат: модифицированный исходный список, пустой список (параметр метода).

Общие требования к заданию:
- Перемещение элементов списка в другое место списка должно выполняться только через изменение указателей.
- Удаление элементов списка должно включать освобождение памяти.
- При тестировании класса должны учитываться особые случаи (пустые списки, отсутствие искомых элементов и т. п.).
