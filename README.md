# Design_patterns

GOF Design Patterns  
Add a brnach proxy

## Реализация паттерна proxy
---
Для реализации паттера proxy добавил абстрактный класс `AbstractSingletone.h`
```
class AbstractSingletone
{
public:
	virtual void __fastcall OpenLogFile(const std::string& FN) = 0;
	virtual void CloseLogFile() = 0;
	virtual void __fastcall WriteToLog(const std::string& str) = 0;
	virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;
	virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;
};
```
Изменил метод `GetCurDateTime()` и реализовал его в классе `ProxyTime`, унаследовал от абстрактного класса:  

 * `Singletone.h`
 * `Proxy.h`
 * `ProxyTime.h`

 Переопределил методы:

*	`void __fastcall OpenLogFile(const std::string& FN);`
*	`void CloseLogFile();`
*	`void __fastcall WriteToLog(const std::string& str);`
*	`void __fastcall WriteToLog(const std::string& str, int n);`
*	`void __fastcall WriteToLog(const std::string& str, double d);`
---
### Использование в программе
В программе главное измнение в файле `SBomber`, в классе в секции `private` создали указатель на объект класса `ProxyTime` 
> `AbstractSingletone* abstractSingletone = &ProxyTime::GetInstance().GetInstance();`  

Далее меняем методы логирования: 
```
//FileLoggerSingletone::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");
abstractSingletone->WriteToLog(string(__FUNCTION__) + " was invoked");
```

Нарочно закомментирован участок кода, чтобы выделить разницу между реализацией singletone и  proxy  

Такой получается вывод в лог:
```
1	Mon Sep 19 02:14:33 2022 - SBomber::SBomber was invoked
2	Mon Sep 19 02:14:33 2022 - SBomber::TimeStart was invoked
3	Mon Sep 19 02:14:33 2022 - SBomber::DrawFrame was invoked
...
130	Mon Sep 19 02:14:35 2022 - SBomber::CheckObjects was invoked
131	Mon Sep 19 02:14:35 2022 - SBomber::TimeFinish deltaTime = 62
...
```  
В результате выполнения реализации паттерна получили вывод в каждой строке нумерацию логируемного события.