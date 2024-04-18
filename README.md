![Img](img/face.jpg)


# Про програму
Програма створена за вимогами ```Лабораторних робіт(3.4, 3.5, 3.6, 3.7)``` предмету ```Комп'ютерна електроніка```.

# Вимоги
## ОС
- Операційна система [Linux](https://www.linux.org/pages/download);
## Інструменти
- Компілятор [GNU GCC(G++)](https://gcc.gnu.org);
- Генератор сценаріїв складання [CMake](https://cmake.org);
## Бібліотеки
- [C++ 11 Standard Library](https://en.cppreference.com/w/cpp/standard_library);
- [Boost C++ Libraries](https://www.boost.org);

# Завантаження
1. Завантажити проєкт через git, або архів(власноруч) та увійти в нього:
```bash
git clone https://github.com/Ge0gN0te/ThreeFormats
cd ThreeFormats
```
2. Створити директорію ```build``` та увійти в неї:
```bash
mkdir build
cd build
```
3. Зібрати та зкомпілювати проєкт через ```CMake```:
```bash
cmake .. && make
```
4. Спробувати запустити зкомпільовану програму:
```bash
./3fm --version
```
Якщо, після запуску, вас зустріла назва програми - вітаю, все пройшло успішно.
> [!NOTE]
> Якщо бажаєте, легко запускати програму через термінал, додайте готову 
> зкомпільовану програму до bin:
> ```bash
> sudo cp 3fm /usr/bin/3fm
> 3fm --version
> ```

# Автор
Програма підготовлена студентом 315-КІ групи ```Диченком Давидом Олександровичем``` (<davyd.dychenko@kitu.nau.edu.ua>).
