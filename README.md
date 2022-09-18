# Design_patterns

GOF Design Patterns  
Add a brnach singletone

## Комментарии по выполнению домашнего задания
---
Для реализации паттерна Singletone рефакторил функции:  
* `void __fastcall OpenLogFile(const std::string& FN);`  
* `void CloseLogFile();`  
* `void __fastcall WriteToLog(const std::string& str);`
* `void __fastcall WriteToLog(const std::string& str, int n);`
* `void __fastcall WriteToLog(const std::string& str, double d);`

Заголовочный файл выглядит так:  

```
class Singletone
{
public:
    static Singletone& GetInstance()
    {
        static Singletone instance;
        return instance;
    }

    void __fastcall OpenLogFile(const std::string& FN);
    void CloseLogFile();
    void __fastcall WriteToLog(const std::string& str);
    void __fastcall WriteToLog(const std::string& str, int n);
    void __fastcall WriteToLog(const std::string& str, double d);
    std::string GetCurDateTime();

private:
    Singletone() {};
    Singletone(const Singletone& obj) = delete;
    Singletone& operator = (const Singletone& obj) = delete;
    std::ofstream logOut;
};
```
---
### Переписал файл главной функции приложения: 

```
int main(void)
{
    Singletone::GetInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();
        Sleep(30);
        
        game.TimeFinish();

    } while (!game.GetExitFlag());

    Singletone::GetInstance().CloseLogFile();

    return 0;
}
```
Заменил методы  
Исходный    |  Singletone
-|:-
`MyTools::OpenLogFile("log.txt");` | `Singletone::GetInstance().OpenLogFile("log.txt");`
`MyTools::CloseLogFile();` | `Singletone::GetInstance().CloseLogFile();` 
  

>Основной вопрос заключается в использовании метода `WriteToLog(...)`, так как этот метод используется в файле SBomber.cpp, вот один из методов из файла SBomber.cpp:  

```
void SBomber::DrawFrame()
{
    Singletone::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        if (vecStaticObj[i] != nullptr)
        {
            vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    fps++;

    FindLevelGUI()->SetParam(passedTime, fps, bombsNumber, score);
}
```
Правильно ли я реализую паттерн?