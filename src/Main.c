// #include "C:/Wichtig/System/Static/Library/WindowEngine1.0.h"
// #include "C:/Wichtig/System/Static/Library/Victor2.h"
// #include "C:/Wichtig/System/Static/Library/Vdctor2.h"
// #include "C:/Wichtig/System/Static/Library/Complex.h"
// #include "C:/Wichtig/System/Static/Library/TransformedView.h"
// #include "C:\Wichtig\System\Static\Container\Vector.h"

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/MenuSystem.h"

MenuSystem menu;
MenuOption* selected;

void Setup(AlxWindow* w){
	menu = MenuSystem_New(
		AlxFont_MAKE_BLOCKY(32,32),
		"./assets/Pointer.png",
		"./assets/Fold.png",
		"./assets/FoldUp.png",
		"./assets/FoldDown.png",
		"./assets/Rainbow_Atlas.png",
		0U,32,0.5f
	);

	MenuSystem_Set(&menu,0,(int[]){   },	MenuOption_New(0,"root","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(0,"magic","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 0 },	MenuOption_New(1,"potions","/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 0,0 },	MenuOption_New(2,"heal","/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 0,0 },	MenuOption_New(3,"damage","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 0 },	MenuOption_New(4,"iceball","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 0 },	MenuOption_New(5,"lightning","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(6,"arrows","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 1 },	MenuOption_New(7,"small","/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 1,0 },	MenuOption_New(8,"invisible","/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 1,0 },	MenuOption_New(9,"fast","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 1 },	MenuOption_New(10,"big","/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 1,1 },	MenuOption_New(11,"invisible","/",NULL,NULL));
	MenuSystem_Add(&menu,2,(int[]){ 1,1 },	MenuOption_New(12,"fast","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 1 },	MenuOption_New(13,"lightningarrow","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(14,"swords","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 2 },	MenuOption_New(15,"fireswords","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 2 },	MenuOption_New(16,"iceswords","/",NULL,NULL));
	MenuSystem_Add(&menu,1,(int[]){ 2 },	MenuOption_New(17,"lightningswords","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(18,"dummy1","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(19,"dummy2","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(20,"dummy3","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(21,"dummy4","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(22,"dummy5","/",NULL,NULL));
	MenuSystem_Add(&menu,0,(int[]){   },	MenuOption_New(23,"dummy6","/",NULL,NULL));

	MenuSystem_Step(&menu);

	selected = NULL;
}
void Update(AlxWindow* w){
	tv.ZoomSpeed = (float)w->ElapsedTime;
	TransformedView_HandlePanZoom(&tv,window.Strokes,(Vec2){ GetMouse().x,GetMouse().y });
	
	if(Stroke(ALX_KEY_ESC).PRESSED){
        if(menu.trace.size == 0)    MenuSystem_Step(&menu); 
        else                        MenuSystem_Clear(&menu);
    }

	if(menu.trace.size > 0){
		if(Stroke(ALX_KEY_ENTER).PRESSED){
			selected = MenuSystem_Select(&menu);
		}
		if(Stroke(ALX_KEY_SPACE).PRESSED){
			MenuSystem_Deactivate(&menu,&menu.trace);
		}

		if(Stroke(ALX_KEY_UP).PRESSED){
			MenuSystem_Up(&menu);
		}
		if(Stroke(ALX_KEY_DOWN).PRESSED){
			MenuSystem_Down(&menu);
		}
		if(Stroke(ALX_KEY_LEFT).PRESSED){
			MenuSystem_Left(&menu);
		}
		if(Stroke(ALX_KEY_RIGHT).PRESSED){
			MenuSystem_Right(&menu);
		}
	}

	MenuSystem_Update(&menu);

	Clear(WHITE);

	MenuSystem_Render(WINDOW_STD_ARGS,&menu,500.0f,750.0f);

	if(selected && selected->text)
		RenderCStr(selected->text,0.0f,0.0f,BLUE);
}
void Delete(AlxWindow* w){
    MenuSystem_Free(&menu);
}

int main(){
    if(Create("Menu System",2200,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}