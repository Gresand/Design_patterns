
#include <conio.h>
#include <windows.h>

#include "SBomber.h"
#include "MyTools.h"
#include "Singletone.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    FileLoggerSingletone::GetInstance().OpenLogFile("log.txt");

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

    FileLoggerSingletone::GetInstance().CloseLogFile();

    return 0;
}
/*Применение шаблона «Команда» в игре SBomber
Задача: применить паттерн «Команда» для выполнения частых стандартных действий в главном классе игры SBomber,
таких как удаление динамических и статических объектов, бросание бомбы.
В проекте SBomber уже есть функции, которые можно оформить как «Команды»:

void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
void __fastcall DeleteStaticObj(GameObject* pObj);
void DropBomb();
std::vector<DynamicObject*> vecDynamicObj;
std::vector<GameObject*> vecStaticObj;

Первые две команды будут получать указатели на удаляемый объект и ссылку на массивы,
откуда его надо удалить.

Для третьей команды можно передавать, константный указатель на объект Plane
(из него команда будет брать координаты самолета), 
ссылку на массив динамических объектов объектов (для создания динамического
объекта Bomb) 
и константную ссылку на количество бомб у самолета (количество доступных 
бомб хранится в объекте SBomber). 
Можно передавать ещё скорость падения и размер (ширину) воронки от взрыва 
— это позволит в будущем бросать более мощные бомбы,
которые будут быстрее падать и оставлять больший след.

Функциональность из этих трёх функций можно для простоты перенести в команды.
В этом случае получателем (Receiver)
и исполнителем будет сама команда. Если потребуется выполнить какую-то
команду внутри класса SBomber, мы будем динамически
создавать эту команду, задавать ей параметры (SetParams) и передавать её функции-методу. Он, в свою очередь, будет
вызывать для этой команды виртуальный метод Execute и удалять её из памяти. Отмена (Undo) действий или команд в нашей игре не нужна.

SBomber::CommandExecuter(AbstractCommand * pCommand);*/