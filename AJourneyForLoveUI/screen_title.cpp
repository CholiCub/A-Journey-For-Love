#include"raylib.h"
#include"screens.h"

int finishScreen = 0;
bool mouseOnStartBox = false;

void InitTitleScreen() {
	finishScreen = 0;
}
void UpdateTitleScreen() {
	if (IsKeyPressed(KEY_ENTER)) {
		finishScreen = 2;
	}
	Rectangle startBox = { GetScreenWidth() / 2 - 70,GetScreenHeight() / 2 + 10, 225,50 };

	Vector2 mousePos = GetMousePosition();
	if ((CheckCollisionPointRec(mousePos, startBox))) { mouseOnStartBox = true; }
	else mouseOnStartBox = false;
	if (mouseOnStartBox && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { /*gameScreen = PLAYER_SETTINGS;*/ DrawText("PLayer_settings scene", 20, 20, 20, RED);
	}
}
void DrawTitleScreen() {
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), SKYBLUE);
	DrawText("A JOURNEY FOR LOVE", GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 - 100, 25, SKYBLUE);
	DrawText("START JOURNEY", GetScreenWidth() / 2 - 70, GetScreenHeight() / 2 + 10, 20, mouseOnStartBox ? RED : BLACK);
}
void UnloadTitleScreen() {

}
int FinsihTitleScreen() {
	return finishScreen;
}