#include"raylib.h"
enum GameScreen { TITLE = 0, PLAYER_SETTINGS, GAMEPLAY };
int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;
	GameScreen gameScreen = TITLE;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A JOURNEY FOR LOVE");

	Rectangle startBox = { SCREEN_WIDTH / 2 - 70,SCREEN_HEIGHT / 2 + 10, 225,50 };
	bool mouseOnStartBox = false;
	
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		//Update

		Vector2 mousePos = GetMousePosition();
		if ((CheckCollisionPointRec(mousePos, startBox))) { mouseOnStartBox = true; }
		else mouseOnStartBox = false;
		if (mouseOnStartBox && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { /*gameScreen = PLAYER_SETTINGS;*/ DrawText("PLayer_settings scene", 20, 20, 20, RED);
		}
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("A JOURNEY FOR LOVE", SCREEN_WIDTH/2-130, SCREEN_HEIGHT/2-100, 25, SKYBLUE);
		DrawText("START JOURNEY", SCREEN_WIDTH/2-70, SCREEN_HEIGHT/2+10, 20, mouseOnStartBox ? RED : BLACK);
		EndDrawing();
	}
	CloseWindow();
}