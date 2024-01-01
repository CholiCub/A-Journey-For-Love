#include"raylib.h"
#include"screens.h"
//enum GameScreen { TITLE = 0, PLAYER_SETTINGS, GAMEPLAY };
GameScreen gameScreen = TITLE;
static const int SCREEN_WIDTH = 1920;
static const int SCREEN_HEIGHT = 800;

//screen manage transitions
bool IsOnTransition = false;
bool IsTransFadeOut = false;
int transFromScreen = -1;

//Local functions
void UpdateDrawFrame();

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "A JOURNEY FOR LOVE");
	currentScreen = TITLE;
	InitTitleScreen();

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		UpdateDrawFrame();
		//Update
		
		BeginDrawing();
		ClearBackground(WHITE);
		EndDrawing();
	}
	CloseWindow();
}
void UpdateDrawFrame() {
	if (!IsOnTransition) {
		switch (currentScreen) {
		case UNKNOWN:
			break;
		case STUDIO_LOGO:
			UpdateStudioLogoScreen();
			break;
		case TITLE:
			UpdateTitleScreen();
			break;
		case PLAYER_SETTINGS:
			UpdatePlayerSettingsScreen();
			break;
		case GAMEPLAY:
			UpdateGameplayScreen();
			break;
		case ENDING:
			UpdateEndingScreen();
			break;
		default:
			break;
		}
	}
}