#include"raylib.h"
enum GameScreen { TITLE = 0, PLAYER_SETTINGS, GAMEPLAY };
int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;
	GameScreen gameScreen = TITLE;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A JOURNEY FOR LOVE");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("A JOURNEY FOR LOVE", SCREEN_WIDTH/2-100, SCREEN_HEIGHT/2-100, 20, SKYBLUE);
		Rectangle startBox = { SCREEN_WIDTH / 2 - 100,SCREEN_HEIGHT / 2 - 50, 225,50 };
		bool mouseOnText = false;
		Vector2 mousePos = GetMousePosition();
		if ((CheckCollisionPointRec(mousePos, startBox))) { mouseOnText = true; }
		if (mouseOnText && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { gameScreen = PLAYER_SETTINGS; }
		else {}
		EndDrawing();
	}
	CloseWindow();
}