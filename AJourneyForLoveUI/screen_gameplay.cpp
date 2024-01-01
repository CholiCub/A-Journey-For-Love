#include"raylib.h"
#include"screens.h"

int finishScreen = 0;

void InitGameplayScreen() {
	finishScreen = 0;
}
void UpdateGameplayScreen() {
	if (IsKeyPressed(KEY_ENTER)) {
		finishScreen = 2;
	}
}
void DrawGameplayScreen() {
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PINK);
	DrawText("Press enter to jumpt to Player ending screen", 0, 0, 20, MAGENTA);
}
void UnloadGameplayScreen() {

}
int FinsihGameplayScreen() {

	return finishScreen;
}