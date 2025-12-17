// #include "C:/Wichtig/System/Static/Library/WindowEngine1.0.h"
// #include "C:/Wichtig/System/Static/Library/Victor2.h"
// #include "C:/Wichtig/System/Static/Library/Vdctor2.h"
// #include "C:/Wichtig/System/Static/Library/Complex.h"
// #include "C:/Wichtig/System/Static/Library/TransformedView.h"
// #include "C:\Wichtig\System\Static\Container\Vector.h"

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/MMenuSystem.h"

MenuSystem menu;
MenuOption* preselected;
MenuOption* selected;

void Setup(AlxWindow* w){
	menu = MenuSystem_New(
		AlxFont_MAKE_HIGH(32,64),
		"./assets/Pointer.png",
		"./assets/Fold.png",
		"./assets/FoldUp.png",
		"./assets/FoldDown.png",
		"./assets/Rainbow_Atlas.png",
		0U,64,0.0f,32.0f,32.0f
	);

	MenuSystem_Set(&menu,0,(int[]){   },	MenuOption_Make(0,"root",			"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(0,"magic",			"/",NULL,NULL,3,10));

	MenuSystem_Add(&menu,1,(int[]){ 0 },	MenuOption_Make(1,"potions",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,2,(int[]){ 0,0 },	MenuOption_New(2,"heal",			"/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 0,0 },	MenuOption_New(3,"damage",			"/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 0 },	MenuOption_New(4,"iceball",			"/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 0 },	MenuOption_New(5,"lightning",		"/",NULL,NULL));

	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(6,"arrows",			"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,1,(int[]){ 1 },	MenuOption_Make(7,"small",			"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,2,(int[]){ 1,0 },	MenuOption_New(8,"invisible",		"/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 1,0 },	MenuOption_New(9,"fast",			"/",NULL,NULL));

	MenuSystem_Add(&menu,1,(int[]){ 1 },	MenuOption_Make(10,"big",			"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,2,(int[]){ 1,1 },	MenuOption_New(11,"invisible",		"/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 1,1 },	MenuOption_New(12,"fast",			"/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 1 },	MenuOption_New(13,"lightningarrow",	"/",NULL,NULL));

	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(14,"swords",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,1,(int[]){ 2 },	MenuOption_New(15,"fireswords",		"/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 2 },	MenuOption_New(16,"iceswords",		"/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 2 },	MenuOption_New(17,"lightningswords","/",NULL,NULL));

	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(18,"dummy1",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(19,"dummy2",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(20,"dummy3",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(21,"dummy4",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(22,"dummy5",		"/",NULL,NULL,3,10));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_Make(23,"dummy6",		"/",NULL,NULL,3,10));

	MenuSystem_Step(&menu);

	preselected = NULL;
	selected = NULL;
}
void Update(AlxWindow* w){
	if(Stroke(ALX_KEY_ESC).PRESSED){
        if(menu.trace.size == 0)    MenuSystem_Step(&menu); 
        else                        MenuSystem_Clear(&menu);
    }

	if(menu.trace.size > 0){
		if(Stroke(ALX_KEY_SPACE).PRESSED){
			MenuSystem_Deactivate(&menu,&menu.trace);
		}

		if(Stroke(ALX_MOUSE_L).PRESSED){
			MMenuSystem_SelectPoint(&menu,GetMouse());
			preselected = selected;
			selected = MenuSystem_Select(&menu);
		}
	}

	MenuSystem_Update(&menu);

	Clear(DARK_BLUE);

	MMenuSystem_Render(WINDOW_STD_ARGS,&menu);

	if(selected && preselected == selected && selected->text)
		RenderCStr(selected->text,0.0f,0.0f,RED);
}
void Delete(AlxWindow* w){
    MenuSystem_Free(&menu);
}

int main(){
    if(Create("Menu System",2200,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}