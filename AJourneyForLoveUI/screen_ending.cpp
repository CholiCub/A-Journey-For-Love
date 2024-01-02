#include"raylib.h"
#include"screens.h"

int finishScreen = 0;

void InitEndingScreen() {

}
void UpdateEndingScreen() {
	if (IsKeyPressed(KEY_ENTER)) {
		finishScreen = 2;
	}
}
void DrawEndingScreen() {
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), LIGHTGRAY);
	DrawText("Press enter to jumpt to Player title screen", 0, 0, 20, BLACK);
}
void UnloadEndingScreen() {

}
int FinsihEndingScreen(){
	return finishScreen;
}