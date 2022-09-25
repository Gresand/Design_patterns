# Design_patterns

GOF Design Patterns  
Add a brnach command

---
## Паттерн Command
---
Реализовал паттерн Command, для этого создал абстрактный класс `AbstractCommand`:
```
class AbstractCommand
{
public:

	virtual ~AbstractCommand() {};
	virtual void Execute() = 0;

protected:

	AbstractCommand() {};
};
```
 и унаследовал три дочерних команды:
 * `CommandDeleteDynamicObj`
 * `CommandDeleteStaticObj`
 * `CommandDropBomb`  

В дочерних классах переопределил метод `Execute()`, чтобы они соответствовали тому что было написано в классе `SBomber`, удалил методы из класса `SBomber`, такие как `SBomber::DeleteDynamicObj()`, `SBomber::DeleteStaticObj()` и `SBomber::DropBomb()`, добавил в заголовок `SBomber.h` указатель `AbstractCommand* pCommand` и в тех местах где вызывались методы класса 
`SBomber` использовал следующие конструкции:  
* Для удаления динамических объектов.
 ```
pCommand = new CommandDeleteDynamicObj(vecBombs[i], vecDynamicObj);
pCommand->Execute();
delete pCommand;
```
* Для удаления статических объектов.
```
pCommand = new CommandDeleteStaticObj(vecDestoyableObjects[i], vecStaticObj);
pCommand->Execute();   
delete pCommand;
```
* Для метода сброса бомбы.
```
case 'b':
    pCommand = new CommandDropBomb(FindPlane(), vecDynamicObj, bombsNumber, score);
    pCommand->Execute();
    delete pCommand;
    break;

case 'B':
    pCommand = new CommandDropBomb(FindPlane(), vecDynamicObj, bombsNumber, score);
    pCommand->Execute();
    delete pCommand;
    break;
```
Задание сделано не до конца, методы отрабатывают, но с ошибками, а именно:
1. В методах удаления не правильно передаю аргументы из-за чего программа аварийно завершается когда бомба пересекает землю.
2. Количество бомб после сброса не изменяется, хотя передаю их по ссылке.
