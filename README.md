<h1>Поиск точки пересечения двух отрезков в пространстве</h1>

<h3>Дано:</h3>
Два отрезка, каждый из которых имеет начало и конец, которые являются точками (радиус-векторами) в пространстве

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/9211b198-fdda-4635-8933-a0af74846186)

<h3>Результат:</h3>
 - Замеренное время работы функции, которая ищет точку пересечения отрезков в пространстве
 <br>
 - Точка пересечения двух отрезков, либо бесконечно удаленная точка, если точек пересечения нет, либо отрезки накладываются друг на друга или совпадают (бесконечное множество точек пересечения)
 
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/a7d44921-766b-49a9-b054-a2e648a98fd3)

<h3>Использованный метод:</h3>
После простейших проверок, является ли отрезок точкой (начало и конец совпадают), параллельны ли отрезки, соеденены ли они концами и лежат ли они в одной плоскости (признак того, что отрезки не скрещиваются)
появляется вариант решения СЛАУ для поиска точки пересечения прямых, и проверки, принадлежит ли данная точка отрезкам.
<br>
<br>
Возникает проблема, если одна из координат равна нулю у каждой точки (то есть оба отрезка лежат в одной координатной плоскости) с высокой вероятностью возникает ошибка деления на 0
(например, при рассчёте определителя для решения СЛАУ методом Крамера, зануляется один из столбцов, а следственно и весь определитель)
<br>
<br>
Поэтому было принято решение разбить систему на три под-системы (комбинации по два уравнения) и решить их методом Крамера (в данном случае, даже если при одной комбинации уравнений возникает ошибка деления на 0, параметр уравнения можно выразить через другие уравнения)
<br>
<br>
<h3>Тесты программы:</h3>

<h4>1. Оба отрезка точки и при этом совпадают</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/d70cf8d4-4a06-497c-8d3d-3eafe09095eb)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/72236297-7a24-4c81-9b89-8c0872bba95d)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/c989398d-690c-4d55-bbf4-b555533d19e0)


<h4>2. Один из отрезков является точкой и лежит на втором</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/5d472470-37a0-4c35-bf55-86ea746e9e8a)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/5bececb6-db46-449c-aeef-7163b831ab17)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/fbf9aaea-9166-42f8-aa7f-79ea3eea1a8f)
<br>
<br>
<h4>3. Один из отрезков является точкой и не лежит на втором</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/2cac9a64-ad2e-4a83-ad7b-780af70af870)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/daef096e-9c28-42a6-82e3-d73fde7fe8f3)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/23350a70-7ba4-4b8f-bbfb-80cac6279007)
<br>
<br>
<h4>4. Два отрезка соеденены концами, но не параллельны</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/d3909f9a-5709-4356-9c8e-1555f5aa02a9)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/706b9df5-6070-4f36-8dec-e1e6d2eea3ec)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/202cc277-957c-46d1-827e-310ffab887fa)
<br>
<br>
<h4>5. Два отрезка соеденены концами, и при этом параллельны</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/1549a01d-456a-4895-88f1-0d05f2cd63e2)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/ede9d182-944b-4d3d-ad7c-2af08331412f)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/245e81e7-eca9-4216-8913-5cd475185c76)
<br>
<br>
<h4>6. Два отрезка параллельны и при этом накладываются друг на друга</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/ecbfb99d-3796-46a8-a1f1-a9dd58873076)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/3a95f7f8-4819-4795-bf83-239c64aa04eb)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/868c3238-d30d-42c9-b1a7-77eeaecaa84e)
<br>
<br>
<h4>7. Два отрезка совпадают</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/5096502e-26ce-4782-97bd-a84f36f6bd88)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/196f97f6-5f13-4a2e-a8d8-24c1bd3215a8)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/0f649399-dc9b-4f86-9e01-c96117f95a79)
<br>
<br>
<h4>8. Два отрезка параллельны и не накладываются друг на друга</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/90a9fad6-c48f-4920-8575-6c90aca4ce74)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/9471595f-7dfa-416f-a87e-e030dd198559)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/35955e19-01d3-4efd-8b96-13edf8d2d3d6)
<br>
<br>
<h4>9. Оба отрезка лежат в плоскости OxOz</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/7a978bd5-5ddb-4a8d-b831-f010299dd9e2)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/8e1c1b99-c71c-47cc-a787-bebca1b13dbc)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/fa2eb92f-2b9e-40f3-b92b-6e53c401e48e)
<br>
<br>
<h4>10. Оба отрезка лежат в плоскости OyOz</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/46e7da1b-997d-451d-8812-de17b81ab4f1)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/ead350d9-a904-44ba-a73f-4f7e6f628bfb)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/28d3ba3e-66b0-4dd1-ab85-1c4bcc0f07a4)
<br>
<br>
<h4>11. Оба отрезка лежат в плоскости OxOy</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/9ae21dae-8479-41dd-902a-9a2d53f8fa31)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/fdb0f931-8a5f-4fa3-8283-ef99950d4b69)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/53220922-7697-4243-90ac-f11eba826ed1)
<br>
<br>
<h4>12. Скрещивающиеся отрезки</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/2785d4e0-cf4e-477d-95d8-8c19bfa5fc7e)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/71f6490e-c9ea-471c-99fe-61640e4587a2)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/75bae6af-3b24-448c-94af-0f1b876bee5a)
<br>
<br>
<h4>13. Пересекающиеся отрезки</h4>

![image](https://github.com/eternalowo/segments_intersection/assets/98911288/6156b3b1-e635-4f05-b526-9fb6534fb3dc)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/3f1f4b6e-7489-4bc8-8b70-c3a305bc82c4)
![image](https://github.com/eternalowo/segments_intersection/assets/98911288/26073a53-4357-448e-b176-cdce21a06e1e)
<br>
<br>
Краткие комментарии к функциям даны в коде, для удобства были добавлены операторы вывода значений радиус-вектора и отрезков.
<br>
<br>
После изменений в коде программа была заново протестирована на данном наборе тестов и выдала ожидаемые результаты
<br>
<br>
Компилятор: MSVC, Стандарт: C++14, тесты проводились в конфигурации Release x64
